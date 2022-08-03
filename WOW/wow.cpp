
#include "StdAfx.h"

#ifdef _WIN64

_NT_BEGIN

#include "wow.h"

struct DLL_LIST
{
	struct FUNCTION_LIST 
	{
		FUNCTION_LIST* Next;
		void** ppv;
		PCSTR Name;
		ULONG Ordinal;
	};

	DLL_LIST* Next;
	PCUNICODE_STRING DllName;
	FUNCTION_LIST* First;

	static DLL_LIST* Get(DLL_LIST* cur, PCUNICODE_STRING DllName)
	{
		if (cur)
		{
			do 
			{
				if (RtlEqualUnicodeString(DllName, cur->DllName, TRUE))
				{
					return cur;
				}

			} while (cur = cur->Next);
		}

		return 0;
	}
};

ULONG GetNameOrdinal(PVOID BaseAddress, PULONG AddressOfNames, ULONG NumberOfNames, PCSTR Name)
{
	if (NumberOfNames)
	{
		DWORD a = 0, o;

		do 
		{
			o = (a + NumberOfNames) >> 1;

			int i = strcmp(RtlOffsetToPointer(BaseAddress, AddressOfNames[o]), Name);

			if (!i)
			{
				return o;
			}

			0 > i ? a = o + 1 : NumberOfNames = o;

		} while (a < NumberOfNames);
	}

	return MAXULONG;
}

ULONG GetFunc(PVOID BaseAddress, PCSTR lpProcName, ULONG Ordinal)
{
	ULONG size, exportRVA, rva;

	if (PIMAGE_EXPORT_DIRECTORY pied = (PIMAGE_EXPORT_DIRECTORY)
		RtlImageDirectoryEntryToData(BaseAddress, TRUE, IMAGE_DIRECTORY_ENTRY_EXPORT, &size))
	{
		exportRVA = RtlPointerToOffset(BaseAddress, pied);

		if (ULONG NumberOfFunctions = pied->NumberOfFunctions)
		{
			if (Ordinal)
			{
				Ordinal -= pied->Base;
			}
			else
			{
				if (0 > (int)(Ordinal = GetNameOrdinal(BaseAddress, 
					(PULONG)RtlOffsetToPointer(BaseAddress, pied->AddressOfNames), pied->NumberOfNames, lpProcName)))
				{
					return 0;
				}

				Ordinal = ((PUSHORT)RtlOffsetToPointer(BaseAddress, pied->AddressOfNameOrdinals))[Ordinal];
			}

			if (Ordinal < NumberOfFunctions)
			{
				rva = ((PULONG)RtlOffsetToPointer(BaseAddress, pied->AddressOfFunctions))[Ordinal];

				if ((ULONG_PTR)rva - (ULONG_PTR)exportRVA >= size)
				{
					return rva;
				}
			}
		}
	}

	return 0;
}

NTSTATUS GetTransferAddress(HANDLE hSection, void** TransferAddress)
{
	SECTION_IMAGE_INFORMATION sii;
	NTSTATUS status = ZwQuerySection(hSection, SectionImageInformation, &sii, sizeof(sii), 0);
	if (0 <= status)
	{
		if (sii.TransferAddress)
		{
			*TransferAddress = sii.TransferAddress;

			return STATUS_SUCCESS;
		}

		return STATUS_SECTION_NOT_IMAGE ; 
	}

	return status;
}

void Query(PCUNICODE_STRING DllName, DLL_LIST::FUNCTION_LIST* funcs)
{
	WCHAR buf[0x100];
	if (0 > swprintf_s(buf, _countof(buf), L"\\KnownDlls32\\%wZ", DllName)) return ;

	UNICODE_STRING ObjectName;
	OBJECT_ATTRIBUTES oa = { sizeof(oa), 0, &ObjectName, OBJ_CASE_INSENSITIVE };
	RtlInitUnicodeString(&ObjectName, buf);

	HANDLE hSection;

	if (0 <= ZwOpenSection(&hSection, SECTION_MAP_EXECUTE|SECTION_QUERY, &oa))
	{
		NTSTATUS status;
		PVOID TransferAddress;
		PVOID BaseAddress = 0;
		SIZE_T ViewSize = 0;

		0 <= (status = GetTransferAddress(hSection, &TransferAddress)) && 
			0 <= (status = ZwMapViewOfSection(hSection, NtCurrentProcess(), &BaseAddress, 0, 0, 0, &ViewSize,
			ViewUnmap, 0, PAGE_EXECUTE));

		NtClose(hSection);

		if (0 <= status)
		{
			if (PIMAGE_NT_HEADERS32 pinth = (PIMAGE_NT_HEADERS32)RtlImageNtHeader(BaseAddress))
			{
				do 
				{
					if (ULONG rva = GetFunc(BaseAddress, funcs->Name, funcs->Ordinal))
					{
						*funcs->ppv = (PBYTE)TransferAddress - pinth->OptionalHeader.AddressOfEntryPoint + rva;
					}

				} while (funcs = funcs->Next);
			}

			ZwUnmapViewOfSection(NtCurrentProcess(), BaseAddress);
		}
	}
}

NTSTATUS NameForAddress(PVOID BaseAddress, PVOID pv, PCSTR* lplpProcName, PULONG pOrdinal)
{
	*lplpProcName = 0, *pOrdinal = 0;

	ULONG size;

	if (PIMAGE_EXPORT_DIRECTORY pied = (PIMAGE_EXPORT_DIRECTORY)
		RtlImageDirectoryEntryToData(BaseAddress, TRUE, IMAGE_DIRECTORY_ENTRY_EXPORT, &size))
	{
		if (ULONG NumberOfFunctions = pied->NumberOfFunctions)
		{
			PULONG AddressOfFunctions = (PULONG)RtlOffsetToPointer(BaseAddress, pied->AddressOfFunctions);
			PULONG AddressOfNames = (PULONG)RtlOffsetToPointer(BaseAddress, pied->AddressOfNames);
			PWORD AddressOfNameOrdinals = (PWORD)RtlOffsetToPointer(BaseAddress, pied->AddressOfNameOrdinals);

			if (ULONG NumberOfNames = pied->NumberOfNames)
			{
				do 
				{
					PCSTR name = RtlOffsetToPointer(BaseAddress, *AddressOfNames++);

					if (RtlOffsetToPointer(BaseAddress, AddressOfFunctions[*AddressOfNameOrdinals++]) == pv)
					{
						*lplpProcName = name;
						return STATUS_SUCCESS;
					}

				} while (--NumberOfNames);
			}

			ULONG Ordinal = pied->Base;
			do 
			{
				if (RtlOffsetToPointer(BaseAddress, *AddressOfFunctions++) == pv)
				{
					*pOrdinal = Ordinal;
					return STATUS_SUCCESS;
				}
			} while (Ordinal++, --NumberOfFunctions);
		}
	}

	return STATUS_PROCEDURE_NOT_FOUND;
}

extern const volatile UCHAR guz;

void DLL_LIST_0::Process(DLL_LIST_0 *p)
{
	PVOID stack = alloca(guz);

	union {
		PVOID buf;
		DLL_LIST* pDll;
		DLL_LIST::FUNCTION_LIST* pFunc;
	};

	buf = stack;

	DLL_LIST* First = 0, *cur;
	DLL_LIST_0* q = p;
	HMODULE hmod;

	do 
	{
		// DbgPrint("%S\n", p->lpModuleName);

		p->hmod = hmod = LoadLibraryExW(p->lpModuleName, 0, DONT_RESOLVE_DLL_REFERENCES);

		if (hmod)
		{
			for (FUNCTION* funcs = p->funcs ; PCSTR lpProcName = funcs->lpProcName; funcs++ )
			{
				union
				{
					ULONG Ordinal = 0;
					PCSTR psz;
				};

				ANSI_STRING ProcedureName, *pProcedureName = 0;

				if (IS_INTRESOURCE(lpProcName))
				{
					psz = lpProcName;
				}
				else
				{
					RtlInitAnsiString(pProcedureName = &ProcedureName, lpProcName);
				}

				// DbgPrint("\t#%u %Z", Ordinal, pProcedureName);

				PVOID pv, DllBase;
				_LDR_DATA_TABLE_ENTRY* ldte;

				if (0 <= LdrGetProcedureAddress(hmod, pProcedureName, Ordinal, &pv) &&
					0 <= LdrFindEntryForAddress(pv, &ldte) &&
					0 <= ((DllBase = ldte->DllBase) == hmod ? 0 : NameForAddress(DllBase, pv, &lpProcName, &Ordinal)))
				{
					// if (DllBase != hmod) DbgPrint(" -> %wZ: #%u %s", &ldte->BaseDllName, Ordinal, lpProcName);

					if (cur = DLL_LIST::Get(First, &ldte->BaseDllName))
					{
					}
					else
					{
						if ((cur = --pDll) < stack)
						{
							stack = alloca(sizeof(DLL_LIST));
						}
						pDll->First = 0;
						pDll->Next = First, First = pDll;
						pDll->DllName = &ldte->BaseDllName;
					}

					if (--pFunc < stack)
					{
						stack = alloca(sizeof(DLL_LIST::FUNCTION_LIST));
					}

					pFunc->Next = cur->First, cur->First = pFunc;

					pFunc->Name = lpProcName;
					pFunc->Ordinal = Ordinal;
					pFunc->ppv = &funcs->pv;
				}

				// DbgPrint("\n");
			}

		}

	} while (p = p->next);

	if (First)
	{
		do 
		{
			Query(First->DllName, First->First);

		} while (First = First->Next);
	}

	do 
	{
		if (hmod = q->hmod)
		{
			FreeLibrary(hmod);
		}
	} while (q = q->next);
}

_NT_END

#endif