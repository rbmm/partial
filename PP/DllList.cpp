// PeVw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

_NT_BEGIN
#include "../inc/initterm.h"
#include "common.h"
#include "../winz/split.h"
#include "task.h"

HANDLE g_hDrv;

ULONG gNtVersion;

#include "../tkn/tkn.h"

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
		NTSTATUS status = NtDeviceIoControlFile(g_hDrv, 0, 0, 0, &iosb, IOCTL_OpenProcess, &Cid->UniqueProcess, sizeof(HANDLE), 0, 0);
		*ProcessHandle = (HANDLE)iosb.Information;
		return status;
	}
	return NtOpenProcess(ProcessHandle, DesiredAccess, ObjectAttributes, Cid);
}

//#undef DbgPrint
#pragma warning(disable : 4456)
volatile UCHAR guz;
OBJECT_ATTRIBUTES zoa = { sizeof(zoa) };
WorkQueue g_queue;

#define SB_READYID 0
#define SB_COUNTID 1
#define SB_INFOID 2
#define SB_STATUSID 3

struct PROCESS_MODULES // embeded in SYSTEM_PROCESS_INFORMATION.SpareLi1
{
	NTSTATUS status;
	ULONG NumberOfModules;
	PRTL_PROCESS_MODULE_INFORMATION Modules;

	PROCESS_MODULES()
	{
		status = STATUS_PENDING;
		NumberOfModules = 0;
		Modules = 0;
	}

	~PROCESS_MODULES()
	{
		if (Modules)
		{
			delete Modules;
		}
	}

	void Reset()
	{
		if (Modules)
		{
			delete Modules;
			Modules = 0;
		}
		status = STATUS_PENDING;
		NumberOfModules = 0;
	}

	static PROCESS_MODULES* get(PSYSTEM_PROCESS_INFORMATION pspi)
	{
		return (PROCESS_MODULES*)&pspi->SpareLi1;
	}

	void* operator new(size_t, PSYSTEM_PROCESS_INFORMATION pspi)
	{
		return get(pspi);
	}

	void operator delete(void*)
	{
	}
};

GLOBALS_EX::GLOBALS_EX()
{
	_hDlgFont = 0;
	NONCLIENTMETRICS ncm = { GetNONCLIENTMETRICSWSize() };
	if (SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(ncm), &ncm, 0))
	{
		wcscpy(ncm.lfMessageFont.lfFaceName, L"Courier New");
		ncm.lfMessageFont.lfHeight = -ncm.iMenuHeight;
		_hDlgFont = CreateFontIndirectW(&ncm.lfMessageFont);
	}
}

GLOBALS_EX::~GLOBALS_EX()
{
	if (_hDlgFont)
	{
		DeleteObject(_hDlgFont);
	}
}

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

// since WINBLUE (8.1)
NTSTATUS ShowCmdLine8(HANDLE UniqueProcess, HWND hwnd)
{
	HANDLE hProcess;
	CLIENT_ID cid = { UniqueProcess };

	NTSTATUS status = NtOpenProcess(&hProcess, PROCESS_QUERY_LIMITED_INFORMATION, &zoa, &cid);

	if (0 <= status)
	{
		PVOID stack = alloca(sizeof(WCHAR));

		union {
			PVOID buf;
			PUNICODE_STRING CmdLine;
		};

		ULONG cb = 0, rcb = 512;

		do 
		{
			if (cb < rcb) cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);

			if (0 <= (status = NtQueryInformationProcess(hProcess, ProcessCommandLineInformation, buf, cb, &rcb)))
			{
				*(PWSTR)RtlOffsetToPointer(CmdLine->Buffer, CmdLine->Length) = 0;
				SetWindowTextW(hwnd, CmdLine->Buffer);
				break;
			}

		} while (status == STATUS_INFO_LENGTH_MISMATCH);

		NtClose(hProcess);
	}

	return status;
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
			PWSTR psz;
		};

		if (
			0 <= (status = NtQueryInformationProcess(hProcess, ProcessBasicInformation, &pbi, sizeof(pbi), 0)) &&
			0 <= (status = ZwReadVirtualMemory(hProcess, &((_PEB*)pbi.PebBaseAddress)->ProcessParameters, &ProcessParameters, sizeof(ProcessParameters), 0)) &&
			0 <= (status = ZwReadVirtualMemory(hProcess, &ProcessParameters->CommandLine, &CmdLine, sizeof(CmdLine), 0)) &&
			0 <= (status = ZwReadVirtualMemory(hProcess, CmdLine.Buffer, buf = alloca(CmdLine.Length + sizeof(WCHAR)), CmdLine.Length, 0))
			)
		{
			*(PWSTR)RtlOffsetToPointer(buf, CmdLine.Length) = 0;
			SetWindowTextW(hwnd, psz);
		}

		NtClose(hProcess);
	}

	return status;
}

NTSTATUS (*ShowCmdLine)(HANDLE UniqueProcess, HWND hwnd);

void ShowCmdLineEx(HANDLE UniqueProcess, HWND hwndParent, HFONT hFont)
{
	WCHAR caption[32];
	swprintf(caption, L"%X Process CmdLine", (DWORD)(ULONG_PTR)UniqueProcess);
	if (HWND hwnd = CreateWindowExW(0, WC_EDIT, caption, WS_OVERLAPPEDWINDOW|WS_VSCROLL|ES_MULTILINE|ES_READONLY,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hwndParent, 0, 0, 0))
	{
		SendMessage(hwnd, WM_SETFONT, (WPARAM)hFont, 0);

		ShowCmdLine(UniqueProcess, hwnd);

		ShowWindow(hwnd, SW_SHOWNORMAL);
	}
}

void InitShowCmdLine()
{
	ShowCmdLine = gNtVersion < _WIN32_WINNT_WINBLUE ? ShowCmdLineOld : ShowCmdLine8;
}

class ZMyApp : public ZApp, public DLL_TASK
{
	virtual DWORD GetWaitHandles(HANDLE ** ppHandles);
	virtual void OnSignalObject(DWORD i);
};

#define PARENT_SPI(pspi) (*(PSYSTEM_PROCESS_INFORMATION*)&(pspi)->SpareLi1)
#define SPI_HTREEITEM(pspi) (*(HTREEITEM*)&(pspi)->PageDirectoryBase)

void InitTreeView(DLL_TASK* task, HWND hwnd, PSYSTEM_PROCESS_INFORMATION pspi)
{
	ULONG NextEntryOffset = 0;

	TVINSERTSTRUCT tvis;
	tvis.hInsertAfter = TVI_LAST;
	tvis.item.mask = TVIF_PARAM|TVIF_TEXT|TVIF_STATE|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvis.item.state = TVIS_EXPANDED;
	tvis.item.stateMask = TVIS_EXPANDED;
	tvis.item.iImage =  I_IMAGENONE;
	tvis.item.iSelectedImage = 0;

	tvis.hParent = TVI_ROOT;
	tvis.item.pszText = L"All DLLs";
	tvis.item.lParam = 0;
	TreeView_InsertItem(hwnd, &tvis);

	tvis.item.pszText = LPSTR_TEXTCALLBACK;

	task->BeginTasks();

	do 
	{
		pspi = (PSYSTEM_PROCESS_INFORMATION)RtlOffsetToPointer(pspi, NextEntryOffset);

		PSYSTEM_PROCESS_INFORMATION parent = PARENT_SPI(pspi);

		PROCESS_MODULES* ppm = new(pspi) PROCESS_MODULES;

		if (pspi->UniqueProcessId)
		{
			tvis.hParent = parent ? SPI_HTREEITEM(parent) : TVI_ROOT;

			tvis.item.lParam = (LPARAM)pspi;

			SPI_HTREEITEM(pspi) = TreeView_InsertItem(hwnd, &tvis);

			ppm->status = STATUS_PENDING;
			task->QueueTask(&g_queue, pspi);
		}
		else
		{
			SPI_HTREEITEM(pspi) = TVI_ROOT;
		}

	} while (NextEntryOffset = pspi->NextEntryOffset);

	task->EndTasks();
}

void InitProcessTree(PSYSTEM_PROCESS_INFORMATION pspi, ULONG& ProcessCount, ULONG& NameLengths)
{
	PSYSTEM_PROCESS_INFORMATION _pspi = pspi;

	ULONG NextEntryOffset = 0, n = 0, len = 0;

	do 
	{
		pspi = (PSYSTEM_PROCESS_INFORMATION)RtlOffsetToPointer(pspi, NextEntryOffset);

		PARENT_SPI(pspi) = 0;

		if (pspi->UniqueProcessId)
		{
			n++, len += pspi->ImageName.Length;
		}

		if (HANDLE InheritedFromUniqueProcessId = pspi->InheritedFromUniqueProcessId)
		{
			PSYSTEM_PROCESS_INFORMATION p = _pspi;

			ULONG NextEntryOffset = 0;

			do 
			{
				p = (PSYSTEM_PROCESS_INFORMATION)RtlOffsetToPointer(p, NextEntryOffset);

				if (p->UniqueProcessId == InheritedFromUniqueProcessId)
				{
					PARENT_SPI(pspi) = p;
					break;
				}

				NextEntryOffset = p->NextEntryOffset;

			} while (p != pspi);
		}

	} while (NextEntryOffset = pspi->NextEntryOffset);

	ProcessCount = n, NameLengths = len;
}

PSYSTEM_PROCESS_INFORMATION EnumProcesses(DLL_TASK* task, HWND hwnd, ULONG& ProcessCount, ULONG& NameLengths)
{
	NTSTATUS status;
	DWORD cb = 0x10000;

	do 
	{
		status = STATUS_INSUFFICIENT_RESOURCES;

		if (PSYSTEM_PROCESS_INFORMATION pspi = (PSYSTEM_PROCESS_INFORMATION)new UCHAR[cb])
		{
			if (0 <= (status = NtQuerySystemInformation(SystemProcessInformation, pspi, cb, &cb)))
			{
				InitProcessTree(pspi, ProcessCount, NameLengths);
				InitTreeView(task, hwnd, pspi);
				return pspi;
			}
			delete pspi;
		}

	} while (status == STATUS_INFO_LENGTH_MISMATCH);

	return 0;
}

PRTL_PROCESS_MODULE_INFORMATION FreeTable(PRTL_BALANCED_LINKS prbl, PRTL_PROCESS_MODULE_INFORMATION prpmi)
{
	if (prbl)
	{
		prpmi = FreeTable(prbl->LeftChild, prpmi);
		if (prpmi)
		{
			*prpmi++ = **(PRTL_PROCESS_MODULE_INFORMATION*)(prbl + 1);
		}
		prpmi = FreeTable(prbl->RightChild, prpmi);
		LocalFree(prbl);
	}

	return prpmi;
}

class MySplit : public ZSplitWndV, RTL_AVL_TABLE 
{
	PSYSTEM_PROCESS_INFORMATION _pspi, _pspiCurrent;
	PROCESS_MODULES* _ppm;
	PROCESS_MODULES _pm;
	HIMAGELIST _himl;
	HWND _hwndLV, _hwndTV;
	ULONG _nSelColum, _iSelItem, _ProcessCount, _NameLengths;
	LONG _sortBits, _flags;

	enum{
		f_ready, f_grid, f_inDelete, f_focus, f_select
	};

	void FreeTableAndFill(PRTL_PROCESS_MODULE_INFORMATION prpmi)
	{
		FreeTable(BalancedRoot.RightChild, FreeTable(BalancedRoot.LeftChild, prpmi));
		RtlInitializeGenericTableAvl(this, (PRTL_AVL_COMPARE_ROUTINE)Compare, Alloc, Free, 0);
	}

	static RTL_GENERIC_COMPARE_RESULTS NTAPI Compare(PRTL_AVL_TABLE , PVOID FirstStruct, PVOID SecondStruct)
	{
		PRTL_PROCESS_MODULE_INFORMATION p = *(PRTL_PROCESS_MODULE_INFORMATION*)FirstStruct, q = *(PRTL_PROCESS_MODULE_INFORMATION*)SecondStruct;

		int i = _stricmp(p->FullPathName, q->FullPathName);

		if (0 > i) return GenericLessThan;
		if (0 < i) return GenericGreaterThan;
		return GenericEqual;
	}

	static PVOID NTAPI Alloc(PRTL_AVL_TABLE, CLONG ByteSize)
	{
		return LocalAlloc(0, ByteSize);
	}

	static VOID NTAPI Free(PRTL_AVL_TABLE , PVOID Buffer)
	{
		LocalFree(Buffer);
	}

	void DeleteSPI()
	{
		_pm.Reset();

		if (PSYSTEM_PROCESS_INFORMATION pspi = _pspi)
		{
			ULONG NextEntryOffset = 0;

			do 
			{
				pspi = (PSYSTEM_PROCESS_INFORMATION)RtlOffsetToPointer(pspi, NextEntryOffset);

				delete PROCESS_MODULES::get(pspi);

			} while (NextEntryOffset = pspi->NextEntryOffset);

			delete _pspi;
		}
	}

	void BuildProcessList()
	{
		if (_bittest(&_flags, f_ready))
		{
			_bittestandreset(&_flags, f_ready);
			
			GLOBALS_EX* globals = static_cast<GLOBALS_EX*>(ZGLOBALS::get());

			ZSDIFrameWnd* pFrame = globals->MainFrame;
			
			pFrame->SetStatusText(SB_READYID, L"...");
			pFrame->SetStatusText(SB_INFOID, L"");

			pFrame->EnableCmd(ID_SESSIONS, FALSE);
			pFrame->EnableCmd(ID_REFRESH, FALSE);
			pFrame->EnableCmd(ID_COPY, FALSE);
			pFrame->EnableCmd(ID_FIND, FALSE);
			pFrame->EnableCmd(ID_CMDLINE, FALSE);

			_iSelItem = MAXDWORD, _pspiCurrent = 0;

			_flags &= ~((1 << f_select) | (1 << f_focus));

			_bittestandset(&_flags, f_inDelete);
			TreeView_DeleteAllItems(_hwndTV);
			_bittestandreset(&_flags, f_inDelete);

			ListView_SetItemCountEx(_hwndLV, 0, 0);

			DeleteSPI();

			_ppm = 0;

			DLL_TASK* task = static_cast<ZMyApp*>(globals->App);
			
			DoIoControl(IOCTL_SetProtectedProcess);

			_pspi = EnumProcesses(task, _hwndTV, _ProcessCount, _NameLengths);

			WCHAR sz[32];
			swprintf(sz, L"Processes=%u", _ProcessCount);
			pFrame->SetStatusText(SB_COUNTID, sz);

			if (task->IsAllTasksDone())
			{
				Done();
			}
		}
	}

	void Done()
	{
		DoIoControl(IOCTL_DelProtectedProcess);
		ZSDIFrameWnd* pFrame = ZGLOBALS::getMainFrame();
		pFrame->SetStatusText(SB_READYID, L"Ready");
		pFrame->EnableCmd(ID_REFRESH, TRUE);
		pFrame->EnableCmd(ID_SESSIONS, TRUE);
		_bittestandset(&_flags, f_ready);
	}

	void OnTaskReady(HWND /*hwnd*/, PROCESS_MODULES* ppm, BOOL bFinished)
	{
		ULONG NumberOfModules;

		if (0 <= ppm->status && ppm->status != STATUS_TIMEOUT)
		{
			if (NumberOfModules = ppm->NumberOfModules)
			{
				PRTL_PROCESS_MODULE_INFORMATION Module = ppm->Modules, *pModule, _Module;
				do 
				{
					BOOLEAN bNew;
					Module->LoadCount = 1;
					Module->MappedBase = Module->ImageBase;

					if (pModule = (PRTL_PROCESS_MODULE_INFORMATION*)RtlInsertElementGenericTableAvl(this, &Module, sizeof(PVOID), &bNew))
					{
						Module->Section = _Module = *pModule;

						if (!bNew)
						{
							_Module->LoadCount++;
						}

						if (_Module->MappedBase != Module->MappedBase)
						{
							_Module->MappedBase = 0;
						}
					}

				} while (++Module, --NumberOfModules);
			}
		}

		if (ppm == _ppm)
		{
			_DisplayDLLs(ppm);
		}

		if (bFinished)
		{
			if (NumberOfModules = RtlNumberGenericTableElementsAvl(this))
			{
				if (PRTL_PROCESS_MODULE_INFORMATION Modules = new RTL_PROCESS_MODULE_INFORMATION[NumberOfModules])
				{
					_pm.Modules = Modules;
					_pm.status = 0;
					_pm.NumberOfModules = NumberOfModules;

					FreeTableAndFill(Modules);

					USHORT Index = 0;
					do 
					{
						Modules++->InitOrderIndex = Index++;
					} while (--NumberOfModules);
				}
				else
				{
					_pm.status = STATUS_INSUFFICIENT_RESOURCES;
				}
			}

			if (_ppm == &_pm)
			{
				_DisplayDLLs(&_pm);
			}

			Done();
		}
	}

	void DisplayDLLs(PSYSTEM_PROCESS_INFORMATION pspi)
	{
		_pspiCurrent = pspi;
		WCHAR buf[128];

		PROCESS_MODULES* ppm;

		if (pspi)
		{
			TIME_FIELDS tf;
			LARGE_INTEGER locatime;
			RtlSystemTimeToLocalTime(&pspi->CreateTime, &locatime);
			RtlTimeToTimeFields(&locatime, &tf);

			char sz[32];
			DWORD s = (DWORD)(pspi->WorkingSetSize >> 10);
			if (s < 1000)
			{
				sprintf(sz, "%u", s);
			}
			else
			{
				sprintf(sz, "%u,%03u", s /1000, s % 1000);
			}
			swprintf(buf, L"Threads=%d | Session=%u | Handles=%u | %SK | %d-%02d-%02d %02d:%02d:%02d",
				pspi->NumberOfThreads, pspi->SessionId, pspi->HandleCount,
				sz, 
				tf.Year, tf.Month, tf.Day, tf.Hour, tf.Minute, tf.Second);

			ppm = PROCESS_MODULES::get(pspi);
		}
		else
		{
			swprintf(buf, L"%u DLLs", _pm.NumberOfModules);
			ppm = &_pm;
		}

		ZGLOBALS::getMainFrame()->SetStatusText(SB_INFOID, buf);

		_DisplayDLLs(ppm);
	}

	void _DisplayDLLs(PROCESS_MODULES* ppm)
	{
		ListView_DeleteAllItems(_hwndLV);

		_ppm = ppm;

		ULONG NumberOfModules = 0;

		NTSTATUS status = ppm->status;

		if (0 <= status)
		{
			switch (status)
			{
			case STATUS_PENDING:
			case STATUS_TIMEOUT:
				break;
			default:
				NumberOfModules = ppm->NumberOfModules;
			}
		}

		WCHAR msg[256];
		if (status)
		{
			if (!FormatMessageW(FORMAT_MESSAGE_FROM_HMODULE|FORMAT_MESSAGE_IGNORE_INSERTS, 
				GetModuleHandleW(L"ntdll"), status, 0, msg, _countof(msg), 0))
			{
				swprintf(msg, L"%x", status);
			}
		}
		else
		{
			msg[0] = 0;
		}

		ZGLOBALS::getMainFrame()->SetStatusText(SB_STATUSID, msg);

		ListView_SetItemCountEx(_hwndLV, NumberOfModules, 0);
	}

	virtual LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual HWND CreateChild(BOOL lt, HWND hwndParent, int x, int y, int nWidth, int nHeight)
	{
		HWND hwnd = 0;

		GLOBALS_EX* globals = static_cast<GLOBALS_EX*>(ZGLOBALS::get());
		HFONT hfont = globals->_hDlgFont;

		if (lt)
		{
			if (hwnd = CreateWindowExW(0, WC_TREEVIEW, 0, WS_CHILD|WS_VISIBLE|
				TVS_LINESATROOT|TVS_HASLINES|TVS_HASBUTTONS|TVS_DISABLEDRAGDROP|
				TVS_TRACKSELECT|TVS_EDITLABELS, x, y, nWidth, nHeight, hwndParent, (HMENU)1, 0, 0))
			{
				if (hfont) SendMessage(hwnd, WM_SETFONT, (WPARAM)hfont, 0);
				
				globals->_hwndTask = hwndParent;

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
				if (hfont) SendMessage(hwnd, WM_SETFONT, (WPARAM)hfont, 0);
				_hwndLV = hwnd;

				SIZE size = { 8, 16 };

				if (HDC hdc = GetDC(hwnd))
				{
					HGDIOBJ o = SelectObject(hdc, hfont);
					GetTextExtentPoint32(hdc, L"W", 1, &size);
					SelectObject(hdc, o);
					ReleaseDC(hwnd, hdc);
				}

				LV_COLUMN lvclmn = { LVCF_TEXT | LVCF_WIDTH };
				lvclmn.cx = 5 * size.cx;
				lvclmn.pszText = L" # ";
				ListView_InsertColumn(hwnd, lvclmn.iSubItem = 0, &lvclmn);
				lvclmn.pszText = L" N ";
				ListView_InsertColumn(hwnd, lvclmn.iSubItem = 1, &lvclmn);
				lvclmn.cx = (2+sizeof(PVOID)*2) * size.cx;
				lvclmn.pszText = L" Base ";
				ListView_InsertColumn(hwnd, lvclmn.iSubItem = 2, &lvclmn);
				lvclmn.cx = 10  * size.cx;
				lvclmn.pszText = L" Size ";
				ListView_InsertColumn(hwnd, lvclmn.iSubItem = 3, &lvclmn);
				lvclmn.cx = 128  * size.cx;
				lvclmn.pszText = L" Name ";
				ListView_InsertColumn(hwnd, lvclmn.iSubItem = 4, &lvclmn);

				ListView_SetExtendedListViewStyle(hwnd, LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP|LVS_EX_DOUBLEBUFFER);
			}
		}

		return hwnd;
	}

	void OnCopy(HWND hwnd)
	{
		if (_ppm && (_iSelItem < _ppm->NumberOfModules))
		{
			PRTL_PROCESS_MODULE_INFORMATION prpmi = &_ppm->Modules[_ppm->Modules[_iSelItem].InitOrderIndex];

			if (OpenClipboard(hwnd))
			{
				EmptyClipboard();
				WCHAR sz[512];
				DWORD cb = (1 + swprintf(sz, L"%p %x %S", prpmi->ImageBase, prpmi->ImageSize, prpmi->FullPathName)) << 1;
				if (HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, cb))
				{
					memcpy((PWSTR)GlobalLock(hg), sz, cb);
					GlobalUnlock(hg);
					if (!SetClipboardData(CF_UNICODETEXT, hg)) GlobalFree(hg);
				}
				CloseClipboard();
			}
		}
	}

	void ShowOwnedProcesses()
	{
		if (_ppm && (_iSelItem < _ppm->NumberOfModules))
		{
			PRTL_PROCESS_MODULE_INFORMATION Modules = &_ppm->Modules[_ppm->Modules[_iSelItem].InitOrderIndex];
			PCSTR FullPathName = Modules->FullPathName;

			GLOBALS_EX* globals = static_cast<GLOBALS_EX*>(ZGLOBALS::get());
			HFONT hfont = globals->_hDlgFont;

			if (HWND hwnd = CreateToolWnd(FullPathName + Modules->OffsetToFileName, globals->hwndMain))
			{
				if (hfont) SendMessage(hwnd, WM_SETFONT, (WPARAM)hfont, 0);

				PWSTR buf = (PWSTR)alloca(_NameLengths + _ProcessCount * 32), sz = buf;

				PSYSTEM_PROCESS_INFORMATION pspi = _pspi;

				ULONG NextEntryOffset = 0;

				do 
				{
					pspi = (PSYSTEM_PROCESS_INFORMATION)RtlOffsetToPointer(pspi, NextEntryOffset);

					PROCESS_MODULES* ppm = PROCESS_MODULES::get(pspi);

					if (ULONG NumberOfModules = ppm->NumberOfModules)
					{
						PRTL_PROCESS_MODULE_INFORMATION Modules = ppm->Modules;
						do 
						{
							if (!_stricmp(Modules->FullPathName, FullPathName))
							{
								sz += swprintf(sz, L"%04x %wZ\r\n", (ULONG)(ULONG_PTR)pspi->UniqueProcessId, &pspi->ImageName);
								break;
							}

						} while (Modules++, --NumberOfModules);
					}

				} while (NextEntryOffset = pspi->NextEntryOffset);

				SetWindowText(hwnd, buf);

				ShowWindow(hwnd, SW_SHOW);
			}
		}
	}

	~MySplit()
	{
		FreeTableAndFill(0);
		DeleteSPI();
		if (_himl)
		{
			ImageList_Destroy(_himl);
		}
	}

public:

	enum {
		WM_PSI_READY = WM_USER + 0x100
	};

	MySplit(int t) : ZSplitWndV(t)
	{
		_nSelColum = ~0UL;
		_pspiCurrent = 0;
		_pspi = 0;
		_ppm = 0;
		_flags = (1 << f_ready);
		_sortBits = 1;
		_iSelItem = MAXDWORD;
		RtlInitializeGenericTableAvl(this, (PRTL_AVL_COMPARE_ROUTINE)Compare, Alloc, Free, 0);
		static WORD id[] = { IDR_MENU1 };
		_himl = CreateIL((HINSTANCE)&__ImageBase, 16, 16, ILC_COLOR32, RTL_NUMBER_OF(id), id);
	}
};

int __cdecl sort0(PRTL_PROCESS_MODULE_INFORMATION& p, PRTL_PROCESS_MODULE_INFORMATION& q)
{
	int i = p->LoadOrderIndex, j = q->LoadOrderIndex;

	return i - j;
}

int __cdecl sort1(PRTL_PROCESS_MODULE_INFORMATION& p, PRTL_PROCESS_MODULE_INFORMATION& q)
{
	int i = ((PRTL_PROCESS_MODULE_INFORMATION)p->Section)->LoadCount, j = ((PRTL_PROCESS_MODULE_INFORMATION)q->Section)->LoadCount;

	return i - j;
}

int __cdecl sort2(PRTL_PROCESS_MODULE_INFORMATION& p, PRTL_PROCESS_MODULE_INFORMATION& q)
{
	PVOID i = p->ImageBase, j = q->ImageBase;

	if (i < j) return -1;
	if (i > j) return +1;
	return 0;
}

int __cdecl sort3(PRTL_PROCESS_MODULE_INFORMATION& p, PRTL_PROCESS_MODULE_INFORMATION& q)
{
	ULONG i = p->ImageSize, j = q->ImageSize;

	if (i < j) return -1;
	if (i > j) return +1;
	return 0;
}

int __cdecl sort4(PRTL_PROCESS_MODULE_INFORMATION& p, PRTL_PROCESS_MODULE_INFORMATION& q)
{
	return _stricmp(p->FullPathName, q->FullPathName);
}

void DoSort(PRTL_PROCESS_MODULE_INFORMATION Modules, DWORD NumberOfModules, int iKey, BOOL bReverseOrder)
{
	if (!NumberOfModules)
	{
		return ;
	}

	PVOID Buffer = alloca(NumberOfModules * sizeof(PVOID));

	PRTL_PROCESS_MODULE_INFORMATION* pModules = (PRTL_PROCESS_MODULE_INFORMATION*)Buffer, p = Modules;
	DWORD i = NumberOfModules;
	do 
	{
		*pModules++ = p++;
	} while (--i);

	static PVOID _sort[] = { sort0, sort1, sort2, sort3, sort4 };

	qsort(Buffer, NumberOfModules, sizeof(PVOID), QSORTFN(_sort[iKey]));

	pModules = (PRTL_PROCESS_MODULE_INFORMATION*)Buffer, p = Modules;

	if (bReverseOrder)
	{
		p = Modules + NumberOfModules;
		do 
		{
			(--p)->InitOrderIndex = (USHORT)(*pModules++ - Modules);
		} while (--NumberOfModules);
	}
	else
	{
		do 
		{
			p++->InitOrderIndex = (USHORT)(*pModules++ - Modules);
		} while (--NumberOfModules);
	}
}

void ShowPolicy(HWND hWndParent, HFONT hFont);
void ShowProtectedProcesses(HWND hwnd, HFONT hFont);

LRESULT MySplit::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PWSTR pszText;
	ULONG cchTextMax;
	ULONG iItem;
	PSYSTEM_PROCESS_INFORMATION pspi;
	PRTL_PROCESS_MODULE_INFORMATION prpmi;
	ZSDIFrameWnd* frame;
	GLOBALS_EX* globals;

	switch (uMsg)
	{
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
			ShowOwnedProcesses();
			break;

		case ID_PROTECTED:
			globals = static_cast<GLOBALS_EX*>(ZGLOBALS::get());
			ShowProtectedProcesses(globals->getMainHWND(), globals->_hDlgFont);
			break;
		
		case ID_SESSIONS:
			globals = static_cast<GLOBALS_EX*>(ZGLOBALS::get());
			ShowPopup(L"Logon Sessions", globals->getMainHWND(), globals->_hDlgFont, ShowSessions);
			break;

		case ID_POLICY:
			globals = static_cast<GLOBALS_EX*>(ZGLOBALS::get());
			ShowPolicy(globals->getMainHWND(), globals->_hDlgFont);
			break;

		case ID_CMDLINE:
			if (_pspiCurrent)
			{
				globals = static_cast<GLOBALS_EX*>(ZGLOBALS::get());
				ShowCmdLineEx(_pspiCurrent->UniqueProcessId, globals->getMainHWND(), globals->_hDlgFont);
			}
			break;
		}
		break;//IMAGE_IMPORT_BY_NAME

	case WM_PSI_READY:
		OnTaskReady(hwnd, (PROCESS_MODULES*)lParam, (BOOL)wParam);
		break;

	case WM_NOTIFY:
		switch (((NMHDR*)lParam)->code)
		{
		case TVN_GETDISPINFOW:
			if (((LPNMTVDISPINFO)lParam)->item.mask & TVIF_TEXT)
			{
				pszText = ((LPNMTVDISPINFO)lParam)->item.pszText;
				cchTextMax = ((LPNMTVDISPINFO)lParam)->item.cchTextMax - 1;
				pszText[cchTextMax - 1] = 0;

				pspi = (PSYSTEM_PROCESS_INFORMATION)((LPNMTVDISPINFO)lParam)->item.lParam;

				_snwprintf(pszText, cchTextMax - 1, L"%04x %wZ", (ULONG)(ULONG_PTR)pspi->UniqueProcessId, &pspi->ImageName);
			}
			break;

		case TVN_SELCHANGED:
			if (!_bittest(&_flags, f_inDelete)) 
			{
				frame = ZGLOBALS::getMainFrame();
				frame->EnableCmd(ID_COPY, FALSE);
				frame->EnableCmd(ID_FIND, FALSE);
				frame->EnableCmd(ID_CMDLINE, TRUE);
				_iSelItem = MAXDWORD;
				_flags &= ~((1 << f_select) | (1 << f_focus));
				DisplayDLLs((PSYSTEM_PROCESS_INFORMATION)((LPNMTREEVIEW)lParam)->itemNew.lParam);
			}
			break;

		case LVN_GETDISPINFO:
			if (
				_ppm &&
				(((NMLVDISPINFO*)lParam)->item.mask & LVIF_TEXT) 
				&&
				(iItem = ((NMLVDISPINFO*)lParam)->item.iItem) < _ppm->NumberOfModules
				)
			{			
				cchTextMax = ((NMLVDISPINFO*)lParam)->item.cchTextMax;
				pszText = ((NMLVDISPINFO*)lParam)->item.pszText;
					
				prpmi = &_ppm->Modules[_ppm->Modules[iItem].InitOrderIndex];

				switch (((NMLVDISPINFO*)lParam)->item.iSubItem)
				{
				case 0:
					if (_ppm != &_pm)
					{
						_snwprintf(pszText, cchTextMax, L"%03u", prpmi->LoadOrderIndex);
					}
					else
					{
						pszText[0] = 0;
					}
					break;
				case 1:
					_snwprintf(pszText, cchTextMax, L"%02u", ((PRTL_PROCESS_MODULE_INFORMATION)prpmi->Section)->LoadCount);
					break;
				case 2:
					_snwprintf(pszText, cchTextMax, L"%p", prpmi->ImageBase);
					break;
				case 3:
					_snwprintf(pszText, cchTextMax, L"%08x", prpmi->ImageSize);
					break;
				case 4:
					_snwprintf(pszText, cchTextMax, L"%S", prpmi->FullPathName);
					break;
				default: pszText[0] = 0;
				}
			}
			break;
		case LVN_COLUMNCLICK:
			if (_ppm && (iItem = ((LPNMLISTVIEW)lParam)->iSubItem) < 5)
			{
				if (_ppm != &_pm || iItem)
				{
					if (_nSelColum != iItem)
					{
						_nSelColum = iItem;
					}
					DoSort(_ppm->Modules, _ppm->NumberOfModules, iItem, _bittestandcomplement(&_sortBits, iItem) != 0);
					InvalidateRect(((LPNMHDR)lParam)->hwndFrom, 0, 0);
				}
			}
			break;
		case LVN_ITEMCHANGED:
			iItem = ((LPNMLISTVIEW)lParam)->uNewState;

			if (((LPNMLISTVIEW)lParam)->iItem != -1)
			{
				if (iItem & LVIS_FOCUSED)
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
				frame = ZGLOBALS::getMainFrame();

				if (iItem & LVIS_SELECTED)
				{
					_iSelItem = ((LPNMLISTVIEW)lParam)->iItem;
					if (!_bittestandset(&_flags, f_select))
					{
						frame->EnableCmd(ID_COPY, TRUE);
						frame->EnableCmd(ID_FIND, TRUE);
					}
				}
				else
				{
					_iSelItem = MAXDWORD;
					if (_bittestandreset(&_flags, f_select))
					{
						frame->EnableCmd(ID_COPY, FALSE);
						frame->EnableCmd(ID_FIND, FALSE);
					}
				}
			}
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
		static const int pp[] = { 80, 200, 800, -1 };
		SetParts(pp, RTL_NUMBER_OF(pp));

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
		g_btns, gNtVersion >= _WIN32_WINNT_WIN8 ? RTL_NUMBER_OF(g_btns) : RTL_NUMBER_OF(g_btns) - 1, TRUE) != 0;
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

DWORD ZMyApp::GetWaitHandles(HANDLE ** ppHandles)
{
	*ppHandles = &_hSemaphore;
	return 1;
}

void ZMyApp::OnSignalObject(DWORD i)
{
	if (!i)
	{
		if (UU* p = PopReadyTask())
		{
			PROCESS_MODULES* ppm = PROCESS_MODULES::get(p->GetPSPI());

			NTSTATUS status = p->status;

			if (0 <= status && status != STATUS_TIMEOUT)
			{
				if (PRTL_PROCESS_MODULES prpm = p->get())
				{
					if (ULONG NumberOfModules = prpm->NumberOfModules)
					{
						if (RTL_PROCESS_MODULE_INFORMATION* Modules = new RTL_PROCESS_MODULE_INFORMATION[NumberOfModules])
						{
							memcpy(Modules, prpm->Modules, NumberOfModules * sizeof(RTL_PROCESS_MODULE_INFORMATION));
							ppm->Modules = Modules;
							ppm->NumberOfModules = NumberOfModules;

							USHORT Index = 0;
							do 
							{
								Modules->LoadOrderIndex = Index;
								Modules++->InitOrderIndex = Index++;
							} while (--NumberOfModules);
						}
						else
						{
							status = STATUS_INSUFFICIENT_RESOURCES;
						}
					}
				}
			}

			ppm->status = status;
			
			delete p;

			SendMessage(static_cast<GLOBALS_EX*>(ZGLOBALS::get())->_hwndTask, MySplit::WM_PSI_READY, IsAllTasksDone(), (LPARAM)ppm);
		}
	}
	else
	{
		__debugbreak();//??
	}
}

void zmain()
{
	GLOBALS_EX globals;
	ZMyApp app;
	ZRegistry reg;

	if (0 <= reg.Create(L"Software\\{9618DB6D-97D9-4ded-A8E7-422E46BD9C87}") && 0 <= app.Init())
	{
		HWND hwnd = 0;

		if (ZMainWnd* p = new ZMainWnd)
		{
			hwnd = p->ZSDIFrameWnd::Create(L"Process | Dll List", (HINSTANCE)&__ImageBase, MAKEINTRESOURCE(IDR_MENU1), TRUE);

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
	NTSTATUS status = ZwOpenProcessToken(NtCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);
	if (0 <= status)
	{
		BEGIN_PRIVILEGES(tp, 2)
			LAA(SE_DEBUG_PRIVILEGE),
			LAA(SE_LOAD_DRIVER_PRIVILEGE)
		END_PRIVILEGES	
		status = ZwAdjustPrivilegesToken(hToken, FALSE, const_cast<PTOKEN_PRIVILEGES>(&tp), 0, 0, 0);
		NtClose(hToken);
	}
	return status;
}

void ep(void*)
{
	ULONG M, m;
	RtlGetNtVersionNumbers(&M, &m, 0);
	gNtVersion = (M << 8)|m;

#ifndef _WIN64
	PVOID wow;
	if (0 > ZwQueryInformationProcess(NtCurrentProcess(), ProcessWow64Information, &wow, sizeof(wow), 0) || wow)
	{
		MessageBox(0, L"The 32-bit version of this program is not compatible with the 64-bit Windows you're running.", 
			L"Machine Type Mismatch", MB_ICONWARNING);
		ExitProcess(0);
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
		ZwOpenFile(&g_hDrv, SYNCHRONIZE, &oa, &iosb, FILE_SHARE_VALID_FLAGS, FILE_SYNCHRONOUS_IO_NONALERT);
		break;
	}

	initterm();
	InitShowCmdLine();

	if (g_queue.Init())
	{
		zmain();
		g_queue.Stop(TRUE);
	}

	destroyterm();

	ExitProcess(0);
}

_NT_END