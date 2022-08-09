#pragma once

class NAMES;

enum { secshift = 17, secsize = (1 << secshift), MaxThreads = 32 };

struct PROCESS_MODULE 
{
	PVOID ImageBase;
	PCSTR FullPathName;
	ULONG ImageSize;
	ULONG Index;

	PROCESS_MODULE* Init(NAMES* Table, ULONG i, PVOID Base, ULONG Size, PSTR Name);
};

// SpareLi1
inline void set_Flags(PSYSTEM_PROCESS_INFORMATION pspi, ULONG Flags)
{
	pspi->SpareLi1.LowPart = Flags;
}

inline ULONG get_Flags(PSYSTEM_PROCESS_INFORMATION pspi)
{
	return pspi->SpareLi1.LowPart;
}

inline void set_status(PSYSTEM_PROCESS_INFORMATION pspi, NTSTATUS status)
{
	pspi->SpareLi1.HighPart = status;
}

inline NTSTATUS get_status(PSYSTEM_PROCESS_INFORMATION pspi)
{
	return pspi->SpareLi1.HighPart;
}

// SpareLi2
inline PCSTR get_cmdline(PSYSTEM_PROCESS_INFORMATION pspi)
{
	return (PCSTR)(ULONG_PTR)pspi->SpareLi2.QuadPart;
}

inline void set_cmdline(PSYSTEM_PROCESS_INFORMATION pspi, PCSTR CmdLine)
{
	pspi->SpareLi2.QuadPart = (LONGLONG)(ULONG_PTR)CmdLine;
}

// PageDirectoryBase, BasePriority
inline PROCESS_MODULE* get_modules(PSYSTEM_PROCESS_INFORMATION pspi, PULONG count)
{
	*count = pspi->BasePriority;
	return (PROCESS_MODULE*)pspi->PageDirectoryBase;
}

inline void set_modules(PSYSTEM_PROCESS_INFORMATION pspi, ULONG_PTR modules, ULONG count)
{
	pspi->BasePriority = count;
	pspi->PageDirectoryBase = modules;
}

enum {
	WM_PSI_READY = WM_USER + 0x100
};

ULONG GetLoadCount(PROCESS_MODULE* pm);

class NAMES : public RTL_AVL_TABLE 
{
	HWND _hwnd;
	ULONG _cbFree = 0, _cbUsed = 0;
	ULONG _nModules = 0;
	LONG _dwRefCount = 1;

	void Init(PVOID pv)
	{
		RtlInitializeGenericTableAvl(this, compare, alloc, free, pv);
	}

public:

	NAMES(HWND hwnd) : _hwnd(hwnd) 
	{
		TableContext = 0;
	}

	void AddRef()
	{
		InterlockedIncrementNoFence(&_dwRefCount);
	}

	void Release()
	{
		if (!InterlockedDecrement(&_dwRefCount))
		{
			delete this;
		}
	}

	void Finish(ULONG n, PSYSTEM_PROCESS_INFORMATION pspi)
	{
		PostMessageW(_hwnd, WM_PSI_READY, n, (LPARAM)pspi);
	}

	BOOL Create(ULONG size);

	void Reset()
	{
		Init(TableContext);
		_cbFree += _cbUsed, _cbUsed = 0, _nModules = 0;
	}

	PCSTR GetCommandLine(HANDLE hProcess);

	PSYSTEM_PROCESS_INFORMATION BuildListOfProcesses();

	PVOID AllocPM(_In_ PRTL_PROCESS_MODULES mods, _In_opt_ PRTL_PROCESS_MODULES32 mods32, _Out_ PULONG pNumberOfModules);

	void QueryLoop(_In_ PSYSTEM_PROCESS_INFORMATION pspi, _In_ HANDLE hSection, _In_ PVOID BaseAddress);

	void IncModulesCount()
	{
		_nModules++;
	}

	ULONG GetMemUsage()
	{
		return _cbUsed;
	}

	ULONG GetModulesCount()
	{
		return _nModules;
	}

	PVOID malloca(_In_ ULONG ByteSize)
	{
		return ByteSize > _cbFree ? new CHAR[ByteSize] : RtlOffsetToPointer(TableContext, _cbUsed);
	}

	void freea(_In_ PVOID pv)
	{
		if (pv != RtlOffsetToPointer(TableContext, _cbUsed))
		{
			delete [] pv;
		}
	}

	void FillModules(PROCESS_MODULE** ppm);

	static PVOID NTAPI alloc (_In_ PRTL_AVL_TABLE Table, _In_ CLONG ByteSize);

	static VOID NTAPI free (_In_ PRTL_AVL_TABLE ,_In_ PVOID )
	{
		__debugbreak();
	}

	static RTL_GENERIC_COMPARE_RESULTS NTAPI compare (_In_ PRTL_AVL_TABLE , _In_ PVOID FirstStruct, _In_ PVOID SecondStruct);

	~NAMES()
	{
		if (PVOID buf = TableContext)
		{
			VirtualFree(buf, 0, MEM_RELEASE);
		}
	}
};

#ifdef _WIN64
void InitWow64();
#endif
