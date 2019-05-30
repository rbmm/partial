// GetPdb.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "resource.h"
#include "../inc/idcres.h"

_NT_BEGIN

#include "../inc/initterm.h"
#include "../asio/ssl.h"
#include "../asio/CiclicBuffer.h"
#include "dllVector.h"
#include "qpm.h"

void EnumAllDlls(HWND hwnd);
BOOL IsValidPDBExist(POBJECT_ATTRIBUTES poa, PGUID Signature, DWORD Age);

HANDLE g_hDrv;

#include "../tkn/tkn.h"

NTSTATUS DoIoControl(ULONG code)
{
	IO_STATUS_BLOCK iosb;
	return g_hDrv ? ZwDeviceIoControlFile(g_hDrv, 0, 0, 0, &iosb, code, 0, 0, 0, 0) : STATUS_INVALID_HANDLE;
}

LPWSTR xwcscpy(LPWSTR dst, LPCWSTR src)
{
	WCHAR c;
	do *dst++ = c = *src++; while(c);
	return dst - 1;
}


STATIC_WSTRING(global, "\\GLOBAL??\\");

NTSTATUS OpenFolderIf(PHANDLE phFile, PCWSTR sz, PCWSTR path)
{
	HANDLE hFile = 0;
	IO_STATUS_BLOCK iosb;
	UNICODE_STRING ObjectName = { sizeof(global) - sizeof(WCHAR), MAXUSHORT - 1, (PWSTR)sz };
	OBJECT_ATTRIBUTES oa = { sizeof(oa), 0, &ObjectName };
	BOOL bFirstSlash = TRUE;

	NTSTATUS status;

	for (;;) 
	{
		switch (*path++)
		{
		case 0:
			*phFile = hFile;
			return hFile ? 0 : STATUS_OBJECT_PATH_INVALID;
		case '\\':
			if (bFirstSlash)
			{
				bFirstSlash = FALSE;
			}
			else
			{
				if (hFile)
				{
					ZwClose(hFile);
				}

				if (0 > (status = ZwCreateFile(&hFile, FILE_ADD_SUBDIRECTORY|SYNCHRONIZE, &oa, &iosb, 0, 
					0, FILE_SHARE_VALID_FLAGS, FILE_OPEN_IF, FILE_DIRECTORY_FILE, 0, 0)))
				{
					return status;
				}
			}
		}

		ObjectName.Length += sizeof(WCHAR);
	}
}

DWORD WorkItem(ZDllVector* task);

class MsIp : public CSocketObject
{
	HWND m_hwnd;

public:

	virtual void OnIp(DWORD ip)
	{
		PostMessage(m_hwnd, e_ip, 0, ip);
	}

	MsIp(HWND hwnd)
	{
		m_hwnd = hwnd;
	}
};

class CDialog : public ZDllVector
{
	enum { e_LogSize = 0x8000 };
	struct DWL_PRG 
	{
		HWND hwndProgress, hwndStatus, hwndName;
	} m_arr[9];
	LONG m_nv[8];

	HWND m_hwnd;
	HANDLE m_hRoot;
	PSTR m_szLog;
	HFONT m_hFont;
	LONG m_dwRef, m_dx;
	ULONG m_nProcessed, m_nOk, m_nFail, m_nExist, m_cbFree;
	BOOLEAN m_bDirChanged, m_DownloadActive, m_bAll, m_bTimerActive;

	//---------------------------------------------------------

	virtual HANDLE get_Root()
	{
		return m_hRoot;
	}

	virtual HWND get_HWND()
	{
		return m_hwnd;
	}

	//---------------------------------------------------------

	static INT_PTR CALLBACK _DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return ((CDialog*)GetWindowLongPtr(hwnd, DWLP_USER))->DlgProc(hwnd, uMsg, wParam, lParam);
	}
	
	void OnTimer(HWND hwnd)
	{
		if (MsIp* p = new MsIp(hwnd))
		{
			p->DnsToIp("msdl.microsoft.com");
			p->Release();
		}
	}

	void OnInitDialog(HWND hwnd)
	{
		AddRef();

		OnTimer(hwnd);

		m_hwnd = hwnd;

		m_bTimerActive = SetTimer(hwnd, 1, 5000, 0) != 0;

		SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)LoadImage((HINSTANCE)&__ImageBase, 
			MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 32, 32, LR_SHARED));

		SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)LoadImage((HINSTANCE)&__ImageBase, 
			MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 16, 16, LR_SHARED));
		
		PCWSTR systemroot = USER_SHARED_DATA->NtSystemRoot;
		PWSTR path = (PWSTR)alloca((wcslen(systemroot) + 16)<< 1);
		PWSTR c = xwcscpy(path, systemroot);

		wcscpy(c, L"\\system32\\");
		SetDlgItemText(hwnd, IDC_EDIT1, path);
		wcscpy(c, L"\\symbols\\");
		SetDlgItemText(hwnd, IDC_EDIT2, path);

		int i = 9;

		do 
		{
			DWL_PRG* p = m_arr + --i;

			p->hwndProgress = GetDlgItem(hwnd, IDC_PROGRESS1 + i);
			p->hwndStatus = GetDlgItem(hwnd, IDC_STATIC1 + 2*i);
			p->hwndName = GetDlgItem(hwnd, IDC_STATIC2 + 2*i);
		} while (i);

		m_bAll = FALSE;

		RECT rc, RC;
		m_dx = 0;
		if (GetWindowRect(GetDlgItem(hwnd, IDC_PROGRESS9), &RC) && GetWindowRect(GetDlgItem(hwnd, IDC_PROGRESS1), &rc))
		{
			if ((m_dx = RC.top - rc.top + 3) && GetWindowRect(hwnd, &rc))
			{
				MoveWindow(hwnd, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top - m_dx, FALSE);
			}
		}

		m_szLog = new CHAR[e_LogSize];

		m_hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, FIXED_PITCH|FF_MODERN, L"Courier New");
	}

	void toCtrl(HWND hwndCtrl)
	{
		MessageBeep(MAXDWORD);
		SetFocus(hwndCtrl);
	}

	void toCtrl(HWND hwnd, HWND hwndCtrl, ULONG error, PCWSTR caption)
	{
		NTSTATUS status = RtlGetLastNtStatus();
		if (RtlNtStatusToDosError(status) == error)
		{
			toCtrl(hwnd, hwndCtrl, status, caption);
		}
		else
		{
			WCHAR err[256];
			FormatWin32Status(err, error);
			SetFocus(hwndCtrl);
			MessageBox(hwnd, err, caption, MB_ICONWARNING);
		}
	}

	void toCtrl(HWND hwnd, HWND hwndCtrl, NTSTATUS status, PCWSTR caption)
	{
		WCHAR err[256];
		FormatNTStatus(err, status);
		UINT type;
		switch ((ULONG)status >> 30)
		{
		case 0:
			type = MB_OK;
			break;
		case 1:
			type = MB_OK|MB_ICONINFORMATION;
			break;
		case 2:
			type = MB_OK|MB_ICONWARNING;
			break;
		case 3:
			type = MB_OK|MB_ICONHAND;
			break;
		default:__assume(false);
		}
		SetFocus(hwndCtrl);
		MessageBox(hwnd, err, caption, type);

	}

	BOOL OpenFolder(HWND hwnd, HWND hwndCtrl)
	{
		if (int len = GetWindowTextLength(hwndCtrl))
		{
			PWSTR buf = (PWSTR)alloca(((len + 1) << 1) + sizeof(global)), path = buf + RTL_NUMBER_OF(global) - 1;
			
			memcpy(buf, global, sizeof(global) - sizeof(WCHAR));

			if (len == GetWindowText(hwndCtrl, path, len + 1))
			{
				if (path[len - 1] != '\\')
				{
					path[len] = '\\';
					path[len + 1] = 0;
				}

				if (m_hRoot)
				{
					ZwClose(m_hRoot);
					m_hRoot = 0;
				}

				NTSTATUS status = OpenFolderIf(&m_hRoot, buf, path);

				if (0 > status)
				{
					toCtrl(hwnd, hwndCtrl, status, L"Open Folder");
				}
				else
				{
					m_bDirChanged = FALSE;
					return TRUE;
				}
			}
		}
		toCtrl(hwndCtrl);

		return FALSE;
	}
	
	void StartStop(HWND hwnd, BOOLEAN bStart)
	{
		EnableWindow(GetDlgItem(hwnd, IDOK), !bStart);
		EnableWindow(GetDlgItem(hwnd, IDCANCEL), bStart);
		EnableWindow(GetDlgItem(hwnd, IDC_EDIT2), !bStart);
		EnableWindow(GetDlgItem(hwnd, IDC_CHECK1), !bStart);
		EnableWindow(GetDlgItem(hwnd, IDC_CHECK2), !bStart);
		if (!m_bAll) EnableWindow(GetDlgItem(hwnd, IDC_EDIT1), !bStart);
		m_DownloadActive = bStart;
	}

	void DoLog(UINT i, PCSTR msg, NTSTATUS status)
	{
		if (m_bAll)
		{
			if (PCSTR name = GetName(m_nv[i]))
			{
				ULONG len = (ULONG)strlen(name) + (ULONG)strlen(msg) + 64;
				if (m_cbFree > len)
				{
					PSTR buf = m_szLog + e_LogSize - m_cbFree;
					m_cbFree -= sprintf(buf, "%s - %s - %x\r\n", name, msg, status);
				}
			}
		}
	}

	void SetOverallProgress(ULONG status)
	{
		switch (status)
		{
		case 0:
			m_nOk++;
			break;
		case STATUS_OBJECT_NAME_EXISTS:
			m_nExist++;
			break;
		default:
			m_nFail++;
		}

		if (m_bAll)
		{
			PostMessage(m_arr[8].hwndProgress, PBM_SETPOS, ++m_nProcessed, GetDllCount());
			WCHAR sz[32];
			swprintf(sz, L"%u / %u", m_nProcessed, GetDllCount());
			SetWindowText(m_arr[8].hwndStatus, sz);
		}
	}

	INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		HWND hwndCtrl;
		CDataPacket* packet;
		DWORD len;
		WCHAR sz[128];

		switch(uMsg)
		{
		case WM_TIMER:
			OnTimer(hwnd);
			break;

		case e_packet:
			packet = (CDataPacket*)lParam;
			if (hwnd = CreateWindowExW(0, WC_EDIT, L"Fail", 
				WS_OVERLAPPEDWINDOW|WS_VSCROLL|WS_HSCROLL|ES_MULTILINE|ES_AUTOHSCROLL|ES_AUTOVSCROLL, 
				CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, 0, 0))
			{
				if (m_hFont)
				{
					SendMessage(hwnd, WM_SETFONT, (WPARAM)m_hFont, 0);
				}

				SetWindowTextA(hwnd, packet->getData());
				ShowWindow(hwnd, SW_SHOW);
			}
			packet->Release();
			break;

		case e_List:
			Init((PULONG)lParam, (ULONG)wParam);
			if ((ULONG)wParam)
			{
				m_nProcessed = 0, m_nOk = 0, m_nFail = 0, m_nExist = 0;
				PostMessage(m_arr[8].hwndProgress, PBM_SETRANGE32, 0, GetDllCount());
				PostMessage(m_arr[8].hwndProgress, PBM_SETPOS, 0, 0);
				int n = 9;
				do 
				{
					SetWindowText(m_arr[--n].hwndStatus, 0);
					SetWindowText(m_arr[n].hwndName, 0);
				} while (n);
				swprintf(sz, L"%u / %u", 0, GetDllCount());
				n = 8;//8
				do 
				{
					AddRef();
					IncActive();
					if (!QueueUserWorkItem((PTHREAD_START_ROUTINE)WorkItem, static_cast<ZDllVector*>(this), 0))
					{
						DecActive();
						Release();
					}
				} while (--n);
			}
			DecActive();
			SetWindowLongPtr(hwnd, DWLP_MSGRESULT, e_List);
			return TRUE;

		case e_stop:
			StartStop(hwnd, FALSE);
			if (m_bAll && m_cbFree != e_LogSize)
			{
				if (hwnd = CreateWindowExW(0, WC_EDIT, L"Fail PDBs", 
					WS_OVERLAPPEDWINDOW|WS_VSCROLL|WS_HSCROLL|ES_MULTILINE|ES_AUTOHSCROLL|ES_AUTOVSCROLL, 
					CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, 0, 0))
				{
					if (m_hFont)
					{
						SendMessage(hwnd, WM_SETFONT, (WPARAM)m_hFont, 0);
					}

					SetWindowTextA(hwnd, m_szLog);
					ShowWindow(hwnd, SW_SHOW);
				}
			}
			break;

		case e_connect:
		case e_connect2:
			if ((NTSTATUS)lParam)
			{
				swprintf(sz, L"connect(%u) error %x", uMsg - e_connect, (ULONG)lParam);
				SetWindowText(m_arr[wParam].hwndStatus, sz);
				SetOverallProgress((NTSTATUS)lParam);
			}
			break;

		case e_disconnect:
			if (lParam)
			{
				SetOverallProgress(0);
				if (!m_bAll) SetWindowText(m_arr[wParam].hwndStatus, L"OK");
			}
			else
			{
				SetWindowText(m_arr[wParam].hwndStatus, L"download fail");
				SetOverallProgress(ERROR_GEN_FAILURE);
				DoLog((UINT)wParam, "download", STATUS_UNSUCCESSFUL);
			}
			break;

		case e_ip:
			if ((ULONG)lParam)
			{
				set_ip((ULONG)lParam);
				EnableWindow(GetDlgItem(hwnd, IDOK), TRUE);
		case WM_DESTROY:
				if (m_bTimerActive)
				{
					m_bTimerActive = FALSE;
					KillTimer(hwnd, 1);
				}
			}
			break;

		case e_recv:
			swprintf(sz, L"downloading... %u", (ULONG)lParam);
			SetWindowText(m_arr[wParam].hwndStatus, sz);
			PostMessage(m_arr[wParam].hwndProgress, PBM_SETPOS, -lParam, 0);
			break;

		case e_length:
			swprintf(sz, L"downloading... %u", (ULONG)lParam);
			SetWindowText(m_arr[wParam].hwndStatus, sz);
			PostMessage(m_arr[wParam].hwndProgress, PBM_SETRANGE32, -lParam, 0);
			break;

		case e_name:
			PostMessage(m_arr[wParam].hwndProgress, PBM_SETRANGE32, 0, 0);
			PostMessage(m_arr[wParam].hwndProgress, PBM_SETPOS, 0, 0);
			SetWindowTextA(m_arr[wParam].hwndName, strrchr(GetName((LONG)lParam), '\\') + 1);
			SetWindowText(m_arr[wParam].hwndStatus, L"connecting...");
			m_nv[wParam] = (LONG)lParam;
			break;

		case e_init:
			SetOverallProgress((NTSTATUS)lParam);
			if (lParam != STATUS_OBJECT_NAME_EXISTS)
			{
				m_nv[(UCHAR)wParam] = (DWORD)wParam >> 8;
				DoLog((UCHAR)wParam, "locate", (NTSTATUS)lParam);
			}
			break;

		case WM_CLOSE:
			if (!m_DownloadActive)
			{
				EndDialog(hwnd, 0);
			}
			break;

		case WM_NCDESTROY:
			Release();
			break;

		case WM_INITDIALOG:
			SetWindowLongPtr(hwnd, DWLP_USER, lParam);
			((CDialog*)lParam)->OnInitDialog(hwnd);
			break;

		case WM_COMMAND:
			switch(wParam)
			{
			case MAKEWPARAM(IDC_CHECK2, BN_CLICKED):
				break;

			case MAKEWPARAM(IDC_CHECK1, BN_CLICKED):
				if (m_dx = -m_dx)
				{
					RECT rc;
					if (GetWindowRect(hwnd, &rc))
					{
						MoveWindow(hwnd, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top - m_dx, TRUE);
					}
				}
				EnableWindow(GetDlgItem(hwnd, IDC_EDIT1), m_bAll);
				EnableWindow(GetDlgItem(hwnd, IDC_CHECK2), m_bAll);
				m_bAll = !m_bAll;
				break;

			case MAKEWPARAM(IDC_EDIT2, EN_UPDATE):
				m_bDirChanged = TRUE;
				break;

			case IDCANCEL:
				StopAll();
				break;

			case IDOK:
				if (m_bDirChanged && !OpenFolder(hwnd, GetDlgItem(hwnd, IDC_EDIT2)))
				{
					return 0;
				}

				Reset();
				StartStop(hwnd, TRUE);

				if (m_bAll)
				{
					IncActive();
					m_cbFree = e_LogSize;
					if (HANDLE hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)EnumAllDlls, hwnd, 0, 0))
					{
						ZwClose(hThread);
					}
					else
					{
						DecActive();
					}
				}
				else
				{
					Single();

					if (len = GetWindowTextLength(hwndCtrl = GetDlgItem(hwnd, IDC_EDIT1)))
					{
						SDP params;
						
						params.type = SDP::e_path;
						params.task = this;
						params.DllFileName = (PWSTR)alloca((len + 1) << 1);
						GetWindowText(hwndCtrl, params.DllFileName, len + 1);
						PostMessage(m_arr[0].hwndProgress, PBM_SETRANGE32, 0, 0);
						PostMessage(m_arr[0].hwndProgress, PBM_SETPOS, 0, 0);
						PWSTR c = wcsrchr(params.DllFileName, '\\');
						SetWindowText(m_arr[0].hwndName, c ? c + 1 : params.DllFileName);
						SetWindowText(m_arr[0].hwndStatus, L"");

						ULONG err;
						if (c = wcschr(params.DllFileName, '*'))
						{
							params.type = SDP::e_sign;
							err = CreateSingleDownloadFromGuid(&params, c);
						}
						else
						{
							err = CreateSingleDownload(&params);
						}

						if (err && (err != ERROR_OBJECT_NAME_EXISTS))
						{
							toCtrl(hwnd, hwndCtrl, err, 0);
						}
					}
					else
					{
						toCtrl(hwndCtrl);
					}
				}

				DecActive();
				break;
			}
			break;
		}
		return 0;
	}

	ULONG CreateSingleDownloadFromGuid(SDP* params, PWSTR c)
	{
		PCWSTR DllFileName = params->DllFileName;

		PWSTR e;

		if (wcsrchr(c + 1, '*'))
		{
			return ERROR_INVALID_PARAMETER;
		}

		*c = 0;

		if (wcslen(++c) <= 32)
		{
			return ERROR_INVALID_PARAMETER;
		}

		params->Age = wcstoul(c += 32, &e, 16);

		if (*e != 0)
		{
			return ERROR_INVALID_PARAMETER;
		}

		int n = RTL_NUMBER_OF(params->Signature.Data4);

		do 
		{
			*c = 0;
			params->Signature.Data4[--n] = (UCHAR)wcstoul(c -= 2, &e, 16);

			if (*e != 0)
			{
				return ERROR_INVALID_PARAMETER;
			}
		} while (n);

		*c = 0;
		params->Signature.Data3 = (USHORT)wcstoul(c -= 4, &e, 16);

		if (*e != 0)
		{
			return ERROR_INVALID_PARAMETER;
		}

		*c = 0;
		params->Signature.Data2 = (USHORT)wcstoul(c -= 4, &e, 16);

		if (*e != 0)
		{
			return ERROR_INVALID_PARAMETER;
		}

		*c = 0;
		params->Signature.Data1 = wcstoul(c -= 8, &e, 16);

		if (*e != 0)
		{
			return ERROR_INVALID_PARAMETER;
		}

		int len = WideCharToMultiByte(CP_UTF8, 0, DllFileName, MAXDWORD, 0, 0, 0, 0);

		if (0 >= len)
		{
			return ERROR_INVALID_PARAMETER;
		}

		params->PdbFileName = (PSTR)alloca(len + 1);

		if (0 >= WideCharToMultiByte(CP_UTF8, 0, DllFileName, MAXDWORD, params->PdbFileName, len, 0, 0))
		{
			return ERROR_INVALID_PARAMETER;
		}

		return CreateSingleDownload(params);
	}

public:
	CDialog(SharedCred* Cred) : ZDllVector(Cred)
	{
		m_hRoot = 0, m_bDirChanged = TRUE, m_DownloadActive = FALSE, m_hFont = 0;
		m_dwRef = 1;
	}

	~CDialog()
	{
		if (m_hFont)
		{
			DeleteObject(m_hFont);
		}
		if (m_szLog)
		{
			delete m_szLog;
		}

		if (m_hRoot)
		{
			ZwClose(m_hRoot);
		}
	}

	void Run()
	{
		DialogBoxParam((HINSTANCE)&__ImageBase, MAKEINTRESOURCE(IDD_GETPDB_DIALOG), HWND_DESKTOP, _DlgProc, (LPARAM)this);
	}

	virtual void AddRef()
	{
		InterlockedIncrement(&m_dwRef);
	}

	virtual void Release()
	{
		if (!InterlockedDecrement(&m_dwRef))
		{
			delete this;
		}
	}
};

void  onIOunlock(void)
{
}

#define LAA(se) {{se},SE_PRIVILEGE_ENABLED|SE_PRIVILEGE_ENABLED_BY_DEFAULT}

#define BEGIN_PRIVILEGES(tp, n) static const struct {ULONG PrivilegeCount;LUID_AND_ATTRIBUTES Privileges[n];} tp = {n,{
#define END_PRIVILEGES }};

NTSTATUS AdjustPrivileges()
{
	HANDLE hToken;
	NTSTATUS status = ZwOpenProcessToken(NtCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);
	if (0 <= status)
	{
		BEGIN_PRIVILEGES(tp, 3)
			LAA(SE_DEBUG_PRIVILEGE),
			LAA(SE_LOAD_DRIVER_PRIVILEGE),
			LAA(SE_MANAGE_VOLUME_PRIVILEGE)
		END_PRIVILEGES	
		status = ZwAdjustPrivilegesToken(hToken, FALSE, (PTOKEN_PRIVILEGES)&tp, 0, 0, 0);
		ZwClose(hToken);
	}
	return status;
}

//extern ULONG gTlsIndex;

void _ep()
{
	//gTlsIndex = TlsAlloc();
#ifndef _WIN64
	PVOID wow;
	if (0 > ZwQueryInformationProcess(NtCurrentProcess(), ProcessWow64Information, &wow, sizeof(wow), 0) || wow)
	{
		MessageBox(0, L"use 64-bit version of GetPdb!", 0, MB_ICONWARNING);
		return;
	}
#else
	QUERY_PROCESS_MODULES::InitWow();
#endif
	AdjustPrivileges();

	STATIC_UNICODE_STRING(tkn, "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\{FC81D8A3-6002-44bf-931A-352B95C4522F}");

	switch (ZwLoadDriver((PUNICODE_STRING)&tkn))
	{
	case 0:
	case STATUS_IMAGE_ALREADY_LOADED:
		IO_STATUS_BLOCK iosb;
		STATIC_OBJECT_ATTRIBUTES(oa, "\\device\\69766781178D422cA183775611A8EE55");
		NtOpenFile(&g_hDrv, SYNCHRONIZE, &oa, &iosb, FILE_SHARE_VALID_FLAGS, FILE_SYNCHRONOUS_IO_NONALERT);
		break;
	}

	WSADATA wd;
	if (!WSAStartup(WINSOCK_VERSION, &wd))
	{
		if (SharedCred* Cred = new SharedCred)
		{
			if (0 <= Cred->Acquire(SECPKG_CRED_OUTBOUND, 0, SCH_CRED_NO_DEFAULT_CREDS|SCH_CRED_MANUAL_CRED_VALIDATION))
			{
				if (CDialog* dlg = new CDialog(Cred))
				{
					dlg->Run();
					dlg->Release();
				}
			}
			Cred->Release();
		}

		WSACleanup();
	}
}

struct MY_RUNDOWN_REF : RUNDOWN_REF
{
	virtual void RundownCompleted()
	{
		destroyterm();
		ExitProcess(0);
	}
} g_myRR;

RUNDOWN_REF * g_IoRundown = &g_myRR;

void ep(void*)
{
	initterm();

	_ep();

	g_IoRundown->BeginRundown();
}

_NT_END