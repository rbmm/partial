#include "StdAfx.h"

extern "C"{
	PSTR __fastcall strnstr(SIZE_T n1, const void* str1, SIZE_T n2, const void* str2);
	PSTR __fastcall strnchr(SIZE_T n1, const void* str1, char c);
}

#define _strnstr(a, b, x) strnstr(RtlPointerToOffset(a, b), a, sizeof(x) - 1, x)
#define _strnstrL(a, b, x) strnstr(RtlPointerToOffset(a, b), a, strlen(x), x)
#define _strnchr(a, b, c) strnchr(RtlPointerToOffset(a, b), a, c)
#define _strnstrS(a, b, s, x) strnstr(RtlPointerToOffset(a, b), a, s, x)

#define LP(str) RTL_NUMBER_OF(str) - 1, str
#define PL(str) str, RTL_NUMBER_OF(str) - 1 

_NT_BEGIN

#include "undname.h"
#include "lineheap.h"
#include "pdb.h"
BOOL eprintf(PCWSTR format, ...);

static _lineHeap g_sh, g_nh;

__inline bool IsBeginSymbol(char c)
{
	switch (c)
	{
	case ' ':
	case ',':
	case '<':
	case '(':
	case '&':
		return true;
	}
	return false;
}

void SmartRemove(PSTR sz, PCSTR sbstr, ULONG len)
{
	PSTR end = sz + strlen(sz), c, to = 0, q = 0, from = 0, _sz = sz;

	while (c = _strnchr(sz, end, ':'))
	{
		if (*c == ':' && RtlPointerToOffset(sz, c) > len && !memcmp(q = c - len - 1, sbstr, len) && 
			(q == _sz || IsBeginSymbol(q[-1]) ))
		{
			if (to)
			{
				ULONG l = (ULONG)(q - from);
				memcpy(to, from, l);
				to += l;
			}
			else
			{
				to = q;
			}
			from = c + 1;
		}
		sz = c + 1;
	}

	if (to)
	{
		memcpy(to, from, 1 + end - from);
	}
}

void RemoveEmptyVoid(PSTR sz)
{
	PSTR end = sz + strlen(sz), c, to = 0, from = 0;

	while (c = _strnchr(sz, end, '('))
	{
		if (c[0] == 'v' && c[1] == 'o' && c[2] == 'i' && c[3] == 'd' && c[4] == ')')
		{
			if (to)
			{
				ULONG l = (ULONG)(c - from);
				memcpy(to, from, l);
				to += l;
			}
			else
			{
				to = c;
			}
			from = c + 4, sz = c + 5;
		}
		else 
		{
			sz = c;
		}
	}

	if (to)
	{
		memcpy(to, from, 1 + end - from);
	}
}

class CNameSpace : public RTL_AVL_TABLE
{
private:
	RTL_AVL_TABLE m_rat[3];
	PCSTR m_name;
	BOOLEAN m_bNamespace, m_bClass;

	static RTL_GENERIC_COMPARE_RESULTS NTAPI NameSpaceCompareRoutine(
		PRTL_AVL_TABLE, CNameSpace* FirstStruct, CNameSpace* SecondStruct
		)
	{
		int i = strcmp(FirstStruct->m_name, SecondStruct->m_name);
		if (i < 0) return GenericLessThan;
		if (0 < i) return GenericGreaterThan;
		return GenericEqual;
	}

	static RTL_GENERIC_COMPARE_RESULTS NTAPI SymbolCompareRoutine(
		PRTL_AVL_TABLE, PCSTR FirstStruct, PCSTR SecondStruct
		)
	{
		int i = strcmp(FirstStruct, SecondStruct);
		if (i < 0) return GenericLessThan;
		if (0 < i) return GenericGreaterThan;
		return GenericEqual;
	}

	static PVOID NTAPI AllocateRoutine(PRTL_AVL_TABLE ,CLONG ByteSize)
	{
		return g_sh.alloc(ByteSize);
	}

public:
	void* operator new(size_t cb) { return g_sh.alloc((DWORD)cb); }

	CNameSpace* InsertNamespace(PCSTR name)
	{
		BOOLEAN bNew;
		CNameSpace* pNS = (CNameSpace*)RtlInsertElementGenericTableAvl(this, &CNameSpace(name), sizeof(CNameSpace), &bNew);

		if (pNS && bNew)
		{
			pNS->m_name = g_nh.alloc(name);
			pNS->Init();
		}

		return pNS;
	}

	void InsertSymbol(int i, PSTR name)
	{
		if (i < 0)
		{
			i = 0;
		}
		else
		{
			m_bNamespace = FALSE;
			if (0 < i)
			{
				m_bClass = TRUE;
			}
		}

		ULONG len = (ULONG)strlen(name) + 1;
		BOOLEAN bNew;
		RtlInsertElementGenericTableAvl(m_rat + i, name, len, &bNew);
		//if (!bNew)
		//{
		//	__nop();
		//}
	}

	CNameSpace(PCSTR name) : m_name(name), m_bNamespace(TRUE), m_bClass(FALSE)
	{ 
	}

	void Init()
	{
		RtlInitializeGenericTableAvl(this, 
			(PRTL_AVL_COMPARE_ROUTINE)NameSpaceCompareRoutine, AllocateRoutine, 0, 0);

		int i = RTL_NUMBER_OF(m_rat) - 1;
		do 
		{
			RtlInitializeGenericTableAvl(m_rat + i, 
				(PRTL_AVL_COMPARE_ROUTINE)SymbolCompareRoutine, AllocateRoutine, 0, 0);
		} while(i--);
	}

	PSTR Dump(PSTR buf, int level = -1);

} g_ns("");

PSTR CNameSpace::Dump(PSTR buf, int level)
{
	char* prefix = "";
	if (0 < level) {
		prefix = (char*)alloca(1 + level);
		memset(prefix, '\t', level);
		prefix[level] = 0;
	}

	if (0 <= level) buf += sprintf(buf, "%s%s %s\r\n%s{\r\n", prefix, 
		m_bNamespace ? "namespace" : (m_bClass ? "class" : "struct"), m_name, prefix);

	if (CNameSpace *pNS = (CNameSpace*)RtlEnumerateGenericTableAvl(this, TRUE))
	{
		do 
		{
			buf = pNS->Dump(buf, level + 1);
		} while (pNS = (CNameSpace*)RtlEnumerateGenericTableAvl(this, FALSE));
	}

	int i = RTL_NUMBER_OF(m_rat) - 1, _i = m_bClass ? 2 : 0;
	PRTL_AVL_TABLE Table = m_rat + RTL_NUMBER_OF(m_rat);

	static const PSTR s_ppp[] = { "public", "protected", "private" };

	do 
	{
		if (PCSTR psz = (PCSTR)RtlEnumerateGenericTableAvl(--Table, TRUE))
		{
			if (i != _i)
			{
				buf += sprintf(buf, "%s%s:\r\n", prefix, s_ppp[i]);
			}
			do 
			{
				buf += sprintf(buf, level < 0 ? "%s%s;\r\n" : "%s\t%s;\r\n", prefix, psz);
			} while (psz = (PCSTR)RtlEnumerateGenericTableAvl(Table, FALSE));
		}
	} while(i--);

	if (0 <= level) buf += sprintf(buf, "%s};\r\n\r\n", prefix);

	return buf;
}

BOOL IsOperator(PCSTR name, PCSTR pc)
{
	// c == '<' { <, <=, <<, <<= }
	// c == '>' { ->, ->*, >>=, >> , >, >= }

	for (char c = *--pc; ; c = 0)
	{
		switch (*--pc)
		{
		case '-':
		case '>':
			if (c == '>')
			{
				continue;
			}
			return FALSE;
		case '<':
			if (c == '<')
			{
				continue;
			}
			return FALSE;
		case 'r':
			return pc - 6 > name &&
				pc[-1] == 'o' && 
				pc[-2] == 't' && 
				pc[-3] == 'a' && 
				pc[-4] == 'r' && 
				pc[-5] == 'e' && 
				pc[-6] == 'p' && 
				pc[-7] == 'o' &&
				(pc - 7 == name || pc[-8] < 'A');
		default:
			return FALSE;
		}
	}
}

BOOL AddSymbol(PSTR name)
{
	enum { max_short_len = 0x1000, max_full_len = 0x4000};

	PSTR ShortName = (PSTR)alloca(max_short_len), FullName = (PSTR)alloca(max_full_len);

	if (!_unDName(ShortName, name, max_short_len, 
		UNDNAME_NAME_ONLY|
		UNDNAME_NO_MS_KEYWORDS|
		UNDNAME_NO_ALLOCATION_MODEL|
		UNDNAME_NO_SPECIAL_SYMS
		)) 
	{
		return FALSE;
	}

	if (strchr(ShortName, '`') || *ShortName == '?') 
	{
		return FALSE;
	}

	if (!_unDName(FullName, name, max_full_len, 
		UNDNAME_NO_MS_KEYWORDS|
		UNDNAME_NO_ALLOCATION_MODEL|
		UNDNAME_NO_THISTYPE|
		UNDNAME_NO_THROW_SIGNATURES|
		UNDNAME_NO_RETURN_UDT_MODEL|
		UNDNAME_32_BIT_DECODE|
		UNDNAME_NO_SPECIAL_SYMS|
		UNDNAME_NO_ECSU
		)) return FALSE;

	if (strchr(FullName, '`')) 
	{
		return FALSE;
	}

#if 0
	if (strstr(FullName, "_StandardDestroyCB(_ITEMID_CHILD *,void *)"))
	{
		__nop();//IActivatableClassRegistration * *(void)
	}
#endif

	int i = -1;
	if (!strncmp(FullName, "public: ", 8)) i = 0, FullName += 8;
	else if (!strncmp(FullName, "protected: ", 11)) i = 1, FullName += 11;
	else if (!strncmp(FullName, "private: ", 9)) i = 2, FullName += 9;

	RemoveEmptyVoid(ShortName);
	RemoveEmptyVoid(FullName);

	PSTR a = strstr(FullName, ShortName), c = ShortName;

	if (!a)
	{
		return FALSE;
	}

	*a = 0, a += strlen(ShortName);

	int lock = 0;
	PCSTR szremove = 0;


	CNameSpace *pNS = &g_ns;
	ULONG len;

	for(;;) 
	{
		switch (*c++)
		{
		case ' ':
			if (lock)
			{
				continue;
			}

			if (!IsOperator(ShortName, c))
			{
				return FALSE;
			}
		case 0:
			if (lock)
			{
				return FALSE;
			}
			len = (ULONG)strlen(ShortName);
			if ((c = (PSTR)memcpy(FullName + strlen(FullName), ShortName, len) + len) != a)
			{
				strcpy(c, a);
			}
			pNS->InsertSymbol(i, FullName);
			return TRUE;

		case '<':
			if (!IsOperator(ShortName, c))
			{
				lock++;
			}
			continue;

		case '>':
			if (!IsOperator(ShortName, c))
			{
				if (!lock--)
				{
					return FALSE;
				}
			}
			continue;

		case ':':
			if (!lock)
			{
				if (*c != ':')
				{
					return FALSE;
				}

				c[-1] = 0;

				pNS = pNS->InsertNamespace(ShortName);

				SmartRemove(c, ShortName, (ULONG)strlen(ShortName));

				if (szremove)
				{
					len = (ULONG)strlen(szremove);
					SmartRemove(FullName, szremove, len);
					SmartRemove(a, szremove, len);
				}

				szremove = ShortName;

				ShortName = ++c;
			}
			continue;
		}
	}
}

extern "C"
{
	ULONG __fastcall strnlen(ULONG len, PCSTR sz);
}

C_ASSERT(sizeof(SYM_HEADER) == 4);
C_ASSERT(FIELD_OFFSET(PUBSYM32, pubsymflags) == 4);

NTSTATUS LoadPublicSymbols(PdbReader* pdb, PVOID sym, LONG size)
{
	union {
		PVOID pv;
		PBYTE pb;
		SYM_HEADER* psh;
		ANNOTATIONSYM* pas;
		PUBSYM32* pbs;
	};

	pv = sym;

	DWORD n = 0, len;

	PSTR name;

	do 
	{
		len = psh->len + sizeof(WORD);

		if ((size -= len) < 0) 
		{
			return STATUS_INVALID_IMAGE_FORMAT;
		}

		if (psh->type == S_PUB32)
		{
			name = pbs->name;
			// if (!c++) continue;
			if (*name != '?')
			{
				continue;
			}

			// if (??_C@_) continue;// string
			if (name[1] == '?' && name[2] == '_' && name[3] == 'C' && name[4] == '@' && name[5] == '_')
			{
				continue;
			}

			//if (!strcmp(name, "??0CRestrictedError@@QEAA@$$QEAV0@@Z"))
			//{
			//	__debugbreak();
			//}

			ULONG MaxCount = RtlPointerToOffset(name, pb + len);
			ULONG nlen = (ULONG)strnlen(MaxCount, name);
			if (nlen >= MaxCount)
			{
				return STATUS_INVALID_IMAGE_FORMAT;
			}

			if (ULONG rva = pdb->rva(pbs->seg, pbs->off))
			{
				if (AddSymbol(name))
				{
					n++;
				}
			}
		}

	} while (pb += len, size);

	return n ? STATUS_SUCCESS : STATUS_NOT_FOUND;
}

void DumpPublicSymbols(PdbReader* pdb, PVOID sym, LONG size, PWSTR lpsz)
{
	//char tst[] = "void fn<int a(void), void b(void*,void), void* c(void)>(void)";
	//RemoveEmptyVoid(tst);
	eprintf(L"search for public symbols...");

	if (!g_sh.Create(0x1000000, sizeof(PVOID)) || !g_nh.Create(0x100000, 1)) return;

	g_ns.Init();

	if (0 <= LoadPublicSymbols(pdb, sym, size))
	{
		PSTR buf = 0, end;
		SIZE_T RegionSize = 0x1000000;
		if (0 <= ZwAllocateVirtualMemory(NtCurrentProcess(), (void**)&buf, 0, &RegionSize, MEM_COMMIT, PAGE_READWRITE))
		{
			end = g_ns.Dump(buf);
			LARGE_INTEGER li;
			li.QuadPart = end - buf;
			HANDLE hFile;
			IO_STATUS_BLOCK iosb;

			PWSTR name = (PWSTR)alloca((wcslen(lpsz) + 8)<< 1);

			swprintf(name, L"%s.pub.h", lpsz);

			UNICODE_STRING ObjectName;
			OBJECT_ATTRIBUTES oa = { sizeof(oa), 0, &ObjectName };
			if (RtlDosPathNameToNtPathName_U(name, &ObjectName, 0, 0))
			{
				if (0 <= ZwCreateFile(&hFile, FILE_APPEND_DATA|SYNCHRONIZE, &oa, &iosb, &li, 0, 0, 
					FILE_OVERWRITE_IF, FILE_NON_DIRECTORY_FILE|FILE_SYNCHRONOUS_IO_NONALERT, 0, 0))
				{
					ZwWriteFile(hFile, 0, 0, 0, &iosb, buf, li.LowPart, 0, 0);
					ZwClose(hFile);
				}
				RtlFreeUnicodeString(&ObjectName);
			}

			ZwFreeVirtualMemory(NtCurrentProcess(), (void**)&buf, &RegionSize, MEM_RELEASE);
		}
	}
}

_NT_END