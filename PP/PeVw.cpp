// PeVw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

_NT_BEGIN
#define MAX_DESTRUCTOR_COUNT 8
#include "../inc/initterm.h"
#include "common.h"
#include "fontDlg.h"
#include "../winZ/split.h"
#include "../winZ/view.h"

GLOBALS_EX::GLOBALS_EX()
{
	_hDlgFont = CreateFont(16, 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, CLEARTYPE_QUALITY, FIXED_PITCH|FF_MODERN, L"Courier New");
}

GLOBALS_EX::~GLOBALS_EX()
{
	if (_hDlgFont)
	{
		DeleteObject(_hDlgFont);
	}
}

#define GetPeDoc() ((ZPeDoc*)_pDocument)

class ZPeDoc : public ZDocument
{
	PVOID _BaseAddress;
	SIZE_T _ViewSize;

	virtual BOOL IsCmdEnabled(WORD cmd);
	virtual LRESULT OnCmdMsg(WPARAM wParam, LPARAM lParam);

	~ZPeDoc();

public:
	void Create(PCWSTR FilePath);
	
	ZPeDoc();

	PVOID get_BaseAddress() { return _BaseAddress; };
	SIZE_T get_ViewSize() { return _ViewSize; }

};

class ZPeView : public ZSplitWndV, public ZView, ZFontNotify
{
	virtual void OnNewFont(HFONT hFont);

	virtual HWND CreateChild(BOOL lt, HWND hwndParent, int x, int y, int nWidth, int nHeight);
	
	virtual LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual ZWnd* getWnd()
	{
		return this;
	}

public:
	ZPeView(ZDocument* pDocument) : ZSplitWndV(256), ZView(pDocument)
	{

	}
};

void ZPeView::OnNewFont(HFONT hFont)
{
	SendMessage(getPaneWnd(TRUE), WM_SETFONT, (WPARAM)hFont, TRUE);
	SendMessage(getPaneWnd(FALSE), WM_SETFONT, (WPARAM)hFont, TRUE);
}

#define MAKE_PE_PARAM(pv, type) ((ULONG_PTR)(pv) | ((ULONG_PTR)(type) << 8))

enum {
	e_Signature,
	e_IMAGE_FILE_HEADER,
	e_IMAGE_OPTIONAL_HEADER32,
	e_IMAGE_OPTIONAL_HEADER64,
	e_IMAGE_ROM_OPTIONAL_HDR_MAGIC,
	e_IMAGE_DATA_DIRECTORY,
	e_IMAGE_SECTION_HEADER
};

LRESULT ZPeView::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case TVN_SELCHANGED:
		ListView_DeleteAllItems(hwnd = getPaneWnd(FALSE));
		if (lParam = ((LPNMTREEVIEW)lParam)->itemNew.lParam)
		{
			//PVOID pv = lParam &;
		}
		break;
	}

	return ZSplitWndV::WindowProc(hwnd, uMsg, wParam, lParam);
}

HWND ZPeView::CreateChild(BOOL lt, HWND hwndParent, int x, int y, int nWidth, int nHeight)
{
	HWND hwnd;

	ZFont* font = ZGLOBALS::getFont();
	HFONT hFont = font->getFont();

	if (!lt)
	{
		if (hwnd = CreateWindowEx(0, WC_LISTVIEW, 0, 
			WS_CHILD|WS_VISIBLE|LVS_REPORT|LVS_NOSORTHEADER|LVS_SHOWSELALWAYS|LVS_SINGLESEL|WS_HSCROLL|WS_VSCROLL, 
			x, y, nWidth, nHeight, hwndParent, 0, 0, 0))
		{
			SendMessage(hwnd, WM_SETFONT, (WPARAM)hFont, TRUE);

			SIZE s;
			font->getSIZE(&s);

			LV_COLUMN lvclmn = { LVCF_TEXT | LVCF_WIDTH };
			lvclmn.cx = s.cx *17;
			lvclmn.pszText = L" RVA ";
			ListView_InsertColumn(hwnd, lvclmn.iSubItem = 0, &lvclmn);
			lvclmn.pszText = L" Data ";
			ListView_InsertColumn(hwnd, lvclmn.iSubItem = 1, &lvclmn);
			lvclmn.cx = s.cx *32;
			lvclmn.pszText = L" Description ";
			ListView_InsertColumn(hwnd, lvclmn.iSubItem = 2, &lvclmn);
			lvclmn.pszText = L" Value ";
			ListView_InsertColumn(hwnd, lvclmn.iSubItem = 3, &lvclmn);

			ListView_SetExtendedListViewStyle(hwnd, LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP);
		}

		return hwnd;
	}

	if (hwnd = CreateWindowExW(0, WC_TREEVIEW, 0, WS_CHILD|WS_VISIBLE|TVS_LINESATROOT|TVS_HASLINES|TVS_HASBUTTONS|TVS_DISABLEDRAGDROP|
		TVS_TRACKSELECT|TVS_EDITLABELS, x, y, nWidth, nHeight, hwndParent, 0, 0, 0))
	{
		SendMessage(hwnd, WM_SETFONT, (WPARAM)hFont, TRUE);

		WCHAR sz[256];

		if (GetWindowText(GetParent(hwndParent), sz, RTL_NUMBER_OF(sz)))
		{
			TVINSERTSTRUCT tv;
			tv.hParent = TVI_ROOT;
			tv.hInsertAfter = TVI_LAST;
			tv.item.mask = TVIF_TEXT|TVIF_PARAM;
			tv.item.pszText = sz;
			tv.item.lParam = 0;

			tv.hParent = TreeView_InsertItem(hwnd, &tv);

			PVOID BaseAddress = GetPeDoc()->get_BaseAddress();
			//SIZE_T ViewSize = GetPeDoc()->get_ViewSize();

			__try
			{
				HTREEITEM hParent, *phSections = 0, hA, hB, *ph;

				if (PIMAGE_NT_HEADERS pinth = RtlImageNtHeader(BaseAddress))
				{
					if (WORD NumberOfSections = pinth->FileHeader.NumberOfSections)
					{
						ph = phSections = (HTREEITEM*)alloca(NumberOfSections * sizeof(HTREEITEM));

						hA = TVI_LAST, hB = TVI_LAST;
						tv.item.pszText = sz;
						PIMAGE_SECTION_HEADER pish = IMAGE_FIRST_SECTION(pinth);
						do 
						{
							tv.hInsertAfter = hA;
							tv.item.lParam = MAKE_PE_PARAM(pish, e_IMAGE_SECTION_HEADER);
							swprintf(sz, L"IMAGE_SECTION_HEADER %.8S", pish->Name);
							hA = TreeView_InsertItem(hwnd, &tv);
							
							tv.hInsertAfter = hB;
							tv.item.lParam = 0;
							swprintf(sz, L"SECTION %.8S", pish->Name);
							*ph++ = hB = TreeView_InsertItem(hwnd, &tv);

						} while (pish++,--NumberOfSections);
					}

					hParent = tv.hParent;

					tv.hInsertAfter = TVI_FIRST;

					tv.item.pszText = L"IMAGE_NT_HEADERS";
					tv.hParent = TreeView_InsertItem(hwnd, &tv);

					tv.hInsertAfter = TVI_LAST;

					tv.item.lParam = MAKE_PE_PARAM(&pinth->Signature, e_Signature);
					tv.item.pszText = L"Signature";
					TreeView_InsertItem(hwnd, &tv);

					tv.item.lParam = MAKE_PE_PARAM(&pinth->FileHeader, e_IMAGE_FILE_HEADER);
					tv.item.pszText = L"IMAGE_FILE_HEADER";
					TreeView_InsertItem(hwnd, &tv);

					DWORD type;

					switch (pinth->OptionalHeader.Magic)
					{
					case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
						tv.item.pszText = L"IMAGE_OPTIONAL_HEADER32";
						type = e_IMAGE_OPTIONAL_HEADER32;
						break;
					case IMAGE_NT_OPTIONAL_HDR64_MAGIC:
						tv.item.pszText = L"IMAGE_OPTIONAL_HEADER64";
						type = e_IMAGE_OPTIONAL_HEADER64;
						break;
					case IMAGE_ROM_OPTIONAL_HDR_MAGIC:
						tv.item.pszText = L"IMAGE_ROM_OPTIONAL_HDR_MAGIC";
						type = e_IMAGE_ROM_OPTIONAL_HDR_MAGIC;
						break;
					default: type = 0;
					}

					if (type)
					{
						tv.item.lParam = MAKE_PE_PARAM(&pinth->OptionalHeader, type);
						tv.hParent = TreeView_InsertItem(hwnd, &tv);

						if (DWORD NumberOfRvaAndSizes = pinth->OptionalHeader.NumberOfRvaAndSizes / sizeof(IMAGE_DATA_DIRECTORY))
						{
							PIMAGE_DATA_DIRECTORY pidd = pinth->OptionalHeader.DataDirectory;

							int i = 0;
							do 
							{
							
#define CASE_IDE(x) case IMAGE_DIRECTORY_ENTRY_##x: tv.item.pszText = L"IMAGE_DIRECTORY_ENTRY_"wstring(x);break;
								
								switch (i)
								{
								CASE_IDE(EXPORT)CASE_IDE(IMPORT)CASE_IDE(RESOURCE)CASE_IDE(EXCEPTION)CASE_IDE(SECURITY)
								CASE_IDE(BASERELOC)CASE_IDE(DEBUG)CASE_IDE(ARCHITECTURE)CASE_IDE(GLOBALPTR)CASE_IDE(TLS)
								CASE_IDE(LOAD_CONFIG)CASE_IDE(BOUND_IMPORT)CASE_IDE(IAT)CASE_IDE(DELAY_IMPORT)CASE_IDE(COM_DESCRIPTOR)
								default:
									swprintf(sz, L"%u", i);
								}
								tv.item.lParam = MAKE_PE_PARAM(pidd, e_IMAGE_DATA_DIRECTORY);
								TreeView_InsertItem(hwnd, &tv);
							} while (i++, pidd++, --NumberOfRvaAndSizes);
						}
					}

					TreeView_Expand(hwnd, hParent, TVE_EXPAND);
				}

			}
			__except(EXCEPTION_EXECUTE_HANDLER)
			{

			}
		}
	}

	return hwnd;
}

BOOL ZPeDoc::IsCmdEnabled(WORD /*cmd*/)
{
	return FALSE;
}

LRESULT ZPeDoc::OnCmdMsg(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	return 0;
}

ZPeDoc::ZPeDoc()
{
	_BaseAddress = 0;
	_ViewSize = 0;
}

ZPeDoc::~ZPeDoc()
{
	if (_BaseAddress)
	{
		ZwUnmapViewOfSection(NtCurrentProcess(), _BaseAddress);
	}
}

class ZPeFrame : public ZMDIChildFrame
{
	virtual HWND CreateView(HWND hWndParent, int nWidth, int nHeight, PVOID lpCreateParams)
	{
		HWND hwnd = 0;
		if (ZPeView* p = new ZPeView((ZDocument*)lpCreateParams))
		{
			hwnd = p->Create(0, 0, WS_CHILD|WS_VISIBLE, 0, 0, nWidth, nHeight, hWndParent, 0, lpCreateParams);
			p->Release();
		}

		return hwnd;
	}
};

void ZPeDoc::Create(PCWSTR FilePath)
{
	UNICODE_STRING ObjectName;
	PWSTR FileName;
	NTSTATUS status = STATUS_UNSUCCESSFUL;
	PCWSTR caption = L"RtlDosPathNameToNtPathName_U";

	if (RtlDosPathNameToNtPathName_U(FilePath, &ObjectName, &FileName, 0))
	{
		HANDLE hFile, hSection;
		IO_STATUS_BLOCK iosb;
		OBJECT_ATTRIBUTES oa = { sizeof(oa), 0, &ObjectName, OBJ_CASE_INSENSITIVE };

		caption = L"ZwOpenFile";

		if (0 <= (status = ZwOpenFile(&hFile, FILE_GENERIC_READ, &oa, &iosb, FILE_SHARE_VALID_FLAGS, FILE_SYNCHRONOUS_IO_NONALERT)))
		{
			caption = L"ZwCreateSection";

			if (0 <= (status = ZwCreateSection(&hSection, SECTION_MAP_READ, 0, 0, PAGE_READONLY, SEC_IMAGE, hFile)))
			{
				caption = L"ZwMapViewOfSection";

				if (0 <= (status = ZwMapViewOfSection(hSection, NtCurrentProcess(), &_BaseAddress, 0, 0, 0, &_ViewSize, ViewUnmap, 0, PAGE_READONLY)))
				{
					if (ZPeFrame* p = new ZPeFrame)
					{
						p->Create(FileName, this);
						p->Release();
					}
				}
				NtClose(hSection);
			}

			NtClose(hFile);
		}

		RtlFreeUnicodeString(&ObjectName);
	}
	
	if (0 > status)
	{
		WCHAR err[256];
		FormatNTStatus(err, status);
		MessageBox(ZGLOBALS::getMainHWND(), err, caption, MB_ICONHAND);
	}
}

class ZMainWnd : public ZMDIFrameWnd
{
	DWORD _nFilterIndex;

	virtual LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual BOOL CreateSB(HWND hwnd);
	virtual BOOL CreateTB(HWND hwnd);

	virtual PCUNICODE_STRING getPosName()
	{
		STATIC_UNICODE_STRING_(MainWnd);
		return &MainWnd;
	}

	virtual DWORD getDocumentCmdId(WORD const** ppCmdId)
	{
		static const WORD cmdid[] = { 
			0
		};

		*ppCmdId = cmdid;

		return RTL_NUMBER_OF(cmdid);
	}
public:

	ZMainWnd()
	{
		DbgPrint("++ZMainWnd()\n");
		_nFilterIndex = 1;
	}

	~ZMainWnd()
	{
		DbgPrint("--ZMainWnd()\n");
	}
};

BOOL ZMainWnd::CreateSB(HWND hwnd)
{
	if (hwnd = ZStatusBar::Create(hwnd))
	{
		static const int pp[] = { 256, 256 + 64, 256 + 64 + 64, 256 + 64 + 64 + 64, -1 };
		SetParts(pp, RTL_NUMBER_OF(pp));
		return TRUE;
	}
	return FALSE;
}

BOOL ZMainWnd::CreateTB(HWND hwnd)
{
	static TBBUTTON g_btns[] = {
		{0, IDB_BITMAP1, TBSTATE_ENABLED, BTNS_AUTOSIZE, {}, (DWORD_PTR)L"Open", -1},
		{0, IDB_BITMAP2, TBSTATE_ENABLED, BTNS_AUTOSIZE, {}, (DWORD_PTR)L"Choose Font", -1 },
	};

	return ZToolBar::Create(hwnd, (HINSTANCE)&__ImageBase, 0, 0, 24, 24, g_btns, RTL_NUMBER_OF(g_btns), FALSE) != 0;
}

LRESULT ZMainWnd::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		switch (wParam)
		{
		case ID_FILE_EXIT:
			DestroyWindow(hwnd);
			break;

		case IDB_BITMAP2:
			ChoseFont(hwnd);
			break;

		case IDB_BITMAP1:

			OPENFILENAME ofn = { 
				sizeof(ofn), 
				hwnd, 
				0, 
				L"exe\0*.exe\0dll\0*.dll\0sys\0*.sys\0All Files\0*.*\0\0", 
				0, 
				0, 
				_nFilterIndex,
				(PWSTR)alloca(10000*sizeof(WCHAR)), 
				0x10000, 
				0, 
				0, 
				0,
				L"Select PE",
				OFN_EXPLORER|OFN_FILEMUSTEXIST|OFN_FORCESHOWHIDDEN|OFN_NODEREFERENCELINKS|OFN_NONETWORKBUTTON|OFN_NOTESTFILECREATE
			};

			*ofn.lpstrFile = 0;

			if (GetOpenFileName(&ofn))
			{
				if (ZPeDoc* p = new ZPeDoc)
				{
					p->Create(ofn.lpstrFile);
					p->Release();
				}
			}


			break;
		}
		break;
	}
	return ZMDIFrameWnd::WindowProc(hwnd, uMsg, wParam, lParam);
}

void zmain()
{
	GLOBALS_EX globals;
	ZApp app;
	ZRegistry reg;
	ZFont font(TRUE);

	if (0 <= reg.Create(L"Software\\{9E94D828-ABCA-4e5a-8B40-45387B7F501B}") && font.Init())
	{
		HWND hwnd = 0;

		if (ZMainWnd* p = new ZMainWnd)
		{
			hwnd = p->ZSDIFrameWnd::Create(L"PeView", (HINSTANCE)&__ImageBase, MAKEINTRESOURCE(IDR_MENU1));

			p->Release();
		}

		if (hwnd)
		{
			app.Run();
		}
	}
}

void ep()
{
	STATIC_OBJECT_ATTRIBUTES(oa, "\\device\\$$tt$$");
	HANDLE hFile;
	IO_STATUS_BLOCK iosb;
	if (0 <= ZwOpenFile(&hFile, SYNCHRONIZE, &oa, &iosb, FILE_SHARE_VALID_FLAGS, 0))
	{
		MessageBox(0,0,0,0);
		NtClose(hFile);
	}
	initterm();

	if (ZWnd::_InitClass())
	{
		zmain();
		ZWnd::_DoneClass();
	}

	destroyterm();

	ExitProcess(0);
}

_NT_END


