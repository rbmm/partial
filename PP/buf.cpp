#include "stdafx.h"

_NT_BEGIN

#include "buf.h"

WLog& WLog::operator << (WCHAR c)
{
	if (_Ptr < _RegionSize)
	{
		*(PWSTR)((PBYTE)_BaseAddress + _Ptr) = c;
		_Ptr += sizeof(WCHAR);
	}
	return *this;
}

WLog& WLog::operator ()(PCWSTR format, ...)
{
	va_list args;
	va_start(args, format);

	int len = _vsnwprintf_s(_buf(), _cch(), _TRUNCATE, format, args);

	if (0 < len)
	{
		_Ptr += len * sizeof(WCHAR);
	}

	va_end(args);

	return *this;
}

WLog& WLog::operator[](NTSTATUS status)
{
	if (status)
	{
		static HMODULE hNT;

		if (!hNT)
		{
			hNT = GetModuleHandle(L"ntdll");
		}

		if (ULONG n = FormatMessageW(FORMAT_MESSAGE_FROM_HMODULE|FORMAT_MESSAGE_IGNORE_INSERTS, hNT, status, 0, _buf(), _cch(), 0))
		{
			_Ptr += n * sizeof(WCHAR);
		}
	}
	return *this;
}

_NT_END