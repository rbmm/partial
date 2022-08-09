// PeVw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../ntver/nt_ver.h"
_NT_BEGIN
#include "../inc/initterm.h"
#include "common.h"
#include "../winz/split.h"
#include "qpm.h"

#include "../tkn/tkn.h"

NTSTATUS DoIoControl(ULONG code);

//#undef DbgPrint
#pragma warning(disable : 4456)
extern volatile const UCHAR guz = 0;
OBJECT_ATTRIBUTES zoa = { sizeof(zoa) };

enum Colum { CID_ORDER, CID_COUNT, CID_BASE, CID_SIZE, CID_NAME, CID_MAX };

enum { SB_COUNTID, SB_DLLID, SB_INFOID, SB_STATUSID };

void SetEditText(HWND hwnd, PVOID txt);

ULONG FormatStatus(NTSTATUS status, PWSTR lpBuffer, ULONG cch)
{
	static HMODULE s_ntdll;
	if (!s_ntdll)
	{
		s_ntdll = GetModuleHandleW(L"ntdll");
	}

	return s_ntdll ? FormatMessageW(
		FORMAT_MESSAGE_FROM_HMODULE|FORMAT_MESSAGE_IGNORE_INSERTS, s_ntdll, status, 0, lpBuffer, cch, 0) : 0;
}

void SetStatusMsg(NTSTATUS status, ZSDIFrameWnd* pMainFrame = ZGLOBALS::getMainFrame())
{
	WCHAR msg[0x100];
	if (FormatStatus(status, msg, _countof(msg)))
	{
		pMainFrame->SetStatusText(SB_STATUSID, msg);
	}
}

void SetDllCount(ULONG cItems, ZSDIFrameWnd* pMainFrame = ZGLOBALS::getMainFrame())
{
	WCHAR buf[64];
	swprintf_s(buf, _countof(buf), L"%u DLLs", cItems);
	pMainFrame->SetStatusText(SB_DLLID, buf);
}

ULONG Init(_Inout_ PSYSTEM_PROCESS_INFORMATION pspi)
{
	ULONG NextEntryOffset = 0, n = 0;
	do 
	{
		(PBYTE&)pspi += NextEntryOffset;
		pspi->PageDirectoryBase = 0;
		pspi->SpareLi1.LowPart = 0;
		pspi->SpareLi1.HighPart = STATUS_UNSUCCESSFUL;
		pspi->SpareLi2.QuadPart = 0;
		pspi->SpareLi3.QuadPart = 0;

		n++;

	} while (NextEntryOffset = pspi->NextEntryOffset);

	return n;
}

ULONG WINAPI QueryThread(NAMES* Table)
{
	ULONG n = 0;
	PSYSTEM_PROCESS_INFORMATION pspi = Table->BuildListOfProcesses();

	if (pspi)
	{
		n = Init(pspi);

		static LARGE_INTEGER SectionSize = { MaxThreads << secshift };

		HANDLE hSection;

		if (0 <= NtCreateSection(&hSection, SECTION_ALL_ACCESS, 0, &SectionSize, PAGE_READWRITE, SEC_COMMIT, 0))
		{
			PVOID BaseAddress = 0;
			SIZE_T ViewSize = 0;

			if (0 <= ZwMapViewOfSection(hSection, NtCurrentProcess(), &BaseAddress, 0, 0, 0, &ViewSize, ViewUnmap, 0, PAGE_READWRITE))
			{
				DoIoControl(IOCTL_SetProtectedProcess);

				Table->QueryLoop(pspi, hSection, BaseAddress);

				DoIoControl(IOCTL_DelProtectedProcess);

				ZwUnmapViewOfSection(NtCurrentProcess(), BaseAddress);
			}

			NtClose(hSection);
		}
	}

	Table->Finish(n, pspi);
	Table->Release();
	return 0;
}

//////////////////////////////////////////////////////////////////////////

HIMAGELIST CreateIL(HINSTANCE hInstance, int cx, int cy, UINT flags, DWORD n, WORD pID[])
{
	HIMAGELIST himl = ImageList_Create(cx, cy, flags, n, 0);

	if (himl)
	{
		do 
		{
			if (HICON hi = (HICON)LoadImage(hInstance, MAKEINTRESOURCE(*pID++), IMAGE_ICON, 0, 0, 0))
			{
				ImageList_ReplaceIcon(himl, -1, hi);
				DestroyIcon(hi);
			}
		} while (--n);
	}

	return himl;
}

HWND CreateToolWnd(PCSTR Name, HWND hwndParent)
{
	int len = MultiByteToWideChar(CP_ACP, 0, Name, MAXDWORD, 0, 0);
	if (0 > len) return 0;

	STATIC_WSTRING(loaded_to, " loaded in:");
	PWSTR sz = (PWSTR)alloca((len << 1) + sizeof(loaded_to) - 1);

	MultiByteToWideChar(CP_ACP, 0, Name, len, sz, len);
	wcscpy(sz + len - 1, loaded_to);

	int cx = GetSystemMetrics(SM_CXSCREEN), cy = GetSystemMetrics(SM_CYSCREEN);

	return CreateWindowExW(WS_EX_TOOLWINDOW, WC_EDIT, sz, 
		WS_POPUPWINDOW|WS_THICKFRAME|WS_HSCROLL|WS_DLGFRAME|WS_VSCROLL|ES_MULTILINE|ES_READONLY, 
		(cx - 400) >> 1, (cy - 480) >> 1, 
		400, 480, hwndParent, 0, 0, 0);
}

void ShowProtectedProcesses(HWND hwnd);
void ShowSessions(HWND hwnd);
void ShowPolicy(HWND hwnd);

void ShowPopup(PCWSTR caption, HWND hwndParent, HFONT hFont, void (*SetText)(HWND hwnd))
{
	if (HWND hwnd = CreateWindowExW(0, WC_EDIT, caption, WS_OVERLAPPEDWINDOW|WS_VSCROLL|ES_MULTILINE|ES_READONLY,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hwndParent, 0, 0, 0))
	{
		SendMessage(hwnd, WM_SETFONT, (WPARAM)hFont, 0);

		SetText(hwnd);

		ShowWindow(hwnd, SW_SHOWNORMAL);
	}
}

NTSTATUS MyOpenProcess(PHANDLE ProcessHandle, ULONG DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID Cid);

NTSTATUS AllocForEdit(ULONG cb, void** ppv)
{
	if (PVOID buf = LocalAlloc(0, cb))
	{
		*ppv = buf;
		return STATUS_SUCCESS;
	}

	return STATUS_NO_MEMORY;
}

NTSTATUS ShowCmdLineOld(HANDLE UniqueProcess, HWND hwnd)
{
	HANDLE hProcess;
	CLIENT_ID cid = { UniqueProcess };
	NTSTATUS status = MyOpenProcess(&hProcess, PROCESS_QUERY_INFORMATION|PROCESS_VM_READ, &zoa, &cid);
	if (0 <= status)
	{
		PROCESS_BASIC_INFORMATION pbi;
		UNICODE_STRING CmdLine;
		union {
			_RTL_USER_PROCESS_PARAMETERS * ProcessParameters;
			PVOID buf;
		};

		if (
			0 <= (status = NtQueryInformationProcess(hProcess, ProcessBasicInformation, &pbi, sizeof(pbi), 0)) &&
			0 <= (status = ZwReadVirtualMemory(hProcess, &((_PEB*)pbi.PebBaseAddress)->ProcessParameters, &ProcessParameters, sizeof(ProcessParameters), 0)) &&
			0 <= (status = ZwReadVirtualMemory(hProcess, &ProcessParameters->CommandLine, &CmdLine, sizeof(CmdLine), 0)) &&
			0 <= (status = AllocForEdit(CmdLine.Length + sizeof(WCHAR), &buf))
			)
		{
			if (0 <= (status = ZwReadVirtualMemory(hProcess, CmdLine.Buffer, buf, CmdLine.Length, 0)))
			{
				*(PWSTR)RtlOffsetToPointer(buf, CmdLine.Length) = 0;
				SetEditText(hwnd, buf), buf = 0;
			}

			LocalFree(buf);
		}

		NtClose(hProcess);
	}

	return status;
}

void ShowCmdLineEx(PCSTR cmdline, HANDLE UniqueProcess, HWND hwndParent, HFONT hFont)
{
	WCHAR caption[32];
	swprintf_s(caption, _countof(caption), L"%X Process CmdLine", (DWORD)(ULONG_PTR)UniqueProcess);
	if (HWND hwnd = CreateWindowExW(0, WC_EDIT, caption, WS_OVERLAPPEDWINDOW|WS_VSCROLL|ES_MULTILINE|ES_READONLY,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hwndParent, 0, 0, 0))
	{
		SendMessage(hwnd, WM_SETFONT, (WPARAM)hFont, 0);

		if (cmdline)
		{
			PWSTR psz = 0;
			ULONG cch = 0;
			while (cch = MultiByteToWideChar(CP_UTF8, 0, cmdline, MAXULONG, psz, cch))
			{
				if (psz)
				{
					SetEditText(hwnd, psz), psz = 0;
					break;
				}

				if (!(psz = (PWSTR)LocalAlloc(0, cch*sizeof(WCHAR))))
				{
					break;
				}
			}

			if (psz)
			{
				LocalFree(psz);
			}
		}
		else if (g_nt_ver.Version < _WIN32_WINNT_WINBLUE)
		{
			ShowCmdLineOld(UniqueProcess, hwnd);
		}

		ShowWindow(hwnd, SW_SHOWNORMAL);
	}
}

void InitTreeView(HWND hwnd, TVINSERTSTRUCT* tvis, _In_ PSYSTEM_PROCESS_INFORMATION pspi, _In_ HANDLE UniqueProcessId)
{
	pspi->SpareLi3.LowPart = 1;

	HTREEITEM hParent = tvis->hParent;

	tvis->item.lParam = hParent == TVI_ROOT ? -(LPARAM)UniqueProcessId : (LPARAM)pspi;

	tvis->hParent = TreeView_InsertItem(hwnd, tvis);

	while (ULONG NextEntryOffset = pspi->NextEntryOffset)
	{
		(PBYTE&)pspi += NextEntryOffset;

		if (pspi->InheritedFromUniqueProcessId == UniqueProcessId)
		{
			InitTreeView(hwnd, tvis, pspi, pspi->UniqueProcessId);
		}
	}

	tvis->hParent = hParent;
}

void InitTreeView(HWND hwnd, PSYSTEM_PROCESS_INFORMATION pspi)
{
	TVINSERTSTRUCT tvis = { TVI_ROOT, TVI_LAST };

	tvis.item.mask = TVIF_PARAM|TVIF_TEXT|TVIF_STATE|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvis.item.state = TVIS_EXPANDED;
	tvis.item.stateMask = TVIS_EXPANDED;
	tvis.item.iImage = I_IMAGENONE;
	tvis.item.iSelectedImage = 0;

	tvis.item.pszText = LPSTR_TEXTCALLBACK;
	tvis.item.lParam = 0;

	PSYSTEM_PROCESS_INFORMATION _pspi = pspi;

	ULONG _NextEntryOffset = pspi->NextEntryOffset;

	ULONG NextEntryOffset = 0;
	do 
	{
		(PBYTE&)pspi += NextEntryOffset;

		if (HANDLE UniqueProcessId = pspi->UniqueProcessId)
		{
			if (!pspi->SpareLi3.LowPart)
			{
				_pspi->NextEntryOffset = RtlPointerToOffset(_pspi, pspi);
				InitTreeView(hwnd, &tvis, _pspi, pspi->InheritedFromUniqueProcessId);
			}
		}

	} while (NextEntryOffset = pspi->NextEntryOffset);

	_pspi->NextEntryOffset = _NextEntryOffset;
}

class MySplit : public ZSplitWndV
{
	NAMES* _pTable = 0;
	PSYSTEM_PROCESS_INFORMATION _pspi = 0, _pspiCurrent = 0;
	PROCESS_MODULE** _ppm = 0;
	HIMAGELIST _himl = 0;
	HFONT _hFont = 0;
	HWND _hwndLV, _hwndTV;
	ULONG _iSubItem = CID_ORDER, _iSelItem = MAXULONG, _iMenuHeight = 0, _cItems = 0;
	LONG _sortBits = 0, _flags = (1 << f_ready);

	enum{
		f_ready, f_grid, f_inDelete, f_focus, f_select
	};

	BOOL OnCreate(HWND hwnd)
	{
		NONCLIENTMETRICS ncm = { sizeof(NONCLIENTMETRICS) };
		if (SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(ncm), &ncm, 0))
		{
			ncm.lfCaptionFont.lfHeight = -ncm.iMenuHeight;
			ncm.lfCaptionFont.lfWeight = FW_NORMAL;
			ncm.lfCaptionFont.lfQuality = CLEARTYPE_QUALITY;
			ncm.lfCaptionFont.lfPitchAndFamily = FIXED_PITCH|FF_MODERN;
			wcscpy(ncm.lfCaptionFont.lfFaceName, L"Courier New");

			if (HFONT hFont = CreateFontIndirect(&ncm.lfCaptionFont))
			{
				_iMenuHeight = ncm.iMenuHeight;

				if (NAMES* pTable = new NAMES(hwnd))
				{
					if (pTable->Create(0x200000))
					{
						_pTable = pTable, _hFont = hFont;
						return TRUE;
					}

					delete pTable;
				}

				DeleteObject(hFont);
			}
		}

		return FALSE;
	}

	void FreePPM()
	{
		if (PROCESS_MODULE** ppm = _ppm)
		{
			_pTable->freea(ppm), _ppm = 0;
		}
	}

	void OnDestroy()
	{
		if (NAMES* pTable = _pTable)
		{
			FreePPM();
			pTable->Release();
		}

		if (HFONT hFont = _hFont)
		{
			DeleteObject(hFont);
		}
	}

	void OnTaskReady(ULONG n, PSYSTEM_PROCESS_INFORMATION pspi);

	void GetDispInfo(TVITEMW* item);
	void GetDispInfo(LVITEMW* item);
	void GetInfoTip(NMTVGETINFOTIP* item);
	void ItemChanged(NMLISTVIEW* item);
	void ColumClick(HWND hwndLV, ULONG iSubItem);

	void BuildProcessList()
	{
		if (_bittest(&_flags, f_ready))
		{
			_bittestandreset(&_flags, f_ready);

			FreePPM();

			NAMES* pTable = _pTable;

			pTable->Reset();
			pTable->AddRef();

			HANDLE hThread = CreateThread(0, 0, (PTHREAD_START_ROUTINE)QueryThread, pTable, 0, 0);
			if (hThread)
			{
				NtClose(hThread);
			}
			else
			{
				pTable->Release();
			}
			
			ZSDIFrameWnd* pFrame = ZGLOBALS::get()->MainFrame;
			
			pFrame->SetStatusText(SB_DLLID, 0);
			pFrame->SetStatusText(SB_INFOID, 0);

			pFrame->EnableCmd(ID_SESSIONS, FALSE);
			pFrame->EnableCmd(ID_REFRESH, FALSE);
			pFrame->EnableCmd(ID_COPY, FALSE);
			pFrame->EnableCmd(ID_FIND, FALSE);
			pFrame->EnableCmd(ID_CMDLINE, FALSE);

			_iSelItem = MAXULONG, _pspiCurrent = 0, _pspi = 0;

			_flags &= ~((1 << f_select) | (1 << f_focus));

			_bittestandset(&_flags, f_inDelete);
			SendMessage(_hwndTV, WM_SETREDRAW, FALSE, 0);
			TreeView_DeleteAllItems(_hwndTV);
			_bittestandreset(&_flags, f_inDelete);

			ListView_SetItemCountEx(_hwndLV, 0, 0);

			if (!hThread)
			{
				Done(0);
			}
		}
	}

	void Done(ULONG n)
	{
		WCHAR sz[64];
		swprintf_s(sz, _countof(sz), L" %u Processes", n);
		ZSDIFrameWnd* pFrame = ZGLOBALS::getMainFrame();

		pFrame->SetStatusText(SB_COUNTID, sz);
		pFrame->EnableCmd(ID_REFRESH, TRUE);
		pFrame->EnableCmd(ID_SESSIONS, TRUE);

		SendMessage(_hwndTV, WM_SETREDRAW, TRUE, 0);
		_bittestandset(&_flags, f_ready);
	}

	void DisplayDLLs(LPARAM lParam)
	{
		ZSDIFrameWnd* pMainFrame = ZGLOBALS::getMainFrame();
		
		pMainFrame->EnableCmd(ID_COPY, FALSE);
		pMainFrame->EnableCmd(ID_FIND, FALSE);
		pMainFrame->EnableCmd(ID_CMDLINE, TRUE);
		pMainFrame->SetStatusText(SB_STATUSID, 0);

		_flags &= ~((1 << f_select) | (1 << f_focus));

		_iSelItem = MAXULONG, _pspiCurrent = 0, _cItems = 0;

		NAMES* pTable = _pTable;

		FreePPM();

		if (0 > lParam)
		{
			ListView_SetItemCountEx(_hwndLV, 0, 0);
			pMainFrame->SetStatusText(SB_INFOID, 0);

			SetStatusMsg(STATUS_PROCESS_IS_TERMINATING, pMainFrame);
			
			return ;
		}

		if (0 < lParam)
		{
			DisplayDLLs((PSYSTEM_PROCESS_INFORMATION)lParam);
			return ;
		}

		ULONG cItems = RtlNumberGenericTableElementsAvl(pTable);

		if (cItems)
		{
			SetDllCount(cItems, pMainFrame);

			if (PROCESS_MODULE** ppm = (PROCESS_MODULE**)pTable->malloca(cItems * sizeof(PROCESS_MODULE*)))
			{
				pTable->FillModules(ppm);
				_ppm = ppm, _cItems = cItems;

				HWND hwndLV = _hwndLV;

				switch (ULONG iSubItem = _iSubItem)
				{
				case CID_ORDER:
				case CID_BASE:
					{
						LVCOLUMN lc = { LVCF_FMT, LVCFMT_LEFT };
						ListView_SetColumn(hwndLV, iSubItem, &lc);
						lc.fmt = LVCFMT_LEFT|HDF_SORTUP;
						ListView_SetColumn(hwndLV, CID_NAME, &lc);
						_bittestandreset(&_sortBits, CID_NAME);
						_iSubItem = CID_NAME;
					}
					break;
				default:
					_bittestandcomplement(&_sortBits, iSubItem);
					ColumClick(hwndLV, iSubItem);
				}

				ListView_SetItemCountEx(hwndLV, cItems, 0);
			}
		}
	}

	void DisplayDLLs(PSYSTEM_PROCESS_INFORMATION pspi)
	{
		_pspiCurrent = pspi, _cItems = 0;
		WCHAR buf[128];

		TIME_FIELDS tf;
		LARGE_INTEGER locatime;
		RtlSystemTimeToLocalTime(&pspi->CreateTime, &locatime);
		RtlTimeToTimeFields(&locatime, &tf);

		char sz[32];
		ULONG count = (DWORD)(pspi->WorkingSetSize >> 10);
		if (count < 1000)
		{
			sprintf_s(sz, _countof(sz), "%u", count);
		}
		else
		{
			sprintf_s(sz, _countof(sz), "%u,%03u", count /1000, count % 1000);
		}

		union {
			LONG Flags;
			struct {
				ULONG IsProtectedProcess : 1;
				ULONG IsWow64Process : 1;
				ULONG IsProcessDeleting : 1;
				ULONG IsCrossSessionCreate : 1;
				ULONG IsFrozen : 1;
				ULONG IsBackground : 1;
				ULONG IsStronglyNamed : 1;
				ULONG IsSecureProcess : 1;
				ULONG IsSubsystemProcess : 1;
				ULONG SpareBits : 23;
			};
		};

		Flags = get_Flags(pspi);

		WCHAR cz[] = L".........";

		static const char sf[] = "PWDCFBNSY";

		ULONG i = _countof(cz) - 1;
		do 
		{
			if (_bittest(&Flags, --i))
			{
				cz[i] = sf[i];
			}
		} while (i);

		swprintf_s(buf, _countof(buf), L"%s Threads=%d | Session=%u | Handles=%u | %SK | %d-%02d-%02d %02d:%02d:%02d",
			cz, pspi->NumberOfThreads, pspi->SessionId, pspi->HandleCount, sz, 
			tf.Year, tf.Month, tf.Day, tf.Hour, tf.Minute, tf.Second);

		ZGLOBALS::getMainFrame()->SetStatusText(SB_INFOID, buf);

		ULONG cItems = 0;

		if (PROCESS_MODULE* pm = get_modules(pspi, &count))
		{
			SetDllCount(count);

			if (PROCESS_MODULE** ppm = (PROCESS_MODULE**)_pTable->malloca(count * sizeof(PROCESS_MODULE*)))
			{
				_ppm = ppm, cItems = count, _cItems = count;

				do 
				{
					*ppm++ = pm++;
				} while (--count);

				ULONG iSubItem = _iSubItem;
				if (iSubItem < CID_MAX)
				{
					_bittestandcomplement(&_sortBits, iSubItem);
					ColumClick(_hwndLV, iSubItem);
				}
			}
		}
		
		if (NTSTATUS status = get_status(pspi))
		{
			SetStatusMsg(status);
		}

		ListView_SetItemCountEx(_hwndLV, cItems, 0);
	}

	virtual LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual HWND CreateChild(BOOL lt, HWND hwndParent, int x, int y, int nWidth, int nHeight)
	{
		HWND hwnd = 0;

		if (lt)
		{
			if (hwnd = CreateWindowExW(0, WC_TREEVIEW, 0, WS_CHILD|WS_VISIBLE|
				TVS_LINESATROOT|TVS_HASLINES|TVS_HASBUTTONS|TVS_DISABLEDRAGDROP|
				TVS_TRACKSELECT|TVS_EDITLABELS|TVS_INFOTIP, x, y, nWidth, nHeight, hwndParent, (HMENU)1, 0, 0))
			{
				SendMessage(hwnd, WM_SETFONT, (WPARAM)_hFont, 0);
				
				_hwndTV = hwnd;

				if (_himl)
				{
					TreeView_SetImageList(hwnd, _himl, TVSIL_NORMAL);
				}

				BuildProcessList();
			}
		}
		else
		{
			if (hwnd = CreateWindowExW(0, WC_LISTVIEW, 0, 
				WS_VISIBLE|WS_CHILD|LVS_REPORT|LVS_SHOWSELALWAYS|LVS_OWNERDATA|LVS_SHAREIMAGELISTS|LVS_SINGLESEL|WS_HSCROLL|WS_VSCROLL,
				x, y, nWidth, nHeight, hwndParent, (HMENU)2, 0, 0))
			{
				SetWindowTheme(hwnd, L"Explorer", 0);
				SendMessage(hwnd, WM_SETFONT, (WPARAM)_hFont, 0);
				_hwndLV = hwnd;

				LV_COLUMN lvclmn = { 
					LVCF_TEXT | LVCF_WIDTH | LVCF_FMT | LVCF_SUBITEM, LVCFMT_LEFT 
				};

				static const PCWSTR headers[] = {
					L" # ", L" N ", L" Base ", L" Size ", L" Name "
				};

				static const ULONG lens[] = { 3, 3, 10 * sizeof(PVOID) >> 3, 6, 48 };

				C_ASSERT(_countof(headers) == _countof(lens));

				do
				{
					lvclmn.pszText = const_cast<PWSTR>(headers[lvclmn.iSubItem]);
					lvclmn.cx = lens[lvclmn.iSubItem] * _iMenuHeight;
					lvclmn.fmt = lvclmn.iSubItem == CID_ORDER ? HDF_SORTDOWN|LVCFMT_LEFT : LVCFMT_LEFT;

					ListView_InsertColumn(hwnd, lvclmn.iSubItem, &lvclmn);
				} while (++lvclmn.iSubItem < _countof(headers));

				ListView_SetExtendedListViewStyle(hwnd, LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP|LVS_EX_DOUBLEBUFFER);
			}
		}

		return hwnd;
	}

	void OnCopy(HWND hwnd)
	{
		if (_iSelItem < _cItems)
		{
			if (PROCESS_MODULE** ppm = _ppm)
			{
				PROCESS_MODULE* pm = ppm[_iSelItem];

				PWSTR buf = 0;
				int cch = 0;
				ULONG cb;
				HGLOBAL hg = 0;

				PVOID args[] = { pm->ImageBase, (PVOID)(ULONG_PTR)pm->ImageSize, (PVOID)pm->FullPathName };
				while (0 < (cch = _vsnwprintf(buf, cch, L"%p %x %S", (va_list)args)))
				{
					if (buf)
					{
						if (OpenClipboard(hwnd))
						{
							EmptyClipboard();
							if (SetClipboardData(CF_UNICODETEXT, hg)) hg = 0;
							CloseClipboard();
						}
						break;
					}

					if (!(hg = GlobalAlloc(GMEM_MOVEABLE, cb = ++cch * sizeof(WCHAR))) ||
						!(buf = (PWSTR)GlobalLock(hg)))
					{
						break;
					}

				}
				if (buf) GlobalUnlock(hg);
				if (hg) GlobalFree(hg);
			}
		}
	}

	void ShowOwnedProcesses(HWND hwndParent)
	{
		if (_iSelItem < _cItems)
		{
			if (PVOID buf = LocalAlloc(0, 0x10000))
			{
				PWSTR psz = (PWSTR)buf;
				ULONG cch = 0x8000;
				*psz = 0;

				PROCESS_MODULE* pm = _ppm[_iSelItem];
				PCSTR FullPathName = pm->FullPathName;

				ULONG NextEntryOffset = 0;
				PSYSTEM_PROCESS_INFORMATION pspi = _pspi;

				do 
				{
					(ULONG_PTR&)pspi += NextEntryOffset;

					ULONG n;
					if (PROCESS_MODULE* pm = get_modules(pspi, &n))
					{
						do 
						{
							if (pm->FullPathName == FullPathName)
							{
								int len = swprintf_s(psz, cch, L"%04x %wZ\r\n", (ULONG)(ULONG_PTR)pspi->UniqueProcessId, &pspi->ImageName);
								if (0 < len)
								{
									psz += len, cch -= len;
								}
								break;
							}
						} while (pm++, --n);
					}

				} while (NextEntryOffset = pspi->NextEntryOffset);

				PCSTR FileName = strrchr(FullPathName, '\\');

				if (!FileName && !(FileName = strrchr(FullPathName, '/')))
				{
					FileName = FullPathName;
				}
				else
				{
					FileName++;
				}

				if (HWND hwnd = CreateToolWnd( FileName, hwndParent))
				{
					SendMessage(hwnd, WM_SETFONT, (WPARAM)_hFont, 0);

					SetEditText(hwnd, buf), buf = 0;
					ShowWindow(hwnd, SW_SHOW);
				}

				LocalFree(buf);
			}
		}
	}

	~MySplit()
	{
		if (HIMAGELIST himl = _himl)
		{
			ImageList_Destroy(_himl);
		}
	}

public:

	MySplit(int t) : ZSplitWndV(t)
	{
		static WORD id[] = { IDR_MENU1 };
		_himl = CreateIL((HINSTANCE)&__ImageBase, 16, 16, ILC_COLOR32, RTL_NUMBER_OF(id), id);
	}
};

void ShowPolicy(HWND hWndParent, HFONT hFont);
void ShowProtectedProcesses(HWND hwnd, HFONT hFont);

struct Sort 
{
	int s;
	union {
		ULONG iSubItem;
		Colum c;
	};

	static int CompareU(ULONG_PTR a, ULONG_PTR b)
	{
		if (a < b) return -1;
		if (a > b) return +1;
		return 0;
	}

	int Compare(PROCESS_MODULE* p, PROCESS_MODULE* q)
	{
		switch (c)
		{
		case CID_ORDER:
			return CompareU(p->Index, q->Index);
		case CID_COUNT:
			return CompareU(GetLoadCount(p), GetLoadCount(q));
		case CID_BASE:
			return CompareU((ULONG_PTR)p->ImageBase, (ULONG_PTR)q->ImageBase);
		case CID_SIZE:
			return CompareU(p->ImageSize, q->ImageSize);
		case CID_NAME:
			return strcmp(p->FullPathName, q->FullPathName);
		}

		return 0;
	}

	static int __cdecl FuncCompare(void * This, const void * p, const void * q)
	{
		return reinterpret_cast<Sort*>(This)->s * 
			reinterpret_cast<Sort*>(This)->Compare(*(PROCESS_MODULE**)p, *(PROCESS_MODULE**)q);
	}
};

void MySplit::ColumClick(HWND hwndLV, ULONG iSubItem)
{
	if (iSubItem < CID_MAX)
	{
		if (!_pspiCurrent)
		{
			switch (iSubItem)
			{
			case CID_ORDER:
			case CID_BASE:
				return ;
			}
		}

		if (PROCESS_MODULE** ppm = _ppm)
		{
			Sort ctx { _bittestandcomplement(&_sortBits, iSubItem) ? +1 : -1, iSubItem };

			qsort_s(ppm, _cItems, sizeof(PVOID), Sort::FuncCompare, &ctx);

			LVCOLUMN lc = { LVCF_FMT, LVCFMT_LEFT };

			if (_iSubItem != iSubItem)
			{
				ListView_SetColumn(hwndLV, _iSubItem, &lc);
				_iSubItem = iSubItem;
			}

			lc.fmt = 0 < ctx.s ? LVCFMT_LEFT|HDF_SORTUP : LVCFMT_LEFT|HDF_SORTDOWN;

			ListView_SetColumn(hwndLV, iSubItem, &lc);

			InvalidateRect(hwndLV, 0, 0);
		}
	}
}

void MySplit::ItemChanged(NMLISTVIEW* item)
{
	UINT uNewState = item->uNewState;

	if (0 <= item->iItem)
	{
		if (uNewState & LVIS_FOCUSED)
		{
			_bittestandset(&_flags, f_focus);
		}
		else 
		{
			_bittestandreset(&_flags, f_focus);
		}
	}

	if (_bittest(&_flags, f_focus))
	{
		ZSDIFrameWnd* frame = ZGLOBALS::getMainFrame();

		if (uNewState & LVIS_SELECTED)
		{
			_iSelItem = item->iItem;

			if (!_bittestandset(&_flags, f_select))
			{
				frame->EnableCmd(ID_COPY, TRUE);
				frame->EnableCmd(ID_FIND, TRUE);
			}
		}
		else
		{
			_iSelItem = MAXULONG;
			if (_bittestandreset(&_flags, f_select))
			{
				frame->EnableCmd(ID_COPY, FALSE);
				frame->EnableCmd(ID_FIND, FALSE);
			}
		}
	}
}

void MySplit::GetInfoTip(NMTVGETINFOTIP* item)
{
	if (ULONG cchTextMax = item->cchTextMax)
	{
		PWSTR pszText = item->pszText;

		union {
			LPARAM lParam;
			PSYSTEM_PROCESS_INFORMATION pspi;
		};

		lParam = item->lParam;

		if (0 > lParam)
		{
			FormatStatus(STATUS_PROCESS_IS_TERMINATING, pszText, cchTextMax);
			return ;
		}

		if (!lParam)
		{
			return ;
		}

		if (PCSTR psz = get_cmdline(pspi))
		{
			MultiByteToWideChar(CP_UTF8, 0, psz, MAXULONG, pszText, cchTextMax);
			return ;
		}
	}
}

void MySplit::GetDispInfo(LVITEMW* item)
{
	if (PROCESS_MODULE** ppm = _ppm)
	{
		if (item->mask & LVIF_TEXT)
		{
			ULONG iItem = item->iItem;

			if (iItem < _cItems)
			{
				if (ULONG cchTextMax = item->cchTextMax)
				{
					PWSTR pszText = item->pszText;

					*pszText = 0;

					PROCESS_MODULE* pm = ppm[iItem];

					switch (item->iSubItem)
					{
					case CID_ORDER:
						if (_pspiCurrent) swprintf_s(pszText, cchTextMax, L"%03u", pm->Index);
						break;
					case CID_COUNT:
						swprintf_s(pszText, cchTextMax, L"%03u", GetLoadCount(pm));
						break;
					case CID_BASE:
						if (_pspiCurrent) swprintf_s(pszText, cchTextMax, L"%p", pm->ImageBase);
						break;
					case CID_SIZE:
						swprintf_s(pszText, cchTextMax, L"%8x", pm->ImageSize);
						break;
					case CID_NAME:
						swprintf_s(pszText, cchTextMax, L"%S", pm->FullPathName);
						break;
					}
				}
			}
		}
	}
}

void MySplit::GetDispInfo(TVITEMW* item)
{
	if (item->mask & TVIF_TEXT)
	{
		if (ULONG cchTextMax = item->cchTextMax)
		{
			PWSTR pszText = item->pszText;

			union {
				LPARAM lParam;
				PSYSTEM_PROCESS_INFORMATION pspi;
			};

			if (0 > (lParam = item->lParam))
			{
				swprintf_s(pszText, cchTextMax, L"%x", (ULONG)(ULONG_PTR)-lParam);
			}
			else if (0 < lParam)
			{
				if (0 > swprintf_s(pszText, cchTextMax, L"%04x %wZ", (ULONG)(ULONG_PTR)pspi->UniqueProcessId, &pspi->ImageName))
				{
					__debugbreak();
				}
			}
			else
			{
				wcscpy_s(pszText, cchTextMax, L"ALL");
			}
		}
	}
}

void MySplit::OnTaskReady(ULONG n, PSYSTEM_PROCESS_INFORMATION pspi)
{
	if (pspi)
	{
		_pspi = pspi;
		InitTreeView(_hwndTV, pspi);
	}

	Done(n);
}

LRESULT MySplit::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_NCCREATE:
		if (!OnCreate(hwnd))
		{
			return 0;
		}
		break;

	case WM_NCDESTROY:
		OnDestroy();
		break;

	case WM_COMMAND:
		switch (wParam)
		{
		case ID_REFRESH:
			BuildProcessList();
			break;

		case ID_GRID:
			ListView_SetExtendedListViewStyle(_hwndLV, _bittestandcomplement(&_flags, f_grid) ? 
				LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP|LVS_EX_DOUBLEBUFFER
				: LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP|LVS_EX_DOUBLEBUFFER);
			break;

		case ID_COPY:
			OnCopy(hwnd);
			break;

		case ID_FIND:
			ShowOwnedProcesses(hwnd);
			break;

		case ID_PROTECTED:
			ShowProtectedProcesses(ZGLOBALS::get()->getMainHWND(), _hFont);
			break;
		
		case ID_SESSIONS:
			ShowPopup(L"Logon Sessions", ZGLOBALS::get()->getMainHWND(), _hFont, ShowSessions);
			break;

		case ID_POLICY:
			ShowPolicy(ZGLOBALS::get()->getMainHWND(), _hFont);
			break;

		case ID_CMDLINE:
			if (_pspiCurrent)
			{
				ShowCmdLineEx(get_cmdline(_pspiCurrent), _pspiCurrent->UniqueProcessId, hwnd, _hFont);
			}
			break;
		}
		break;

	case WM_PSI_READY:
		OnTaskReady((ULONG)wParam, (PSYSTEM_PROCESS_INFORMATION)lParam);
		break;

	case WM_NOTIFY:
		switch (((NMHDR*)lParam)->code)
		{
		case TVN_GETDISPINFOW:
			if (!_bittest(&_flags, f_inDelete)) 
			{
				GetDispInfo(&((LPNMTVDISPINFO)lParam)->item);
			}
			break;

		case TVN_SELCHANGED:
			if (!_bittest(&_flags, f_inDelete)) 
			{
				DisplayDLLs(((LPNMTREEVIEW)lParam)->itemNew.lParam);
			}
			break;

		case TVN_GETINFOTIP:
			if (!_bittest(&_flags, f_inDelete)) 
			{
				GetInfoTip((NMTVGETINFOTIP*)lParam);
			}
			break;

		case LVN_GETDISPINFO:
			GetDispInfo(&((NMLVDISPINFO*)lParam)->item);
			break;

		case LVN_COLUMNCLICK:
			ColumClick(((LPNMLISTVIEW)lParam)->hdr.hwndFrom, ((LPNMLISTVIEW)lParam)->iSubItem);
			break;

		case LVN_ITEMCHANGED:
			ItemChanged((LPNMLISTVIEW)lParam);
			break;
		}
	}
	return ZSplitWndV::WindowProc(hwnd, uMsg, wParam, lParam);
}

class ZMainWnd : public ZSDIFrameWnd
{
	HWND _hwnd;
	LONG _maskCurrent, _maskNew;

	virtual LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual BOOL CreateSB(HWND hwnd);
	virtual BOOL CreateTB(HWND hwnd);

	virtual PCUNICODE_STRING getPosName()
	{
		STATIC_UNICODE_STRING_(MainWnd);
		return &MainWnd;
	}

	virtual BOOL CreateClient(HWND hwnd, int x, int y, int nWidth, int nHeight)
	{
		if (MySplit* p = new MySplit(nWidth>>2))
		{
			_hwnd = p->Create(0, 0, WS_CHILD|WS_VISIBLE|WS_BORDER, x - 1, y, nWidth + 2, nHeight + 1, hwnd, 0, 0);
			p->Release();
		}

		return _hwnd != 0;
	}
};

BOOL ZMainWnd::CreateSB(HWND hwnd)
{
	if (hwnd = ZStatusBar::Create(hwnd))
	{
		NONCLIENTMETRICS ncm = { sizeof(NONCLIENTMETRICS) };
		if (SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(ncm), &ncm, 0))
		{
			int pp[] = { 5*ncm.iMenuHeight, 9*ncm.iMenuHeight, 32*ncm.iMenuHeight, -1 };
			SetParts(pp, _countof(pp));
		}

		return TRUE;
	}
	return FALSE;
}

BOOL ZMainWnd::CreateTB(HWND hwnd)
{
	static TBBUTTON g_btns[] = {
		{IMAGE_BITMAP, ID_REFRESH, 0, BTNS_AUTOSIZE, {}, (DWORD_PTR)L" Refresh ", -1},
		{IMAGE_BITMAP, ID_CMDLINE, 0, BTNS_AUTOSIZE, {}, (DWORD_PTR)L" Command Line ", -1},
		{IMAGE_BITMAP, ID_GRID, TBSTATE_ENABLED, BTNS_AUTOSIZE, {}, (DWORD_PTR)L" Display Grid ", -1},
		{IMAGE_BITMAP, ID_COPY, 0, BTNS_AUTOSIZE, {}, (DWORD_PTR)L" Copy Name ", -1},
		{IMAGE_BITMAP, ID_FIND, 0, BTNS_AUTOSIZE, {}, (DWORD_PTR)L" Find ", -1},
		{IMAGE_BITMAP, ID_PROTECTED, TBSTATE_ENABLED, BTNS_AUTOSIZE, {}, (DWORD_PTR)L" Protected List ", -1},
		{IMAGE_BITMAP, ID_SESSIONS, TBSTATE_ENABLED, BTNS_AUTOSIZE, {}, (DWORD_PTR)L" Logon Sessions ", -1},
		{IMAGE_BITMAP, ID_POLICY, TBSTATE_ENABLED, BTNS_AUTOSIZE, {}, (DWORD_PTR)L" Policy ", -1},
	};

	return ZToolBar::Create(hwnd, (HINSTANCE)&__ImageBase, 0, 0, 16, 16, 
		g_btns, g_nt_ver.Version < _WIN32_WINNT_WIN8 ? _countof(g_btns) - 1 : _countof(g_btns), TRUE) != 0;
}

LRESULT ZMainWnd::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		SendMessage(_hwnd, WM_COMMAND, wParam, 0);
		break;
	}
	return ZSDIFrameWnd::WindowProc(hwnd, uMsg, wParam, lParam);
}

void zmain()
{
	ZGLOBALS globals;
	ZApp app;
	ZRegistry reg;

	if (0 <= reg.Create(L"Software\\{9618DB6D-97D9-4ded-A8E7-422E46BD9C87}"))
	{
		HWND hwnd = 0;

		if (ZMainWnd* p = new ZMainWnd)
		{
			hwnd = p->ZSDIFrameWnd::Create(L"Processes Tree | Dll List", (HINSTANCE)&__ImageBase, MAKEINTRESOURCE(IDR_MENU1), TRUE);

			p->Release();
		}

		if (hwnd)
		{
			app.Run();
		}
	}
}

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
		status = NtAdjustPrivilegesToken(hToken, FALSE, const_cast<PTOKEN_PRIVILEGES>(&tp), 0, 0, 0);
		NtClose(hToken);
	}
	return status;
}

void InitDriver();
void InitWow64();

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

	AdjustPrivileges();

	InitDriver();

	initterm();
	zmain();

	destroyterm();

	ExitProcess(0);
}

_NT_END