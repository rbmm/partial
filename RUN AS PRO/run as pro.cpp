#include "stdafx.h"
#include "common.h"

#define ComboBox_AddStringEx(hwndCtl, sz, Data) \
	ComboBox_SetItemData(hwndCtl, ComboBox_AddString(hwndCtl, sz), Data)

#include "../inc/idcres.h"
#include "resource.h"

_NT_BEGIN
#include "../tkn/tkn.h"

BOOL g_xp;
volatile UCHAR guz;
OBJECT_ATTRIBUTES zoa = { sizeof zoa };

#ifdef _WIN64

#include "wow.h"

PVOID g_LoadLibraryExWWow;

BEGIN_WOW_DLL(kernel32)
	WOW_FUNC(LoadLibraryExW)
END_HOOK()

WOW_PROCS_BEGIN()
	WOW_DLL(kernel32)
END_HOOK()

#endif

NTSTATUS DisplayStatus(NTSTATUS status, PCWSTR sztext, HWND hwnd = HWND_DESKTOP)
{
	WCHAR err[MAX_PATH];
	
	FormatMessage(FORMAT_MESSAGE_IGNORE_INSERTS|FORMAT_MESSAGE_FROM_HMODULE,
		GetModuleHandleW(L"ntdll"), status, 0, err, RTL_NUMBER_OF(err), 0);
	
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
	
	MessageBoxW(hwnd, err , sztext, mb);
	
	return status;
}

#include "../inc/rtlframe.h"

// +++ xp/2003 support

struct _EF
{
	HANDLE InheritFromProcessHandle;
};

typedef RTL_FRAME<_EF> EF;

struct EEF : public EF
{
	void* operator new(size_t, void* pv)
	{
		return pv;
	}

	void operator delete(void* /*pv*/)
	{
	}
};

#define TRACE_FLAG	0x100
#define RESUME_FLAG 0x10000

LONG vex(::PEXCEPTION_POINTERS ExceptionInfo)
{
	::PEXCEPTION_RECORD ExceptionRecord = ExceptionInfo->ExceptionRecord;

	if (ExceptionRecord->ExceptionCode != STATUS_SINGLE_STEP) return EXCEPTION_CONTINUE_SEARCH;

	PVOID ExceptionAddress = ExceptionRecord->ExceptionAddress;

	if ((ExceptionAddress != ZwCreateProcessEx) && (ExceptionAddress != ZwCreateProcess)) return EXCEPTION_CONTINUE_SEARCH;

	::_CONTEXT* ContextRecord = ExceptionInfo->ContextRecord;

	if (EF* prf = EF::get())
	{

#ifdef _WIN64 
		ContextRecord->R9
#else
		((PULONG_PTR)ContextRecord->Esp)[4]
#endif
		= (ULONG_PTR)prf->InheritFromProcessHandle;
	}

	ContextRecord->ContextFlags |= CONTEXT_DEBUG_REGISTERS;
	ContextRecord->EFlags |= RESUME_FLAG;// not work on xp, work on 2003
	ContextRecord->Dr7 = 0;
	return EXCEPTION_CONTINUE_EXECUTION;
}

// --- xp/2003 support

#define LAA(se) {{se},SE_PRIVILEGE_ENABLED|SE_PRIVILEGE_ENABLED_BY_DEFAULT}

#define BEGIN_PRIVILEGES(tp, n) static const struct {ULONG PrivilegeCount;LUID_AND_ATTRIBUTES Privileges[n];} tp = {n,{
#define END_PRIVILEGES }};

BEGIN_PRIVILEGES(tp_Load, 1)
	LAA(SE_LOAD_DRIVER_PRIVILEGE)
END_PRIVILEGES	

BEGIN_PRIVILEGES(tp_TCB_Assign_Debug_Quota, 4)
	LAA(SE_TCB_PRIVILEGE),
	LAA(SE_DEBUG_PRIVILEGE),
	LAA(SE_INCREASE_QUOTA_PRIVILEGE),
	LAA(SE_ASSIGNPRIMARYTOKEN_PRIVILEGE),
END_PRIVILEGES	

NTSTATUS GetSystemToken(PHANDLE phSysToken, PBYTE buf, PTOKEN_PRIVILEGES NewState = (PTOKEN_PRIVILEGES)&tp_TCB_Assign_Debug_Quota)
{
	NTSTATUS status;

	union {
		PBYTE pb;
		PSYSTEM_PROCESS_INFORMATION pspi;
	};

	pb = buf;
	ULONG NextEntryOffset = 0;

	do 
	{
		pb += NextEntryOffset;

		HANDLE hProcess, hToken, hNewToken;

		if (pspi->InheritedFromUniqueProcessId && pspi->UniqueProcessId && pspi->NumberOfThreads)
		{
			static SECURITY_QUALITY_OF_SERVICE sqos = {
				sizeof sqos, SecurityImpersonation, SECURITY_DYNAMIC_TRACKING, FALSE
			};

			static OBJECT_ATTRIBUTES soa = { sizeof(soa), 0, 0, 0, 0, &sqos };

			if (0 <= NtOpenProcess(&hProcess, PROCESS_QUERY_LIMITED_INFORMATION, &zoa, &pspi->TH->ClientId))
			{
				status = NtOpenProcessToken(hProcess, TOKEN_DUPLICATE, &hToken);

				NtClose(hProcess);

				if (0 <= status)
				{
					status = NtDuplicateToken(hToken, TOKEN_ADJUST_PRIVILEGES|TOKEN_IMPERSONATE, 
						&soa, FALSE, TokenImpersonation, &hNewToken);

					NtClose(hToken);

					goto __v;
				}
			}

			if (0 <= ZwOpenThread(&hProcess, THREAD_DIRECT_IMPERSONATION, &zoa, &pspi->TH->ClientId))
			{
				status = ZwImpersonateThread(NtCurrentThread(), hProcess, &sqos);

				NtClose(hProcess);

				if (0 <= status)
				{
					status = NtOpenThreadTokenEx(NtCurrentThread(), TOKEN_ADJUST_PRIVILEGES|TOKEN_IMPERSONATE,
						FALSE, 0, &hNewToken);

					NtSetInformationThread(NtCurrentThread(), ThreadImpersonationToken, &(hToken = 0), sizeof(hToken));

					goto __v;
				}
			}
			
			continue;

__v:
			if (0 <= status)
			{

				if (STATUS_SUCCESS == NtAdjustPrivilegesToken(hNewToken, FALSE, NewState, 0, 0, 0))	
				{
					*phSysToken = hNewToken;
					return STATUS_SUCCESS;
				}

				NtClose(hNewToken);
			}
		}

	} while (NextEntryOffset = pspi->NextEntryOffset);

	return STATUS_UNSUCCESSFUL;
}

HANDLE g_hDrv;

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

BOOL LoadDrv()
{
	STATIC_UNICODE_STRING(tkn, "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\{FC81D8A3-6002-44bf-931A-352B95C4522F}");
	NTSTATUS status = ZwLoadDriver(const_cast<PUNICODE_STRING>(&tkn));

	if (0 > status && status != STATUS_IMAGE_ALREADY_LOADED)
	{
		return FALSE;
	}

	IO_STATUS_BLOCK iosb;
	STATIC_OBJECT_ATTRIBUTES(oa, "\\device\\69766781178D422cA183775611A8EE55");

	return 0 <= NtOpenFile(&g_hDrv, SYNCHRONIZE, &oa, &iosb, FILE_SHARE_VALID_FLAGS, FILE_SYNCHRONOUS_IO_NONALERT);
}

NTSTATUS SetLowLevel(HANDLE hToken)
{
	TOKEN_MANDATORY_LABEL tml = { { alloca(GetSidLengthRequired(1)), SE_GROUP_INTEGRITY|SE_GROUP_INTEGRITY_ENABLED } };
	static SID_IDENTIFIER_AUTHORITY LabelAuthority = SECURITY_MANDATORY_LABEL_AUTHORITY;
	InitializeSid(tml.Label.Sid, &LabelAuthority, 1);
	*GetSidSubAuthority(tml.Label.Sid, 0) = SECURITY_MANDATORY_LOW_RID;
	return ZwSetInformationToken(hToken, TokenIntegrityLevel, &tml, sizeof(tml));
}

NTSTATUS GetLastNtStatus(BOOL fOk)
{
	if (fOk) return STATUS_SUCCESS;
	NTSTATUS status = RtlGetLastNtStatus();
	ULONG dwError = GetLastError();
	return RtlNtStatusToDosErrorNoTeb(status) == dwError ? status : 0x80000000|(FACILITY_WIN32 << 16)|dwError;
}

NTSTATUS CreateProcessEx(HANDLE hProcess, 
						 PCWSTR lpApplicationName, 
						 PWSTR lpCommandLine, 
						 DWORD dwCreationFlags, 
						 PVOID lpEnvironment,
						 PCWSTR lpCurrentDirectory,
						 STARTUPINFOW* si, 
						 PROCESS_INFORMATION* pi)
{
	HANDLE hToken;
	NTSTATUS status = NtOpenProcessToken(hProcess, TOKEN_QUERY|TOKEN_DUPLICATE|TOKEN_ASSIGN_PRIMARY, &hToken);

	if (0 <= status)
	{
		status = GetLastNtStatus(CreateProcessAsUserW(hToken, lpApplicationName, 
			lpCommandLine, 0, 0, 0, dwCreationFlags, lpEnvironment, lpCurrentDirectory, si, pi));

		NtClose(hToken);
	}

	return status;
}

NTSTATUS CreateProcessEx(HANDLE hProcess, 
					   ULONG SessionId, 
					   ULONG MySessionId, 
					   BOOLEAN bLow,
					   PCWSTR lpApplicationName, 
					   PWSTR lpCommandLine, 
					   DWORD dwCreationFlags, 
					   PVOID lpEnvironment,
					   PCWSTR lpCurrentDirectory,
					   STARTUPINFOW* si, 
					   PROCESS_INFORMATION* pi)
{
	HANDLE hToken, hNewToken;

	NTSTATUS status = NtOpenProcessToken(hProcess, TOKEN_DUPLICATE, &hToken);

	if (0 <= status)
	{
		status = NtDuplicateToken(hToken, TOKEN_QUERY|TOKEN_DUPLICATE|TOKEN_ASSIGN_PRIMARY|
			TOKEN_ADJUST_SESSIONID|TOKEN_ADJUST_DEFAULT, 0, FALSE, TokenPrimary, &hNewToken);

		NtClose(hToken);

		if (0 <= status)
		{
			if (SessionId != MySessionId)
			{
				// need TOKEN_ADJUST_SESSIONID
				status = NtSetInformationToken(hNewToken, TokenSessionId, &SessionId, sizeof(SessionId));
			}

			if (0 <= status && bLow)
			{
				// need TOKEN_ADJUST_DEFAULT
				status = SetLowLevel(hNewToken);
			}

			if (0 <= status)
			{
				// need TOKEN_QUERY|TOKEN_DUPLICATE|TOKEN_ASSIGN_PRIMARY
				status = GetLastNtStatus(CreateProcessAsUser(hNewToken, lpApplicationName, 
					lpCommandLine, 0, 0, 0, dwCreationFlags, 
					lpEnvironment, lpCurrentDirectory, si, pi));
			}
			NtClose(hNewToken);
		}
	}

	return status;
}

NTSTATUS CreateProcessEx(PCLIENT_ID cid, 
						 ULONG SessionId, 
						 ULONG MySessionId, 
						 BOOLEAN bLow,
						 PCWSTR lpApplicationName, 
						 PWSTR lpCommandLine, 
						 DWORD dwCreationFlags, 
						 PVOID lpEnvironment,
						 PCWSTR lpCurrentDirectory,
						 STARTUPINFOEXW* si, 
						 PROCESS_INFORMATION* pi)
{
	PVOID stack = alloca(guz);
	SIZE_T size = max(0x30, sizeof(EEF));
	ULONG cb = 0;

	do 
	{
		if (cb < size)
		{
			size = cb = RtlPointerToOffset(si->lpAttributeList = (LPPROC_THREAD_ATTRIBUTE_LIST)alloca(size - cb), stack);
		}

		if (InitializeProcThreadAttributeList(si->lpAttributeList, 1, 0, &size))
		{
			HANDLE hProcess;

			NTSTATUS status = MyOpenProcess(&hProcess, READ_CONTROL|PROCESS_CREATE_PROCESS|PROCESS_QUERY_LIMITED_INFORMATION, &zoa, cid);

			if (0 <= status)
			{
				// hProcess need PROCESS_CREATE_PROCESS
				if (UpdateProcThreadAttribute(si->lpAttributeList, 0, 
					PROC_THREAD_ATTRIBUTE_PARENT_PROCESS, &hProcess, sizeof(hProcess), 0, 0))
				{
					status = bLow || SessionId != MySessionId ? 
						CreateProcessEx(
						hProcess, 
						SessionId, 
						MySessionId, 
						bLow,
						lpApplicationName, 
						lpCommandLine, 
						dwCreationFlags, 
						lpEnvironment,
						lpCurrentDirectory,
						&si->StartupInfo, 
						pi) : 
					CreateProcessEx(
						hProcess, 
						lpApplicationName, 
						lpCommandLine, 
						dwCreationFlags, 
						lpEnvironment,
						lpCurrentDirectory,
						&si->StartupInfo, 
						pi);
				}
				else
				{
					status = STATUS_UNSUCCESSFUL;
				}

				NtClose(hProcess);
			}

			DeleteProcThreadAttributeList(si->lpAttributeList);

			return status;
		}

	} while (GetLastError() == ERROR_INSUFFICIENT_BUFFER);

	return STATUS_UNSUCCESSFUL;
}

void SetEnv(PCWSTR buf, HWND hwndEdit)
{
	ULONG len = 0, n;
	PCWSTR c = buf;
	do 
	{
		n = 1 + (ULONG)wcslen(c);
		len += n + 1;
		c += n;
	} while (*c);

	PWSTR pv = (PWSTR)alloca(len << 1), sz = pv;

	do 
	{
		n = (ULONG)wcslen(buf);
		memcpy(sz, buf, n << 1);
		sz += n + 2;
		sz[-2] = '\r', sz[-1] = '\n';
		buf += n + 1;
	} while (*buf);

	sz[-2] = 0;

	SetWindowTextW(hwndEdit, pv);
}

NTSTATUS ReadProcessEnv(HANDLE hProcess, PVOID Environment, HWND hwndEdit)
{
	NTSTATUS status;
	MEMORY_BASIC_INFORMATION mbi;

	if (0 > (status = ZwQueryVirtualMemory(hProcess, Environment, MemoryBasicInformation, &mbi, sizeof(mbi), 0))) return status;

	if (mbi.State != MEM_COMMIT || mbi.Type != MEM_PRIVATE)
	{
		return STATUS_UNSUCCESSFUL;
	}

	mbi.RegionSize -= RtlPointerToOffset(mbi.BaseAddress, Environment);

	//Environment must be WCHAR aligned and how minimum 2*sizeof(WCHAR) size
	if (mbi.RegionSize < 2*sizeof(WCHAR) || ((ULONG_PTR)Environment & (__alignof(WCHAR) - 1)))
	{
		return STATUS_UNSUCCESSFUL;
	}

	if (mbi.RegionSize > 0x10000)// >64Kb Environment ??
	{
		mbi.RegionSize = 0x10000;
	}

	PWSTR buf = (PWSTR)alloca(mbi.RegionSize);

	if (0 <= (status = ZwReadVirtualMemory(hProcess, Environment, buf, mbi.RegionSize, 0)))
	{
		*(PULONG)RtlOffsetToPointer(buf, mbi.RegionSize - sizeof(ULONG)) = 0;

		SetEnv(buf, hwndEdit);
		return STATUS_SUCCESS;
	}

	return status;
}

NTSTATUS ReadProcessEnvNative(HANDLE hProcess, HWND hwndEdit)
{
	NTSTATUS status;
	PROCESS_BASIC_INFORMATION pbi;
	_RTL_USER_PROCESS_PARAMETERS* ProcessParameters;
	PVOID Environment;

	if (
		0 > (status = ZwQueryInformationProcess(hProcess, ProcessBasicInformation, &pbi, sizeof(pbi), 0))
		||
		0 > (status = ZwReadVirtualMemory(hProcess, &pbi.PebBaseAddress->ProcessParameters, &ProcessParameters, sizeof(PVOID), 0))
		||
		0 > (status = ZwReadVirtualMemory(hProcess, &ProcessParameters->Environment, &Environment, sizeof(PVOID), 0))
		) 
		return status;

	return ReadProcessEnv(hProcess, Environment, hwndEdit);
}

#if 0

NTSTATUS ReadProcessEnvWow(HANDLE hProcess, PWSTR* ppsz)
{
	ULONG WowPeb, ProcessParameters;
	NTSTATUS status;
	PVOID Environment = 0;

	if (0 > (status = ZwQueryInformationProcess(hProcess, ProcessWow64Information, &WowPeb, sizeof(PVOID), 0))) return status;

	if (!WowPeb)
	{
		return STATUS_SUCCESS;
	}

	enum {
		ofs32_ProcessParameters = 0x10,
		ofs32_Environment = 0x48
	};

	if (
		0 > (status = ZwReadVirtualMemory(hProcess, RtlOffsetToPointer(WowPeb, ofs32_ProcessParameters), &ProcessParameters, sizeof(ULONG), 0))
		||
		0 > (status = ZwReadVirtualMemory(hProcess, RtlOffsetToPointer(ProcessParameters, ofs32_Environment), &Environment, sizeof(ULONG), 0))
		) 
		return status;

	return ReadProcessEnv(hProcess, Environment, ppsz);
}
#endif

NTSTATUS ReadProcessEnv(HANDLE Pid, HWND hwndEdit)
{
	HANDLE hProcess;
	CLIENT_ID cid = { Pid };
	NTSTATUS status = MyOpenProcess(&hProcess, PROCESS_QUERY_INFORMATION|PROCESS_VM_READ, &zoa, &cid);

	if (0 <= status)
	{
		ReadProcessEnvNative(hProcess, hwndEdit);
#if 0
		ReadProcessEnvWow(hProcess, ppszWow);
#endif
		NtClose(hProcess);
	}

	return status;
}

class CMyApp
{
	struct HDEBOBJ
	{
		HDEBOBJ* next;
		HANDLE hDebugObject;

		HDEBOBJ(HANDLE hDebugObject) : hDebugObject(hDebugObject) {}
		~HDEBOBJ() { NtClose(hDebugObject); }
	} *m_first;

	NTSTATUS _OnDropDownPro(HWND hwndCtl);
	int OnDropDownPro(HWND hwndCtl, BOOLEAN bImpersonate = FALSE);
	void OnDropDownDeb(HWND hwndCtl);
	NTSTATUS OnRun(HWND hwnd);
	
	HANDLE _hSysToken;
	LONG m_SessionMask;
	HWND m_hWnd, m_Env, m_hwPro, m_lastEdit, m_CopyEnv, m_hwDeb, m_hwSesId;
	
	static INT_PTR CALLBACK DialogProc_(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	INT_PTR DialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	BOOL OnInitDialog(HWND hwnd);
	void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);	
	
	void DeleteDebugObjects();

public:
	
	CMyApp();
	~CMyApp();
};

void CMyApp::DeleteDebugObjects()
{
	HDEBOBJ* first = m_first, *item;
	while (first)
	{
		item = first;
		first = first->next;
		delete item;
	}
	m_first = 0;
}

CMyApp::~CMyApp()
{
	DeleteDebugObjects();

	if (_hSysToken)
	{
		NtClose(_hSysToken);
	}
}

CMyApp::CMyApp()
{
	m_first = 0;
	m_SessionMask = 0;
	_hSysToken = 0;
	
	DialogBoxParamW((HINSTANCE)&__ImageBase, 
		MAKEINTRESOURCE(IDD_DIALOG1), HWND_DESKTOP, DialogProc_, (LPARAM)this);
}

INT_PTR CALLBACK CMyApp::DialogProc_(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	CMyApp* me = 0;
	
	if (message == WM_INITDIALOG) {
		SetWindowLongPtr(hwnd, DWLP_USER, (LONG_PTR)lParam);
		me = (CMyApp*)lParam;
		SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)LoadImage((HINSTANCE)&__ImageBase, 
			MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 32, 32, LR_SHARED));
		SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)LoadImage((HINSTANCE)&__ImageBase, 
			MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 16, 16, LR_SHARED));

		if (g_xp)
		{
			EnableWindow(GetDlgItem(hwnd, IDC_CHECK1), FALSE);
		}
	}
	
	if (!me) me = (CMyApp*)(LONG_PTR)GetWindowLongPtr(hwnd, DWLP_USER);
	
	return me ? me->DialogProc(hwnd, message, wParam, lParam) : 0;
}

void CMyApp::OnDropDownDeb(HWND hwndCtl)
{
	ComboBox_ResetContent(hwndCtl);
	DeleteDebugObjects();

	HANDLE hDebObj = 0, hProcess;
	NTSTATUS status;
	DWORD cb = 0x10000, rcb;

	union {
		PVOID pv;
		PSYSTEM_HANDLE_INFORMATION_EX pshti;
	};

	static USHORT ObjectTypeIndex;

	if (!ObjectTypeIndex)
	{
		if (0 > NtCreateDebugObject(&hDebObj, SYNCHRONIZE, &zoa, 0))
		{
			return ;
		}
	}

	do 
	{
		status = STATUS_INSUFFICIENT_RESOURCES;

		if (pv = new BYTE[cb])
		{
			if (0 <= (status = ZwQuerySystemInformation(
				SystemExtendedHandleInformation, pv, cb, &cb)))
			{
				if (ULONG_PTR NumberOfHandles = pshti->NumberOfHandles)
				{
					PSYSTEM_HANDLE_TABLE_ENTRY_INFO_EX Handles = pshti->Handles;

					ULONG_PTR UniqueProcessId = GetCurrentProcessId();

					if (!ObjectTypeIndex)
					{
						do 
						{
							if (Handles->UniqueProcessId == UniqueProcessId && Handles->HandleValue == (ULONG_PTR)hDebObj)
							{
								ObjectTypeIndex = Handles->ObjectTypeIndex;

								NumberOfHandles = pshti->NumberOfHandles;
								Handles = pshti->Handles;
								goto __0;
							}
						} while (Handles++, --NumberOfHandles);

						goto __1;
					}

__0:
					cb = 0, rcb = 256;
					PVOID stack = alloca(guz);

					union {
						PVOID buf;
						PUNICODE_STRING Name;
					};

					do 
					{
						if (ObjectTypeIndex == Handles->ObjectTypeIndex && Handles->UniqueProcessId != UniqueProcessId)
						{
							if (0 <= NtOpenProcess(&hProcess, g_xp ?
								PROCESS_DUP_HANDLE|PROCESS_QUERY_INFORMATION : PROCESS_DUP_HANDLE|PROCESS_QUERY_LIMITED_INFORMATION, 
								&zoa, &CID((HANDLE)Handles->UniqueProcessId)))
							{
								do 
								{
									if (cb < rcb) cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);

									if (0 <= (status = ZwQueryInformationProcess(hProcess, ProcessImageFileName, buf, cb, &rcb)))
									{
										PWSTR lpsz = wcsrchr(Name->Buffer, L'\\');

										lpsz = lpsz ? lpsz + 1 : Name->Buffer;

										if (0 <= ZwDuplicateObject(hProcess, (HANDLE)Handles->HandleValue, NtCurrentProcess(),
											&hDebObj, 0, 0, DUPLICATE_SAME_ACCESS))
										{
											if (HDEBOBJ *item = new HDEBOBJ(hDebObj))
											{
												WCHAR sz[128];
												_snwprintf(sz, 128, L"%04X.%04X %s", 
													(ULONG)(ULONG_PTR)Handles->UniqueProcessId, 
													(ULONG)(ULONG_PTR)Handles->HandleValue, lpsz);
												item->hDebugObject = hDebObj;
												if (0 > ComboBox_AddStringEx(hwndCtl, sz, item)) delete item;
												else
												{
													item->next = m_first;
													m_first = item;
													hDebObj = 0;
												} 
											}
											else
											{
												NtClose(hDebObj);
											}
										}
									}

								} while(status == STATUS_INFO_LENGTH_MISMATCH);

								NtClose(hProcess);
							}
						}
					} while (Handles++, --NumberOfHandles);
				}
			}
__1:
			delete [] pv;
		}

	} while (STATUS_INFO_LENGTH_MISMATCH == status);
	
	if (hDebObj)
	{
		NtClose(hDebObj);
	}
}

BOOL CMyApp::OnInitDialog(HWND hwnd)
{
	//SetEnv((PCWSTR)RtlGetCurrentPeb()->ProcessParameters->Environment, GetDlgItem(hwnd, IDC_EDIT6));

	m_lastEdit = 0, m_hWnd = hwnd;

	m_CopyEnv = GetDlgItem(hwnd, IDC_BUTTON3);
	m_hwPro = GetDlgItem(hwnd, IDC_COMBO1);
	m_hwDeb = GetDlgItem(hwnd, IDC_COMBO2);
	m_hwSesId = GetDlgItem(hwnd, IDC_COMBO3);
	ComboBox_SetMinVisible(m_hwPro, 16);
	ComboBox_SetCurSel(m_hwPro, OnDropDownPro(m_hwPro, TRUE));

	return TRUE;
}

INT_PTR CMyApp::DialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{	
	union {
		int i;
		BOOL f;
		NTSTATUS status;
	};

	switch(message) 
	{
	case WM_INITDIALOG:
		if (!OnInitDialog(hwnd)) EndDialog(hwnd, -1);
		return TRUE;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDCANCEL:
			EndDialog(hwnd, 0);
			break;
		case MAKEWPARAM(IDC_EDIT1, EN_SETFOCUS):
		case MAKEWPARAM(IDC_EDIT2, EN_SETFOCUS):
		case MAKEWPARAM(IDC_EDIT3, EN_SETFOCUS):
		case MAKEWPARAM(IDC_EDIT4, EN_SETFOCUS):
			m_lastEdit = (HWND)lParam;
			break;

		case MAKEWPARAM(IDC_COMBO1, CBN_CLOSEUP):
			f = 0 <= ComboBox_GetCurSel((HWND)lParam);
			EnableWindow(GetDlgItem (hwnd, IDC_BUTTON2), f);
			EnableWindow(GetDlgItem (hwnd, IDC_BUTTON3), f);
			break;
		case MAKEWPARAM(IDC_COMBO1, CBN_DROPDOWN):
			OnDropDownPro((HWND)lParam);
			break;
		case MAKEWPARAM(IDC_COMBO2, CBN_DROPDOWN):
			OnDropDownDeb((HWND)lParam);
			break;

		case MAKEWPARAM(IDC_BUTTON3, BN_CLICKED):
			if (0 <= (i = ComboBox_GetCurSel(m_hwPro)))
			{
				ReadProcessEnv((HANDLE)ComboBox_GetItemData(m_hwPro, i), GetDlgItem(hwnd, IDC_EDIT6));
			}
			break;

		case MAKEWPARAM(IDC_BUTTON2, BN_CLICKED):
			status = OnRun(hwnd);
			if (0 > status) {
				DisplayStatus(status, L"CreateProcess", hwnd);//
			}
			break;
		case MAKEWPARAM(IDC_BUTTON1, BN_CLICKED):
			if (hwnd = m_lastEdit)
			{
				OPENFILENAME ofn = { sizeof ofn };
				ofn.hwndOwner = hwnd;
				ofn.lpstrFile = (PWSTR)alloca(512 * sizeof WCHAR);
				ofn.nMaxFile = 512;
				*ofn.lpstrFile = 0;
				ofn.lpstrFile[0] = 0;
				ofn.lpstrFilter = L"Executable\0*.exe\0All Files\0*.*\0";
				ofn.nFilterIndex = 1;
				ofn.Flags = OFN_DONTADDTORECENT|OFN_ENABLESIZING|
					OFN_EXPLORER|OFN_FILEMUSTEXIST|OFN_FORCESHOWHIDDEN
					|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY;
				ofn.FlagsEx = OFN_EX_NOPLACESBAR;

				if (GetOpenFileName(&ofn)){
					SetWindowText(hwnd, ofn.lpstrFile);
				}
				m_lastEdit = hwnd;
				SetFocus(hwnd);
			}
			else
			{
				MessageBeep((UINT)-1);
				return 0;
			}
			break;
		}
		break;
	}
	return 0;
}

int CMyApp::OnDropDownPro(HWND hwndCtl, BOOLEAN bImersonate )
{
	ComboBox_ResetContent(hwndCtl);
	
	HWND hwSesId = m_hwSesId;
	LONG SessionMask = 0, _SessionMask = m_SessionMask;
	NTSTATUS status;
	DWORD cb = 0x10000, rcb;

	union {
		PBYTE pb;
		SYSTEM_PROCESS_INFORMATION* sp;
	};

	ULONG SessionId, MySessionId;
	int index = -1, i;

	ProcessIdToSessionId(GetCurrentProcessId(), &MySessionId);

	do 
	{
		status = STATUS_INSUFFICIENT_RESOURCES;

		if (PBYTE buf = new BYTE[cb += 0x1000])
		{
			if (0 <= (status = NtQuerySystemInformation(SystemProcessInformation, buf, cb, &cb)))
			{
				if (bImersonate)
				{
					if (0 > GetSystemToken(&_hSysToken, buf))
					{
						MessageBox(0, L"GetSystemToken", 0, MB_ICONERROR);
					}
				}
				pb = buf;

#ifdef _WIN64
				OBJECT_ATTRIBUTES oa = { sizeof oa };
				CLIENT_ID cid = { };
#endif
				cb = 0;
				PVOID stack = alloca(guz);
				PWSTR sz = 0;
				DWORD NextEntryDelta = 0;
				HANDLE id = (HANDLE)GetCurrentProcessId();
				do
				{
					pb += NextEntryDelta;

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

						rcb = sp->ImageName.Length + 64;

						if (cb < rcb) cb = RtlPointerToOffset(sz = (PWSTR)alloca(rcb - cb), stack);

						SessionId = sp->SessionId;

						swprintf(sz, L"%04X[%04X] %u %c %wZ", 
							(ULONG)(ULONG_PTR)sp->UniqueProcessId, 
							(ULONG)(ULONG_PTR)sp->InheritedFromUniqueProcessId, 
							SessionId, c, &sp->ImageName);

						ComboBox_SetItemData(hwndCtl, i = ComboBox_AddString(hwndCtl, sz), sp->UniqueProcessId);

						if (sp->UniqueProcessId == id) index = i;

						if (SessionId < 32)
						{
							if (!_bittestandset(&SessionMask, SessionId) &&
								!_bittestandreset(&_SessionMask, SessionId))
							{
								swprintf(sz, L"%u", SessionId);
								ComboBox_SetItemData(hwSesId, i = ComboBox_AddString(hwSesId, sz), SessionId);
								if (MySessionId == SessionId)
								{
									ComboBox_SetCurSel(hwSesId, i);
								}
							}
						}
					}

				} while(NextEntryDelta = sp->NextEntryOffset);
			}

			delete [] buf;
		}
		
	} while(status == STATUS_INFO_LENGTH_MISMATCH);

	if (_SessionMask)
	{
		SessionId = 31;
		do 
		{
			if (_bittest(&_SessionMask, SessionId))
			{
				WCHAR sz[15];
				swprintf(sz, L"%u", SessionId);
				if (0 <= (i = ComboBox_FindStringExact(hwSesId, 0, sz)))
				{
					ComboBox_DeleteString(hwSesId, i);
				}
			}
		} while (SessionId--);
	}

	m_SessionMask = SessionMask;

	return index;
}

NTSTATUS ApcInjector(LPCWSTR lpDllName, HANDLE hProcess, HANDLE hThread)
{
	PVOID BaseAddress = 0;
	SIZE_T Size = (wcslen(lpDllName) + 1) << 1, Len = Size;

	NTSTATUS status = ZwAllocateVirtualMemory(hProcess, &BaseAddress, 0, &Size, MEM_COMMIT, PAGE_READWRITE);

	if (0 > status) return status;

	status = ZwWriteVirtualMemory(hProcess, BaseAddress,(LPVOID)lpDllName, (ULONG)Len, 0);

	if (0 > status) return status;

#ifdef _WIN64
	PVOID wow;
	if (0 <= (status = ZwQueryInformationProcess(hProcess, ProcessWow64Information, &wow, sizeof(wow), 0)))
	{
		return (wow ? RtlQueueApcWow64Thread : ZwQueueApcThread)(hThread, (PKNORMAL_ROUTINE)(wow ? g_LoadLibraryExWWow : LoadLibraryExW), BaseAddress, 0, 0);
	}
	return status;
#else
	return ZwQueueApcThread(hThread,(PKNORMAL_ROUTINE)LoadLibraryExW, BaseAddress, 0, 0);
#endif
}

int SetFocusEx(HWND hwndCtl)
{
	SetFocus(hwndCtl);
	MessageBeep((UINT)-1);
	return 0;
}

struct AutoImpesonate
{
	BOOLEAN _bRevertToSelf;

	~AutoImpesonate()
	{
		if (_bRevertToSelf)
		{
			HANDLE hToken = 0;
			NtSetInformationThread(NtCurrentThread(), ThreadImpersonationToken, &hToken, sizeof(hToken));
		}
	}

	AutoImpesonate(HANDLE hToken)
	{
		_bRevertToSelf = hToken ? 
			0 <= NtSetInformationThread(NtCurrentThread(), ThreadImpersonationToken, &hToken, sizeof(hToken)) : FALSE;
	}
};

NTSTATUS CMyApp::OnRun(HWND hwnd)
{
	NTSTATUS status = STATUS_SUCCESS;

	HWND hwndCtl = m_hwPro;
	int i = ComboBox_GetCurSel(hwndCtl);	
	
	if (0 > i) return STATUS_UNSUCCESSFUL;

	CLIENT_ID cid = { (HANDLE)ComboBox_GetItemData(hwndCtl, i) };

	int len = ComboBox_GetLBTextLen(hwndCtl, i);

	if (len <= 0)
	{
		return STATUS_UNSUCCESSFUL;
	}

	PWSTR str = (PWSTR)alloca((len + 1) * sizeof(WCHAR));

	if (len != ComboBox_GetLBText(hwndCtl, i, str))
	{
		return STATUS_UNSUCCESSFUL;
	}

	if (!(str = wcschr(str, ']')))
	{
		return STATUS_UNSUCCESSFUL;
	}

	ULONG SessionId, ProcessSessionId = wcstoul(str + 2, &str, 10), CurrentProcessId = GetCurrentProcessId();

	if (*str != ' ')
	{
		return STATUS_UNSUCCESSFUL;
	}

	SessionId = ProcessSessionId;

	if (0 <= (i = ComboBox_GetCurSel(m_hwSesId)))
	{
		SessionId = (ULONG)ComboBox_GetItemData(m_hwSesId, i);
	}

	enum {
		e_Env, e_DeskName, e_Dll, e_WorkDir, e_CmdLine, e_AppName, e_EditCount 
	};

	PWSTR strA[e_EditCount], lpsz;
	ULONG n = e_EditCount, dwCreationFlags = CREATE_PRESERVE_CODE_AUTHZ_LEVEL;
	do 
	{	
		if (hwndCtl = GetDlgItem(hwnd, IDC_EDIT6 - --n))
		{
			if (len = GetWindowTextLengthW(hwndCtl))
			{
				if (GetWindowTextW(hwndCtl, strA[n] = (PWSTR)alloca((len + (n ? 1 : 3)) << 1), len + 1) != len)
					return SetFocusEx(hwndCtl);

				if (!n)
				{
					lpsz = &strA[n][len];
					lpsz[0] = '\r', lpsz[1] = '\n', lpsz[2] = 0;
				}
			}
			else
			{
				if (n == e_AppName)
				{
					return SetFocusEx(hwndCtl);
				}
				strA[n] = 0;
			}
		}
		else
		{
			return 0;
		}

	} while (n);

	if (lpsz = strA[e_Env])
	{
		dwCreationFlags |= CREATE_UNICODE_ENVIRONMENT;

		PWSTR from = 0;
		PBYTE to = 0;
		do 
		{
			if (*lpsz == '\r')
			{
				*lpsz++ = 0;

				if (to)
				{
					memcpy(to, from, n = RtlPointerToOffset(from, lpsz));
					to += n;
				}
				else
				{
					to = (PBYTE)lpsz;
				}

				from = lpsz + 1;
			}
		} while (*++lpsz);

		*(PWSTR)to = 0;
	}

	BOOLEAN bLow = !g_xp && IsDlgButtonChecked(hwnd, IDC_CHECK1) == BST_CHECKED;

	PROCESS_INFORMATION pi;

	HANDLE hDebugObject = 0;

	if (0 <= (i = ComboBox_GetCurSel(m_hwDeb))) 
	{
		dwCreationFlags |= DEBUG_PROCESS;
		hDebugObject = ((HDEBOBJ*)ComboBox_GetItemData(m_hwDeb, i))->hDebugObject;
		DbgUiSetThreadDebugObject(hDebugObject);
	}

	if (strA[e_Dll])
	{
		dwCreationFlags |= CREATE_SUSPENDED;
	}

	STARTUPINFOEXW si = { {sizeof(si), 0, strA[e_DeskName] } };

	if ((ULONG_PTR)cid.UniqueProcess == (ULONG_PTR)CurrentProcessId)
	{
		if (!bLow && SessionId == ProcessSessionId)
		{
			status = GetLastNtStatus(CreateProcessW(strA[e_AppName], strA[e_CmdLine], 0, 0, 0, dwCreationFlags, 
				strA[e_Env], strA[e_WorkDir], &si.StartupInfo, &pi));
		}
		else
		{
			status = CreateProcessEx(NtCurrentProcess(), SessionId, ProcessSessionId, bLow, 
				strA[e_AppName], strA[e_CmdLine], dwCreationFlags, strA[e_Env], strA[e_WorkDir], &si.StartupInfo, &pi);
		}
	}
	else
	{
		AutoImpesonate ai(_hSysToken);

		status = CreateProcessEx(&cid, SessionId, ProcessSessionId, bLow, strA[e_AppName], strA[e_CmdLine], 
			dwCreationFlags|EXTENDED_STARTUPINFO_PRESENT, 
			strA[e_Env], strA[e_WorkDir], &si, &pi);
	}

	if (0 <= status)
	{
		if (strA[e_Dll]) 
		{
			if (0 > (status = ApcInjector(strA[e_Dll], pi.hProcess, pi.hThread)))
			{
				DisplayStatus(status, L"Fail inject DLL");
			}
		}

		if (dwCreationFlags & CREATE_SUSPENDED)
		{
			ZwResumeThread(pi.hThread, 0);
		}

		NtClose(pi.hThread);		
		NtClose(pi.hProcess);
	} 

	if (hDebugObject) DbgUiSetThreadDebugObject(0);

	return status;
}

extern "C"
{
	extern PVOID __imp_InitializeProcThreadAttributeList, __imp_UpdateProcThreadAttribute, __imp_DeleteProcThreadAttributeList;
}

//#define CPP_FUNCTION __pragma(message("extern " __FUNCDNAME__ " : PROC ; "  __FUNCSIG__))
#define CPP_FUNCTION

BOOL
WINAPI
tmpInitializeProcThreadAttributeList(
								  LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
								  DWORD dwAttributeCount,
								  DWORD dwFlags,
								  PSIZE_T lpSize
								  )
{
	CPP_FUNCTION;
	if (g_xp) 
	{
		SIZE_T cb = *lpSize;
		*lpSize = sizeof(EEF);
		if (cb >= sizeof(EEF))
		{
			new (lpAttributeList) EEF;
			return TRUE;
		}

		SetLastError(ERROR_INSUFFICIENT_BUFFER);
		return FALSE;
	}

	if (PVOID pv = GetProcAddress(GetModuleHandle(L"kernel32"), "InitializeProcThreadAttributeList"))
	{

		__imp_InitializeProcThreadAttributeList = pv;

		return InitializeProcThreadAttributeList(lpAttributeList, dwAttributeCount, dwFlags, lpSize);
	}

	return FALSE;
}

BOOL
WINAPI
tmpUpdateProcThreadAttribute(
						  _Inout_ LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
						  _In_ DWORD dwFlags,
						  _In_ DWORD_PTR Attribute,
						  _In_reads_bytes_opt_(cbSize) PVOID lpValue,
						  _In_ SIZE_T cbSize,
						  _Out_writes_bytes_opt_(cbSize) PVOID lpPreviousValue,
						  _In_opt_ PSIZE_T lpReturnSize
						  )
{
	CPP_FUNCTION;

	if (g_xp) 
	{
		if (Attribute == PROC_THREAD_ATTRIBUTE_PARENT_PROCESS)
		{
			if (cbSize == sizeof(HANDLE))
			{
				reinterpret_cast<EEF*>(lpAttributeList)->InheritFromProcessHandle = *(HANDLE*)lpValue;

				CONTEXT cntx = {};
				cntx.ContextFlags = CONTEXT_DEBUG_REGISTERS;
				cntx.Dr2 = (ULONG_PTR)ZwCreateProcess;
				cntx.Dr3 = (ULONG_PTR)ZwCreateProcessEx;
				cntx.Dr7 = 0x450;

				return 0 <= ZwSetContextThread(NtCurrentThread(), &cntx);
			}
		}

		return FALSE;
	}

	if (PVOID pv = GetProcAddress(GetModuleHandle(L"kernel32"), "UpdateProcThreadAttribute"))
	{

		__imp_UpdateProcThreadAttribute = pv;

		return UpdateProcThreadAttribute(lpAttributeList, dwFlags, Attribute, lpValue, cbSize, lpPreviousValue, lpReturnSize);
	}

	return FALSE;
}

VOID
WINAPI
tmpDeleteProcThreadAttributeList(
							  _Inout_ LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList
							  )
{
	CPP_FUNCTION;
	if (g_xp) return ;
	if (PVOID pv = GetProcAddress(GetModuleHandle(L"kernel32"), "DeleteProcThreadAttributeList"))
	{
		__imp_DeleteProcThreadAttributeList = pv;

		DeleteProcThreadAttributeList(lpAttributeList);
	}
}

#ifdef _X86_

#pragma comment(linker, "/alternatename:___imp_InitializeProcThreadAttributeList=__imp__InitializeProcThreadAttributeList@16")
#pragma comment(linker, "/alternatename:___imp_UpdateProcThreadAttribute=__imp__UpdateProcThreadAttribute@28")
#pragma comment(linker, "/alternatename:___imp_DeleteProcThreadAttributeList=__imp__DeleteProcThreadAttributeList@4")

#else

extern "C"
{
	PVOID __imp_InitializeProcThreadAttributeList = tmpInitializeProcThreadAttributeList;
	PVOID __imp_UpdateProcThreadAttribute = tmpUpdateProcThreadAttribute;
	PVOID __imp_DeleteProcThreadAttributeList = tmpDeleteProcThreadAttributeList;
}
#endif

NTSTATUS GetLoadDrvToken(PHANDLE phToken)
{
	NTSTATUS status;

	ULONG cb = 0x10000;

	do 
	{
		status = STATUS_INSUFFICIENT_RESOURCES;

		if (PBYTE buf = new BYTE[cb += 0x1000])
		{
			if (0 <= (status = NtQuerySystemInformation(SystemProcessInformation, buf, cb, &cb)))
			{
				status = GetSystemToken(phToken, buf, (PTOKEN_PRIVILEGES)&tp_Load);

				if (status == STATUS_INFO_LENGTH_MISMATCH)
				{
					status = STATUS_UNSUCCESSFUL;
				}
			}

			delete [] buf;
		}

	} while(status == STATUS_INFO_LENGTH_MISMATCH);

	return status;
}
void ep(PVOID wow)
{	
#ifndef _WIN64
	if (0 > ZwQueryInformationProcess(NtCurrentProcess(), ProcessWow64Information, &wow, sizeof(wow), 0) || wow)
	{
		MessageBox(0, L"use 64-bit version of RunAsPro!", 0, MB_ICONWARNING);
		ExitProcess(0);
	}
#else
	getWowProcs();
#endif

	BOOLEAN b;
	RtlAdjustPrivilege(SE_DEBUG_PRIVILEGE, TRUE, FALSE, &b);
	
	if (0 > RtlAdjustPrivilege(SE_LOAD_DRIVER_PRIVILEGE, TRUE, FALSE, &b))
	{
		HANDLE hToken;
		if (0 <= GetLoadDrvToken(&hToken))
		{
			AutoImpesonate a(hToken);
			NtClose(hToken);
			LoadDrv();
		}
	}
	else
	{
		LoadDrv();
	}

	ULONG v;
	RtlGetNtVersionNumbers(&v, 0, 0);
	if (g_xp = (v < 6))//_WIN32_WINNT_VISTA;
	{
		if (!RtlAddVectoredExceptionHandler(TRUE, vex))
		{
			ExitProcess(0);
		}
	}
	
	{ CMyApp theApp; }
	
	ExitProcess(0);
}

_NT_END
