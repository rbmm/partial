// Wobj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

_NT_BEGIN
#define AFX_IDW_STATUS_BAR 0xE801 
#include "../inc/initterm.h"
#include "../winZ/app.h"
#include "../winz/Frame.h"
#include "../winz/split.h"
#include "resource.h"

volatile UCHAR guz;

void ShowSD(HANDLE hObject, PCWSTR caption, HWND hwndMain, HFONT hFont);

NTSTATUS MyOpenDevice( _Out_ PHANDLE Handle, _In_ ACCESS_MASK DesiredAccess, _In_ POBJECT_ATTRIBUTES ObjectAttributes )
{
	IO_STATUS_BLOCK iosb;
	return NtOpenFile(Handle, DesiredAccess, ObjectAttributes, &iosb, FILE_SHARE_VALID_FLAGS, 0);
}

void ShowNTStatus(HWND hwnd, NTSTATUS status, PCWSTR caption)
{
	WCHAR buf[256], *sz = buf;

	sz += swprintf(sz, L"//%08x\r\n", status);

	FormatMessage(FORMAT_MESSAGE_IGNORE_INSERTS|FORMAT_MESSAGE_FROM_HMODULE,
		GetModuleHandleW(L"ntdll"), status, 0, sz, RTL_NUMBER_OF(buf) - (DWORD)(sz - buf), 0);

	switch ((DWORD)status >> 30)
	{
	case 0:
		status = MB_OK;
		break;
	case 1:
		status = MB_OK|MB_ICONINFORMATION;
		break;
	case 2:
		status = MB_OK|MB_ICONWARNING;
		break;
	case 3:
		status = MB_OK|MB_ICONHAND;
		break;
	default:__assume(false);
	}

	MessageBox(hwnd, buf, caption, status);
}

NTSTATUS ZwOpenWindowStation( PHANDLE Handle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes )
{
	if (PWSTR sz = ObjectAttributes->ObjectName->Buffer)
	{
		if (sz = wcsrchr(sz, '\\'))
		{
			if (HWINSTA h = OpenWindowStationW(sz + 1, FALSE, DesiredAccess))
			{
				*Handle = h;
				return STATUS_SUCCESS;
			}
		}
	}
	
	return STATUS_UNSUCCESSFUL;
}

#if 0
BOOL GetObjPointer(HANDLE hObject, PVOID& pvObject)
{
	BOOL fOk = FALSE;
	NTSTATUS status;
	ULONG cb = 0x80000;

	union {
		PSYSTEM_HANDLE_INFORMATION_EX pshi;
		PVOID pv;
	};

	do 
	{
		status = STATUS_INSUFFICIENT_RESOURCES;

		if (pv = LocalAlloc(0, cb += 32 * sizeof(SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX)))
		{
			if (0 <= (status = ZwQuerySystemInformation(SystemExtendedHandleInformation, pv, cb, &cb)))
			{
				if (ULONG_PTR NumberOfHandles = pshi->NumberOfHandles)
				{
					ULONG_PTR UniqueProcessId = GetCurrentProcessId();
					PSYSTEM_HANDLE_TABLE_ENTRY_INFO_EX Handles = pshi->Handles;
					do 
					{
						if (Handles->UniqueProcessId == UniqueProcessId && Handles->HandleValue == (ULONG_PTR)hObject)
						{
							pvObject = Handles->Object;
							fOk = TRUE;
							break;
						}
					} while (Handles++, --NumberOfHandles);
				}
			}
			LocalFree(pv);
		}

	} while (status == STATUS_INFO_LENGTH_MISMATCH);

	return fOk;
}
#endif

HIMAGELIST CreateIL(HINSTANCE hInstance, int cx, int cy, UINT flags, DWORD n, WORD pID[], HICON* phi)
{
	HIMAGELIST himl = ImageList_Create(cx, cy, flags, n, 0);

	if (himl)
	{
		do 
		{
			if (HICON hi = (HICON)LoadImage(hInstance, MAKEINTRESOURCE(*pID++), IMAGE_ICON, 0, 0, 0))
			{
				*phi = hi;
				ImageList_ReplaceIcon(himl, -1, hi);
			}
		} while (++phi, --n);
	}

	return himl;
}

struct OBJ_NODE : public UNICODE_STRING
{
	OBJ_NODE *Parent, *Next, *Child;
	PUNICODE_STRING TypeName;
	ULONG hash;

	enum {
		t_Type = 0x8041ee9a,
		t_Directory = 0xa4531c4d,
		t_SymbolicLink = 0x7f82e7ac,
		t_Token = 0xab194359,
		t_Job = 0x24df96fd,
		t_Process = 0x70fcfc4f,
		t_Thread = 0xc8bcac4a,
		t_UserApcReserve = 0xa3fa2453,
		t_IoCompletionReserve = 0xca6e211a,
		t_DebugObject = 0x08282e52,
		t_Event = 0xf3040cba,
		t_EventPair = 0x97834894,
		t_Mutant = 0xfba93d5b,
		t_Callback = 0xd619e0a5,
		t_Semaphore = 0x33b553e4,
		t_Timer = 0x94ec7de5,
		t_Profile = 0xfe82aac9,
		t_KeyedEvent = 0x6c3a045c,
		t_WindowStation = 0x1551ade4,
		t_Desktop = 0xd1ffc79c,
		t_TpWorkerFactory = 0x084a8cd0,
		t_Adapter = 0x5b4bfe0f,
		t_Controller = 0x38a0df3c,
		t_Device = 0x5646fcd6,
		t_Driver = 0x72d80048,
		t_IoCompletion = 0xbc81c342,
		t_File = 0xecfd8b1c,
		t_TmTm = 0x7a3d2db2,
		t_TmTx = 0x7a3d2dbd,
		t_TmRm = 0x7a3b2d34,
		t_TmEn = 0x7a2e2a02,
		t_Section = 0xbd107d45,
		t_Session = 0xcd4f9c96,
		t_Key = 0x2553a41f,
		t_ALPC_Port = 0xfc99f003,
		t_PowerRequest = 0xb5a1b3ea,
		t_WmiGuid = 0x36d9823c,
		t_EtwRegistration = 0x89b06481,
		t_EtwConsumer = 0x31a53abe,
		t_FilterConnectionPort = 0x04598bf7,
		t_FilterCommunicationPort = 0x7849195f,
		t_PcwObject = 0xe3f801c3,
		t_Port = 0xc13c1121,
		t_WaitablePort = 0x66debaf0,
		t_Partition = 0x5227054a
	};

	OBJ_NODE()
	{
		RtlZeroMemory(this, sizeof OBJ_NODE);
	}

	~OBJ_NODE()
	{
		RtlFreeUnicodeString(this);
	}

	LONG get_FullName(PWSTR lpsz, LONG cb);
private:
	LONG QueryName(PWSTR& Buffer, LONG& Length);
};

int GetImageIndexByHash(ULONG hash)
{
	switch (hash)
	{
	case OBJ_NODE::t_Directory:
		return 1;
	case OBJ_NODE::t_Device:
		return 3;
	case OBJ_NODE::t_Driver:
		return 4;
	case OBJ_NODE::t_Section:
		return 5;
	case OBJ_NODE::t_Port:
	case OBJ_NODE::t_ALPC_Port:
		return 6;
	case OBJ_NODE::t_SymbolicLink:
		return 7;
	case OBJ_NODE::t_Key:
		return 8;
	case OBJ_NODE::t_Event:
		return 9;
	case OBJ_NODE::t_Job:
		return 10;
	case OBJ_NODE::t_Mutant:
		return 11;
	case OBJ_NODE::t_KeyedEvent:
		return 12;
	case OBJ_NODE::t_Type:
		return 13;
	case OBJ_NODE::t_WindowStation:
		return 14;
	case OBJ_NODE::t_Callback:
		return 15;
	case OBJ_NODE::t_Semaphore:
		return 16;
	case OBJ_NODE::t_WaitablePort:
		return 17;
	case OBJ_NODE::t_Session:
		return 18;
	case OBJ_NODE::t_EventPair:
		return 19;
	case OBJ_NODE::t_Partition:
		return 20;
	case OBJ_NODE::t_FilterCommunicationPort:
		return 21;
	case OBJ_NODE::t_FilterConnectionPort:
		return 22;
	case OBJ_NODE::t_Timer:
		return 23;
	default:
		return I_IMAGENONE;
	}
}

LONG OBJ_NODE::QueryName(PWSTR& Buf, LONG& Len)
{
	LONG NameLen = 0, _NameLen = Length;
	if (Parent) 
	{
		NameLen = sizeof(WCHAR) + Parent->QueryName(Buf, Len);
		if ((LONG)sizeof(WCHAR) <= Len) *Buf = L'\\';
		Buf++, Len -= sizeof(WCHAR);
		if (_NameLen <= Len) memcpy(Buf, Buffer, Length);
		Buf += _NameLen >> 1, Len -= _NameLen;
	}
	return NameLen + _NameLen;
}

LONG OBJ_NODE::get_FullName(PWSTR lpsz, LONG cb)
{
	if (!Parent)
	{
		if (cb >= 2 * sizeof(WCHAR))
		{
			*lpsz++ = L'\\', *lpsz = 0;
		}
		return 2 * sizeof(WCHAR);
	}
	LONG NameLength = QueryName(lpsz, cb);
	if ((LONG)sizeof(WCHAR) <= cb) *lpsz = 0;
	return NameLength + sizeof(WCHAR);
}

void DeleteNode(OBJ_NODE* item)
{
	OBJ_NODE* Next = item->Child, *_item;
	while(Next)
	{
		_item = Next;
		Next = Next->Next;
		DeleteNode(_item);
	}
	delete item;
}

void _AddNode(HWND hwnd, LV_ITEM* plv, ULONG hash, OBJ_NODE* item)
{
	if (item->hash == hash)
	{
		plv->lParam = MINLONG_PTR|(LPARAM)item;//
		ListView_InsertItem(hwnd, plv);
	}

	if (item = item->Child)
	{
		do 
		{
			_AddNode(hwnd, plv, hash, item);
		} while (item = item->Next);
	}
}

int CALLBACK CompareFunc(OBJ_NODE* p, OBJ_NODE* q, int iSubItem)
{
	p = (OBJ_NODE*)((LPARAM)p & MAXLONG_PTR);
	q = (OBJ_NODE*)((LPARAM)q & MAXLONG_PTR);
	PCUNICODE_STRING pus1, pus2;
	switch(iSubItem)
	{
	case 0:
		pus1 = p, pus2 = q;
		break;
	case 1:
		pus1 = p->TypeName, pus2 = q->TypeName;
		break;
	default:__assume(0);
	}

	return RtlCompareUnicodeString(pus1, pus2, FALSE);
}

class MySplit : public ZSplitWnd
{
	UNICODE_STRING m_TypeNames[64];
	HICON m_hi[32];
	OBJ_NODE *m_Root, *m_item;
	HWND _hwndLV, _hwndTV;
	HIMAGELIST _himl;
	HFONT _hFont, _hFont2;
	PUNICODE_STRING m_pTypeName;
	ULONG m_hash;
	int m_nSelColum;
	BOOLEAN m_bFullName, m_bGrid;
	
	OBJ_NODE* AddNode(OBJ_NODE* Parent, PCUNICODE_STRING TypeName, PCUNICODE_STRING ObjectName)
	{
		OBJ_NODE* item = new OBJ_NODE;

		if (!item) return 0;

		RtlHashUnicodeString(TypeName, FALSE, HASH_STRING_ALGORITHM_X65599, &item->hash);

		if ((0 > RtlDuplicateUnicodeString(RTL_DUPLICATE_UNICODE_STRING_NULL_TERMINATE, ObjectName, item)) ||
			!(item->TypeName = InsertTypeName(TypeName)))
		{
			delete item;
			return 0;
		}

		if (Parent)
		{
			item->Next = Parent->Child;
			Parent->Child = item;
			item->Parent = Parent;
		} else m_Root = item;

		return item;
	}
	
	void AddDirectory(OBJ_NODE* Parent, HWND hwndTv, LPTVINSERTSTRUCT lpis, POBJECT_ATTRIBUTES poa)
	{
		lpis->item.lParam = (LPARAM)Parent;
		HTREEITEM hParent = TreeView_InsertItem(hwndTv, lpis);
		if (!hParent) return;

		HANDLE hDirectory;
		NTSTATUS status;
		if (0 > ZwOpenDirectoryObject(&hDirectory, DIRECTORY_QUERY, poa)) return;

		DWORD Context = 0, rcb;
		LPVOID buffer = alloca(PAGE_SIZE);

		if (Parent) do 
		{
			status = ZwQueryDirectoryObject(hDirectory, buffer, PAGE_SIZE, FALSE, FALSE, &Context, &rcb);
			if (0 > status) break;
			DIRECTORY_BASIC_INFORMATION* pdbi = (DIRECTORY_BASIC_INFORMATION*)buffer;

			while (pdbi->ObjectName.Length)
			{
				lpis->hParent = hParent;
				OBJ_NODE* item = AddNode(Parent, &pdbi->ObjectTypeName, &pdbi->ObjectName);

				if (!item) 
				{
					status = STATUS_INSUFFICIENT_RESOURCES;
					break;
				}

				if (item->hash == OBJ_NODE::t_Directory)
				{
					AddDirectory(item, hwndTv, lpis, &CObjectAttributes(&pdbi->ObjectName, hDirectory));
				}

				pdbi++;
			}

		} while(status == STATUS_MORE_ENTRIES);


		ZwClose(hDirectory);
	}
	
	PUNICODE_STRING InsertTypeName(PCUNICODE_STRING TypeName)
	{
		int i = RTL_NUMBER_OF(m_TypeNames);
		PUNICODE_STRING pus = m_TypeNames;
		do 
		{
			if (!pus->Length)
			{
				return 0 <= RtlDuplicateUnicodeString(RTL_DUPLICATE_UNICODE_STRING_NULL_TERMINATE, TypeName, pus) ? pus : 0;
			}

			if (RtlEqualUnicodeString(pus, TypeName, TRUE)) return pus;

		} while (++pus, --i);

		return 0;
	}

	void DisplayNode(PUNICODE_STRING TypeName)
	{
		ULONG hash;
		RtlHashUnicodeString(TypeName, FALSE, HASH_STRING_ALGORITHM_X65599, &hash);
		
		m_nSelColum = -1;
		ListView_DeleteAllItems(_hwndLV);
		LV_ITEM lv = { LVIF_TEXT|LVIF_PARAM|LVIF_IMAGE };
		lv.pszText = LPSTR_TEXTCALLBACK;
		lv.iItem = MAXLONG;
		lv.iImage = GetImageIndexByHash(hash);

		_AddNode(_hwndLV, &lv, hash, m_Root);
	}

	void DisplayNode(OBJ_NODE* item)
	{
		HWND hwnd = _hwndLV;
		m_nSelColum = -1;
		ListView_DeleteAllItems(hwnd);
		if (item)
		{
			LV_ITEM lv = { LVIF_TEXT|LVIF_PARAM|LVIF_IMAGE };
			lv.pszText = LPSTR_TEXTCALLBACK;
			lv.iItem = MAXLONG;
			lv.iImage = I_IMAGECALLBACK;

			if (item = item->Child) do 
			{
				//if (item->hash != OBJ_NODE::t_Directory)
				{
					lv.lParam = (LPARAM)item;
					ListView_InsertItem(hwnd, &lv); 
				}
			} while (item = item->Next);
		}
	}

	virtual HWND CreateChild(BOOL lt, HWND hwndParent, int x, int y, int nWidth, int nHeight)
	{
		HWND hwnd = 0;

		if (lt)
		{
			if (hwnd = CreateWindowExW(0, WC_TREEVIEW, 0, WS_CHILD|WS_BORDER|WS_VISIBLE|
				TVS_LINESATROOT|TVS_HASLINES|TVS_HASBUTTONS|TVS_DISABLEDRAGDROP|
				TVS_TRACKSELECT|TVS_EDITLABELS, x, y, nWidth, nHeight, hwndParent, (HMENU)1, 0, 0))
			{
				_hwndTV = hwnd;

				if (_himl)
				{
					 TreeView_SetImageList(hwnd, _himl, TVSIL_NORMAL);
				}
			}
		}
		else
		{
			if (hwnd = CreateWindowExW(0, WC_LISTVIEW, 0, 
				WS_VISIBLE|WS_CHILD|WS_BORDER|LVS_REPORT|LVS_SHOWSELALWAYS|LVS_SHAREIMAGELISTS|LVS_SINGLESEL|WS_HSCROLL|WS_VSCROLL,
				x, y, nWidth, nHeight, hwndParent, (HMENU)2, 0, 0))
			{
				SetWindowTheme(hwnd, L"Explorer", 0);


				_hwndLV = hwnd;

				LV_COLUMN lvclmn = { LVCF_TEXT | LVCF_WIDTH };
				lvclmn.cx = nWidth >> 1;
				lvclmn.pszText = L" Name ";
				ListView_InsertColumn(hwnd, lvclmn.iSubItem = 0, &lvclmn);
				lvclmn.pszText = L" Type ";
				ListView_InsertColumn(hwnd, lvclmn.iSubItem = 1, &lvclmn);

				ListView_SetExtendedListViewStyle(hwnd, LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP|LVS_EX_DOUBLEBUFFER|LVS_EX_INFOTIP);

				if (_himl)
				{
					ListView_SetImageList(hwnd, _himl, LVSIL_SMALL);
				}

				PostMessage(hwndParent, WM_COMMAND, ID_REFRESH, 0);
			}
		}

		if (hwnd && _hFont)
		{
			SendMessage(hwnd, WM_SETFONT, (WPARAM)_hFont, 0);
		}
		return hwnd;
	}

	~MySplit()
	{
		int i = RTL_NUMBER_OF(m_TypeNames);
		PUNICODE_STRING pus = m_TypeNames;
		do RtlFreeUnicodeString(pus++); while (--i);

		i = RTL_NUMBER_OF(m_hi);
		do 
		{
			if (m_hi[--i]) DestroyIcon(m_hi[i]);
		} while (i);

		if (_himl)
		{
			ImageList_Destroy(_himl);
		}
	}

	void DeleteContents()
	{
		if (m_Root)
		{
			TreeView_DeleteAllItems(_hwndTV);
			DeleteNode(m_Root);
			m_Root = 0;
		}
		m_item = 0;
		m_pTypeName = 0;
		ZGLOBALS::getMainFrame()->EnableCmd(ID_COPY, FALSE);
		m_hash = 0;
	}

	virtual LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		int i;
		PWSTR pszText;
		int cchTextMax;
		OBJ_NODE* item;
		UINT mask;
		ZSDIFrameWnd* pWnd;

		switch (uMsg)
		{
		case WM_CREATE:
			{
				ULONG m;
				RtlGetNtVersionNumbers(&m, 0, 0);

				NONCLIENTMETRICS ncm = { m < 6 ? sizeof(NONCLIENTMETRICS) - 4 : sizeof(NONCLIENTMETRICS) };
				if (SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(ncm), &ncm, 0))
				{
					ncm.lfCaptionFont.lfHeight = -ncm.iMenuHeight;
					ncm.lfCaptionFont.lfWeight = FW_NORMAL;
					ncm.lfCaptionFont.lfQuality = CLEARTYPE_QUALITY;
					ncm.lfCaptionFont.lfPitchAndFamily = FIXED_PITCH|FF_MODERN;
					wcscpy(ncm.lfCaptionFont.lfFaceName, L"Courier New");
					
					_hFont = CreateFontIndirect(&ncm.lfStatusFont);
					_hFont2 = CreateFontIndirect(&ncm.lfCaptionFont);
				}
			}
			break;
		case WM_DESTROY:
			DeleteContents();
			if (_hFont2)DeleteObject(_hFont2);
			if (_hFont)DeleteObject(_hFont);
			break;
		case WM_NOTIFY:
			switch (((NMHDR*)lParam)->code)
			{
			case TVN_GETDISPINFOW:
				if (((LPNMTVDISPINFO)lParam)->item.mask & TVIF_TEXT)
				{
					item = (OBJ_NODE*)((LPNMTVDISPINFO)lParam)->item.lParam;
					pszText = ((LPNMTVDISPINFO)lParam)->item.pszText;
					if (cchTextMax = ((LPNMTVDISPINFO)lParam)->item.cchTextMax - 1)
					{
						pszText[cchTextMax - 1] = 0;
						if (item->Parent)
						{
							_snwprintf(pszText, cchTextMax - 1, L"%wZ", (PCUNICODE_STRING)item);
						}
						else
						{
							*pszText = L'\\';
						}
					}
				}
				break;
			case TVN_SELCHANGED:
				lParam = ((LPNMTREEVIEW)lParam)->itemNew.lParam;
				if ((ULONG_PTR)lParam - (ULONG_PTR)m_TypeNames < sizeof(m_TypeNames))
				{
					DisplayNode((PUNICODE_STRING)lParam);
					m_pTypeName = (PUNICODE_STRING)lParam;
				}
				else
				{
					DisplayNode((OBJ_NODE*)lParam);
					m_pTypeName = 0;
					if (item = (OBJ_NODE*)lParam)
					{
						goto __setitem;
					}
				}

				m_item = 0;
				pWnd = ZGLOBALS::getMainFrame();
				pWnd->EnableCmd(ID_COPY, FALSE);
				pWnd->EnableCmd(ID_TOGGLE, m_pTypeName != 0);
				SendMessage(pWnd->ZStatusBar::getHWND(), SB_SETICON, (WPARAM)-1, 0);
				pWnd->SetStatusText(SB_SIMPLEID, L"");
				m_hash = 0;
				break;
			case LVN_GETDISPINFO:
				wParam = ((NMLVDISPINFO*)lParam)->item.lParam;
				item = (OBJ_NODE*)(wParam & MAXLONG_PTR);
				mask = ((NMLVDISPINFO*)lParam)->item.mask;

				if (mask & LVIF_IMAGE)
				{
					((NMLVDISPINFO*)lParam)->item.iImage = GetImageIndexByHash(item->hash);
				}

				if ((mask & LVIF_TEXT) && (DWORD)((NMLVDISPINFO*)lParam)->item.iSubItem < 2)
				{
					pszText = ((NMLVDISPINFO*)lParam)->item.pszText;
					cchTextMax = ((NMLVDISPINFO*)lParam)->item.cchTextMax - 1;
					pszText[cchTextMax - 1] = 0;

					switch(((NMLVDISPINFO*)lParam)->item.iSubItem)
					{
					case 0:
						if (0 > (LPARAM)wParam && m_bFullName)
						{
							item->get_FullName(pszText, (cchTextMax-1)<<1);
						}
						else
						{
							_snwprintf(pszText, cchTextMax - 1, L"%wZ", (PCUNICODE_STRING)item);
						}
						break;

					case 1:
						_snwprintf(pszText, cchTextMax, L"%wZ", item->TypeName);
						if (item->hash == OBJ_NODE::t_SymbolicLink)
						{
							PVOID stack = alloca(guz);
							DWORD cb = item->get_FullName(0, 0), rcb = 0x100;
							PWSTR lpsz = (PWSTR)alloca(cb);
							item->get_FullName(lpsz, cb);
							HANDLE hSymLink;
							NTSTATUS status;
							if (0 <= ZwOpenSymbolicLinkObject(&hSymLink, SYMBOLIC_LINK_QUERY, &CObjectAttributes(lpsz)))
							{
								UNICODE_STRING us = {0, (WORD)cb, lpsz};
								do 
								{
									if (us.MaximumLength < rcb)
									{
										us.MaximumLength = (WORD)RtlPointerToOffset(us.Buffer = (PWSTR)alloca(rcb - cb), stack);
									}
									if (0 <= (status = ZwQuerySymbolicLinkObject(hSymLink, &us, &rcb)))
									{
										_snwprintf(pszText, cchTextMax, L"%wZ", &us);
									}
								} while(status == STATUS_BUFFER_TOO_SMALL);

								ZwClose(hSymLink);
							}
						}
						break;
					default: __assume(0) ;
					}
				}
				break;
			case LVN_COLUMNCLICK:
				i = ((LPNMLISTVIEW)lParam)->iSubItem;
				if (m_nSelColum != i)
				{
					m_nSelColum = i;
					ListView_SortItems(((NMHDR*)lParam)->hwndFrom, CompareFunc, i);
				}
				break;

			case LVN_GETINFOTIP:
				{
					LVITEM lv = { LVIF_PARAM, ((LPNMLVGETINFOTIP)lParam)->iItem };
					if (ListView_GetItem(_hwndLV, &lv))
					{
						if (item = (OBJ_NODE*)(lv.lParam& MAXLONG_PTR))
						{
							item->get_FullName(((LPNMLVGETINFOTIP)lParam)->pszText, ((LPNMLVGETINFOTIP)lParam)->cchTextMax << 1);
						}
					}
				}
				break;

			case LVN_ITEMCHANGED:
				if ((((LPNMLISTVIEW)lParam)->uNewState & LVIS_SELECTED) && !(((LPNMLISTVIEW)lParam)->uOldState & LVIS_SELECTED))
				{
					item = (OBJ_NODE*)(((LPNMLISTVIEW)lParam)->lParam & MAXLONG_PTR);
__setitem:
					DWORD cb = item->get_FullName(0, 0);
					PWSTR lpsz = (PWSTR)alloca(cb);
					item->get_FullName(lpsz, cb);
					pWnd = ZGLOBALS::getMainFrame();
					if (!m_item)
					{
						pWnd->EnableCmd(ID_COPY, TRUE);
					}

					if (m_hash != item->hash)
					{
						SendMessage(pWnd->ZStatusBar::getHWND(), SB_SETICON, (WPARAM)-1, (LPARAM)m_hi[GetImageIndexByHash(m_hash = item->hash)]);
						
						BOOL bEnableSec = FALSE;
						switch (m_hash)
						{
						case OBJ_NODE::t_Directory:
						case OBJ_NODE::t_Event:
						case OBJ_NODE::t_Section:
						case OBJ_NODE::t_Semaphore:
						case OBJ_NODE::t_SymbolicLink:
						case OBJ_NODE::t_Mutant:
						case OBJ_NODE::t_Timer:
						case OBJ_NODE::t_IoCompletion:
						case OBJ_NODE::t_WindowStation:
						case OBJ_NODE::t_KeyedEvent:
						case OBJ_NODE::t_Device:
							bEnableSec = TRUE;
							break;
						}
						pWnd->EnableCmd(ID_SECURITY, bEnableSec);
					}
					pWnd->SetStatusText(SB_SIMPLEID, lpsz);
					pWnd->EnableCmd(ID_TOGGLE, FALSE);
					m_item = item;
				}
				break;
			}
			break;
		case WM_COMMAND:
			switch (wParam)
			{
			case ID_REFRESH:
				Refresh();
				break;
			case ID_TOGGLE:
				m_bFullName = !m_bFullName;
				if (m_pTypeName)
				{
					DisplayNode(m_pTypeName);
				}
				break;
			case ID_GRID:
				ListView_SetExtendedListViewStyle(_hwndLV, (m_bGrid = !m_bGrid) ? 
					LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP|LVS_EX_DOUBLEBUFFER|LVS_EX_INFOTIP
					: LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP|LVS_EX_DOUBLEBUFFER|LVS_EX_INFOTIP);
				break;
			case ID_COPY:
				if (m_item)
				{
					if (OpenClipboard(hwnd))
					{
						EmptyClipboard();
						DWORD cb = m_item->get_FullName(0, 0);
						if (HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, cb))
						{
							PWSTR sz = (PWSTR)GlobalLock(hg);
							m_item->get_FullName(sz, cb);
							GlobalUnlock(hg);
							if (!SetClipboardData(CF_UNICODETEXT, hg)) GlobalFree(hg);
						}
						CloseClipboard();
					}
				}
				break;
			case ID_SECURITY:
				if (m_item)
				{
					UNICODE_STRING ObjectName;
					ObjectName.Buffer = (PWSTR)alloca(ObjectName.MaximumLength = (USHORT)m_item->get_FullName(0, 0));
					m_item->get_FullName(ObjectName.Buffer, ObjectName.MaximumLength);
					ObjectName.Length = ObjectName.MaximumLength - sizeof(WCHAR);

					OBJECT_ATTRIBUTES oa = { sizeof(oa), 0, &ObjectName };
					HANDLE hObject;

					NTSTATUS (* Open)(PHANDLE , ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES );
					switch (m_hash)
					{
					case OBJ_NODE::t_Directory:
						Open = ZwOpenDirectoryObject;
						break;
					case OBJ_NODE::t_Event:
						Open = ZwOpenEvent;
						break;
					case OBJ_NODE::t_Section:
						Open = ZwOpenSection;
						break;
					case OBJ_NODE::t_Semaphore:
						Open = ZwOpenSemaphore;
						break;
					case OBJ_NODE::t_SymbolicLink:
						Open = ZwOpenSymbolicLinkObject;
						break;
					case OBJ_NODE::t_Mutant:
						Open = ZwOpenMutant;
						break;
					case OBJ_NODE::t_Timer:
						Open = ZwOpenTimer;
						break;
					case OBJ_NODE::t_IoCompletion:
						Open = ZwOpenIoCompletion;
						break;
					case OBJ_NODE::t_WindowStation:
						Open = ZwOpenWindowStation;
						break;
					case OBJ_NODE::t_KeyedEvent:
						Open = ZwOpenKeyedEvent;
						break;
					case OBJ_NODE::t_Device:
						Open = MyOpenDevice;
						break;
					default: return 0;
					}

					NTSTATUS status = Open(&hObject, READ_CONTROL, &oa);
					if (0 > status)
					{
						ShowNTStatus(ZGLOBALS::getMainHWND(), status, ObjectName.Buffer);
					}
					else
					{
						ShowSD(hObject, ObjectName.Buffer, ZGLOBALS::get()->hwndMain, _hFont2);
						ZwClose(hObject);
					}
				}
				break;
			}
			break;
		}
		return ZSplitWnd::WindowProc(hwnd, uMsg, wParam, lParam);
	}

public:

	void Refresh()
	{
		DeleteContents();
		TVINSERTSTRUCT tv;
		tv.hParent = TVI_ROOT;
		tv.hInsertAfter = TVI_FIRST;
		tv.item.mask = TVIF_PARAM|TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
		tv.item.pszText = LPSTR_TEXTCALLBACK;
		tv.item.iImage = 1;
		tv.item.iSelectedImage = 2;

		static UNICODE_STRING root;
		//STATIC_UNICODE_STRING(root, "\\");
		STATIC_UNICODE_STRING_(Directory);
		STATIC_OBJECT_ATTRIBUTES(oaRoot, "\\");
		AddDirectory(AddNode(0, &Directory, &root), _hwndTV, &tv, &oaRoot);
		DisplayNode(m_Root);
		HTREEITEM hitem = TreeView_GetChild(_hwndTV, TVI_ROOT);
		TreeView_Expand(_hwndTV, hitem, TVE_EXPAND);
		TreeView_SelectItem(_hwndTV, hitem);

		tv.item.iImage = 0;
		tv.item.iSelectedImage = 0;
		tv.item.pszText = L"All Types";
		tv.item.lParam = 0;
		tv.hParent = TVI_ROOT;
		tv.hParent = TreeView_InsertItem(_hwndTV, &tv);
		PUNICODE_STRING pus = m_TypeNames;
		tv.hInsertAfter = TVI_LAST;
		while (pus->Length)
		{
			ULONG hash;
			RtlHashUnicodeString(pus, FALSE, HASH_STRING_ALGORITHM_X65599, &hash);
			tv.item.iSelectedImage = tv.item.iImage = GetImageIndexByHash(hash);
			tv.item.pszText = pus->Buffer;
			tv.item.lParam = (LPARAM)pus;
			TreeView_InsertItem(_hwndTV, &tv);
			pus++;
		}

		ZSDIFrameWnd* pWnd = ZGLOBALS::getMainFrame();
		SendMessage(pWnd->ZStatusBar::getHWND(), SB_SETICON, (WPARAM)-1, 0);
		pWnd->SetStatusText(SB_SIMPLEID, L"");
		pWnd->EnableCmd(ID_COPY, FALSE);
		pWnd->EnableCmd(ID_SECURITY, FALSE);
		m_hash = 0;
		m_item = 0;
	}

	MySplit(int t) : ZSplitWnd(true, t, (HBRUSH)(1+COLOR_WINDOW))
	{
		_hFont = 0;
		_hFont2 = 0;
		m_Root = 0;
		m_hash = 0;
		m_bFullName = TRUE;
		m_bGrid = FALSE;
		m_nSelColum = -1;
		m_item = 0;
		RtlZeroMemory(m_TypeNames, sizeof(m_TypeNames));
		RtlZeroMemory(m_hi, sizeof(m_hi));
		static WORD id[] = { 301, 302, 303, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 317, 318, 319, 320, 322, 325, 330, 366, 367, 321 };
		_himl = CreateIL((HINSTANCE)&__ImageBase, 16, 16, ILC_COLOR32, RTL_NUMBER_OF(id), id, m_hi);
	}
};

class ZMainWnd : public ZSDIFrameWnd
{
	HWND _hwnd;

	virtual PCUNICODE_STRING getPosName()
	{
		STATIC_UNICODE_STRING_(MainWnd);
		return &MainWnd;
	}

	virtual BOOL CreateClient(HWND hwnd, int x, int y, int nWidth, int nHeight)
	{
		if (MySplit* p = new MySplit(nWidth>>2))
		{
			_hwnd = p->Create(0, 0, WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN, x, y, nWidth, nHeight, hwnd, 0, 0);
			p->Release();
		}

		return _hwnd != 0;
	}

	virtual BOOL CreateSB(HWND hwnd)
	{
		if (hwnd = ZStatusBar::Create(hwnd))
		{
			SendMessage(hwnd, SB_SIMPLE, TRUE, 0);
			return TRUE;
		}
		return FALSE;
	}

	BOOL CreateTB(HWND hwnd)
	{
		static TBBUTTON g_btns[] = {
			{IMAGE_ICON, ID_REFRESH, TBSTATE_ENABLED, BTNS_AUTOSIZE, {}, (DWORD_PTR)L" Refresh ", -1},
			{IMAGE_ICON, ID_SECURITY, 0, BTNS_AUTOSIZE, {}, (DWORD_PTR)L" Security Descriptor", -1},
			{IMAGE_ICON, ID_GRID, TBSTATE_ENABLED, BTNS_AUTOSIZE, {}, (DWORD_PTR)L" Display Grid ", -1},
			{IMAGE_ICON, ID_COPY, 0, BTNS_AUTOSIZE, {}, (DWORD_PTR)L" Copy Name ", -1},
			{IMAGE_ICON, ID_TOGGLE, 0, BTNS_AUTOSIZE, {}, (DWORD_PTR)L" Display Full path", -1},
		};

		int cxy = 32;
		switch (GetSystemMetrics(SM_CXSMICON)>>3)
		{
		case 0:
		case 1:
		case 2: cxy = 16;
			break;
		case 3: cxy = 24;
			break;
		}
		
		return ZToolBar::Create(hwnd, (HINSTANCE)&__ImageBase, 0, 0, cxy, cxy, g_btns, RTL_NUMBER_OF(g_btns), TRUE) != 0;
	}

	virtual LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_COMMAND:
			SendMessage(_hwnd, WM_COMMAND, wParam, 0);
			break;
		case WM_NOTIFY:
			if (AFX_IDW_STATUS_BAR == ((NMHDR*)lParam)->idFrom)
			{
				switch (((NMHDR*)lParam)->code)
				{
				case NM_RCLICK:
				case NM_CLICK:
					hwnd = ((NMHDR*)lParam)->hwndFrom;

					if (DWORD len = (DWORD)SendMessage(hwnd, SB_GETTEXTLENGTH, 0, 0))
					{
						PWSTR lpsz = (PWSTR)alloca(++len <<= 1);
						SendMessage(hwnd, SB_GETTEXT, 0, (LPARAM)lpsz);
						ClientToScreen(hwnd, &((LPNMMOUSE)lParam)->pt);
						if (HMENU hmenu = CreatePopupMenu())
						{
							MENUITEMINFO mii = { sizeof(mii), MIIM_ID|MIIM_STRING, 0, 0, 6, 0, 0, 0, 0, L"Copy" };
							InsertMenuItem(hmenu, 0, TRUE, &mii);

							if ((TrackPopupMenu(hmenu, TPM_NONOTIFY|TPM_RETURNCMD, 
								((LPNMMOUSE)lParam)->pt.x, ((LPNMMOUSE)lParam)->pt.y, 0, hwnd, 0) == 6) && OpenClipboard(hwnd))
							{
								EmptyClipboard();
								if (HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, len))
								{
									memcpy(GlobalLock(hg), lpsz, len);
									GlobalUnlock(hg);
									if (!SetClipboardData(CF_UNICODETEXT, hg)) GlobalFree(hg);
								}
								CloseClipboard();
							}
							DestroyMenu(hmenu);
						}
					}
					break;
				}
			}
			break;
		}
		return ZSDIFrameWnd::WindowProc(hwnd, uMsg, wParam, lParam);
	}
public:
	ZMainWnd()
	{
		_hwnd = 0;
	}
};

void zmain()
{
	ZGLOBALS globals;
	ZApp app;
	ZRegistry reg;
	ZFont font(TRUE);

	if (0 <= reg.Create(L"Software\\{9493D108-6D2D-4e29-9701-0A6E35125DAC}"))
	{
		HWND hwnd = 0;

		if (ZMainWnd* p = new ZMainWnd)
		{
			hwnd = p->ZSDIFrameWnd::Create(L"WinObj", (HINSTANCE)&__ImageBase, MAKEINTRESOURCE(IDR_MENU1), TRUE);// && font.Init()

			p->Release();
		}

		if (hwnd)
		{
			app.Run();
		}
	}
}

void ep(void*)
{
	initterm();
	zmain();
	destroyterm();

	ExitProcess(0);
}

_NT_END
