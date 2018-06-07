#include "StdAfx.h"

_NT_BEGIN

#include "undname.h"
#include "../inc/rtlframe.h"

typedef RTL_FRAME<DATA_BLOB> AFRAME;

static void* __cdecl fAlloc(ULONG cb)
{
	if (AFRAME* prf = AFRAME::get())
	{
		if (cb > prf->cbData)
		{
			return 0;
		}
		prf->cbData -= cb;
		PVOID pv = prf->pbData;
		prf->pbData += cb;
		return pv;
	}

	return 0;
}

static void __cdecl fFree(void* )
{
}

/*********************************************************************
 *		__unDNameEx (MSVCRT.@)
 *
 * Demangle a C++ identifier.
 *
 * PARAMS
 *  buffer   [O] If not NULL, the place to put the demangled string
 *  mangled  [I] Mangled name of the function
 *  buflen   [I] Length of buffer
 *  memget   [I] Function to allocate memory with
 *  memfree  [I] Function to free memory with
 *  getparam [I] call back
 *  flags    [I] Flags determining demangled format
 *
 * RETURNS
 *  Success: A string pointing to the unmangled name, allocated with memget.
 *  Failure: NULL.
 */
extern "C" __declspec(dllimport) 
PSTR __cdecl __unDNameEx
(
 PSTR buffer, 
 PCSTR mangled, 
 DWORD cb,
 void* (__cdecl* memget)(DWORD),
 void (__cdecl* memfree)(void*),
 PSTR (__cdecl* GetParameter)(long i),
 DWORD flags
 );

PSTR __cdecl GetParameter(long /*i*/)
{
	return "";
}

PSTR _unDName(PSTR undName, PCSTR rawName, DWORD cb, DWORD flags)
{
	AFRAME af;
	af.cbData = 32*PAGE_SIZE;
	af.pbData = (PUCHAR)alloca(32*PAGE_SIZE);

	return __unDNameEx(undName, rawName, cb, fAlloc, fFree, GetParameter, flags);
}

PCSTR unDNameEx(PSTR undName, PCSTR rawName, DWORD cb, DWORD flags)
{
	if (*rawName != '?')
	{
		return rawName;
	}
	PSTR sz = _unDName(undName, rawName, cb, flags);
	return sz ? sz : rawName;
}

_NT_END