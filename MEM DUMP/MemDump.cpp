// MemDump.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "resource.h"

_NT_BEGIN
#include "../tkn/tkn.h"
#include "../winz/app.h"
#include "../winz/window.h"
#include "../inc/rtlframe.h"
extern const volatile UCHAR guz = 0;
#ifdef _WIN64

#include "../wow/wow.h"

BEGIN_DLL_FUNCS(ntdll, 0)
	FUNC(LdrQueryProcessModuleInformation),
	FUNC(RtlExitUserThread),
END_DLL_FUNCS();

#endif

BOOL g_xp;

HANDLE g_hDrv;

NTSTATUS DbgReadMemory(HANDLE ProcessHandle, PVOID BaseAddres, PVOID Buffer, SIZE_T BufferLength, PSIZE_T ReturnLength )
{
	SIZE_T cbCopy;

	if (!ReturnLength)
	{
		ReturnLength = &cbCopy;
	}

	*ReturnLength = BufferLength;

	if ((INT_PTR)BaseAddres < 0)
	{
		if (g_hDrv)
		{
			IO_STATUS_BLOCK iosb;
			NTSTATUS status = ZwDeviceIoControlFile(g_hDrv, 0, 0, 0, &iosb, IOCTL_ReadMemory, &BaseAddres, sizeof(BaseAddres), Buffer, (DWORD)BufferLength);
			*ReturnLength = iosb.Information;
			return status;
		}
		else
		{
			*ReturnLength = 0;
			return STATUS_ACCESS_VIOLATION;
		}
	}
	else 
	{
		return ZwReadVirtualMemory(ProcessHandle, BaseAddres, Buffer, BufferLength, ReturnLength);
	}
}

#define PROCESS_ALL_ACCESS_XP (SYNCHRONIZE | 0xFFF)

static OBJECT_ATTRIBUTES zoa = {sizeof(zoa)};

NTSTATUS DoIoControl(ULONG code)
{
	IO_STATUS_BLOCK iosb;
	return g_hDrv ? ZwDeviceIoControlFile(g_hDrv, 0, 0, 0, &iosb, code, 0, 0, 0, 0) : STATUS_INVALID_HANDLE;
}

NTSTATUS MyOpenProcess(PHANDLE ProcessHandle, ULONG DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID Cid)
{
	if (g_hDrv)
	{
		IO_STATUS_BLOCK iosb;
		NTSTATUS status = ZwDeviceIoControlFile(g_hDrv, 0, 0, 0, &iosb, IOCTL_OpenProcess, &Cid->UniqueProcess, sizeof(HANDLE), 0, 0);
		*ProcessHandle = (HANDLE)iosb.Information;
		return status;
	}
	return ZwOpenProcess(ProcessHandle, DesiredAccess, ObjectAttributes, Cid);
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

EXTERN_C {
	extern PVOID __imp_SetProcessValidCallTargets;
}

#ifdef _X86_
#pragma comment(linker, "/alternatename:___imp_SetProcessValidCallTargets=__imp__SetProcessValidCallTargets@20")
#endif

//#define _PRINT_CPP_NAMES_
#include "../inc/asmfunc.h"

BOOL WINAPI SetProcessValidCallTargetsTemp(
	_In_ HANDLE hProcess,
	_In_ PVOID VirtualAddress,
	_In_ SIZE_T RegionSize,
	_In_ ULONG NumberOfOffsets,
	_Inout_updates_(NumberOfOffsets) PCFG_CALL_TARGET_INFO OffsetInformation
	)
{
	CPP_FUNCTION;
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

class QUERY_PROCESS_MODULES
{
	enum { secsize = 0x20000 };

	PRTL_PROCESS_MODULES _psmi;
	HANDLE _hSection;

public:

	QUERY_PROCESS_MODULES();
	
	~QUERY_PROCESS_MODULES();

	NTSTATUS create();

	NTSTATUS _query(HANDLE UniqueProcess);

	NTSTATUS query(HANDLE UniqueProcess);

	PRTL_PROCESS_MODULES get() { return _psmi; }
};

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
		}
		ZwClose(_hSection);
	}
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
	DoIoControl(IOCTL_SetProtectedProcess);
	NTSTATUS status = _query(UniqueProcess);
	DoIoControl(IOCTL_DelProtectedProcess);
	return status;
}

NTSTATUS QUERY_PROCESS_MODULES::_query(HANDLE UniqueProcess)
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
			PVOID LdrQueryProcessModuleInformationWow = ntdll.funcs[0].pv;
			PVOID RtlExitUserThreadWow = ntdll.funcs[1].pv;

			if (
				0 <= status && status != STATUS_TIMEOUT &&
				0 <= ZwQueryInformationProcess(hProcess, ProcessWow64Information, &wow, sizeof(wow), 0) && wow &&
				LdrQueryProcessModuleInformationWow && RtlExitUserThreadWow &&
				(!ExportSuppression || (0 <= SetExportValid(hProcess, LdrQueryProcessModuleInformationWow, RtlExitUserThreadWow)))
				)
			{
				if (0 <= RtlCreateUserThread(hProcess, 0, TRUE, 0, 0, 0, RtlExitUserThreadWow, 0, &hThread, 0))
				{
					RtlQueueApcWow64Thread(hThread, (PKNORMAL_ROUTINE)LdrQueryProcessModuleInformationWow, 
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

#define ComboBox_AddStringEx(hwndCtl, sz, Data) ComboBox_SetItemData(hwndCtl, ComboBox_AddString(hwndCtl, sz), Data)

struct _SORTMODE 
{
	int mode;
};

typedef RTL_FRAME<_SORTMODE> SORTMODE;

int __cdecl KModCompare(PRTL_PROCESS_MODULE_INFORMATION& mod1, PRTL_PROCESS_MODULE_INFORMATION& mod2)
{
	if (SORTMODE* prf = SORTMODE::get())
	{
		switch(prf->mode) 
		{
		case 0: 
			if (mod1->ImageBase < mod2->ImageBase) return -1;
			if (mod1->ImageBase > mod2->ImageBase) return +1;
			return 0;
		case 1: return _stricmp(
					mod1->FullPathName + mod1->OffsetToFileName,
					mod2->FullPathName + mod2->OffsetToFileName);
		case -1: return _stricmp(mod1->FullPathName, mod2->FullPathName);
		default:__assume(false);
		}
	}

	return 0;
}

void OnDropdownComboDlls(HWND hwndDlg, HWND hwndCtl, HANDLE dwProcessId, QUERY_PROCESS_MODULES* pqpm)
{
	ComboBox_ResetContent(hwndCtl);

	COMBOBOXINFO cbi = { sizeof cbi };

	if (!GetComboBoxInfo(hwndCtl, &cbi)) return ;

	if (!pqpm->query(dwProcessId))
	{
		PRTL_PROCESS_MODULES psmi = pqpm->get();

		if (int Num = psmi->NumberOfModules)
		{
			PRTL_PROCESS_MODULE_INFORMATION csmi = psmi->Modules;

			int ksort = 3, i;
			do ; while(ksort && (IsDlgButtonChecked(hwndDlg, IDC_RADIO1 + --ksort) != BST_CHECKED));

			PRTL_PROCESS_MODULE_INFORMATION* arr = (PRTL_PROCESS_MODULE_INFORMATION*)alloca(Num * sizeof PVOID);

			i = Num - 1; 

			do arr[i] = csmi + i; while (i--);

			if (ksort < 2) 
			{
				SORTMODE rf;
				rf.mode = -ksort;

				qsort(arr, Num, sizeof(PVOID), (int (__cdecl *)(const void *, const void *))KModCompare);
			}

			HDC hdc = ::GetDC(cbi.hwndList);
			HGDIOBJ o = (HGDIOBJ)::SendMessage(cbi.hwndList, WM_GETFONT, 0, 0);
			if (o) o = SelectObject(hdc, o); else o = (HGDIOBJ)-1;

			SIZE size;
			RECT rc;
			GetClientRect(cbi.hwndList, &rc);
			SCROLLINFO si = { sizeof si };
			si.fMask = SIF_ALL;
			si.nPage = rc.right - rc.left;

			WCHAR sz[MAX_PATH + 32];

			i = 0;
			do
			{
				csmi = arr[i];

				swprintf(sz, L"[%p %p%c %c %c %S",
					csmi->ImageBase, (PBYTE)csmi->ImageBase + csmi->ImageSize,
					csmi->Flags & LDRP_IMAGE_NOT_AT_BASE ? L'[' : L')',
					csmi->LoadCount == MAXUSHORT ? L'@' : L'$',
					csmi->Flags & LDRP_STATIC_LINK ? L's' : L'd',
					csmi->FullPathName);

				GetTextExtentPoint32(hdc, sz, (int)wcslen(sz), &size);
				if (si.nMax < size.cx) si.nMax = size.cx;
				ComboBox_AddStringEx(hwndCtl, sz, csmi);

			} while(++i < Num);

			if (o != (HGDIOBJ)-1)SelectObject(hdc, o);

			ReleaseDC(cbi.hwndList, hdc);

			SendMessage(hwndCtl, CB_SETHORIZONTALEXTENT, si.nMax, 0);

			si.nMax += 16;
			SetScrollInfo(cbi.hwndList, SB_HORZ, &si, TRUE);
		}
	}
}
#define FormatStatus(err, module, status) FormatMessage(\
	FORMAT_MESSAGE_IGNORE_INSERTS|FORMAT_MESSAGE_FROM_HMODULE,\
	GetModuleHandleW(L ## # module),status, 0, err, RTL_NUMBER_OF(err), 0)

#define FormatWin32Status(err, status) FormatStatus(err, kernel32.dll, status)
#define FormatNTStatus(err, status) FormatStatus(err, ntdll.dll, status)

NTSTATUS DisplayStatus(HWND hwndDlg, NTSTATUS status, LPCWSTR sztext)
{
	WCHAR err[MAX_PATH];

	FormatNTStatus(err, status);

	ULONG mb;

	switch((ULONG)status >> 30) {
	case 0: mb = MB_OK;
		break;
	case 1: mb = MB_ICONINFORMATION;
		break;
	case 2: mb = MB_ICONWARNING;
		break;
	case 3: mb = MB_ICONHAND;
		break;
	default: __assume(false);
	}

	MessageBoxW(hwndDlg, err , sztext, mb);

	return status;
}

class CMemDumpDlg : public ZDlg, QUERY_PROCESS_MODULES
{
	// Construction
public:
protected:
protected:
	HANDLE m_hProcess;
	HANDLE m_dwProcessId;
	PVOID m_lpBuffer;
	SIZE_T m_cbBuffer, m_cbBufferData;

	NTSTATUS OnButtonCopy(HWND hwndDlg, NTSTATUS (* pfnReadData)(HANDLE, LPVOID, LPVOID, SIZE_T), HANDLE handle, LPVOID Base, SIZE_T Size);
	void OnDestroy();
	BOOL OnInitDialog(HWND hwndDlg);
	HWND _GetData(HWND hwndDlg, PVOID* pBase, DWORD* pSize, BOOL* pbImage, DWORD* pcbFIleName);
	BOOL GetData(HWND hwndDlg, PVOID* pBase, DWORD* pSize, BOOL* pbImage, DWORD* pcbFIleName);

	static void OnDropdownComboProcess(HWND hwndDlg, SYSTEM_PROCESS_INFORMATION* sp);
	static void OnDropdownComboProcess(HWND hwndDlg);
	void OnCloseupComboProcess(HWND hwndDlg);
	void OnSelchangeComboProcess(HWND hwndDlg);
	void OnButtonFromModule(HWND hwndDlg);
	void OnButtonDump(HWND hwndDlg);
	void OnButtonEditImage(HWND hwndDlg);
	void OnButtonCopy(HWND hwndDlg);
	void OnButtonPaste(HWND hwndDlg);
	void OnButtonZero(HWND hwndDlg);
	void OnButtonFromFile(HWND hwndDlg);

	virtual INT_PTR DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_INITDIALOG:
			OnInitDialog(hwndDlg);
			if (0 > QUERY_PROCESS_MODULES::create())
			{
				DestroyWindow(hwndDlg);
			}
			break;
		case WM_DESTROY:
			OnDestroy();
			break;
		case WM_COMMAND:
			switch (wParam)
			{
			case IDCANCEL:
				EndDialog(hwndDlg, 0);
				break;
			case MAKEWPARAM(IDC_COMBO2, CBN_SELCHANGE): 
				OnSelchangeComboProcess(hwndDlg);
				break;
			case MAKEWPARAM(IDC_COMBO2, CBN_DROPDOWN): 
				OnDropdownComboProcess(hwndDlg);
				break;
			case MAKEWPARAM(IDC_COMBO1, CBN_DROPDOWN):
				OnDropdownComboDlls(hwndDlg, (HWND)lParam, m_dwProcessId, this);
				break;
			case IDC_BUTTON1: OnButtonFromModule(hwndDlg);
				break;
			case IDC_BUTTON2: OnButtonDump(hwndDlg);
				break;
			case IDC_BUTTON3: OnButtonCopy(hwndDlg);
				break;
			case IDC_BUTTON4: OnButtonPaste(hwndDlg);
				break;
			case IDC_BUTTON5: OnButtonZero(hwndDlg);
				break;
			case IDC_BUTTON7: OnButtonFromFile(hwndDlg);
				break;
			}
			break;
		}
		return ZDlg::DialogProc(hwndDlg, uMsg, wParam, lParam);
	}
};

/////////////////////////////////////////////////////////////////////////////
// CMemDumpDlg message handlers

BOOL CMemDumpDlg::OnInitDialog(HWND hwndDlg)
{
	m_hProcess = 0;
	m_dwProcessId = 0;
	m_cbBuffer = 0;
	m_cbBufferData = 0;

	ComboBox_SetMinVisible(::GetDlgItem(hwndDlg, IDC_COMBO1), 16);
	ComboBox_SetMinVisible(::GetDlgItem(hwndDlg, IDC_COMBO2), 16);
	CheckDlgButton(hwndDlg, IDC_RADIO3, BST_CHECKED);

	SendMessage(hwndDlg, WM_SETICON, ICON_BIG, (LPARAM)LoadImage((HINSTANCE)&__ImageBase, 
		MAKEINTRESOURCE(IDR_MAINFRAME), IMAGE_ICON, 32, 32, LR_SHARED));

	SendMessage(hwndDlg, WM_SETICON, ICON_SMALL, (LPARAM)LoadImage((HINSTANCE)&__ImageBase, 
		MAKEINTRESOURCE(IDR_MAINFRAME), IMAGE_ICON, 16, 16, LR_SHARED));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMemDumpDlg::OnDropdownComboProcess(HWND hwndDlg, SYSTEM_PROCESS_INFORMATION* sp)
{
	HWND hwndCtl = ::GetDlgItem(hwndDlg, IDC_COMBO2);
	ComboBox_ResetContent(hwndCtl);
	COMBOBOXINFO cbi = { sizeof cbi };

	if (!GetComboBoxInfo(hwndCtl, &cbi)) return ;

	ULONG cb = 0, rcb, NextEntryDelta = 0;

	HDC hdc = ::GetDC(cbi.hwndList);
	if (!hdc) return ;
	HGDIOBJ o = (HGDIOBJ)::SendMessage(cbi.hwndList, WM_GETFONT, 0, 0);
	if (o) o = SelectObject(hdc, o); else o = (HGDIOBJ)-1;

	SIZE size;
	RECT rc;
	::GetClientRect(cbi.hwndList, &rc);
	SCROLLINFO si = { sizeof si };
	si.fMask = SIF_ALL;
	si.nPage = rc.right - rc.left;

	PWSTR sz = 0;
#ifdef _WIN64
	OBJECT_ATTRIBUTES oa = { sizeof oa };
	CLIENT_ID cid = { };
#endif

	do
	{
		sp = (SYSTEM_PROCESS_INFORMATION*)RtlOffsetToPointer(sp, NextEntryDelta);
		if (sp->UniqueProcessId)
		{
#ifdef _WIN64
			cid.UniqueProcess = (HANDLE)(ULONG_PTR)sp->UniqueProcessId;
			HANDLE hProcess;
			PVOID wow;
			WCHAR c = L'?';

			if (0 <= NtOpenProcess(&hProcess, g_xp ? PROCESS_QUERY_INFORMATION : PROCESS_QUERY_LIMITED_INFORMATION, &oa, &cid))
			{		
				if (0 <= NtQueryInformationProcess(hProcess, ProcessWow64Information, &wow, sizeof(wow), 0))
				{
					c = wow ? '*' : ' ';
				}

				NtClose(hProcess);
			}
#else
			WCHAR c = L' ';
#endif

			rcb = sp->ImageName.Length + 32;
			if (cb < rcb) sz = (LPWSTR)alloca(rcb - cb), cb = rcb;
			swprintf(sz, L"%4X(%4X) %2d %c %wZ", 
				HandleToUlong(sp->UniqueProcessId), HandleToUlong(sp->InheritedFromUniqueProcessId), 
				sp->NumberOfThreads, c, &sp->ImageName);
			GetTextExtentPoint32(hdc, sz, (int)wcslen(sz), &size);
			if (si.nMax < size.cx) si.nMax = size.cx;
			ComboBox_AddStringEx(hwndCtl, sz, sp->UniqueProcessId);
		}

	} while(NextEntryDelta = sp->NextEntryOffset);

	if (o != (HGDIOBJ)-1)SelectObject(hdc, o);

	::ReleaseDC(cbi.hwndList, hdc);

	::SendMessage(cbi.hwndList, LB_SETHORIZONTALEXTENT, si.nMax, 0);

	si.nMax += 16;
	::SetScrollInfo(cbi.hwndList, SB_HORZ, &si, TRUE);
}

void CMemDumpDlg::OnDropdownComboProcess(HWND hwndDlg) 
{
	NTSTATUS status;
	DWORD rcb = 0x1000;
	do 
	{
		if (SYSTEM_PROCESS_INFORMATION* sp = (SYSTEM_PROCESS_INFORMATION*)LocalAlloc(0, rcb += PAGE_SIZE))
		{
			status = NtQuerySystemInformation(SystemProcessInformation, sp, rcb, &rcb);

			if (0 <= status)
			{
				OnDropdownComboProcess(hwndDlg, sp);
			}

			LocalFree(sp);
		}
		else
		{
			break;
		}
	} while(status == STATUS_INFO_LENGTH_MISMATCH);
}

void CMemDumpDlg::OnSelchangeComboProcess(HWND hwndDlg) 
{
	HWND hwndCtl = ::GetDlgItem(hwndDlg, IDC_COMBO2);
	int i;
	HANDLE dwProcessId = (HANDLE)(((i = ComboBox_GetCurSel(hwndCtl)) == CB_ERR)
		? 0 : ComboBox_GetItemData(hwndCtl, i));

	if (m_dwProcessId != dwProcessId) {

		m_dwProcessId = dwProcessId;

		if (m_hProcess) ZwClose(m_hProcess);

		m_hProcess = 0;

		if (dwProcessId)
		{
			CLIENT_ID cid = {dwProcessId};
			MyOpenProcess(&m_hProcess, PROCESS_ALL_ACCESS_XP, &zoa, &cid);
		}

		ComboBox_ResetContent(::GetDlgItem(hwndDlg, IDC_COMBO1));
	}	
}

void CMemDumpDlg::OnDestroy() 
{
	if (m_cbBuffer) ZwFreeVirtualMemory(NtCurrentProcess(), &m_lpBuffer, &m_cbBuffer, MEM_RELEASE);
	if (m_hProcess) ZwClose(m_hProcess);
}

void CMemDumpDlg::OnButtonFromModule(HWND hwndDlg) 
{
	HWND hwndCtl = ::GetDlgItem(hwndDlg, IDC_COMBO1);

	int i = ComboBox_GetCurSel(hwndCtl );
	if (i == CB_ERR) return ;

	RTL_PROCESS_MODULE_INFORMATION* smi = (RTL_PROCESS_MODULE_INFORMATION*)ComboBox_GetItemData(hwndCtl, i);

	if (!smi) return ;

	CheckDlgButton(hwndDlg, IDC_CHECK1, BST_CHECKED);

	TCHAR sz[17];

	swprintf(sz, L"%p", smi->ImageBase);
	SetDlgItemText(hwndDlg, IDC_EDIT1,sz);

	swprintf(sz, L"%X", smi->ImageSize);
	SetDlgItemText(hwndDlg, IDC_EDIT2, sz);
}

DWORD ImageToLine(PVOID Base, PVOID ImageBase, DWORD SizeOfImage)
{
	if (PIMAGE_NT_HEADERS pinth = RtlImageNtHeader(ImageBase))
	{
		if (pinth->OptionalHeader.SizeOfImage > SizeOfImage) return 0;
		
		pinth->OptionalHeader.ImageBase = (ULONG_PTR)Base;

		DWORD s;
		if (PIMAGE_IMPORT_DESCRIPTOR piid = (PIMAGE_IMPORT_DESCRIPTOR)RtlImageDirectoryEntryToData(ImageBase, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, &s))
		{
			while (piid->Name)
			{
				if (ULONG OriginalFirstThunk = piid->OriginalFirstThunk)
				{
					if (ULONG FirstThunk = piid->FirstThunk)
					{
						union {
							DWORD d;
							ULONGLONG u;
						};
						union {
							PVOID pv;
							PDWORD pd;
							PULONGLONG pu;
						};
						union {
							PVOID qv;
							PDWORD qd;
							PULONGLONG qu;
						};

						pv = RtlOffsetToPointer(ImageBase, OriginalFirstThunk), 
						qv = RtlOffsetToPointer(ImageBase, FirstThunk);

						switch (pinth->OptionalHeader.Magic)
						{
						case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
							do 
							{
								d = *pd++, *qd++ = d;
							} while (d);
							break;
						case IMAGE_NT_OPTIONAL_HDR64_MAGIC:
							do 
							{
								u = *pu++, *qu++ = d;
							} while (u);
							break;
						}
					}
				}
				piid++;
			}
		}

		if (DWORD NumberOfSections = pinth->FileHeader.NumberOfSections)
		{
			PCHAR pb = RtlOffsetToPointer(ImageBase, pinth->OptionalHeader.SizeOfHeaders);

			PIMAGE_SECTION_HEADER pish = IMAGE_FIRST_SECTION(pinth);

			do 
			{
				DWORD SizeOfRawData = pish->SizeOfRawData, VirtualSize = pish->Misc.VirtualSize,
					VirtualAddress = pish->VirtualAddress, PointerToRawData = pish->PointerToRawData;

				if (
					VirtualAddress <= VirtualAddress + VirtualSize && VirtualAddress + VirtualSize <= SizeOfImage &&
					PointerToRawData <= PointerToRawData + SizeOfRawData && PointerToRawData + SizeOfRawData <= SizeOfImage 
					)
				{
					if (SizeOfRawData)
					{
						PCHAR pbRawData = RtlOffsetToPointer(ImageBase, PointerToRawData);

						if (pb > pbRawData)
						{
							return 0;
						}

						memcpy(pbRawData, RtlOffsetToPointer(ImageBase, VirtualAddress), min(SizeOfRawData, VirtualSize));

						if (VirtualSize < SizeOfRawData)
						{
							RtlZeroMemory(pbRawData+VirtualSize, SizeOfRawData - VirtualSize);
						}

						pb += SizeOfRawData;
					}
				}
				else
				{
					return 0;
				}

			} while (pish++, --NumberOfSections);

			return RtlPointerToOffset(ImageBase, pb);
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return 0;
	}
}

NTSTATUS ReadDataFromMemory(HANDLE hProcess, LPVOID Base, LPVOID lpBuffer, SIZE_T cbBuffer)
{
	return DbgReadMemory(hProcess, Base, lpBuffer, cbBuffer, 0);
}

NTSTATUS ReadDataFromFile(HANDLE hFile, LPVOID , LPVOID lpBuffer, SIZE_T cbBuffer)
{
	IO_STATUS_BLOCK iosb;
	LARGE_INTEGER li = {};
	return ZwReadFile(hFile, 0, 0, 0, &iosb, lpBuffer, (DWORD)cbBuffer, &li, 0);
}

NTSTATUS CMemDumpDlg::OnButtonCopy(HWND hwndDlg, NTSTATUS (* pfnReadData)(HANDLE, LPVOID, LPVOID, SIZE_T), HANDLE handle, LPVOID Base, SIZE_T Size)
{
	LPVOID BaseAddress = m_lpBuffer;
	SIZE_T RegionSize = m_cbBuffer;

	NTSTATUS status = 0;

	if (m_cbBuffer < Size)
	{
		if (m_cbBuffer) ZwFreeVirtualMemory(NtCurrentProcess(), &m_lpBuffer, 
			&m_cbBuffer, MEM_RELEASE), m_cbBuffer = 0;

		status = ZwAllocateVirtualMemory(NtCurrentProcess(), &(BaseAddress = 0), 0, 
			&(RegionSize = Size), MEM_COMMIT, PAGE_READWRITE);
	}

	if (0 <= status)
	{
		status = pfnReadData(handle, Base, BaseAddress, Size);
		if (0 <= status) {
			if (m_cbBuffer < Size) m_lpBuffer = BaseAddress, m_cbBuffer = RegionSize;
			m_cbBufferData = Size;			
		}
		else ZwFreeVirtualMemory(NtCurrentProcess(), &BaseAddress, &RegionSize, MEM_RELEASE);
	}

	WCHAR sz[17];
	swprintf(sz, L"%X", (ULONG)m_cbBufferData);
	SetDlgItemText(hwndDlg, IDC_STATIC1, sz);

	return status;
}

void CMemDumpDlg::OnButtonCopy(HWND hwndDlg)
{
	LPVOID Base;
	DWORD Size;

	if (!GetData(hwndDlg, &Base, &Size, 0, 0)) return;

	NTSTATUS status = OnButtonCopy(hwndDlg, ReadDataFromMemory, m_hProcess, Base, Size);

	0 > status ? DisplayStatus(hwndDlg, status, L"Copy Failed") : MessageBox(hwndDlg, L"Copy Ok!", L"", 0);
}

NTSTATUS WriteToProcessMemory(HANDLE hProcess, LPVOID RemoteBase, SIZE_T Size, LPVOID LocaleBase)
{
	LPVOID _RemoteBase = RemoteBase;
	SIZE_T _Size = Size;

	DWORD OldProtect;
	NTSTATUS status = ZwProtectVirtualMemory(hProcess, &_RemoteBase, &_Size,
		PAGE_READWRITE, &OldProtect);

	if (0 > status) return status;

	status = ZwWriteVirtualMemory(hProcess, RemoteBase, LocaleBase, Size, 0);
	ZwProtectVirtualMemory(hProcess, &_RemoteBase, &_Size, OldProtect, &OldProtect);

	return status;
}

void CMemDumpDlg::OnButtonPaste(HWND hwndDlg)
{
	LPVOID Base;
	DWORD Size;
	if (!GetData(hwndDlg, &Base, &Size, 0, 0)) return;

	NTSTATUS status = Size > m_cbBufferData ? STATUS_BUFFER_TOO_SMALL :
		WriteToProcessMemory(m_hProcess, Base, Size, m_lpBuffer);

	0 > status ? DisplayStatus(hwndDlg, status, L"Paste Failed") : MessageBox(hwndDlg, L"Paste Ok!", L"", 0);
}

void CMemDumpDlg::OnButtonZero(HWND hwndDlg)
{
	PVOID Base, BaseAddress;
	SIZE_T RegionSize;
	DWORD Size;

	if (!GetData(hwndDlg, &Base, &Size, 0, 0)) return;

	NTSTATUS status = ZwAllocateVirtualMemory(NtCurrentProcess(), &(BaseAddress = 0), 0, 
		&(RegionSize = Size), MEM_COMMIT, PAGE_READWRITE);

	if (0 <= status)
	{
		status = WriteToProcessMemory(m_hProcess, Base, Size, BaseAddress);
		ZwFreeVirtualMemory(NtCurrentProcess(), &BaseAddress, &RegionSize, MEM_RELEASE);
	}

	0 > status ? DisplayStatus(hwndDlg, status, L"Zero Memory Failed") : MessageBox(hwndDlg, L"Memory Zeroed!", L"", 0);
}

void CMemDumpDlg::OnButtonFromFile(HWND hwndDlg)
{
	DWORD len;

	if (!GetData(hwndDlg, 0, 0, 0, &len)) return;

	LPWSTR fileName = (PWSTR)alloca(len << 1);
	GetDlgItemText(hwndDlg, IDC_EDIT4, fileName, len);

	UNICODE_STRING ntPath;
	NTSTATUS status = STATUS_UNSUCCESSFUL;
	if (RtlDosPathNameToNtPathName_U(fileName, &ntPath, 0, 0))
	{
		HANDLE hFile;
		IO_STATUS_BLOCK iosb;

		status = ZwOpenFile(&hFile, FILE_GENERIC_READ, 
			&CObjectAttributes(&ntPath), &iosb, FILE_SHARE_READ, 
			FILE_NON_DIRECTORY_FILE|FILE_SYNCHRONOUS_IO_NONALERT);

		if (0 <= status)
		{
			FILE_STANDARD_INFORMATION fsi;
			status = ZwQueryInformationFile(hFile, &iosb, &fsi, sizeof fsi,
				FileStandardInformation);

			if (0 <= status)
			{
				if (fsi.EndOfFile.HighPart) status = STATUS_BUFFER_OVERFLOW;
				else if (!fsi.EndOfFile.LowPart) status = STATUS_MAPPED_FILE_SIZE_ZERO;
				else status = OnButtonCopy(hwndDlg, ReadDataFromFile, hFile, 0, fsi.EndOfFile.LowPart);
			}
			ZwClose(hFile);
		}
		RtlFreeUnicodeString(&ntPath);
	} 

	0 > status ? DisplayStatus(hwndDlg, status, L"Copy Failed") : MessageBox(hwndDlg, L"Copy Ok!", L"", 0);
}

BOOL CMemDumpDlg::GetData(HWND hwndDlg, LPVOID* pBase, DWORD* pSize, BOOL* pbImage, DWORD* pcbFIleName)
{
	HWND hwnd = _GetData(hwndDlg, pBase, pSize, pbImage, pcbFIleName);
	if (!hwnd) return TRUE;
	::SetFocus(hwnd);
	MessageBeep((UINT)-1);
	return FALSE;
}

#ifdef _WIN64
#define uptoul _wcstoui64
#else
#define uptoul wcstoul
#endif

HWND CMemDumpDlg::_GetData(HWND hwndDlg, PVOID* pBase, DWORD* pSize, BOOL* pbImage, DWORD* pcbFIleName)
{
	WCHAR sz[18], *c;

	if (pBase)
	{
		ULONGLONG Base;
		if (!GetDlgItemText(hwndDlg, IDC_EDIT1, sz, 17) || !(Base = uptoul(sz, &c, 16)) || *c)
		{
			return ::GetDlgItem(hwndDlg, IDC_EDIT1);
		}
		*pBase = (PVOID)Base;
	}

	if (pSize)
	{
		DWORD Size;
		if (!GetDlgItemText(hwndDlg, IDC_EDIT2, sz, 9) || !(Size = wcstoul(sz, &c, 16)) ||  *c) 
		{
			return ::GetDlgItem(hwndDlg, IDC_EDIT2);
		}
		*pSize = Size;
	}

	if (pcbFIleName)
	{
		HWND hwnd = ::GetDlgItem(hwndDlg, IDC_EDIT4);
		DWORD cbFIleName = ::GetWindowTextLengthW(hwnd);
		if (!cbFIleName) return hwnd;
		*pcbFIleName = cbFIleName + 1;
	}

	if (pbImage) *pbImage = (BST_CHECKED == IsDlgButtonChecked(hwndDlg, IDC_CHECK1));

	return 0;
}

void CMemDumpDlg::OnButtonDump(HWND hwndDlg)
{
	PVOID Base, BaseAddress;
	SIZE_T RegionSize;
	DWORD len, Size;
	BOOL bImage;

	if (!GetData(hwndDlg, &Base, &Size, &bImage, &len)) return;

	LPWSTR fileName = (PWSTR)alloca(len << 1);
	GetDlgItemText(hwndDlg, IDC_EDIT4, fileName, len);

	NTSTATUS status = ZwAllocateVirtualMemory(NtCurrentProcess(), &(BaseAddress = 0), 0, 
		&(RegionSize = Size), MEM_COMMIT, PAGE_READWRITE);

	if (0 <= status)
	{
		if (0 <= (status = DbgReadMemory(m_hProcess, Base, BaseAddress, Size, 0)))
		{
			LARGE_INTEGER li;
			li.QuadPart = Size;

			if (bImage)
			{
				if (!(Size = ImageToLine(Base, BaseAddress, Size)))
				{
					status = STATUS_INVALID_IMAGE_NOT_MZ;
				}
			}

			if ((0 <= status) && (0x1000000 < li.QuadPart))
			{
				WCHAR sz[32];
				swprintf(sz, L"FileSize = %I64d", li.QuadPart);
				if (IDYES != MessageBoxW(hwndDlg, sz, L"File To Large. Are You Sure ?",
					MB_YESNOCANCEL|MB_ICONQUESTION)) status = STATUS_CANCELLED;
			}

			if (0 <= status)
			{
				UNICODE_STRING ntPath;
				if (RtlDosPathNameToNtPathName_U(fileName, &ntPath, 0, 0))
				{
					HANDLE hFile;
					IO_STATUS_BLOCK iosb;
					if (0 <= ZwCreateFile(&hFile, FILE_GENERIC_WRITE, 
						&CObjectAttributes(&ntPath), &iosb, &li, 0, 0, 
						FILE_OVERWRITE_IF, FILE_NON_DIRECTORY_FILE|
						FILE_SYNCHRONOUS_IO_NONALERT, 0, 0))
					{
						status = ZwWriteFile(hFile, 0, 0, 0, &iosb, BaseAddress, (ULONG)Size, 0, 0);

						if (0 > status)
						{
							FILE_DISPOSITION_INFORMATION fdi;
							fdi.DeleteFile = TRUE;
							ZwSetInformationFile(hFile, &iosb, &fdi, sizeof fdi, 
								FileDispositionInformation);
						}
						ZwClose(hFile);
					}
					RtlFreeUnicodeString(&ntPath);
				} 
				else status = STATUS_UNSUCCESSFUL;
			}
		}
		ZwFreeVirtualMemory(NtCurrentProcess(), &BaseAddress, &RegionSize, MEM_RELEASE);
	}

	0 > status ? DisplayStatus(hwndDlg, status, L"Save Memory Failed") : MessageBox(hwndDlg, L"Dump Created!", L"", 0);
}

#define MAX_DESTRUCTOR_COUNT 8

#include "../inc/initterm.h"

NTSTATUS AdjustPrivileges()
{
	HANDLE hToken;
	NTSTATUS status = NtOpenProcessToken(NtCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);
	if (0 <= status)
	{
		BEGIN_PRIVILEGES(tp, 2)
			LAA(SE_DEBUG_PRIVILEGE),
			LAA(SE_LOAD_DRIVER_PRIVILEGE)
		END_PRIVILEGES	
		status = NtAdjustPrivilegesToken(hToken, FALSE, (PTOKEN_PRIVILEGES)&tp, 0, 0, 0);
		NtClose(hToken);
	}
	return status;
}

void ep(void*)
{
#ifndef _WIN64
	PVOID wow;
	if (0 > NtQueryInformationProcess(NtCurrentProcess(), ProcessWow64Information, &wow, sizeof(wow), 0) || wow)
	{
		MessageBox(0, L"The 32-bit version of this program is not compatible with the 64-bit Windows you're running.", 
			L"Machine Type Mismatch", MB_ICONWARNING);
		ExitProcess(0);
	}
#else
	DLL_LIST_0::Process(&ntdll);
#endif

	NTSTATUS status = AdjustPrivileges();
	if (0 > status)
	{
		DisplayStatus(0, status, L"AdjustPrivilege");
	}
	
	STATIC_UNICODE_STRING(tkn, "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\{FC81D8A3-6002-44bf-931A-352B95C4522F}");
	
	switch (ZwLoadDriver((PUNICODE_STRING)&tkn))
	{
	case 0:
	case STATUS_IMAGE_ALREADY_LOADED:
		IO_STATUS_BLOCK iosb;
		STATIC_OBJECT_ATTRIBUTES(oa, "\\device\\69766781178D422cA183775611A8EE55");
		ZwOpenFile(&g_hDrv, SYNCHRONIZE, &oa, &iosb, FILE_SHARE_VALID_FLAGS, FILE_SYNCHRONOUS_IO_NONALERT);
		break;
	}

	ULONG v;
	RtlGetNtVersionNumbers(&v, 0, 0);
	g_xp = v < 6;//_WIN32_WINNT_VISTA;
	initterm();

	if (CMemDumpDlg* p = new CMemDumpDlg)
	{
		p->DoModal((HINSTANCE)&__ImageBase, MAKEINTRESOURCE(IDD_DIALOG1), HWND_DESKTOP, 0);
		p->Release();
	}

	destroyterm();

	if (g_hDrv)
	{
		ZwClose(g_hDrv);
	}

	ExitProcess(0);
}

_NT_END
