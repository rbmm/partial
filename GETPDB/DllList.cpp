#include "StdAfx.h"

_NT_BEGIN

#include "common.h"
#include "task.h"

OBJECT_ATTRIBUTES zoa = { sizeof(zoa) };

PSTR xcscpy(PSTR dst, PCSTR src)
{
	CHAR c;
	do *dst++ = c = *src++; while(c);
	return dst;
}

struct DLL_LIST : RTL_AVL_TABLE 
{
	static RTL_GENERIC_COMPARE_RESULTS NTAPI Compare(PRTL_AVL_TABLE , PVOID FirstStruct, PVOID SecondStruct)
	{
		int i = strcmp((PCSTR)FirstStruct, (PCSTR)SecondStruct);

		if (0 > i) return GenericLessThan;
		if (0 < i) return GenericGreaterThan;
		return GenericEqual;
	}

	static PVOID NTAPI Alloc(PRTL_AVL_TABLE, CLONG ByteSize)
	{
		return LocalAlloc(0, ByteSize);
	}

	static VOID NTAPI Free(PRTL_AVL_TABLE , PVOID Buffer)
	{
		LocalFree(Buffer);
	}

	PSTR FreeTable(PRTL_BALANCED_LINKS prbl, PSTR buf, PULONG* ppu, PVOID base)
	{
		if (prbl)
		{
			buf = FreeTable(prbl->LeftChild, buf, ppu, base);
			if (buf)
			{
				PULONG pu = *ppu;
				*pu = RtlPointerToOffset(base, buf);
				*ppu = pu + 1;
				buf = xcscpy(buf, (PCSTR)(prbl + 1));
			}
			buf = FreeTable(prbl->RightChild, buf, ppu, base);
			LocalFree(prbl);
		}
		return buf;
	}

	DLL_LIST()
	{
		RtlInitializeGenericTableAvl(this, Compare, Alloc, Free, 0);
	}

	void FreeTableAndFill(PSTR buf, PULONG* ppu, PVOID base)
	{
		FreeTable(BalancedRoot.RightChild, FreeTable(BalancedRoot.LeftChild, buf, ppu, base), ppu, base);
		BalancedRoot.LeftChild = 0, BalancedRoot.RightChild = 0;
	}

	~DLL_LIST()
	{
		FreeTableAndFill(0, 0, 0);
	}
};

#include "../tkn/tkn.h"

NTSTATUS DoIoControl(ULONG code);

void EnumAllDlls(HWND hwnd)
{
	//BOOLEAN b;
	//RtlAdjustPrivilege(SE_DEBUG_PRIVILEGE, TRUE, FALSE, &b);

	BOOL bFail = TRUE;

	WorkQueue queue;
	if (queue.Init())
	{
		DLL_TASK task;

		if (0 <= task.Init())
		{
			NTSTATUS status;
			DWORD rcb = 0x10000, cb = 0;
			static volatile UCHAR guz;
			PVOID stack = alloca(guz);
			union {
				PVOID buf;
				PSYSTEM_PROCESS_INFORMATION pspi;
				PBYTE pb;
			};

			do 
			{
				if (cb < rcb)
				{
					cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);
				}

				if (0 <= (status = ZwQuerySystemInformation(SystemProcessInformation, pspi, cb, &rcb)))
				{
					task.BeginTasks();

					DoIoControl(IOCTL_SetProtectedProcess);

					ULONG NextEntryOffset = 0;
					do 
					{
						pb += NextEntryOffset;

						if (pspi->UniqueProcessId)
						{
							task.QueueTask(&queue, pspi);
						}
					} while (NextEntryOffset = pspi->NextEntryOffset);

					task.EndTasks();

					BOOLEAN b;
					PCWSTR systemroot = USER_SHARED_DATA->NtSystemRoot;
					DWORD _len = (ULONG)wcslen(systemroot), len, N = 0;
					PSTR sz = (PSTR)alloca(_len), _sz = sz;
					WCHAR c;
					do 
					{
						*sz++ = (CHAR)tolower(c = *systemroot++);
					} while (c);
					
					cb = 0;
					DLL_LIST table;

					do 
					{
						if (0 <= ZwWaitForSingleObject(task._hSemaphore, FALSE, 0))
						{
							if (UU* p = task.PopReadyTask())
							{
								NTSTATUS s = p->status;

								if (0 <= s && s != STATUS_TIMEOUT)
								{
									if (PRTL_PROCESS_MODULES prpm = p->get())
									{
										if (ULONG NumberOfModules = prpm->NumberOfModules)
										{
											PRTL_PROCESS_MODULE_INFORMATION Modules = prpm->Modules;
											do 
											{
												PSTR FullPathName = _strlwr(Modules->FullPathName);
												len = (ULONG)strlen(FullPathName);
												STATIC_ASTRING(SystemRoot, "\\systemroot\\");
												if (
													(_len < len && !memcmp(FullPathName, _sz, _len)) || 
													(RTL_NUMBER_OF(SystemRoot) - 1 < len && !memcmp(FullPathName, SystemRoot, RTL_NUMBER_OF(SystemRoot) - 1))
													)
												{
													if (RtlInsertElementGenericTableAvl(&table, FullPathName, 1 + len, &b) && b)
													{
														N++;
														cb += len + 1;
													}
												}
												
											} while (Modules++, --NumberOfModules);
										}
									}
								}

								delete p;
							}
						}

					} while (!task.IsAllTasksDone());

					DoIoControl(IOCTL_DelProtectedProcess);

					if (N)
					{
						if (PCHAR Buf = new CHAR[cb + (N << 2)])
						{
							PULONG pu = (PULONG)Buf;
							table.FreeTableAndFill(Buf + (N << 2), &pu, Buf);

							bFail = FALSE;
							if (SendMessage(hwnd, e_List, N, (LPARAM)Buf) != e_List)
							{
								delete Buf;
							}
						}
					}
				}

			} while (status == STATUS_INFO_LENGTH_MISMATCH);
		}
		
		queue.Stop(TRUE, 0);
	}

	if (bFail)
	{
		SendMessage(hwnd, e_List, 0, 0);
	}

	ExitThread(0);
}

_NT_END