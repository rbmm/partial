#define DECLSPEC_DEPRECATED_DDK

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NON_CONFORMING_SWPRINTFS
#define _NO_CRT_STDIO_INLINE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define WIN32_NO_STATUS
#define WIN32_LEAN_AND_MEAN

#pragma warning(disable : 4200 4201 4324 4706)

#include <Windows.h>
#include <winioctl.h>
#undef WIN32_NO_STATUS
#include <ntstatus.h>

typedef GUID *PGUID;
#define MINCHAR     0x80        // winnt
#define MAXCHAR     0x7f        // winnt
#define MINSHORT    0x8000      // winnt
#define MAXSHORT    0x7fff      // winnt
#define MINLONG     0x80000000  // winnt
#define MAXLONG     0x7fffffff  // winnt
#define MAXUCHAR    0xff        // winnt
#define MAXUSHORT   0xffff      // winnt
#define MAXULONG    0xffffffff  // winnt


#define PHNT_VERSION PHNT_THRESHOLD

#pragma warning(disable : 4005)
#include "phnt.h"
#pragma warning(default : 4005)

#define echo(x) x
#define label(x) echo(x)##__LINE__
#define RTL_CONSTANT_STRINGW_(s) { sizeof( s ) - sizeof( (s)[0] ), sizeof( s ), const_cast<PWSTR>(s) }
#define RTL_CONSTANT_STRINGW(s) RTL_CONSTANT_STRINGW_(echo(L)echo(s))

#define STATIC_UNICODE_STRING(name, str) \
	static const WCHAR label(__)[] = echo(L)str;\
	static const UNICODE_STRING name = RTL_CONSTANT_STRINGW_(label(__))

#define STATIC_OBJECT_ATTRIBUTES(oa, name)\
	STATIC_UNICODE_STRING(label(m), name);\
	static OBJECT_ATTRIBUTES oa = { sizeof(oa), 0, const_cast<PUNICODE_STRING>(&label(m)), OBJ_CASE_INSENSITIVE }


struct EXPORT_ENTRY 
{
	PCSTR Name;
	PVOID* pAddress;
};

ULONG GetNameOrdinal(PVOID Base, PDWORD AddressOfNames, DWORD NumberOfNames, PCSTR Name)
{
	if (NumberOfNames)
	{
		DWORD a = 0, o;

		do 
		{
			o = (a + NumberOfNames) >> 1;

			int i = strcmp(RtlOffsetToPointer(Base, AddressOfNames[o]), Name);

			if (!i)
			{
				return o;
			}

			0 > i ? a = o + 1 : NumberOfNames = o;

		} while (a < NumberOfNames);
	}

	return MAXULONG;
}

void getWowProcs(PVOID ImageBase, PVOID BaseAddress, const EXPORT_ENTRY entry[])
{
	ULONG exportSize, exportRVA;

	if (PIMAGE_EXPORT_DIRECTORY pied = (PIMAGE_EXPORT_DIRECTORY)
		RtlImageDirectoryEntryToData(BaseAddress, TRUE, IMAGE_DIRECTORY_ENTRY_EXPORT, &exportSize))
	{
		exportRVA = RtlPointerToOffset(BaseAddress, pied);

		if (ULONG NumberOfFunctions = pied->NumberOfFunctions)
		{
			ULONG NumberOfNames = pied->NumberOfNames;
			ULONG OrdinalBase = pied->Base;

			PULONG AddressOfFunctions = (PULONG)RtlOffsetToPointer(BaseAddress, pied->AddressOfFunctions);
			PULONG AddressOfNames = (PULONG)RtlOffsetToPointer(BaseAddress, pied->AddressOfNames);
			PWORD AddressOfNameOrdinals = (PWORD)RtlOffsetToPointer(BaseAddress, pied->AddressOfNameOrdinals);

			for ( ; PCSTR Name = entry->Name; entry++)
			{
				ULONG o;

				if (*Name == '#')
				{
					if ((o = strtoul(Name + 1, const_cast<char**>(&Name), 10)) < OrdinalBase || *Name)
					{
						continue;
					}
					o -= OrdinalBase;
				}
				else
				{
					o = GetNameOrdinal(BaseAddress, AddressOfNames, NumberOfNames, Name);
					if (o < NumberOfNames)
					{
						o = AddressOfNameOrdinals[o];
					}
				}

				if (o >= NumberOfFunctions)
				{
					continue;
				}

				DWORD Rva = AddressOfFunctions[o];

				if ((ULONG_PTR)Rva - (ULONG_PTR)exportRVA >= exportSize)
				{
					*entry->pAddress = RtlOffsetToPointer(ImageBase, Rva);
					continue;
				}

				// not handle forward export (assume ntdll.dll only)
			}
		}
	}
}

void getWowProcs(const EXPORT_ENTRY entry[])
{
	STATIC_OBJECT_ATTRIBUTES(oa_ntdll, "\\KnownDlls32\\ntdll.dll");

	HANDLE hSection;

	if (0 <= ZwOpenSection(&hSection, SECTION_QUERY|SECTION_MAP_READ, &oa_ntdll))
	{
		SECTION_IMAGE_INFORMATION sii;
		if (0 <= ZwQuerySection(hSection, SectionImageInformation, &sii, sizeof(sii), 0))
		{
			PVOID BaseAddress = 0;
			SIZE_T ViewSize = 0;

			if (0 <= ZwMapViewOfSection(hSection, NtCurrentProcess(), &BaseAddress, 0, 0, 0, &ViewSize, ViewUnmap, 0, PAGE_READONLY))
			{
				__try
				{
					if (PIMAGE_NT_HEADERS32 pinth = (PIMAGE_NT_HEADERS32)RtlImageNtHeader(BaseAddress))
					{
						getWowProcs((PBYTE)sii.TransferAddress - pinth->OptionalHeader.AddressOfEntryPoint, BaseAddress, entry);
					}
				}
				__except(EXCEPTION_EXECUTE_HANDLER)
				{
				}

				ZwUnmapViewOfSection(NtCurrentProcess(), BaseAddress);
			}
		}
		NtClose(hSection);
	}
}

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
		return STATUS_SUCCESS;
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

BOOL WINAPI SetProcessValidCallTargetsNotImpl(
	_In_ HANDLE /*hProcess*/,
	_In_ PVOID /*VirtualAddress*/,
	_In_ SIZE_T /*RegionSize*/,
	_In_ ULONG /*NumberOfOffsets*/,
	_Inout_updates_(NumberOfOffsets) PCFG_CALL_TARGET_INFO /*OffsetInformation*/
	)
{
	RtlNtStatusToDosError(STATUS_NOT_IMPLEMENTED);
	return FALSE;
}

EXTERN_C PVOID __imp_SetProcessValidCallTargets = SetProcessValidCallTargetsTemp;

BOOL WINAPI SetProcessValidCallTargetsTemp(
	_In_ HANDLE hProcess,
	_In_ PVOID VirtualAddress,
	_In_ SIZE_T RegionSize,
	_In_ ULONG NumberOfOffsets,
	_Inout_updates_(NumberOfOffsets) PCFG_CALL_TARGET_INFO OffsetInformation
	)
{
	__imp_SetProcessValidCallTargets = GetProcAddress(GetModuleHandle(L"Kernelbase"), "SetProcessValidCallTargets");
	return SetProcessValidCallTargets(hProcess, VirtualAddress, RegionSize, NumberOfOffsets, OffsetInformation);
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

typedef struct RTL_PROCESS_MODULE_INFORMATION32 {
	ULONG Section;                 // Not filled in
	ULONG MappedBase;
	ULONG ImageBase;
	ULONG ImageSize;
	ULONG Flags;
	USHORT LoadOrderIndex;
	USHORT InitOrderIndex;
	USHORT LoadCount;
	USHORT OffsetToFileName;
	CHAR  FullPathName[ 256 ];
} *PRTL_PROCESS_MODULE_INFORMATION32;

typedef struct RTL_PROCESS_MODULES32 {
	ULONG NumberOfModules;
	RTL_PROCESS_MODULE_INFORMATION32 Modules[];
} *PRTL_PROCESS_MODULES32;

typedef
void
NTAPI
KNORMAL_ROUTINE (
				 PVOID NormalContext,
				 PVOID SystemArgument1,
				 PVOID SystemArgument2
				 );

typedef KNORMAL_ROUTINE *PKNORMAL_ROUTINE;

void DumpProcessModules(HANDLE hProcess)
{
	HANDLE hSection;

	static const LARGE_INTEGER SectionSize = { 0x40000 }; //256k

	NTSTATUS status = NtCreateSection(&hSection, SECTION_ALL_ACCESS, 0, 
		const_cast<PLARGE_INTEGER>(&SectionSize), PAGE_READWRITE, SEC_COMMIT, 0);

	if (0 <= status)
	{
		union {
			PRTL_PROCESS_MODULES psmi;
			PRTL_PROCESS_MODULES32 psmi32;
			PVOID BaseAddress;
		};
		SIZE_T ViewSize = 0;
		ULONG NumberOfModules;

		if (0 <= (status = ZwMapViewOfSection(hSection, NtCurrentProcess(), 
			&(BaseAddress = 0), 0, 0, 0, &ViewSize, ViewUnmap, 0, PAGE_READWRITE)))
		{
			HANDLE hThread;

			PVOID RemoteBaseAddress = 0;

			if (0 <= (status = ZwMapViewOfSection(hSection, hProcess, 
				&RemoteBaseAddress, 0, 0, 0, &ViewSize, ViewUnmap, 0, PAGE_READWRITE)))
			{
				static const LARGE_INTEGER timeout = { (ULONG)-20000000, -1};// 2 sec

				bool ExportSuppression = IsExportSuppressionEnabled(hProcess);

				if (!ExportSuppression || 
					(0 <= SetExportValid(hProcess, LdrQueryProcessModuleInformation, RtlExitUserThread)))
				{
					CreateRemoteThread(hProcess, 0, 0, (PTHREAD_START_ROUTINE)RtlExitUserThread, 0, CREATE_SUSPENDED, 0);
					RtlGetLastNtStatus();
					if (0 <= (status = RtlCreateUserThread(hProcess, 0, TRUE, 0, 0, 0, 
						(PUSER_THREAD_START_ROUTINE)RtlExitUserThread, 0, &hThread, 0)))
					{
						ZwQueueApcThread(hThread, (PKNORMAL_ROUTINE)LdrQueryProcessModuleInformation, 
							RemoteBaseAddress, 
							(PVOID)(ViewSize - sizeof(ULONG)), 
							(PBYTE)RemoteBaseAddress + ViewSize - sizeof(ULONG));

						NtSetInformationThread(hThread, ThreadHideFromDebugger, 0, 0);

						ZwResumeThread(hThread, 0);

						if ((status = ZwWaitForSingleObject(hThread, FALSE, 
							const_cast<PLARGE_INTEGER>(&timeout))) == STATUS_TIMEOUT)
						{
							ZwTerminateThread(hThread, STATUS_ABANDONED);
						}

						NtClose(hThread);

						if (status == STATUS_WAIT_0 && (NumberOfModules = psmi->NumberOfModules))
						{
							PRTL_PROCESS_MODULE_INFORMATION Modules = psmi->Modules;
							do 
							{
								DbgPrint("%p %08x %08x %02u %s\n", 
									Modules->ImageBase, 
									Modules->ImageSize, 
									Modules->Flags,
									Modules->InitOrderIndex,
									Modules->FullPathName);

							} while (Modules++, --NumberOfModules);
						}
					}
				}

				PVOID wow;// address of 32-bit PEB

				if (0 <= NtQueryInformationProcess(hProcess, ProcessWow64Information, &wow, sizeof(wow), 0) && wow)
				{
					static bool bWowProcessed = false;
					static PVOID g_LdrQueryProcessModuleInformationWow = 0, g_RtlExitUserThreadWow = 0;

					if (!bWowProcessed)
					{
						EXPORT_ENTRY ee[] = {
							{ "LdrQueryProcessModuleInformation", &g_LdrQueryProcessModuleInformationWow },
							{ "RtlExitUserThread", &g_RtlExitUserThreadWow },
							{ },
						};

						getWowProcs(ee);

						bWowProcessed = true;
					}

					if (g_LdrQueryProcessModuleInformationWow && g_RtlExitUserThreadWow)
					{
						if (!ExportSuppression || 
							(0 <= SetExportValid(hProcess, 
							g_LdrQueryProcessModuleInformationWow, g_RtlExitUserThreadWow)))
						{

							if (0 <= RtlCreateUserThread(hProcess, 0, TRUE, 0, 0, 0, 
								(PUSER_THREAD_START_ROUTINE)g_RtlExitUserThreadWow, 0, &hThread, 0))
							{
								RtlQueueApcWow64Thread(hThread, (PKNORMAL_ROUTINE)g_LdrQueryProcessModuleInformationWow, 
									RemoteBaseAddress, 
									(PVOID)(ViewSize - sizeof(ULONG)), 
									(PBYTE)RemoteBaseAddress + ViewSize - sizeof(ULONG));

								NtSetInformationThread(hThread, ThreadHideFromDebugger, 0, 0);

								ZwResumeThread(hThread, 0);

								if ((status = ZwWaitForSingleObject(hThread, FALSE, 
									const_cast<PLARGE_INTEGER>(&timeout))) == STATUS_TIMEOUT)
								{
									ZwTerminateThread(hThread, STATUS_ABANDONED);
								}

								NtClose(hThread);

								if (status == STATUS_WAIT_0 && (NumberOfModules = psmi->NumberOfModules))
								{
									PRTL_PROCESS_MODULE_INFORMATION32 Modules = psmi32->Modules;
									do 
									{
										DbgPrint("%08x %08x %08x %02u %s\n", 
											Modules->ImageBase, 
											Modules->ImageSize, 
											Modules->Flags,
											Modules->InitOrderIndex,
											Modules->FullPathName);

									} while (Modules++, --NumberOfModules);
								}
							}
						}
					}
				}

				ZwUnmapViewOfSection(hProcess, RemoteBaseAddress);
			}

			ZwUnmapViewOfSection(NtCurrentProcess(), BaseAddress);
		}

		NtClose(hSection);
	}
}

void DumpProcessModules(ULONG dwProcessId)
{
	if (HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId))
	{
		DumpProcessModules(hProcess);
		NtClose(hProcess);
	}
}

void DumpProcessModulesWithES()
{
	WCHAR AppName[MAX_PATH];
	if (ExpandEnvironmentStringsW(L"%systemroot%\\syswow64\\notepad.exe", AppName, _countof(AppName)))
	{
		STARTUPINFOEXW si = { { sizeof(si)} };

		SIZE_T s = 0;
__c:
		switch (InitializeProcThreadAttributeList(si.lpAttributeList, 1, 0, &s) ? NOERROR : GetLastError())
		{
		case NOERROR:
			if (si.lpAttributeList)
			{
				ULONG64 mp = PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_EXPORT_SUPPRESSION;
				if (UpdateProcThreadAttribute(si.lpAttributeList, 0, 
					PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY, &mp, sizeof(mp), 0, 0))
				{
					PROCESS_INFORMATION pi;
					if (CreateProcessW(AppName, 0, 0, 0, 0, EXTENDED_STARTUPINFO_PRESENT, 0, 0, &si.StartupInfo, &pi))
					{
						CloseHandle(pi.hThread);
						WaitForInputIdle(pi.hProcess, INFINITE);
						DumpProcessModules(pi.hProcess);
						CloseHandle(pi.hProcess);
					}
				}
			}
			break;
		case ERROR_INSUFFICIENT_BUFFER:
			if (!(si.lpAttributeList))
			{
				si.lpAttributeList = (PPROC_THREAD_ATTRIBUTE_LIST)alloca(s);
				goto __c;
			}
			break;
		}
	}
}