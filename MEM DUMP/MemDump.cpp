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

void FreePM(_In_ PRTL_PROCESS_MODULES mods);
NTSTATUS QueryPM(_In_ HANDLE dwProcessId, _Out_ PRTL_PROCESS_MODULES* pmods);
void InitWow64();

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
			NTSTATUS status = NtDeviceIoControlFile(g_hDrv, 0, 0, 0, &iosb, IOCTL_ReadMemory, &BaseAddres, sizeof(BaseAddres), Buffer, (DWORD)BufferLength);
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

OBJECT_ATTRIBUTES zoa = {sizeof(zoa)};

NTSTATUS DoIoControl(ULONG code)
{
	IO_STATUS_BLOCK iosb;
	return g_hDrv ? NtDeviceIoControlFile(g_hDrv, 0, 0, 0, &iosb, code, 0, 0, 0, 0) : STATUS_INVALID_HANDLE;
}

NTSTATUS MyOpenProcess(PHANDLE ProcessHandle, ULONG DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID Cid)
{
	if (g_hDrv)
	{
		IO_STATUS_BLOCK iosb;
		NTSTATUS status = NtDeviceIoControlFile(g_hDrv, 0, 0, 0, &iosb, IOCTL_OpenProcess, &Cid->UniqueProcess, sizeof(HANDLE), 0, 0);
		*ProcessHandle = (HANDLE)iosb.Information;
		return status;
	}
	return NtOpenProcess(ProcessHandle, DesiredAccess, ObjectAttributes, Cid);
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

void OnDropdownComboDlls(HWND hwndDlg, HWND hwndCtl, HANDLE dwProcessId)
{
	ComboBox_ResetContent(hwndCtl);

	COMBOBOXINFO cbi = { sizeof cbi };

	if (!GetComboBoxInfo(hwndCtl, &cbi)) return ;

	PRTL_PROCESS_MODULES psmi;
	if (0 <= QueryPM(dwProcessId, &psmi))
	{
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

		FreePM(psmi);
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

class CMemDumpDlg : public ZDlg
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
				OnDropdownComboDlls(hwndDlg, (HWND)lParam, m_dwProcessId);
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

			if (0 <= NtOpenProcess(&hProcess, PROCESS_QUERY_LIMITED_INFORMATION, &oa, &cid))
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

		if (m_hProcess) NtClose(m_hProcess);

		m_hProcess = 0;

		if (dwProcessId)
		{
			CLIENT_ID cid = {dwProcessId};
			MyOpenProcess(&m_hProcess, PROCESS_ALL_ACCESS, &zoa, &cid);
		}

		ComboBox_ResetContent(::GetDlgItem(hwndDlg, IDC_COMBO1));
	}	
}

void CMemDumpDlg::OnDestroy() 
{
	if (m_cbBuffer) ZwFreeVirtualMemory(NtCurrentProcess(), &m_lpBuffer, &m_cbBuffer, MEM_RELEASE);
	if (m_hProcess) NtClose(m_hProcess);
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
			NtClose(hFile);
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
						NtClose(hFile);
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
	InitWow64();
#endif

	if (NTSTATUS status = AdjustPrivileges())
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

	initterm();

	{
		CMemDumpDlg dlg;
		dlg.DoModal((HINSTANCE)&__ImageBase, MAKEINTRESOURCE(IDD_DIALOG1), HWND_DESKTOP, 0);
	}

	destroyterm();

	if (g_hDrv)
	{
		NtClose(g_hDrv);
	}

	ExitProcess(0);
}

_NT_END
