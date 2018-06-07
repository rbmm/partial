#include "stdafx.h"

_NT_BEGIN

#include "pdb.h"

extern "C"
{
	ULONG __fastcall strnlen(ULONG len, PCSTR sz);
}

#include "lineheap.h"

void SmartRemove(PSTR sz, PCSTR sbstr, ULONG len);
BOOL IsOperator(PCSTR name, PCSTR pc);
BOOL eprintf(PCWSTR format, ...);

BOOL IsUnnamedTag(PCSTR name)
{
	switch (*name++)
	{
	case '<': return !strcmp(name, "unnamed-tag>");
	case '_': return !strcmp(name, "_unnamed");
	}
	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////////////
// CLineHeap

static _lineHeap g_sh, g_nh;

//////////////////////////////////////////////////////////////////////////

char* xstrcpy(char * _Dst, const char * _Src)
{
	char c;
	do *_Dst++ = c = *_Src++; while(c);
	return _Dst - 1;
}

PCSTR GetBasicTypeName(CV_typ_t utype)
{
	switch (utype)
	{
	case T_CHAR32:
		return "CHAR32";
	case T_CHAR16:
		return "CHAR16";
	case T_NOTYPE:
		return "...";
	case T_VOID:
		return "void";
	case T_RCHAR:
	case T_CHAR:
		return "CHAR";
	case T_UCHAR:
		return "UCHAR";
	case T_INT8:
		return "__int8";
	case T_BOOL08:
		return "BOOLEAN";
	case T_WCHAR:
		return "WCHAR";
	case T_UINT8:
		return "unsigned __int8";
	case T_SHORT:
		return "SHORT";
	case T_USHORT:
		return "USHORT";
	case T_INT4:
		return "INT";
	case T_UINT4:
		return "UINT";
	case T_LONG:
		return "LONG";
	case T_ULONG:
		return "ULONG";
	case T_HRESULT:
		return "HRESULT";
	case T_QUAD:
		return "LONGLONG";
	case T_UQUAD:
		return "ULONGLONG";
	case T_REAL32:
		return "float";
	case T_REAL64:
		return "double";
	case T_REAL80:
		return "REAL80";
	case T_REAL128:
		return "REAL128";
	}

	__debugbreak();
	return "??";
}

ULONG GetBasicTypeLen(CV_typ_t utype)
{
	switch (utype)
	{
	case 0:
		return 0;
	case T_CHAR:
	case T_UCHAR:
	case T_RCHAR:
	case T_INT8:
	case T_BOOL08:
		return 1;
	case T_WCHAR:
	case T_UINT8:
	case T_SHORT:
	case T_USHORT:
		return 2;
	case T_INT4:
	case T_UINT4:
	case T_LONG:
	case T_ULONG:
	case T_HRESULT:
	case T_REAL32:
		return 4;
	case T_QUAD:
	case T_UQUAD:
	case T_REAL64:
		return 8;
	case T_REAL80:
		return 10;
	case T_REAL128:
		return 16;
	}

	__debugbreak();
	return 0;
}

struct ZType;
struct ZMember;

struct __declspec(novtable) VDump 
{
	virtual PSTR Dump(PSTR lpsz, PCSTR opt = 0) = 0;
};

struct ZBase 
{
	ZBase* _next;
	ZType* _type;
	ULONG _ofs;
	union {
		unsigned short _value;
		CV_fldattr_t _attr;
		CV_modifier_t _mod;
	};

	void* operator new(size_t cb)
	{
		return g_sh.alloc((LONG)cb);
	}
};

struct ZType 
{
	PCSTR _name;
	union {
		ZType* _pti; // for LF_BITFIELD, LF_ARRAY, LF_POINTER, LF_MODIFIER
		ZBase* _first;
		CV_typ_t _base; // for LF_ENUM
	};
	union {
		ZMember* _member;
		PCSTR _classname; // for LF_POINTER ( CV_PTR_MODE_PMEM | CV_PTR_MODE_PMFUNC)
	};
	union {
		LONG _len;
		struct  { // LF_PROCEDURE
			unsigned short  _parmcount;      // number of parameters
			CV_funcattr_t   _funcattr;       // attributes
			CV_call_e   _calltype;           // calling convention
		};
		struct { // LF_BITFIELD
			unsigned char   _length;
			unsigned char   _position;
		};
		CV_Pointer_t  _pAttr; // LF_POINTER
		CV_modifier_t _Modifier; // LF_MODIFIER
	};
	USHORT _leaf, _bProcessed;

	void* operator new(size_t cb)
	{
		return g_sh.alloc((LONG)cb);
	}

	ZType(USHORT leaf)
	{
		_leaf = leaf;
	}

	ZType(USHORT leaf, PSTR name)
	{
		RtlZeroMemory(this, sizeof(*this));
		_leaf = leaf, _name = name;
	}

	void Add(ZMember* pmi);
	void AddBaseType(ZType* pti, ULONG ofs, unsigned short value);

	ZType* getNestedType(PCSTR name);
	ZType* addNestedType(USHORT leaf, PCSTR name);

	PSTR Dump(PSTR lpsz, PSTR szLevel, int level, VDump* pDmp, LONG offset = 0);

	ULONG getSize()
	{
		if (CV_IS_PRIMITIVE((ULONG_PTR)this))
		{
			return GetBasicTypeLen((ULONG)(ULONG_PTR)this);
		}

		switch (_leaf)
		{
		case LF_MODIFIER:
			return _pti->getSize();
		case LF_POINTER:
			return _pAttr.size;
		case LF_ARRAY:
			return _pti->getSize() * _len;
		case LF_ENUM:
		case LF_CLASS:
		case LF_STRUCTURE:
		case LF_UNION:
			if (0 >= _len)
			{
				__debugbreak();
			}
			return _len;
		}

		__debugbreak();
		return 0;
	}
};

#ifdef _WIN64
C_ASSERT(sizeof(ZType) == 0x20);
#else
C_ASSERT(sizeof(ZType) == 0x14);
#endif

struct ZMember 
{
	PCSTR _name;
	ZMember* _next;
	ZType* _type;
	union {
		LONG _offset;
		LONG _value; // _leaf == LF_ENUMERATE
	};
	CV_fldattr_t _attr;
	USHORT _leaf;

	ZMember(USHORT leaf)
	{
		_leaf = leaf;
	}

	void* operator new(size_t cb)
	{
		return g_sh.alloc((LONG)cb);
	}

	PSTR Dump(PSTR lpsz, int level);
};

ZType* ZType::getNestedType(PCSTR name)
{
	if (ZMember* member = _member)
	{
		do 
		{
			if (member->_leaf == LF_NESTTYPE)
			{
				if (!strcmp(member->_type->_name, name))
				{
					return member->_type;
				}
			}
			else
			{
				return 0;
			}
		} while (member = member->_next);
	}

	return 0;
}

ZType* ZType::addNestedType(USHORT leaf, PCSTR name)
{
	//if (!strcmp(name, unnamed_tag))
	//{
	//	__nop();
	//}
	ZMember* pmi = new ZMember(LF_NESTTYPE);
	ZType* pti = new ZType(leaf);
	pmi->_type = pti;
	pti->_name = g_nh.alloc(name);
	pmi->_next = _member;
	pmi->_attr.access = _leaf == LF_CLASS ? CV_private : CV_public;
	_member = pmi;
	return pti;
}

struct NameDump : VDump 
{
	PCSTR _name;

	NameDump(PCSTR name)
	{
		_name = name;
	}

	virtual PSTR Dump(PSTR lpsz, PCSTR /*opt = 0*/)
	{
		return xstrcpy(lpsz, _name);
	}
};

STATIC_ASTRING(mconst, "const ");
STATIC_ASTRING(mvolatile, "volatile ");
STATIC_ASTRING(m__unaligned, "__unaligned ");
struct PtrDump : VDump
{
	VDump* _p;
	CV_Pointer_t _attr;
	PCSTR _name;

	PtrDump(VDump* p, CV_Pointer_t attr, PCSTR name)
	{
		_p = p, _attr = attr, _name = name;
	}

	virtual PSTR Dump(PSTR lpsz, PCSTR opt)
	{
		if (opt)
		{
			*lpsz++ = '(';
		}

		switch (_attr.ptrmode)
		{
		case CV_PTR_MODE_PMFUNC:
			if (!opt || !_name || strcmp(opt, _name))
			{
				__debugbreak();
			}
		case CV_PTR_MODE_PMEM:
			lpsz += sprintf(lpsz, "%s::", _name);
		case CV_PTR_MODE_PTR:
			*lpsz++ = '*';
			break;
		case CV_PTR_MODE_RVREF:
			*lpsz++ = '&';
		case CV_PTR_MODE_REF:
			*lpsz++ = '&';
			break;
		default:
			__debugbreak();
		}

		*lpsz++ = ' ';

		if (_attr.isconst)
		{
			lpsz = xstrcpy(lpsz, mconst);
		}

		if (_attr.isvolatile)
		{
			lpsz = xstrcpy(lpsz, mvolatile);
		}

		if (_attr.isunaligned)
		{
			lpsz = xstrcpy(lpsz, m__unaligned);
		}

		lpsz = _p->Dump(lpsz);

		if (opt)
		{
			*lpsz++ = ')';
		}

		return lpsz;
	}
};

struct ModDump : VDump
{
	VDump* _p;
	CV_modifier_t _Modifier;

	ModDump(VDump* p, CV_modifier_t Modifier)
	{
		_p = p, _Modifier = Modifier;
	}

	virtual PSTR Dump(PSTR lpsz, PCSTR opt)
	{
		if (_Modifier.MOD_const)
		{
			lpsz = xstrcpy(lpsz, mconst);
		}

		if (_Modifier.MOD_unaligned)
		{
			lpsz = xstrcpy(lpsz, m__unaligned);
		}

		if (_Modifier.MOD_volatile)
		{
			lpsz = xstrcpy(lpsz, mvolatile);
		}

		lpsz = _p->Dump(lpsz, opt);

		return lpsz;
	}
};

struct ArrDump : VDump
{
	VDump* _p;
	ULONG _n;

	ArrDump(VDump* p, ULONG n)
	{
		_p = p, _n = n;
	}

	virtual PSTR Dump(PSTR lpsz, PCSTR /*opt*/)
	{
		lpsz = _p->Dump(lpsz, "");
		
		return _n ? lpsz + sprintf(lpsz, "[0x%x]", _n) : xstrcpy(lpsz, "[]");
	}
};

struct BitsDump : VDump
{
	VDump* _p;
	UCHAR _length, _position;
	USHORT _size;

	BitsDump(VDump* p, UCHAR length, UCHAR position, USHORT size)
	{
		_p = p, _length = length, _position = position, _size = size;
	}

	virtual PSTR Dump(PSTR lpsz, PCSTR /*opt*/)
	{
		lpsz = _p->Dump(lpsz);

		lpsz += sprintf(lpsz, " : %02u; // ", _length);

		PCSTR format = 0;
		switch (_size)
		{
		case 1:
			format = "0x%02x";
			break;
		case 2:
			format = "0x%04x";
			break;
		case 4:
			format = "0x%08x";
			break;
		case 8:
			lpsz += sprintf(lpsz, "0x%016I64x", ((1ULL << _length) - 1) << _position);
			break;
		default: lpsz += sprintf(lpsz, "[??] %x/%x", _position, 1 << _size);
		}

		if (format)
		{
			lpsz += sprintf(lpsz, format, ((1UL << _length) - 1) << _position);
		}

		return lpsz;
	}
};

char gszLevel[64];

struct ProcDump : VDump 
{
	VDump* _p;
	ZBase* _param;
	CV_call_e _calltype;

	ProcDump(VDump* p, ZBase* param, CV_call_e calltype)
	{
		_p = p, _param = param, _calltype = calltype;
	}

	virtual PSTR Dump(PSTR lpsz, PCSTR /*opt*/)
	{
		lpsz = _p->Dump(lpsz, "");
		*lpsz++ = '(';
		if (ZBase* param = _param)
		{
			NameDump arg("");
			do 
			{
				*lpsz++ = ' ';
				lpsz = param->_type->Dump(lpsz, gszLevel + RTL_NUMBER_OF(gszLevel) - 1, 0, &arg);
				*lpsz++ = ',';
			} while (param = param->_next);
			--lpsz;
		}
		*lpsz++ = ')';

		return lpsz;
	}
};

struct MProcDump : VDump 
{
	VDump* _p;
	ZBase* _param;
	CV_call_e _calltype;
	CV_modifier_t _mod;
	PCSTR _classname;

	MProcDump(VDump* p, ZBase* param, CV_call_e calltype, CV_modifier_t mod, PCSTR classname)
	{
		_p = p, _param = param, _calltype = calltype, _mod = mod, _classname = classname;
	}

	virtual PSTR Dump(PSTR lpsz, PCSTR /*opt*/)
	{
		lpsz = _p->Dump(lpsz, _classname);
		*lpsz++ = '(';
		if (ZBase* param = _param)
		{
			NameDump arg("");
			do 
			{
				*lpsz++ = ' ';
				lpsz = param->_type->Dump(lpsz, "", 0, &arg);
				*lpsz++ = ',';
			} while (param = param->_next);
			--lpsz;
		}
		*lpsz++ = ')';

		if (_mod.MOD_const)
		{
			lpsz = xstrcpy(lpsz, " const");
		}

		return lpsz;
	}
};

struct CNS : RTL_AVL_TABLE
{
	PCSTR _name;
	CNS* _next;
	CNS* _child;
	ZType* _first;

	void* operator new(size_t cb)
	{
		return g_sh.alloc((LONG)cb);
	}

	static RTL_GENERIC_COMPARE_RESULTS NTAPI CompareRoutine(PRTL_AVL_TABLE, PVOID FirstStruct, PVOID SecondStruct)
	{
		int i = strcmp(((ZType*)FirstStruct)->_name, ((ZType*)SecondStruct)->_name);
		if (i < 0) return GenericLessThan;
		if (0 < i) return GenericGreaterThan;
		return GenericEqual;
	}

	static PVOID NTAPI AllocateRoutine(PRTL_AVL_TABLE, CLONG ByteSize)
	{
		return g_sh.alloc(ByteSize);
	}

	ZType* GetType(PCSTR name)
	{
		return (ZType*)RtlLookupElementGenericTableAvl(this, &name);
	}

	ZType* InsertType(USHORT leaf, PSTR name)
	{
		BOOLEAN NewElement;
		ZType ti(leaf, name), *pti;
		if (pti = (ZType*)RtlInsertElementGenericTableAvl(this, &ti, sizeof(ti), &NewElement))
		{
			if (NewElement)
			{
				pti->_name = g_nh.alloc(name);
			}
			return pti;
		}

		__debugbreak();
		return 0;
	}

	CNS* _AddChild(PCSTR name)
	{
		if (name = g_nh.alloc(name))
		{
			if (CNS* pns = new CNS(name))
			{
				pns->_next = _child;
				_child = pns;
				return pns;
			}
		}

		__debugbreak();
		return 0;
	}

	CNS(PCSTR name = 0)
	{
		_name = name;
		_next = 0, _child = 0;
		RtlInitializeGenericTableAvl(this, CompareRoutine, AllocateRoutine, 0, 0);
	}

	CNS* FindChild(PCSTR name)
	{
		if (CNS* pns = _child)
		{
			do 
			{
				if (!strcmp(name, pns->_name))
				{
					return pns;
				}
			} while (pns = pns->_next);
		}

		return 0;
	}

	CNS* AddChild(PCSTR name)
	{
		CNS* pns = FindChild(name);

		return pns ? pns : _AddChild(name);
	}

	PSTR Dump(PSTR lpsz, PSTR szLevel, int level);

} g_NS;

PCSTR getAccessName(CV_access_e access)
{
	switch (access)
	{
	case CV_private: return "private";
		break;
	case CV_protected: return "protected";
		break;
	case CV_public: return "public";
		break;
	}

	__debugbreak();
	return 0;
}

PSTR ZType::Dump(PSTR lpsz, PSTR szLevel, int level, VDump* pDmp, LONG offset)
{
	if (level > 16)
	{
		__debugbreak();
	}

	if (CV_IS_PRIMITIVE((ULONG_PTR)this))
	{
		lpsz = xstrcpy(lpsz, GetBasicTypeName((CV_typ_t)(ULONG_PTR)this));
		*lpsz++ = ' ';
		return pDmp->Dump(lpsz);
	}

	if (pDmp && _name)
	{
		//if (*_name == '<')
		//{
		//	__nop();
		//}
		lpsz = xstrcpy(lpsz, _name);
		*lpsz++ = ' ';
		return pDmp->Dump(lpsz);
	}

	PCSTR pcszUDTtype = 0;

	union {
		ZType* pti;
		ZBase* pb;
		CV_typ_t base;
	};

	pti = _pti;

	LONG ofs;
	USHORT leaf = _leaf;

	switch (leaf)
	{
	case LF_CLASS:
		pcszUDTtype = "class";
		break;
	case LF_STRUCTURE:
		pcszUDTtype = "struct";
		break;
	case LF_UNION:
		pcszUDTtype = "union";
		break;
	case LF_ENUM:
		pcszUDTtype = "enum";
		break;
	case LF_PROCEDURE:
		{
			ProcDump proc(pDmp, pb->_next, _calltype);
			return pb->_type->Dump(lpsz, szLevel, level, &proc);
		}
	case LF_MFUNCTION:
		{
			ZBase* ret = pb->_next;
			MProcDump proc(pDmp, ret->_next, _calltype, pb->_mod, pb->_type->_name);
			return ret->_type->Dump(lpsz, szLevel, level, &proc);
		}
	case LF_ARRAY:
		{
			ArrDump ad(pDmp, _len);
			return pti->Dump(lpsz, szLevel, level, &ad);
		}
	case LF_POINTER:
		{
			PtrDump ptr(pDmp, _pAttr, _classname);
			return pti->Dump(lpsz, szLevel, level, &ptr);
		}
	case LF_MODIFIER:
		{
			ModDump mod(pDmp, _Modifier);
			return pti->Dump(lpsz, szLevel, level, &mod);
		}
	case LF_BITFIELD:
		{
			BitsDump bits(pDmp, _length, _position, (USHORT)pti->getSize());
			return pti->Dump(lpsz, szLevel, level, &bits);
		}
	default:
		__debugbreak();
	}

	if (pDmp)
	{
		szLevel--, level++, lpsz -= 9;
	}

	if (!pDmp)
	{
		lpsz += sprintf(lpsz, "\r\n%s", szLevel);
	}

	lpsz = xstrcpy(lpsz, pcszUDTtype);
	*lpsz++ = ' ';

	if (_name && *_name != '<')
	{
		lpsz = xstrcpy(lpsz, _name);
		*lpsz++ = ' ';
	}

	if (!_bProcessed)
	{
		lpsz[-1] = ';', lpsz[0] = '\r', lpsz[1] = '\n';
		return lpsz + 2;
	}

	PCSTR pcsz;

	switch (leaf)
	{
	case LF_ENUM:
		switch (base)
		{
		case T_NOTYPE:
		case T_INT4:
		case T_LONG:
			break;
		default: 
			lpsz[0] = ':', lpsz[1] = ' ';
			lpsz = xstrcpy(lpsz + 2, GetBasicTypeName(_base));
			*lpsz++ = ' ';
		}
		break;
	case LF_CLASS:
	case LF_STRUCTURE:
		if (pb)
		{
			char c = ':';
			do 
			{
				pcsz = "";
				switch (pb->_attr.access)
				{
				case CV_private: if (leaf != LF_CLASS) pcsz = "private ";
					break;
				case CV_protected: pcsz = "protected ";
					break;
				case CV_public: if (leaf != LF_STRUCTURE) pcsz = "public ";
					break;
				default:
					__debugbreak();
				}

				lpsz += sprintf(lpsz, pb->_attr.sealed ? "%c %svirtual %s" : "%c %s%s", c, pcsz, pb->_type->_name);
				
				c = ',';

			} while (pb = pb->_next);
			
			*lpsz++ = ' ';
		}
		break;
	}
	
	*lpsz++ = '{';

	if (ZMember* member = _member)
	{
		CV_access_e access = leaf == LF_CLASS ? CV_private : CV_public;
		do 
		{
			if (member->_attr.access != access)
			{
				lpsz += sprintf(lpsz, "\r\n%s%s:", szLevel, getAccessName(access = (CV_access_e)member->_attr.access));
			}

			lpsz += sprintf(lpsz, "\r\n%s\t", szLevel);

			NameDump nd(member->_name);
			pti = member->_type;

			// LF_NESTTYPE, LF_ENUMERATE, LF_MEMBER, LF_STMEMBER, LF_METHOD
			switch (member->_leaf)
			{
			case LF_NESTTYPE:
				if ((pcsz = pti->_name) && *pcsz != '<')
				{
					lpsz = pti->Dump(lpsz - 1, szLevel - 1, level + 1, 0);
				}
				continue;

			case LF_ENUMERATE:
				lpsz += sprintf(lpsz, "%s = 0x%x,", member->_name, member->_value);
				continue;

			case LF_STMEMBER:
				lpsz = pti->Dump(xstrcpy(lpsz, "static "), szLevel, level, &nd);
				break;

			case LF_MEMBER:
				ofs = offset + member->_offset;
				lpsz = pti->Dump(lpsz + sprintf(lpsz, "/*%04x*/ ", ofs), szLevel, level, &nd, ofs);
				break;

			case LF_METHOD:
				if (member->_type->_leaf == LF_MFUNCTION)
				{
					ZBase* first = member->_type->_first;
					BOOL pure = FALSE;

					switch (member->_attr.mprop)
					{
					case CV_MTpurevirt:
						pure = TRUE;
					case CV_MTvirtual:
						lpsz = xstrcpy(lpsz, "/*    */ virtual ");
						break;
					case CV_MTstatic:
						if (!first->_mod.MOD_static)
						{
							__debugbreak();
						}
						lpsz = xstrcpy(lpsz, "static ");
						break;
					case CV_MTpureintro:
						pure = TRUE;
					case CV_MTintro:
						lpsz += sprintf(lpsz, "/*%04x*/ virtual ", member->_offset);
						break;
					}

					lpsz = pti->Dump(lpsz, szLevel, level, &nd);

					if (pure)
					{
						lpsz = xstrcpy(lpsz, " = 0");
					}
				}
				else
				{
					__debugbreak();
				}
				break;

			default:
				__debugbreak();
			}

			*lpsz++ = ';';

		} while (member = member->_next);
	}

	if (_len)
	{
		switch(leaf)
		{
		case LF_STRUCTURE:
		case LF_CLASS:
		case LF_UNION:
			lpsz += sprintf(lpsz, "\r\n%s\t/*%04x*/", szLevel, offset + _len);
			break;
		case LF_ENUM:
			lpsz--;
			break;
		}
	}

	return pDmp 
		? pDmp->Dump(lpsz + sprintf(lpsz, "\r\n%s} ", szLevel))
		: lpsz + sprintf(lpsz, "\r\n%s};\r\n", szLevel);
}

PSTR CNS::Dump(PSTR lpsz, PSTR szLevel, int level)
{
	if (_name)
	{
		lpsz += sprintf(lpsz, "\r\n%snamespace %s {\r\n", szLevel, _name);
		level++, szLevel--;

		//if (_name[0]=='w'&&_name[1]=='i'&&_name[2]=='l'&&_name[3]==0)
		//{
		//	__debugbreak();
		//}
	}

	if (CNS* child = _child)
	{
		do 
		{
			lpsz = child->Dump(lpsz, szLevel, level);
		} while (child = child->_next);
	}

	while (ZType* pti = (ZType*)RtlEnumerateGenericTableAvl(this, FALSE))
	{
		lpsz = pti->Dump(lpsz, szLevel, level, 0);
	}

	if (_name)
	{
		lpsz += sprintf(lpsz, "\r\n%s}\r\n", szLevel + 1);
	}

	return lpsz;
}

void ZType::Add(ZMember* pmi)
{
	ZMember** pp = &_member, *p;
	while(p = *pp)
	{
		pp = &p->_next;
	}

	*pp = pmi;
	pmi->_next = 0;
}

void ZType::AddBaseType(ZType* pti, ULONG ofs, unsigned short value)
{
	if (ZBase* pb = new ZBase)
	{
		pb->_next = 0;
		pb->_type = pti;
		pb->_ofs = ofs;
		pb->_value = value;

		ZBase** pp = &_first, *p;

		while (p = *pp)
		{
			pp = &p->_next;
		}

		*pp = pb;
	}
}

//////////////////////////////////////////////////////////////////////////
STATIC_ASTRING(tmptst, "PARAM_DESCRIPTION");

ZType* getType(USHORT leaf, CV_prop_t property, PSTR name)
{
	//if (!memcmp(name, tmptst, sizeof(tmptst)-1))
	//{
	//	__nop();
	//}

	int lock = 0;

	PSTR c = name; 
	CNS* pns = &g_NS, *p;
	ZType* pti = 0;

	for(;;) 
	{
		switch (*c++)
		{
		case ' ':
			if (lock)
			{
				continue;
			}
			if (!IsOperator(name, c))
			{
				__debugbreak();
			}
		case 0:
			if (lock)
			{
				return 0;
				//__debugbreak();
			}

			if (IsUnnamedTag(name))
			{
				return new ZType(leaf);
			}

			if (property.isnested)
			{
				if (!pti || !(pti = pti->getNestedType(name)))
				{
					__debugbreak();
				}
			}
			else
			{
				if (!(pti = pns->GetType(name)))
				{
					__debugbreak();
				}
			}
			return pti;


		case '<':
			if (!IsOperator(name, c))
			{
				lock++;
			}
			continue;

		case '>':
			if (!IsOperator(name, c))
			{
				if (!lock--)
				{
					__debugbreak();
				}
			}
			continue;

		case ':':
			if (!lock)
			{
				if (*c != ':')
				{
					__debugbreak();
				}

				c[-1] = 0;

				SmartRemove(c, name, (ULONG)strlen(name));

				if (pti)
				{
					if (!(pti = pti->getNestedType(name)))
					{
						__debugbreak();
					}
				}
				else
				{
					if (p = pns->FindChild(name))
					{
						pns = p;
					}
					else
					{
						if (property.isnested)
						{
							if (!(pti = pns->GetType(name)))
							{
								__debugbreak();
							}
						}
						else
						{
							__debugbreak();
						}
					}
				}

				c[-1] = ':';

				name = ++c;
			}
			continue;
		}
	}
}

void InsertNestedUDT(USHORT leaf, CV_prop_t property, PSTR name, ULONG len)
{
	if ((property.value & (prop_isnested|prop_scoped)) == prop_isnested)
	{
		//if (!strcmp(name, "_userSTGMEDIUM::_STGMEDIUM_UNION"))__debugbreak();
		int lock = 0;

		PSTR c = name; 
		CNS* pns = &g_NS, *p;
		ZType* pti = 0, *pt;

		for(;;) 
		{
			switch (*c++)
			{
			case ' ':
				if (lock)
				{
					continue;
				}
				if (!IsOperator(name, c))
				{
					__debugbreak();
				}

			case 0:
				if (lock || !pti)
				{
					return;
					//__debugbreak();
				}

				if (!IsUnnamedTag(name))
				{
					if (pt = pti->getNestedType(name))
					{
						pt->_leaf = leaf;
						if (!property.fwdref)
						{
							pt->_len = len;
						}
					}
					else
					{
						if (pti = pti->addNestedType(leaf, name))
						{
							if (!property.fwdref)
							{
								pti->_len = len;
							}
						}
						else
						{
							__debugbreak();
						}
					}
				}
				return;

			case '<':
				if (!IsOperator(name, c))
				{
					lock++;
				}
				continue;

			case '>':
				if (!IsOperator(name, c))
				{
					if (!lock--)
					{
						__debugbreak();
					}
				}
				continue;

			case ':':
				if (!lock)
				{
					if (*c != ':')
					{
						__debugbreak();
					}

					c[-1] = 0;

					SmartRemove(c, name, (ULONG)strlen(name));

					if (pti)
					{
						if (pt = pti->getNestedType(name))
						{
							pti = pt;
						}
						else
						{
							if (!(pti = pti->addNestedType(0, name)))// leaf is unknown!!
							{
								__debugbreak();
							}
						}
					}
					else
					{
						if (p = pns->FindChild(name))
						{
							pns = p;
						}
						else
						{
							if (!(pti = pns->GetType(name)))
							{
								//__debugbreak();
								pti = pns->InsertType(LF_STRUCTURE, name);// ???
							}
						}
					}

					c[-1] = ':';

					name = ++c;
				}
				continue;
			}
		}
	}
}

void InsertUDT(USHORT leaf, CV_prop_t property, PSTR name, ULONG len)
{
	//if (strstr(name, "supports_cleanup<IKeyValuePair<EventRegistrationToken,int> *>"))
	//{
	//	__debugbreak();
	//}
	// only top types
	//static ULONG stmp[4];
	//if (!property.fwdref)
	//{
	//	switch (property.value & (prop_isnested|prop_scoped))
	//	{
	//	case 0: stmp[0]++;
	//		break;
	//	case prop_isnested: stmp[1]++;
	//		break;
	//	case prop_scoped: stmp[2]++;
	//		break;
	//	case prop_isnested|prop_scoped: stmp[3]++;
	//		break;
	//	default: __assume(false);
	//	}
	//}

	if (!(property.value & (prop_isnested|prop_scoped)))
	{
		int lock = 0;
		ZType* pti = 0;

		//if (!strcmp(name, "_SYSTEM_POWER_STATE_CONTEXT"))__debugbreak();
		PSTR c = name; 
		CNS* pns = &g_NS;
		for(;;) 
		{
			switch (*c++)
			{
			case ' ':
				if (lock)
				{
					continue;
				}
				if (!IsOperator(name, c))
				{
					__debugbreak();
				}

			case 0:
				if (!IsUnnamedTag(name))
				{
					if (lock || !(pti = pns->InsertType(leaf, name)))
					{
						return;
						//__debugbreak();
					}
					if (!property.fwdref)
					{
						pti->_len = len;
					}
				}
				return;

			case '<':
				if (!IsOperator(name, c))
				{
					lock++;
				}
				continue;

			case '>':
				if (!IsOperator(name, c))
				{
					if (!lock--)
					{
						__debugbreak();
					}
				}
				continue;

			case ':':
				if (!lock)
				{
					if (*c != ':')
					{
						__debugbreak();
					}

					c[-1] = 0;

					pns = pns->AddChild(name);

					SmartRemove(c, name, (ULONG)strlen(name));

					c[-1] = ':';

					name = ++c;
				}
				continue;
			}
		}
	}
}

PSTR GetLastNameComponent(PSTR name)
{
	int lock = 0;

	PSTR c = name; 
	for(;;) 
	{
		switch (*c++)
		{
		case 0:
			if (lock)
			{
				__debugbreak();
			}
			return name;

		case '<':
			if (!IsOperator(name, c))
			{
				lock++;
			}
			continue;

		case '>':
			if (!IsOperator(name, c))
			{
				if (!lock--)
				{
					__debugbreak();
				}
			}
			continue;

		case ':':
			if (!lock)
			{
				if (*c != ':')
				{
					__debugbreak();
				}

				SmartRemove(c, name, (ULONG)strlen(name));
				name = ++c;
			}
			continue;
		}
	}
}

ULONG IsNameOk(lfRecord* plr, PCSTR name, ULONG len)
{
	ULONG size = RtlPointerToOffset(plr, name);
	return size < len && (size += strnlen(len - size, name)) < len ? 1 + size : 0;
}

BOOL FillOfs(TYPTYPE* ptr, LONG cb, ULONG dTypes, PULONG pOfs)
{
	ULONG ofs = sizeof(USHORT);

	do 
	{
		if (0 > (cb -= sizeof(USHORT)))
		{
			return FALSE;
		}

		ULONG len = ptr->len;
		LONG length;

		if (len < sizeof(USHORT) || (0 > (cb -= len)))
		{
			return FALSE;
		}

		*pOfs++ = ofs, ofs += len + sizeof(USHORT);

		lfRecord* plr = &ptr->u;

		PSTR name;

		switch (plr->leaf)
		{
		case LF_ENUM:
			if (len <= sizeof(lfEnum) || !IsNameOk(plr, plr->Enum.name, len) )
			{
				return FALSE;
			}
			InsertUDT(LF_ENUM, plr->Enum.property, plr->Enum.name, GetBasicTypeLen(plr->Enum.utype));
			break;

		case LF_UNION:
			if (
				len <= sizeof(lfUnion) 
				|| 
				!plr->Union.length_name.value(&length, &name) 
				||
				!IsNameOk(plr, name, len)
				)
			{
				return FALSE;
			}
			InsertUDT(LF_UNION, plr->Union.property, name, length);
			break;

		case LF_CLASS:
		case LF_STRUCTURE:
			if (
				len <= sizeof(lfClass) 
				|| 
				!plr->Class.length_name.value(&length, &name) 
				||
				!IsNameOk(plr, name, len)
				)
			{
				return FALSE;
			}
			InsertUDT(plr->leaf, plr->Class.property, name, length);

			break;
		}

		ptr = ptr->Next();

	} while (--dTypes);

	return TRUE;
}

#undef DbgPrint

class TiEnum
{
	PVOID _Base;
	PULONG _pOfs;
	ULONG _tiMin, _dTypes;
	BOOL _Is64Bit;

public:
	
	TiEnum(PVOID Base, PULONG pOfs, ULONG tiMin, ULONG dTypes, BOOL Is64Bit)
	{
		_Base = Base, _pOfs = pOfs, _tiMin = tiMin, _dTypes = dTypes, _Is64Bit = Is64Bit;
	}

	ZType* ExpandUdt(ZType* pType, USHORT parmcount, CV_typ_t rvtype, CV_typ_t arglist);

	BOOL ProcessFieldList(ZType* pType, CV_typ_t field);

	void Round2();
	void Round3();
	ZType* CreateUDT(lfRecord* plr, BOOL bRecursive);
	ZType* _CreateUDT(CV_typ_t utype);

	lfRecord* IndexToType(CV_typ_t utype)
	{
		if ((utype -= _tiMin) >= _dTypes)
		{
			__debugbreak();
			return FALSE;
		}

		return (lfRecord*)RtlOffsetToPointer(_Base, _pOfs[utype]);
	}
};

void TiEnum::Round2()
{
	CV_typ_t index = _dTypes;
	PVOID Base = _Base;
	PULONG pOfs = _pOfs;
	LONG len;
	PSTR name = 0;
	do 
	{
		lfRecord* plr = (lfRecord*)RtlOffsetToPointer(Base, pOfs[--index]);
			
		//if (index == 0x735a) __debugbreak();

		switch (plr->leaf)
		{
		case LF_ENUM:
			InsertNestedUDT(LF_ENUM, plr->Enum.property, plr->Enum.name, GetBasicTypeLen(plr->Enum.utype));
			break;

		case LF_UNION:
			plr->Union.length_name.value(&len, &name);
			InsertNestedUDT(LF_UNION, plr->Union.property, name, len);
			break;

		case LF_CLASS:
		case LF_STRUCTURE:
			plr->Class.length_name.value(&len, &name);
			InsertNestedUDT(plr->leaf, plr->Class.property, name, len);
			break;
		}
	} while (index);
}

void TiEnum::Round3()
{
	PVOID Base = _Base;
	PULONG pOfs = _pOfs;

	CV_typ_t index = _dTypes;
	do 
	{
		CreateUDT((lfRecord*)RtlOffsetToPointer(Base, pOfs[--index]), FALSE);
	} while (index);
}

ZType* TiEnum::_CreateUDT(CV_typ_t utype)
{
	if (CV_IS_PRIMITIVE(utype))
	{
		if (utype == T_PVOID)
		{
			utype = _Is64Bit ? T_64PVOID : T_32PVOID;
		}
		ULONG len = 0;
		switch (utype >> 8)
		{
		case 0:
			break;
		case 0x04:
			len = 4;
			break;
		case 0x06:
			len = 8;
			break;
		default:
			__debugbreak();
			return 0;
		}

		switch (utype &= 0xff)
		{
		case T_CHAR:
		case T_UCHAR:
		case T_RCHAR:
		case T_WCHAR:
		case T_INT8:
		case T_UINT8:
		case T_INT4:
		case T_UINT4:
		case T_LONG:
		case T_ULONG:
		case T_SHORT:
		case T_USHORT:
		case T_VOID:
		case T_HRESULT:
		case T_QUAD:
		case T_UQUAD:
		case T_BOOL08:
		case T_REAL32:
		case T_REAL64:
		case T_REAL80:
		case T_REAL128:
		case T_CHAR32:
		case T_CHAR16:
			break;
		default:__debugbreak();
		}

		if (len)
		{
			ZType* pType = new ZType(LF_POINTER);
			pType->_pti = (ZType*)(utype & 0xff);
			pType->_pAttr.value = 0;
			//pType->_pAttr.ptrmode = CV_PTR_MODE_PTR; // CV_PTR_MODE_PTR == 0
			pType->_pAttr.ptrtype = _Is64Bit ? CV_PTR_64 : CV_PTR_NEAR32;
			pType->_pAttr.size = len;
			return pType;
		}

		return (ZType*)(ULONG_PTR)utype;
	}
	else
	{
		return CreateUDT(IndexToType(utype), TRUE);
	}
}

ZType* TiEnum::CreateUDT(lfRecord* plr, BOOL bRecursive)
{
	ZType* pti;
	ULONG cb;
	PSTR name;
	LONG len;
	CV_modifier_t attr;

	switch (plr->leaf)
	{
	case LF_MODIFIER:
		if (bRecursive)
		{
			if (*((PUSHORT)plr - 1) < sizeof(lfModifier))
			{
				__debugbreak();
			}

			pti = new ZType(LF_MODIFIER);
			pti->_Modifier = plr->Modifier.attr;
			pti->_pti = _CreateUDT(plr->Modifier.type);
			return pti;
		}
		break;

	case LF_POINTER:
		if (bRecursive)
		{
			if (*((PUSHORT)plr - 1) < sizeof(lfPointerBody))
			{
				__debugbreak();
			}
			pti = new ZType(LF_POINTER);

			switch (plr->Pointer.attr.ptrmode)
			{
			case CV_PTR_MODE_PTR:
			case CV_PTR_MODE_REF:
				if (!plr->Pointer.attr.size)
				{
					switch (plr->Pointer.attr.ptrtype)
					{
					case CV_PTR_NEAR32:
						plr->Pointer.attr.size = 4;
						break;
					case CV_PTR_64:
						plr->Pointer.attr.size = 8;
						break;
					}
				}
				break;
			case CV_PTR_MODE_PMFUNC:
			case CV_PTR_MODE_PMEM:
				if (*((PUSHORT)plr - 1) < sizeof(lfPointer))
				{
					__debugbreak();
				}
				if (ZType* pct = _CreateUDT(plr->Pointer.pm.pmclass))
				{
					if (CV_IS_PRIMITIVE((ULONG_PTR)pct))
					{
						__debugbreak();
					}
					else
					{
						pti->_classname = pct->_name;
					}
				}
				else
				{
					__debugbreak();
				}
				break;
			}

			pti->_pAttr = plr->Pointer.attr;
			pti->_pti = _CreateUDT(plr->Pointer.utype);

			return pti;
		}
		break;

	case LF_MFUNCTION:
		if (bRecursive)
		{
			if (*((PUSHORT)plr - 1) < sizeof(lfMFunc))
			{
				__debugbreak();
			}
			pti = new ZType(LF_MFUNCTION);
			pti->_calltype = plr->MFunc.calltype;
			pti->_funcattr = plr->MFunc.funcattr;

			//////////////////////////////////////////////////////////////////////////
			
			attr.value = 0;

			if (ULONG thistype = plr->MFunc.thistype)
			{
				while (lfRecord* p = IndexToType(thistype))
				{
					switch (p->leaf)
					{
					case LF_POINTER:
						thistype = p->Pointer.utype;
						break;
					case LF_MODIFIER:
						thistype = p->Modifier.type;
						if (!attr.value)
						{
							attr.value = p->Modifier.attr.value;
							break;
						}
					default: __debugbreak();
					}

					if (thistype == plr->MFunc.classtype)
					{
						break;
					}
				}
			}
			else
			{
				attr.MOD_static = TRUE;
			}
			//////////////////////////////////////////////////////////////////////////

			pti->AddBaseType(_CreateUDT(plr->MFunc.classtype), 0, attr.value);//

			return ExpandUdt(pti, plr->MFunc.parmcount, plr->MFunc.rvtype, plr->MFunc.arglist);
		}
		break;

	case LF_PROCEDURE:
		if (bRecursive)
		{
			if (*((PUSHORT)plr - 1) < sizeof(lfProc))
			{
				__debugbreak();
			}
			pti = new ZType(LF_PROCEDURE);
			if (plr->Proc.calltype)
			{
				__nop();
			}
			pti->_calltype = plr->Proc.calltype;
			pti->_funcattr = plr->Proc.funcattr;

			return ExpandUdt(pti, plr->Proc.parmcount, plr->Proc.rvtype, plr->Proc.arglist);
		}
		break;

	case LF_BITFIELD:
		if (bRecursive)
		{
			if (*((PUSHORT)plr - 1) < sizeof(lfBitfield))
			{
				__debugbreak();
			}
			pti = new ZType(LF_BITFIELD);
			pti->_length = plr->Bitfield.length;
			pti->_position = plr->Bitfield.position;
			pti->_pti = _CreateUDT(plr->Bitfield.type);
			return pti;
		}
		break;

	case LF_ARRAY:
		if (bRecursive)
		{
			cb = *((PUSHORT)plr - 1);
			if (
				cb < sizeof(lfArray) ||
				!plr->Array.length_name.value(&len, &name) ||
				!IsNameOk(plr, name, cb)
				)
			{
				__debugbreak();
				return 0;
			}
			pti = new ZType(LF_ARRAY);
			pti->_pti = _CreateUDT(plr->Array.elemtype);
			if (len)
			{
				ULONG size = pti->_pti->getSize();
				if (len % size)
				{
					__debugbreak();
					return 0;
				}
				pti->_len = len / size;
			}
			else
			{
				pti->_len = 0;
			}
			return pti;
		}
		break;

	case LF_ENUM:
		if (!plr->Enum.property.scoped)
		{
			if (!(pti = getType(LF_ENUM, plr->Enum.property, plr->Enum.name)) || pti->_leaf != LF_ENUM)
			{
				__debugbreak();
			}

			if (!pti->_bProcessed && !plr->Enum.property.fwdref)
			{
				if (!CV_IS_PRIMITIVE(plr->Enum.utype))
				{
					__debugbreak();
				}
				pti->_bProcessed = TRUE;
				pti->_len = GetBasicTypeLen(plr->Enum.utype);
				pti->_base = plr->Enum.utype;
				ProcessFieldList(pti, plr->Enum.field);
			}

			return pti;
		}
		break;

	case LF_UNION:
		if (!plr->Union.property.scoped)
		{
			if (
				!plr->Union.length_name.value(&len, &name)
				||
				!(pti = getType(LF_UNION, plr->Union.property, name)) 
				|| 
				pti->_leaf != LF_UNION
				)
			{
				__debugbreak();
				return 0;
			}

			if (!pti->_bProcessed && !plr->Union.property.fwdref)
			{
				pti->_bProcessed = TRUE;
				pti->_len = len;
				ProcessFieldList(pti, plr->Union.field);
			}

			return pti;
		}
		break;

	case LF_CLASS:
	case LF_STRUCTURE:
		if (!plr->Class.length_name.value(&len, &name))
		{
			__debugbreak();
		}

		if (plr->Class.property.scoped)
		{
			if (bRecursive)
			{
				pti = new ZType(plr->leaf);
				pti->_name = g_nh.alloc(GetLastNameComponent(name));
				return pti;
			}
		}
		else
		{
			if (!(pti = getType(plr->leaf, plr->Class.property, name)) || pti->_leaf != plr->leaf)
			{
				if (!pti)
				{
					return 0;
				}
				switch (pti->_leaf)
				{
				case LF_CLASS:
				case LF_STRUCTURE:
					break;
				default:
					__debugbreak();
					return 0;
				}
			}
			//if (pti->_name && strstr(pti->_name, "ArrayHolder<char>"))__debugbreak();//

			if (!pti->_bProcessed && !plr->Class.property.fwdref)
			{
				pti->_bProcessed = TRUE;
				pti->_len = len;
				ProcessFieldList(pti, plr->Class.field);
			}

			return pti;
		}
		break;
	}

	if (bRecursive)
	{
		__debugbreak();
	}

	return 0;
}

BOOL TiEnum::ProcessFieldList(ZType* pType, CV_typ_t field)
{
	if (!field)
	{
		return TRUE;
	}

	lfRecord* plr = IndexToType(field);
	
	LONG len = *((PUSHORT)plr - 1), k;

	if (0 > (len -= sizeof(lfFieldList)))
	{
		__debugbreak();
		return FALSE;
	}

	if (plr->leaf != LF_FIELDLIST)
	{
		__debugbreak();
		return FALSE;
	}

	if (!len)
	{
		return TRUE;
	}

	PUCHAR pc = plr->FieldList.data;
	PSTR name;
	LONG offset, value;

	ULONG cb;

	do 
	{
		if (*pc >= LF_PAD0)
		{
			pc++, len--;
			continue;
		}
		
		plr = (lfRecord*)pc;
		ZMember* pmi;

		switch (plr->leaf)
		{
		case LF_VBCLASS:
		case LF_IVBCLASS:
			if (
				len <= sizeof(lfVBClass)
				||
				!plr->VBClass.get_end(&value, &offset, &name)
				||
				(ULONG)len <= (cb = RtlPointerToOffset(plr, name))
				)
			{
				__debugbreak();
				return FALSE;
			}
			pc = (PUCHAR)RtlOffsetToPointer(plr, cb);
			len -= cb;

			plr->VBClass.attr.sealed = 1;
			pType->AddBaseType(_CreateUDT(plr->VBClass.index), value, plr->VBClass.attr.value);
			break;

		case LF_BCLASS:
			if (
				len <= sizeof(lfBClass)
				||
				!plr->BClass.offset.value(&value, &name)
				||
				(ULONG)len <= (cb = RtlPointerToOffset(plr, name))
				)
			{
				__debugbreak();
				return FALSE;
			}
			pc = (PUCHAR)RtlOffsetToPointer(plr, cb);
			len -= cb;

			plr->BClass.attr.sealed = 0;
			pType->AddBaseType(_CreateUDT(plr->BClass.index), value, plr->BClass.attr.value);
			break;

		case LF_ENUMERATE:
			if (
				len <= sizeof(lfEnumerate)
				||
				!plr->Enumerate.value_name.value(&value, &name)
				||
				!(cb = IsNameOk(plr, name, len))
				)
			{
				__debugbreak();
				return FALSE;
			}
			pc = (PUCHAR)RtlOffsetToPointer(plr, cb);
			len -= cb;

			pmi = new ZMember(LF_ENUMERATE);
			pmi->_value = value;
			pmi->_attr = plr->Enumerate.attr;
			pmi->_name = g_nh.alloc(name);
			pType->Add(pmi);
			break;

		case LF_MEMBER:
			if (
				len <= sizeof(lfMember)
				||
				!plr->Member.offset_name.value(&value, &name)
				||
				!(cb = IsNameOk(plr, name, len))
				)
			{
				__debugbreak();
				return FALSE;
			}
			pc = (PUCHAR)RtlOffsetToPointer(plr, cb);
			len -= cb;

			//if (!strcmp(name, "AsynchronousParameters"))//$$$
			//{
			//	__nop();
			//}

			pmi = new ZMember(LF_MEMBER);
			pmi->_offset = value;
			pmi->_attr = plr->Member.attr;
			pmi->_name = g_nh.alloc(name);
			pmi->_type = _CreateUDT(plr->Member.index);
			pType->Add(pmi);
			break;

		case LF_STMEMBER:
			name = plr->StMember.name;
			if (
				len <= sizeof(lfSTMember)
				||
				!(cb = IsNameOk(plr, name, len))
				)
			{
				__debugbreak();
				return FALSE;
			}
			pc = (PUCHAR)RtlOffsetToPointer(plr, cb);
			len -= cb;

			pmi = new ZMember(LF_STMEMBER);
			pmi->_attr = plr->StMember.attr;
			pmi->_name = g_nh.alloc(name);
			pmi->_type = _CreateUDT(plr->StMember.index);
			pType->Add(pmi);
			break;

		case LF_METHOD:
			name = plr->Method.name;
			if (
				len <= sizeof(lfMethod)
				||
				!(cb = IsNameOk(plr, name, len))
				)
			{
				__debugbreak();
				return FALSE;
			}
			pc = (PUCHAR)RtlOffsetToPointer(plr, cb);
			len -= cb;

			if (ULONG n = plr->Method.count)
			{
				lfMethodList* p = (lfMethodList*)IndexToType(plr->Method.mList);

				k = *((PUSHORT)p - 1);

				if (0 > (k -= sizeof(USHORT)))
				{
					__debugbreak();
					return FALSE;
				}

				if (p->leaf != LF_METHODLIST)
				{
					__debugbreak();
					return FALSE;
				}

				mlMethod* mList = p->mList;

				do 
				{
					if (0 > (k -= sizeof(mlMethod)))
					{
						__debugbreak();
						return FALSE;
					}
					
					pmi = new ZMember(LF_METHOD);
					pmi->_name = g_nh.alloc(name);
					pmi->_attr = mList->attr;
					pmi->_offset = -1;
					pmi->_type = _CreateUDT(mList->index);
					pType->Add(pmi);

					switch (mList->attr.mprop)
					{
					case CV_MTintro:
					case CV_MTpureintro:
						if (0 > (k -= sizeof(ULONG)))
						{
							__debugbreak();
						}
						pmi->_offset = static_cast<mlMethodV*>(mList)->vbaseoff;
						mList = static_cast<mlMethodV*>(mList) + 1;
						break;
					default:
						mList++;
					}
				} while (--n);
			}
			break;

		case LF_ONEMETHOD:
			if (
				len <= sizeof(lfOneMethod)
				||
				!(cb = IsNameOk(plr, name = plr->OneMethod.get_name(&offset), len))
				)
			{
				__debugbreak();
				return FALSE;
			}
			pc = (PUCHAR)RtlOffsetToPointer(plr, cb);
			len -= cb;

			pmi = new ZMember(LF_METHOD);
			pmi->_attr = plr->OneMethod.attr;
			pmi->_offset = offset;
			pmi->_name = g_nh.alloc(name);
			pmi->_type = _CreateUDT(plr->OneMethod.index);
			pType->Add(pmi);
			break;

		case LF_NESTTYPE:
		case LF_NESTTYPEEX:
			if (
				len <= sizeof(lfNestTypeEx)
				||
				!(cb = IsNameOk(plr, name = plr->NestType.name, len))
				)
			{
				__debugbreak();
				return FALSE;
			}
			pc = (PUCHAR)RtlOffsetToPointer(plr, cb);
			len -= cb;

			//_CreateUDT(plr->NestType.index);//tmp$$$
			break;

		case LF_VFUNCTAB:
			if (0 > (len -= sizeof(lfVFuncTab)))
			{
				__debugbreak();
				return FALSE;
			}
			pc = (PUCHAR)plr + sizeof(lfVFuncTab);
			break;

		case LF_INDEX:
			if (0 > (len -= sizeof(lfIndex)))
			{
				__debugbreak();
				return FALSE;
			}
			pc = (PUCHAR)plr + sizeof(lfIndex);
			if (!ProcessFieldList(pType, plr->Index.index))
			{
				return FALSE;
			}
			break;
		default:
			__debugbreak();
		}

	} while (len);

	return TRUE;
}

ZType* TiEnum::ExpandUdt(ZType* pType, USHORT parmcount, CV_typ_t rvtype, CV_typ_t arglist)
{
	if (!rvtype || (parmcount && !arglist))
	{
		__debugbreak();
		return 0;
	}

	pType->_parmcount = parmcount;
	pType->_name = 0;

	pType->AddBaseType(_CreateUDT(rvtype), 0, 0);

	if (parmcount)
	{
		lfRecord* plr = IndexToType(arglist);

		if (plr->leaf != LF_ARGLIST || plr->ArgList.count != parmcount || FIELD_OFFSET(lfArgList, arg[parmcount]) != *((PUSHORT)plr - 1))
		{
			__debugbreak();
			return 0;
		}

		CV_typ_t* arg = plr->ArgList.arg, a;
		do 
		{
			pType->AddBaseType((a = *arg++) ? _CreateUDT(a) : (ZType*)T_NOTYPE, 0, 0);/* ... */

		} while (--parmcount);
	}

	return pType;
}

BOOL TPIDumpTypes (TPIHDR* pHdr, LONG cb, BOOL Is64Bit)
{
	LONG cbHdr = pHdr->cbHdr;

	if (cb < sizeof(cbHdr))
	{
		return FALSE;
	}

	ULONG tiMin = pHdr->tiMin;

	CV_typ_t dTypes = pHdr->tiMax - tiMin;

	if (!dTypes || tiMin < CV_FIRST_NONPRIM)
	{
		return FALSE;
	}

	eprintf(L"found type info...\n");

	if (PULONG pOfs = new ULONG[dTypes])
	{
		PVOID pData = RtlOffsetToPointer(pHdr, cbHdr);
		BOOL fOk = FALSE;
		__try
		{
			if (FillOfs((TYPTYPE*)pData, cb - cbHdr, dTypes, pOfs))
			{
				TiEnum te(pData, pOfs, tiMin, dTypes, Is64Bit);
				te.Round2();
				te.Round3();
				fOk = TRUE;
			}
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
		}
		delete pOfs;

		return fOk;
	}

	return FALSE;
}

void TPIDumpTypesAndSave (TPIHDR* pHdr, LONG cb, PWSTR lpsz, BOOL Is64Bit)
{
	if (!g_sh.Create(0x8000000, sizeof(PVOID)) || !g_nh.Create(0x2000000, sizeof(char))) return;

	eprintf(L"search for type info...\n");

	if (TPIDumpTypes(pHdr, cb, Is64Bit))
	{
		memset(gszLevel, '\t', RTL_NUMBER_OF(gszLevel));
		gszLevel[RTL_NUMBER_OF(gszLevel) - 1]=0;

		PSTR buf = 0, end;
		SIZE_T RegionSize = 0x6000000;
		if (0 <= ZwAllocateVirtualMemory(NtCurrentProcess(), (void**)&buf, 0, &RegionSize, MEM_COMMIT, PAGE_READWRITE))
		{
			end = g_NS.Dump(buf, gszLevel + RTL_NUMBER_OF(gszLevel) - 1, 0);
			if (cb = RtlPointerToOffset(buf, end))
			{
				LARGE_INTEGER li;
				li.QuadPart = cb;
				HANDLE hFile;
				IO_STATUS_BLOCK iosb;

				PWSTR name = (PWSTR)alloca((wcslen(lpsz) + 8)<< 1);

				swprintf(name, L"%s.udt.h", lpsz);

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
			}
			ZwFreeVirtualMemory(NtCurrentProcess(), (void**)&buf, &RegionSize, MEM_RELEASE);
		}
	}
}

_NT_END