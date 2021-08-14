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
		int i = strcmp(reinterpret_cast<CNT_MODULE_INFORMATION*>(FirstStruct)->FullPathName, 
			reinterpret_cast<CNT_MODULE_INFORMATION*>(SecondStruct)->FullPathName);

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
				CNT_MODULE_INFORMATION* pcmi = reinterpret_cast<CNT_MODULE_INFORMATION*>(prbl + 1);
				*(PSHORT)buf = pcmi->LoadCount, buf += sizeof(SHORT);
				buf = xcscpy(buf, pcmi->FullPathName);
				if ((ULONG_PTR)buf & 1)
				{
					buf++;
				}
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
	PCHAR buf;
	ULONG N = 0, size = 0;
	DLL_LIST table;

	WorkQueue queue;
	if (queue.Init())
	{
		DLL_TASK task;

		if (0 <= task.Init())
		{
			NTSTATUS status;
			ULONG cb = 0x80000;

			do 
			{
				status = STATUS_NO_MEMORY;

				if (buf = new CHAR[cb])
				{
					if (0 <= (status = NtQuerySystemInformation(SystemProcessInformation, buf, cb, &cb)))
					{
						task.BeginTasks();

						DoIoControl(IOCTL_SetProtectedProcess);

						union {
							PSYSTEM_PROCESS_INFORMATION pspi;
							PCHAR pb;
						};

						pb = buf;

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
						ULONG _len = (ULONG)wcslen(systemroot), len;
						PSTR sz = (PSTR)alloca(_len), _sz = sz;
						WCHAR c;
						do 
						{
							*sz++ = (CHAR)tolower(c = *systemroot++);
						} while (c);

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
														Modules->OffsetToFileName = 0 > (LONG_PTR)Modules->ImageBase ? 0x8000 : 0;

														if (CNT_MODULE_INFORMATION* pcmi = (CNT_MODULE_INFORMATION*)
															RtlInsertElementGenericTableAvl(&table, 
															&Modules->OffsetToFileName, sizeof(USHORT) + 1 + len, &b))
														{
															pcmi->LoadCount++;
															if (b)
															{
																N++;
																size += FIELD_OFFSET(CNT_MODULE_INFORMATION, FullPathName[(len + 2) & ~1]);
															}
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
					}

					delete [] buf;
				}

			} while (status == STATUS_INFO_LENGTH_MISMATCH);

		}
		
		queue.Stop(TRUE, 0);
	}

	if (N)
	{
		if (buf = new CHAR[size + (N << 2)])
		{
			PULONG pu = (PULONG)buf;
			table.FreeTableAndFill(buf + (N << 2), &pu, buf);

			struct L {
				static int __cdecl compare(void* base, const void* p, const void* q)
				{
					ULONG a = reinterpret_cast<CNT_MODULE_INFORMATION*>(RtlOffsetToPointer(base, *(ULONG*)p))->LoadCount;
					ULONG b = reinterpret_cast<CNT_MODULE_INFORMATION*>(RtlOffsetToPointer(base, *(ULONG*)q))->LoadCount;

					if ((UCHAR)a < (UCHAR)b) return -1;
					if ((UCHAR)a > (UCHAR)b) return +1;
					return a - b;
				}
			};
			qsort_s(buf, N, sizeof(ULONG), L::compare, buf);

			bFail = FALSE;
			if (SendMessage(hwnd, e_List, N, (LPARAM)buf) != e_List)
			{
				delete [] buf;
			}
		}
	}

	if (bFail)
	{
		SendMessage(hwnd, e_List, 0, 0);
	}

	ExitThread(0);
}

_NT_END