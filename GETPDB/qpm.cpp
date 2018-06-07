#include "StdAfx.h"

_NT_BEGIN

#include "qpm.h"
#include "common.h"
#ifdef _WIN64

#include "../wow/wow.h"

PVOID g_LdrQueryProcessModuleInformationWow;
PVOID g_RtlExitUserThreadWow;

BEGIN_WOW_DLL(ntdll)
	WOW_FUNC(LdrQueryProcessModuleInformation)
	WOW_FUNC(RtlExitUserThread)
END_HOOK()

WOW_PROCS_BEGIN()
	WOW_DLL(ntdll)
END_HOOK()

BOOL QUERY_PROCESS_MODULES::InitWow()
{
	getWowProcs();
	return g_LdrQueryProcessModuleInformationWow && g_RtlExitUserThreadWow;
}

#endif

static OBJECT_ATTRIBUTES zoa = { sizeof(zoa) };

QUERY_PROCESS_MODULES::QUERY_PROCESS_MODULES()
{
	_psmi = 0;
	_hSection = 0;
}

QUERY_PROCESS_MODULES::~QUERY_PROCESS_MODULES()
{
	if (_hSection)
	{
		if (_psmi)
		{
			ZwUnmapViewOfSection(NtCurrentProcess(), _psmi);
			_psmi = 0;
		}
		ZwClose(_hSection);
	}

	if (_psmi)
	{
		delete _psmi;
	}
}

NTSTATUS QUERY_PROCESS_MODULES::create(PRTL_PROCESS_MODULES psmi)
{
	if (ULONG NumberOfModules = psmi->NumberOfModules)
	{
		ULONG n = 0;
		PRTL_PROCESS_MODULE_INFORMATION Modules = psmi->Modules, _Modules;
		do 
		{
			if (0 > (INT_PTR)Modules++->ImageBase)
			{
				n++;
			}

		} while (--NumberOfModules);

		if (n)
		{
			if (_psmi = (PRTL_PROCESS_MODULES)new UCHAR[FIELD_OFFSET(RTL_PROCESS_MODULES, Modules[n])])
			{
				NumberOfModules = psmi->NumberOfModules;
				Modules = psmi->Modules;
				_Modules = _psmi->Modules;
				_psmi->NumberOfModules = n;

				do 
				{
					if (0 > (INT_PTR)Modules->ImageBase)
					{
						*_Modules++ = *Modules;
					}

				} while (Modules++, --NumberOfModules);

				return 0;
			}
			else
			{
				return STATUS_INSUFFICIENT_RESOURCES;
			}
		}
	}

	return STATUS_NO_MORE_ENTRIES;
}

NTSTATUS QUERY_PROCESS_MODULES::create()
{
	static LARGE_INTEGER SectionSize = { 2*secsize };

	NTSTATUS status;
	HANDLE hSection;

	if (0 <= (status = ZwCreateSection(&hSection, SECTION_ALL_ACCESS, 0, &SectionSize, PAGE_READWRITE, SEC_COMMIT, 0)))
	{
		PVOID BaseAddress = 0;
		SIZE_T ViewSize = 0;

		if (0 <= (status = ZwMapViewOfSection(hSection, NtCurrentProcess(), &BaseAddress, 0, 0, 0, &ViewSize, ViewUnmap, 0, PAGE_READWRITE)))
		{
			_psmi = (PRTL_PROCESS_MODULES)BaseAddress;
			_hSection = hSection;

			return 0;
		}

		ZwClose(hSection);
	}

	return status;
}

NTSTATUS QUERY_PROCESS_MODULES::query(HANDLE UniqueProcess)
{
	HANDLE hProcess, hThread;

	CLIENT_ID cid = { UniqueProcess };

	NTSTATUS status;

	if (0 <= (status = ZwOpenProcess(&hProcess, PROCESS_CREATE_THREAD|PROCESS_VM_OPERATION|PROCESS_VM_READ|PROCESS_VM_WRITE|PROCESS_QUERY_INFORMATION, &zoa, &cid)))
	{
		PVOID RemoteBaseAddress = 0;
		SIZE_T ViewSize = 0;
		static LARGE_INTEGER timeout = { (ULONG)-20000000, -1};// 2 sec

		if (0 <= (status = ZwMapViewOfSection(_hSection, hProcess, &RemoteBaseAddress, 0, 0, 0, &ViewSize, ViewUnmap, 0, PAGE_READWRITE)))
		{
			PULONG psize = (PULONG)RtlOffsetToPointer(RemoteBaseAddress, secsize - sizeof(ULONG));

			if (0 <= (status = RtlCreateUserThread(hProcess, 0, TRUE, 0, 0, 0, RtlExitUserThread, 0, &hThread, 0)))
			{
				status = ZwQueueApcThread(hThread, (PKNORMAL_ROUTINE)LdrQueryProcessModuleInformation, RemoteBaseAddress, (PVOID)(secsize - sizeof(ULONG)), psize);
				ZwSetInformationThread(hThread, ThreadHideFromDebugger, 0, 0);
				ZwResumeThread(hThread, 0);
				if ((status = ZwWaitForSingleObject(hThread, FALSE, &timeout)) == STATUS_TIMEOUT)
				{
					ZwTerminateThread(hThread, STATUS_ABANDONED);
				}
				ZwClose(hThread);
			}
#ifdef _WIN64
			PVOID wow;

			if (
				0 <= status && status != STATUS_TIMEOUT &&
				0 <= ZwQueryInformationProcess(hProcess, ProcessWow64Information, &wow, sizeof(wow), 0) && wow &&
				g_LdrQueryProcessModuleInformationWow && g_RtlExitUserThreadWow
				)
			{
				if (0 <= RtlCreateUserThread(hProcess, 0, TRUE, 0, 0, 0, g_RtlExitUserThreadWow, 0, &hThread, 0))
				{
					RtlQueueApcWow64Thread(hThread, (PKNORMAL_ROUTINE)g_LdrQueryProcessModuleInformationWow, RtlOffsetToPointer(RemoteBaseAddress, secsize), (PVOID)(secsize - sizeof(ULONG)), psize);
					ZwSetInformationThread(hThread, ThreadHideFromDebugger, 0, 0);
					ZwResumeThread(hThread, 0);
					if ((status = ZwWaitForSingleObject(hThread, FALSE, &timeout)) == STATUS_TIMEOUT)
					{
						ZwTerminateThread(hThread, STATUS_ABANDONED);
					}
					ZwClose(hThread);
				}

				if (0 <= status && status != STATUS_TIMEOUT)
				{
					PRTL_PROCESS_MODULES32 psmi = (PRTL_PROCESS_MODULES32)RtlOffsetToPointer(_psmi, secsize);

					if (ULONG NumberOfModules = psmi->NumberOfModules)
					{
						if (--NumberOfModules)
						{
							PCWSTR systemroot = USER_SHARED_DATA->NtSystemRoot;
							PSTR system32 = (PSTR)alloca(wcslen(systemroot) + sizeof("\\system32\\"));
							sprintf(system32, "%S\\system32\\", systemroot);
							ANSI_STRING as32, as;
							RtlInitAnsiString(&as32, system32);

							PRTL_PROCESS_MODULE_INFORMATION32 Modules = psmi->Modules + 1;

							PRTL_PROCESS_MODULES psmi = _psmi;
							PRTL_PROCESS_MODULE_INFORMATION _Modules = psmi->Modules + psmi->NumberOfModules;
							psmi->NumberOfModules += NumberOfModules;

							do 
							{
								_Modules->Flags = Modules->Flags;
								_Modules->ImageBase = (PVOID)Modules->ImageBase;
								_Modules->ImageSize = Modules->ImageSize;
								_Modules->InitOrderIndex = Modules->InitOrderIndex;
								_Modules->LoadCount = Modules->LoadCount;
								_Modules->LoadOrderIndex = Modules->LoadOrderIndex;
								_Modules->MappedBase = (PVOID)Modules->MappedBase;
								_Modules->OffsetToFileName = Modules->OffsetToFileName;
								_Modules->Section = (PVOID)Modules->Section;
								memcpy(_Modules->FullPathName, Modules->FullPathName, 256);

								RtlInitAnsiString(&as, _Modules->FullPathName);

								if (RtlPrefixString(&as32, &as, TRUE))
								{
									memcpy(as.Buffer + as32.Length - 6, "wow64", 5);
								}

							} while (_Modules++, Modules++, --NumberOfModules);
						}
					}
				}
			}
#endif
			ZwUnmapViewOfSection(hProcess, RemoteBaseAddress);
		}

		ZwClose(hProcess);
	}

	return status;
}

_NT_END