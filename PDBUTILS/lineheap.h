#pragma once

class _lineHeap
{
	PVOID m_buf;
	PBYTE m_ptr;
	SIZE_T m_size, m_TotalSize;
	ULONG m_align;
public:
	_lineHeap();

	~_lineHeap();

	BOOL Create(SIZE_T size, ULONG align);

	PVOID alloc(DWORD size);

	PSTR alloc(PCSTR str);

	BOOL AddressInHeap(PVOID Address);

	void Reset() 
	{ 
		m_ptr = (PBYTE)m_buf, m_size = m_TotalSize; 
	}

};
