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

	int len = _vscwprintf(format, args);

	if (0 < len)
	{
		ULONG Size = _Ptr + (len + 1) * sizeof(WCHAR);

		if (Size <= _RegionSize)
		{
			len = _vsnwprintf_s((PWSTR)((PBYTE)_BaseAddress + _Ptr), 
				(_RegionSize - _Ptr) / sizeof(WCHAR), _TRUNCATE, format, args);

			if (0 < len)
			{
				_Ptr += len * sizeof(WCHAR);
			}
		}
	}

	return *this;
}

WLog& WLog::operator[](NTSTATUS status)
{
	if (status)
	{
		PWSTR MsgBuffer;

		static HMODULE hNT;

		if (!hNT)
		{
			hNT = GetModuleHandle(L"ntdll");
		}

		if (ULONG r = FormatMessage(FORMAT_MESSAGE_IGNORE_INSERTS|FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_HMODULE, hNT, status, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(PWSTR)&MsgBuffer, 0, NULL))
		{
			operator ()(MsgBuffer);
			LocalFree(MsgBuffer);
		}
	}
	return *this;
}

_NT_END