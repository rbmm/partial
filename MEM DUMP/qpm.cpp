#include "StdAfx.h"

_NT_BEGIN

#include "../tkn/tkn.h"

NTSTATUS DoIoControl(ULONG code);
NTSTATUS MyOpenProcess(PHANDLE ProcessHandle, ULONG DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID Cid);
NTSTATUS MyOpenThread(PHANDLE ThreadHandle, ULONG DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID Cid);

BOOLEAN IsExportSuppressionEnabled(HANDLE hProcess);
NTSTATUS SetExportValid(HANDLE hProcess, LPCVOID pv1, LPCVOID pv2);
NTSTATUS SetExportValid(HANDLE hProcess, LPCVOID pv);

extern volatile const UCHAR guz;
extern OBJECT_ATTRIBUTES zoa;

#ifdef _WIN64

#include "../wow/wow.h"

BEGIN_DLL_FUNCS(ntdll, 0)
FUNC(LdrQueryProcessModuleInformation),
FUNC(RtlExitUserThread),
END_DLL_FUNCS();

void InitWow64()
{
	DLL_LIST_0::Process(&ntdll);
}

#endif

void Add32Modules(PRTL_PROCESS_MODULES mods, PRTL_PROCESS_MODULES32 mods32, ULONG Size)
{
	if (ULONG NumberOfModules = mods32->NumberOfModules)
	{
		if (Size == __builtin_offsetof(RTL_PROCESS_MODULES32, Modules) + NumberOfModules * sizeof(RTL_PROCESS_MODULE_INFORMATION32))
		{
			PRTL_PROCESS_MODULE_INFORMATION Modules = mods->Modules + mods->NumberOfModules;

			mods->NumberOfModules += NumberOfModules;

			PRTL_PROCESS_MODULE_INFORMATION32 Modules32 = mods32->Modules;
			do 
			{
				Modules->Flags = Modules32->Flags;
				Modules->ImageBase = (PVOID)(ULONG_PTR)Modules32->ImageBase;
				Modules->ImageSize = Modules32->ImageSize;
				Modules->InitOrderIndex = Modules32->InitOrderIndex;
				Modules->LoadCount = Modules32->LoadCount;
				Modules->LoadOrderIndex = Modules32->LoadOrderIndex;
				Modules->MappedBase = (PVOID)(ULONG_PTR)Modules32->MappedBase;
				Modules->OffsetToFileName = Modules32->OffsetToFileName;
				Modules->Section = (PVOID)(ULONG_PTR)Modules32->Section;

				strcpy(Modules++->FullPathName, Modules32++->FullPathName);

			} while (--NumberOfModules);
		}
	}
}

NTSTATUS StartQuery(
					_In_ HANDLE hProcess,
					_In_ PVOID RemoteBaseAddress,
					_In_ ULONG Size,
					_In_ BOOLEAN ExportSuppression,
#ifdef _WIN64
					_In_ BOOL wow,
#endif
					_Out_ PHANDLE phThread
					)
{
	PVOID pvLdrQueryProcessModuleInformation;
	PVOID pvRtlExitUserThread;
	NTSTATUS (NTAPI *QueueApcThread)(HANDLE hThread, PKNORMAL_ROUTINE , PVOID , PVOID , PVOID );

#ifdef _WIN64
	if (wow)
	{
		pvLdrQueryProcessModuleInformation = ntdll.funcs[0].pv;
		pvRtlExitUserThread = ntdll.funcs[1].pv;
		QueueApcThread = RtlQueueApcWow64Thread;
	}
	else
#endif
	{
		pvLdrQueryProcessModuleInformation = LdrQueryProcessModuleInformation;
		pvRtlExitUserThread = RtlExitUserThread;
		QueueApcThread = ZwQueueApcThread;
	}

	NTSTATUS status;

	if (ExportSuppression)
	{
		if (0 > (status = SetExportValid(hProcess, pvLdrQueryProcessModuleInformation, pvRtlExitUserThread)))
		{
			return status;
		}
	}

	HANDLE hThread;
	if (0 <= (status = RtlCreateUserThread(hProcess, 0, TRUE, 0, 0, 0, pvRtlExitUserThread, 0, &hThread, 0)))
	{
		if (0 <= (status = QueueApcThread(hThread, 
			(PKNORMAL_ROUTINE)pvLdrQueryProcessModuleInformation, 
			RemoteBaseAddress, 
			(PVOID)(ULONG_PTR)Size, 
			(PBYTE)RemoteBaseAddress + Size)))
		{
			NtSetInformationThread(hThread, ThreadHideFromDebugger, 0, 0);

			if (0 <= (status = ZwResumeThread(hThread, 0)))
			{
				*phThread = hThread;

				return STATUS_SUCCESS;
			}
		}

		ZwTerminateThread(hThread, 0);
		NtClose(hThread);
	}

	return status;
}

void FreePM(_In_ PRTL_PROCESS_MODULES mods)
{
	VirtualFree(mods, 0, MEM_RELEASE);
}

NTSTATUS QueryPM(_In_ HANDLE dwProcessId, _Out_ PRTL_PROCESS_MODULES* pmods)
{
	HANDLE hProcess;

	CLIENT_ID cid = { dwProcessId };
	NTSTATUS status = MyOpenProcess(&hProcess, 
		PROCESS_VM_OPERATION|PROCESS_CREATE_THREAD|PROCESS_QUERY_INFORMATION|PROCESS_SET_INFORMATION, &zoa, &cid);

	if (0 <= status)
	{
		PROCESS_EXTENDED_BASIC_INFORMATION pebi;

		if (0 <= (status = NtQueryInformationProcess(hProcess, ProcessBasicInformation, &pebi, sizeof(pebi), 0)))
		{
			if (pebi.IsProcessDeleting)
			{
				status = STATUS_PROCESS_IS_TERMINATING;
			}
			else if (pebi.IsFrozen && pebi.IsStronglyNamed)
			{
				status = STATUS_INVALID_DEVICE_STATE;
			}
			else
			{
				enum { secshift = 17, secsize = (1 << secshift) };

#ifdef _WIN64
				if (!ntdll.funcs[0].pv || !ntdll.funcs[1].pv)
#endif
				{
					pebi.IsWow64Process = 0;
				}

				LARGE_INTEGER SectionSize = { (pebi.IsWow64Process  ? 2 : 1) << secshift };

				HANDLE hSection;

				if (0 <= (status = NtCreateSection(&hSection, SECTION_ALL_ACCESS, 0, &SectionSize, PAGE_READWRITE, SEC_COMMIT, 0)))
				{
					struct QueryBuf 
					{
						ULONG NumberOfModules;
						UCHAR buf[secsize - 2 * sizeof(ULONG)];
						ULONG ReturnedSize;
					};

					union {
						PVOID BaseAddress = 0;
						PRTL_PROCESS_MODULES mods;
						QueryBuf* pQb;
					};

					SIZE_T ViewSize = 0;

					if (0 <= (status = ZwMapViewOfSection(hSection, NtCurrentProcess(), 
						&BaseAddress, 0, 0, 0, &ViewSize, ViewUnmap, 0, PAGE_READWRITE)))
					{
						BOOLEAN ExportSuppression = IsExportSuppressionEnabled(hProcess);

						PVOID RemoteBaseAddress = 0;

						if (0 <= (status = ZwMapViewOfSection(hSection, hProcess, &RemoteBaseAddress, 0, 
							0, 0, &(ViewSize = 0), ViewUnmap, 0, PAGE_READWRITE)))
						{
							DoIoControl(IOCTL_SetProtectedProcess);

							HANDLE hThreads[2]{};

							if (0 <= (status = StartQuery(hProcess, RemoteBaseAddress, 
								secsize - sizeof(ULONG), ExportSuppression, 
#ifdef _WIN64
								FALSE, 
#endif
								hThreads)))
							{
								ULONG HandleCount = 1;

#ifdef _WIN64
								if (pebi.IsWow64Process && 0 <= (status = StartQuery(
									hProcess, RtlOffsetToPointer(RemoteBaseAddress, secsize), 
									secsize - sizeof(ULONG), 
									ExportSuppression, TRUE, hThreads + 1)))
								{
									HandleCount = 2;
								}
#endif

								LARGE_INTEGER Timeout = { (ULONG)-10000000, -1 };

								status = ZwWaitForMultipleObjects(HandleCount, hThreads, WaitAll, TRUE, &Timeout);

								if (status)
								{
									ULONG i = HandleCount;
									do 
									{
										ZwTerminateThread(hThreads[--i], 0);
									} while (i);
								}

								status = STATUS_UNSUCCESSFUL;

								if (ULONG NumberOfModules = mods->NumberOfModules)
								{
									if (pQb->ReturnedSize == __builtin_offsetof(RTL_PROCESS_MODULES, Modules) + NumberOfModules * sizeof(RTL_PROCESS_MODULE_INFORMATION))
									{
#ifdef _WIN64
										if (HandleCount == 2)
										{
											union {
												PRTL_PROCESS_MODULES32 mods32;
												QueryBuf* pQb32;
											};

											pQb32 = pQb + 1;

											Add32Modules(mods, mods32, pQb32->ReturnedSize);
										}
#endif

										*pmods = mods, BaseAddress = 0, status = STATUS_SUCCESS;
									}
								}

								do 
								{
									NtClose(hThreads[--HandleCount]);
								} while (HandleCount);

							}

							DoIoControl(IOCTL_DelProtectedProcess);

							ZwUnmapViewOfSection(hProcess, RemoteBaseAddress);
						}

						if (BaseAddress) ZwUnmapViewOfSection(NtCurrentProcess(), BaseAddress);
					}

					NtClose(hSection);
				}
			}
		}

		NtClose(hProcess);
	}

	return status;
}

_NT_END