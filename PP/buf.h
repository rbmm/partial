#pragma once

class WLog
{
	PVOID _BaseAddress;
	ULONG _RegionSize, _Ptr;
public:

	WLog(WLog&&) = delete;
	WLog(WLog&) = delete;
	WLog(PVOID BaseAddress, ULONG RegionSize): _BaseAddress(BaseAddress), _RegionSize(RegionSize), _Ptr(0) {  }

	operator PCWSTR()
	{
		return (PCWSTR)_BaseAddress;
	}

	PWSTR _buf()
	{
		return (PWSTR)((PBYTE)_BaseAddress + _Ptr);
	}

	ULONG _cch()
	{
		return (_RegionSize - _Ptr) / sizeof(WCHAR);
	}

	ULONG size()
	{
		return _Ptr;
	}

	void operator >> (HWND hwnd);

	WLog& operator << (WCHAR c);

	WLog& operator ()(PCWSTR format, ...);

	WLog& operator[](NTSTATUS status);
};
