#include "stdafx.h"

_NT_BEGIN

#include "../winz/window.h"
#include "buf.h"

NTSTATUS MyOpenProcess(PHANDLE ProcessHandle, ULONG DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID Cid);

extern OBJECT_ATTRIBUTES zoa;

class ZSF : public ZWnd
{
public:
	struct CP {
		PCWSTR psz1, psz2;
		HFONT hFont;
	};
protected:
private:
	HWND _hwndEdit1, _hwndEdit2;
	int _y;

	virtual LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_ERASEBKGND:
			return TRUE;

		case WM_PAINT:
			return EmptyPaint(hwnd);

		case WM_SIZE:
			switch (wParam)
			{
			case SIZE_MAXIMIZED:
			case SIZE_RESTORED:
			case SIZE_MINIMIZED:
				int cx = GET_X_LPARAM(lParam);
				MoveWindow(_hwndEdit1, 0, 0, cx, _y, TRUE);
				MoveWindow(_hwndEdit2, 0, _y, cx, GET_Y_LPARAM(lParam) - _y, TRUE);
			}
			break;
		case WM_CREATE:
			RECT rc;
			GetClientRect(hwnd, &rc);
			CP* cp = reinterpret_cast<CP*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
			CreateClient(hwnd, rc.right, rc.bottom, cp->psz1, cp->psz2, cp->hFont);
			break;
		}
		return __super::WindowProc(hwnd, uMsg, wParam, lParam);
	}

	virtual BOOL CreateClient(HWND hWndParent, int nWidth, int nHeight, PCWSTR psz1, PCWSTR psz2, HFONT hFont)
	{
		int y = nHeight / 2;

		HWND hwnd = CreateWindowExW(0, WC_EDIT, 0, WS_CHILD|WS_VISIBLE|ES_MULTILINE|ES_READONLY, 
			0, 0, nWidth, y, hWndParent, 0, 0, 0);

		_hwndEdit1 = hwnd;

		SendMessage(hwnd, WM_SETFONT, (WPARAM)hFont, 0);

		SetWindowTextW(hwnd, psz1);

		if (HDC hdc = GetDC(hwnd))
		{
			TEXTMETRIC tm;				
			HGDIOBJ ho = SelectObject(hdc, hFont);
			if (GetTextMetricsW(hdc, &tm))
			{
				MoveWindow(hwnd, 0, 0, nWidth, y = 
					(tm.tmHeight * (4*(ULONG)SendMessage(hwnd, EM_GETLINECOUNT, 0, 0)+1))/4, TRUE);
				_y = y;
			}
			SelectObject(hdc, ho);
			ReleaseDC(hwnd, hdc);
		}

		hwnd = CreateWindowExW(0, WC_EDIT, 0, WS_CHILD|WS_VISIBLE|ES_MULTILINE|WS_VSCROLL|ES_READONLY, 
			0, y, nWidth, nHeight - y, hWndParent, 0, 0, 0);

		SendMessage(hwnd, WM_SETFONT, (WPARAM)hFont, 0);

		_hwndEdit2 = hwnd;

		SetWindowTextW(hwnd, psz2);

		return TRUE;
	}
};

void ShowE2(HWND hWndParent, PCWSTR Caption, PCWSTR psz1, PCWSTR psz2, HFONT hFont )
{
	if (ZSF* p = new ZSF)
	{
		ZSF::CP cp = { psz1, psz2, hFont };

		if (HWND hwnd = p->Create(0, Caption, WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN, 
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWndParent, 0, &cp))
		{
			ShowWindow(hwnd, SW_SHOW);
		}

		p->Release();
	}
}

BOOL
GetProcessMitigationPolicy(
						   _In_ HANDLE hProcess,
						   _In_ PROCESS_MITIGATION_POLICY MitigationPolicy,
						   _Out_writes_bytes_(DWORD) PVOID lpBuffer
						   )
{
	struct PROCESS_MITIGATION {
		PROCESS_MITIGATION_POLICY Policy;
		DWORD Flags;
	};

	PROCESS_MITIGATION m = { MitigationPolicy };
	NTSTATUS status = NtQueryInformationProcess(hProcess, ProcessMitigationPolicy, &m, sizeof(m), 0);
	if (0 <= status)
	{
		*(PULONG)lpBuffer = m.Flags;
		return TRUE;
	}

	SetLastError(RtlNtStatusToDosError(status));
	return FALSE;
}


void els3(WLog& log, PVOID buf)
{
	union {
		PBYTE pb;
		PVOID pv;
		PSYSTEM_PROCESS_INFORMATION pspi;
	};

	pv = buf;
	ULONG NextEntryOffset = 0;

	do 
	{
		pb += NextEntryOffset;

		CLIENT_ID cid = { pspi->UniqueProcessId };

		if (cid.UniqueProcess)
		{
			HANDLE hProcess;
			NTSTATUS status = MyOpenProcess(&hProcess, PROCESS_QUERY_INFORMATION, &zoa, &cid);
			if (0 > status)
			{
				log(L"[                  ] %04x(%04x) Open(%wZ)=%x\r\n", 
					(ULONG)(ULONG_PTR)pspi->UniqueProcessId, 
					(ULONG)(ULONG_PTR)pspi->InheritedFromUniqueProcessId,
					&pspi->ImageName, status);
			}
			else
			{
				union {
					PROCESS_MITIGATION_DYNAMIC_CODE_POLICY dcp;
					PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY cfg;
					PROCESS_MITIGATION_BINARY_SIGNATURE_POLICY bsp;
					PROCESS_MITIGATION_CHILD_PROCESS_POLICY cpp;
				};

				WCHAR sz[] = L".... ... ..... ...";

				if (GetProcessMitigationPolicy(hProcess, ProcessSignaturePolicy, &dcp))
				{
					if (dcp.ProhibitDynamicCode) sz[0] = '#';
					if (dcp.AllowThreadOptOut) sz[1] = '#';
					if (dcp.AllowRemoteDowngrade) sz[2] = '#';
					if (dcp.AuditProhibitDynamicCode) sz[3] = '#';
				}

				if (GetProcessMitigationPolicy(hProcess, ProcessControlFlowGuardPolicy, &cfg))
				{
					if (cfg.EnableControlFlowGuard) sz[5] = '#';
					if (cfg.EnableExportSuppression) sz[6] = '#';
					if (cfg.StrictMode) sz[7] = '#';
				}

				if (GetProcessMitigationPolicy(hProcess, ProcessSignaturePolicy, &bsp))
				{
					if (bsp.MicrosoftSignedOnly) sz[9] = '#';
					if (bsp.StoreSignedOnly) sz[10] = '#';
					if (bsp.MitigationOptIn) sz[11] = '#';
					if (bsp.AuditMicrosoftSignedOnly) sz[12] = '#';
					if (bsp.AuditStoreSignedOnly) sz[13] = '#';
				}
			
				if (GetProcessMitigationPolicy(hProcess, ProcessChildProcessPolicy, &cpp))
				{
					if (cpp.NoChildProcessCreation) sz[15] = '#';
					if (cpp.AuditNoChildProcessCreation) sz[16] = '#';
					if (cpp.AllowSecureProcessCreation) sz[17] = '#';
				}

				log(L"[%s] %04x(%04x) %wZ\r\n", sz, 
					(ULONG)(ULONG_PTR)pspi->UniqueProcessId, 
					(ULONG)(ULONG_PTR)pspi->InheritedFromUniqueProcessId,
					&pspi->ImageName);

				NtClose(hProcess);
			}
		}

	} while (NextEntryOffset = pspi->NextEntryOffset);
}

void els3(WLog& log)
{
	NTSTATUS status;
	ULONG cb = 0x20000;

	do 
	{
		status = STATUS_INSUFFICIENT_RESOURCES;

		if (PVOID pv = LocalAlloc(0, cb))
		{
			if (0 <= (status = NtQuerySystemInformation(SystemProcessInformation, pv, cb, &cb)))
			{
				els3(log, pv);
			}
			LocalFree(pv);
		}

	} while (status == STATUS_INFO_LENGTH_MISMATCH);

	if (0 > status)
	{
		log(L"QuerySystemInformation(SystemProcessInformation)=%x\r\n", status);
		log[status];
	}
}

void ShowPolicy(HWND hWndParent, HFONT hFont)
{
	if (PWSTR buf = new WCHAR[0x40000])
	{
		WLog log(buf, 0x40000);
		els3(log);
		ShowE2(hWndParent, L"Mitigation Policy", 
			L"[#... ... ..... ...] ProhibitDynamicCode\r\n"
			L"[.#.. ... ..... ...] AllowThreadOptOut\r\n"
			L"[..#. ... ..... ...] AllowRemoteDowngrade\r\n"
			L"[...# ... ..... ...] AuditProhibitDynamicCode\r\n"
			L"[.... #.. ..... ...] EnableControlFlowGuard\r\n"
			L"[.... .#. ..... ...] EnableExportSuppression\r\n"
			L"[.... ..# ..... ...] StrictMode\r\n"
			L"[.... ... #.... ...] MicrosoftSignedOnly\r\n"
			L"[.... ... .#... ...] StoreSignedOnly\r\n"
			L"[.... ... ..#.. ...] MitigationOptIn\r\n"
			L"[.... ... ...#. ...] AuditMicrosoftSignedOnly\r\n"
			L"[.... ... ....# ...] AuditStoreSignedOnly\r\n"
			L"[.... ... ..... #..] NoChildProcessCreation\r\n"
			L"[.... ... ..... .#.] AuditNoChildProcessCreation\r\n"
			L"[.... ... ..... ..#] AllowSecureProcessCreation", 
			log, hFont );

		delete [] buf;
	}
}

_NT_END