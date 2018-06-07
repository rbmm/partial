// stdafx.cpp : source file that includes just the standard includes
// PdbUtils.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
void* __cdecl operator new[](size_t ByteSize)
{
	return LocalAlloc(0, ByteSize);
}

void* __cdecl operator new(size_t ByteSize)
{
	return LocalAlloc(0, ByteSize);
}

void __cdecl operator delete(void* Buffer)
{
	LocalFree(Buffer);
}

void __cdecl operator delete(void * p, size_t)
{
	HeapFree(GetProcessHeap(), 0, p);
}

#ifdef _X86_
extern "C"
{
	uintptr_t __security_cookie;

	void __fastcall __security_check_cookie(__in uintptr_t _StackCookie)
	{
		if (__security_cookie != _StackCookie)
		{
			__debugbreak();
		}
	}

	BOOL __cdecl _ValidateImageBase(PVOID pImageBase)
	{
		return NT::RtlImageNtHeader(pImageBase) != 0;
	}

	PIMAGE_SECTION_HEADER __cdecl _FindPESection(PVOID pImageBase, ULONG rva)
	{
		return NT::RtlImageRvaToSection(NT::RtlImageNtHeader(pImageBase), pImageBase, rva);
	}

#pragma comment(linker, "/include:@__security_check_cookie@4")
#pragma comment(linker, "/include:__ValidateImageBase")
#pragma comment(linker, "/include:__FindPESection")

}

#endif

