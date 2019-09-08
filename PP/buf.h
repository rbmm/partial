#pragma once

class WLog
{
	PVOID _BaseAddress;
	ULONG _RegionSize, _Ptr;
public:

	WLog(WLog&&) = delete;
	WLog(WLog&) = delete;
	WLog(PVOID BaseAddress, ULONG RegionSize): _BaseAddress(BaseAddress), _RegionSize(RegionSize), _Ptr(0) {  }

	ULONG size()
	{
		return _Ptr;
	}

	operator PCWSTR()
	{
		return (PCWSTR)_BaseAddress;
	}

	WLog& operator << (WCHAR c);

	WLog& operator ()(PCWSTR format, ...);

	WLog& operator[](NTSTATUS status);
};
