#include "StdAfx.h"

_NT_BEGIN

#include "qpm.h"
#define USER_SHARED_DATA ((PKUSER_SHARED_DATA)0x7ffe0000)
#ifdef _WIN64

#include "../wow/wow.h"

PVOID g_LdrQueryProcessModuleInformationWow, g_RtlExitUserThreadWow;

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

NTSTATUS
GetProcessMitigationPolicy(
						   _In_ HANDLE hProcess,
						   _In_ PROCESS_MITIGATION_POLICY MitigationPolicy,
						   _Out_writes_bytes_(ULONG) PVOID lpBuffer
						   )
{
	struct PROCESS_MITIGATION {
		PROCESS_MITIGATION_POLICY Policy;
		ULONG Flags;
	};

	PROCESS_MITIGATION m = { MitigationPolicy };
	NTSTATUS status = NtQueryInformationProcess(hProcess, ProcessMitigationPolicy, &m, sizeof(m), 0);
	if (0 <= status)
	{
		*(PULONG)lpBuffer = m.Flags;
		return TRUE;
	}

	return status;
}

bool IsExportSuppressionEnabled(HANDLE hProcess)
{
	PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY cfg;

	return 0 <= GetProcessMitigationPolicy(hProcess, ProcessControlFlowGuardPolicy, &cfg) &&
		cfg.EnableControlFlowGuard && cfg.EnableExportSuppression;
}

BOOL WINAPI SetProcessValidCallTargetsTemp(
	_In_ HANDLE hProcess,
	_In_ PVOID VirtualAddress,
	_In_ SIZE_T RegionSize,
	_In_ ULONG NumberOfOffsets,
	_Inout_updates_(NumberOfOffsets) PCFG_CALL_TARGET_INFO OffsetInformation
	);

BOOL (WINAPI * SetProcessValidCallTargets)(
	_In_ HANDLE hProcess,
	_In_ PVOID VirtualAddress,
	_In_ SIZE_T RegionSize,
	_In_ ULONG NumberOfOffsets,
	_Inout_updates_(NumberOfOffsets) PCFG_CALL_TARGET_INFO OffsetInformation
	) = SetProcessValidCallTargetsTemp;

BOOL WINAPI SetProcessValidCallTargetsTemp(
	_In_ HANDLE hProcess,
	_In_ PVOID VirtualAddress,
	_In_ SIZE_T RegionSize,
	_In_ ULONG NumberOfOffsets,
	_Inout_updates_(NumberOfOffsets) PCFG_CALL_TARGET_INFO OffsetInformation
	)
{
	if (PVOID pv = GetProcAddress(GetModuleHandle(L"Kernelbase"), "SetProcessValidCallTargets"))
	{
		(void*&)SetProcessValidCallTargets = pv;
		return SetProcessValidCallTargets(hProcess, VirtualAddress, RegionSize, NumberOfOffsets, OffsetInformation);
	}
	else return FALSE;
}

NTSTATUS SetExportValid(HANDLE hProcess, LPCVOID pv)
{
	MEMORY_BASIC_INFORMATION mbi;

	NTSTATUS status = NtQueryVirtualMemory(hProcess, (void*)pv, MemoryBasicInformation, &mbi, sizeof(mbi), 0);

	if (0 <= status)
	{
		if (mbi.State != MEM_COMMIT || mbi.Type != MEM_IMAGE)
		{
			return STATUS_INVALID_ADDRESS;
		}

		CFG_CALL_TARGET_INFO OffsetInformation = {
			(ULONG_PTR)pv - (ULONG_PTR)mbi.BaseAddress,
			CFG_CALL_TARGET_CONVERT_EXPORT_SUPPRESSED_TO_VALID | CFG_CALL_TARGET_VALID
		};

		return SetProcessValidCallTargets(hProcess, mbi.BaseAddress, mbi.RegionSize, 1, &OffsetInformation) &&
			(OffsetInformation.Flags & CFG_CALL_TARGET_PROCESSED) ? STATUS_SUCCESS : STATUS_STRICT_CFG_VIOLATION;
	}

	return status;
}

NTSTATUS SetExportValid(HANDLE hProcess, LPCVOID pv1, LPCVOID pv2)
{
	MEMORY_BASIC_INFORMATION mbi;

	NTSTATUS status;

	if (0 <= (status = NtQueryVirtualMemory(hProcess, (void*)pv1, MemoryBasicInformation, &mbi, sizeof(mbi), 0)))
	{
		if (mbi.State != MEM_COMMIT || mbi.Type != MEM_IMAGE)
		{
			return STATUS_INVALID_ADDRESS;
		}

		CFG_CALL_TARGET_INFO OffsetInformation[] = {
			{ (ULONG_PTR)pv1 - (ULONG_PTR)mbi.BaseAddress,
			CFG_CALL_TARGET_CONVERT_EXPORT_SUPPRESSED_TO_VALID | CFG_CALL_TARGET_VALID},
			{ (ULONG_PTR)pv2 - (ULONG_PTR)mbi.BaseAddress,
			CFG_CALL_TARGET_CONVERT_EXPORT_SUPPRESSED_TO_VALID | CFG_CALL_TARGET_VALID},
		};

		if ((ULONG_PTR)pv2 - (ULONG_PTR)mbi.BaseAddress < mbi.RegionSize)
		{
			return SetProcessValidCallTargets(hProcess, mbi.BaseAddress, mbi.RegionSize, 2, OffsetInformation) &&
				(OffsetInformation[0].Flags & CFG_CALL_TARGET_PROCESSED) &&
				(OffsetInformation[1].Flags & CFG_CALL_TARGET_PROCESSED)? STATUS_SUCCESS : STATUS_STRICT_CFG_VIOLATION;
		}

		if (!SetProcessValidCallTargets(hProcess, mbi.BaseAddress, mbi.RegionSize, 1, OffsetInformation) ||
			!(OffsetInformation[0].Flags & CFG_CALL_TARGET_PROCESSED))
		{
			return STATUS_STRICT_CFG_VIOLATION;
		}

		return SetExportValid(hProcess, pv2);
	}

	return status;
}

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
		NtClose(_hSection);
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

		NtClose(hSection);
	}

	return status;
}

NTSTATUS MyOpenProcess(PHANDLE ProcessHandle, ULONG DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID Cid);

NTSTATUS QUERY_PROCESS_MODULES::query(HANDLE UniqueProcess)
{
	HANDLE hProcess, hThread;

	CLIENT_ID cid = { UniqueProcess };

	NTSTATUS status;

	RtlZeroMemory(_psmi, 2*secsize);

	if (0 <= (status = MyOpenProcess(&hProcess, PROCESS_ALL_ACCESS_XP, &zoa, &cid)))
	{
		bool ExportSuppression = IsExportSuppressionEnabled(hProcess);

		PVOID RemoteBaseAddress = 0;
		SIZE_T ViewSize = 0;
		static LARGE_INTEGER timeout = { (ULONG)-20000000, -1};// 2 sec

		if (0 <= (status = ZwMapViewOfSection(_hSection, hProcess, &RemoteBaseAddress, 0, 0, 0, &ViewSize, ViewUnmap, 0, PAGE_READWRITE)))
		{
			if (!ExportSuppression || (0 <= (status = SetExportValid(hProcess, LdrQueryProcessModuleInformation, RtlExitUserThread))))
			{
				if (0 <= (status = RtlCreateUserThread(hProcess, 0, TRUE, 0, 0, 0, RtlExitUserThread, 0, &hThread, 0)))
				{
					ZwQueueApcThread(hThread, (PKNORMAL_ROUTINE)LdrQueryProcessModuleInformation, 
						RemoteBaseAddress, 
						(PVOID)(secsize - sizeof(ULONG)), 
						(PBYTE)RemoteBaseAddress + secsize - sizeof(ULONG));

					ZwSetInformationThread(hThread, ThreadHideFromDebugger, 0, 0);

					ZwResumeThread(hThread, 0);

					if ((status = ZwWaitForSingleObject(hThread, FALSE, &timeout)) == STATUS_TIMEOUT)
					{
						ZwTerminateThread(hThread, STATUS_ABANDONED);
					}

					NtClose(hThread);
				}
			}

#ifdef _WIN64
			PVOID wow;

			if (
				0 <= status && status != STATUS_TIMEOUT &&
				0 <= ZwQueryInformationProcess(hProcess, ProcessWow64Information, &wow, sizeof(wow), 0) && wow &&
				g_LdrQueryProcessModuleInformationWow && g_RtlExitUserThreadWow &&
				(!ExportSuppression || (0 <= SetExportValid(hProcess, g_LdrQueryProcessModuleInformationWow, g_RtlExitUserThreadWow)))
				)
			{
				if (0 <= RtlCreateUserThread(hProcess, 0, TRUE, 0, 0, 0, (void*)g_RtlExitUserThreadWow, 0, &hThread, 0))
				{
					RtlQueueApcWow64Thread(hThread, (PKNORMAL_ROUTINE)g_LdrQueryProcessModuleInformationWow, 
						RtlOffsetToPointer(RemoteBaseAddress, secsize), 
						(PVOID)(secsize - sizeof(ULONG)), 
						(PBYTE)RemoteBaseAddress + 2*secsize - sizeof(ULONG));
					ZwSetInformationThread(hThread, ThreadHideFromDebugger, 0, 0);
					ZwResumeThread(hThread, 0);
					if ((status = ZwWaitForSingleObject(hThread, FALSE, &timeout)) == STATUS_TIMEOUT)
					{
						ZwTerminateThread(hThread, STATUS_ABANDONED);
					}
					NtClose(hThread);
				}

				if (0 <= status && status != STATUS_TIMEOUT)
				{
					PRTL_PROCESS_MODULES32 psmi = (PRTL_PROCESS_MODULES32)RtlOffsetToPointer(_psmi, secsize);

					if (ULONG NumberOfModules = psmi->NumberOfModules)
					{
						if (--NumberOfModules)
						{
							PRTL_PROCESS_MODULE_INFORMATION32 Modules = psmi->Modules + 1;

							PRTL_PROCESS_MODULES psmi0 = _psmi;
							PRTL_PROCESS_MODULE_INFORMATION _Modules = psmi0->Modules + psmi0->NumberOfModules;
							psmi0->NumberOfModules += NumberOfModules;

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
							} while (_Modules++, Modules++, --NumberOfModules);
						}
					}
				}

			}
#endif
			ZwUnmapViewOfSection(hProcess, RemoteBaseAddress);
		}

		NtClose(hProcess);
	}

	return status;
}

_NT_END