#include "StdAfx.h"

_NT_BEGIN

#include "lineheap.h"

_lineHeap::_lineHeap() 
{ 
	m_buf = 0, m_size = 0; 
}

_lineHeap::~_lineHeap() 
{ 
	SIZE_T size = 0;
	if (m_buf) ZwFreeVirtualMemory(NtCurrentProcess(), &m_buf, &size, MEM_RELEASE); 
}

BOOL _lineHeap::Create(SIZE_T size, ULONG align)
{
	if (0 > ZwAllocateVirtualMemory(NtCurrentProcess(), &m_buf, 0, &size, MEM_COMMIT, PAGE_READWRITE)) return FALSE;

	m_ptr = (PBYTE)m_buf;
	m_size = size;
	m_TotalSize = size;
	m_align = align - 1;
	return TRUE;
}

PVOID _lineHeap::alloc(DWORD size)
{
	size = (size + m_align) & ~m_align;
	if (m_size < size) 
	{
		__debugbreak();
		return 0;
	}
	m_size -= size;
	PVOID ptr = m_ptr;
	m_ptr += size;
	return ptr;
}

PSTR _lineHeap::alloc(PCSTR str)
{
	if (str)
	{
		DWORD len = (DWORD)strlen(str) + 1;

		if (PSTR sz = (PSTR)alloc(len))
		{
			memcpy(sz, str, len);
			return sz;
		}

		__debugbreak();
		return 0;
	}

	return 0;
}

#define INRANGE(base, address, size) ((DWORD_PTR)(address) - (DWORD_PTR)(base) < (DWORD_PTR)(size))

BOOL _lineHeap::AddressInHeap(PVOID Address) 
{
	return INRANGE((PBYTE)m_buf, Address, m_ptr - (PBYTE)m_buf);
}

_NT_END