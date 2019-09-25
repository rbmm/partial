
#include "StdAfx.h"

#ifdef _WIN64

_NT_BEGIN

#include "wow.h"

ULONG GetNameOrdinal(PVOID Base, PDWORD AddressOfNames, DWORD NumberOfNames, PCSTR Name)
{
	if (NumberOfNames)
	{
		DWORD a = 0, o;

		do 
		{
			o = (a + NumberOfNames) >> 1;

			int i = strcmp(RtlOffsetToPointer(Base, AddressOfNames[o]), Name);

			if (!i)
			{
				return o;
			}

			0 > i ? a = o + 1 : NumberOfNames = o;

		} while (a < NumberOfNames);
	}

	return MAXULONG;
}

static volatile UCHAR guz = 0;

VOID getWowProcs(PCUNICODE_STRING DllName, const EXPORT_ENTRY entry[]);

VOID getWowProcs(PVOID ImageBase, PVOID BaseAddress, const EXPORT_ENTRY entry[])
{
	STATIC_WSTRING_(DLL);
	PVOID stack = alloca(sizeof(DLL));
	UNICODE_STRING DllName = {};

	ULONG exportSize, exportRVA;

	if (PIMAGE_EXPORT_DIRECTORY pied = (PIMAGE_EXPORT_DIRECTORY)
		RtlImageDirectoryEntryToData(BaseAddress, TRUE, IMAGE_DIRECTORY_ENTRY_EXPORT, &exportSize))
	{
		exportRVA = RtlPointerToOffset(BaseAddress, pied);

		if (ULONG NumberOfFunctions = pied->NumberOfFunctions)
		{
			ULONG NumberOfNames = pied->NumberOfNames;
			ULONG OrdinalBase = pied->Base;

			PULONG AddressOfFunctions = (PULONG)RtlOffsetToPointer(BaseAddress, pied->AddressOfFunctions);
			PULONG AddressOfNames = (PULONG)RtlOffsetToPointer(BaseAddress, pied->AddressOfNames);
			PWORD AddressOfNameOrdinals = (PWORD)RtlOffsetToPointer(BaseAddress, pied->AddressOfNameOrdinals);

			for ( ; PCSTR Name = entry->Name; entry++)
			{
				ULONG o;

				if (*Name == '#')
				{
					if ((o = strtoul(Name + 1, const_cast<char**>(&Name), 10)) < OrdinalBase || *Name)
					{
						continue;
					}
					o -= OrdinalBase;
				}
				else
				{
					o = GetNameOrdinal(BaseAddress, AddressOfNames, NumberOfNames, Name);
					if (o < NumberOfNames)
					{
						o = AddressOfNameOrdinals[o];
					}
				}

				if (o >= NumberOfFunctions)
				{
					continue;
				}

				DWORD Rva = AddressOfFunctions[o];

				if ((ULONG_PTR)Rva - (ULONG_PTR)exportRVA >= exportSize)
				{
					*entry->pAddress = RtlOffsetToPointer(ImageBase, Rva);
					continue;
				}

				// forward export
				PCSTR pfn = RtlOffsetToPointer(BaseAddress, Rva);

				if (!(Name = strrchr(pfn, '.')))
				{
					continue;
				}

				ULONG BytesInUnicodeString, BytesInMultiByteString = RtlPointerToOffset(pfn, ++Name);

				if (0 > RtlMultiByteToUnicodeSize(&BytesInUnicodeString, pfn, BytesInMultiByteString) || 
					(BytesInUnicodeString += sizeof(DLL)) >= MAXUSHORT )
				{
					continue;
				}

				if (DllName.MaximumLength < BytesInUnicodeString)
				{
					DllName.MaximumLength = (USHORT)RtlPointerToOffset(
						DllName.Buffer = (PWSTR)alloca(BytesInUnicodeString - DllName.MaximumLength), 
						stack);
				}

				if (0 > RtlMultiByteToUnicodeN(DllName.Buffer, DllName.MaximumLength, 
					&BytesInUnicodeString, pfn, BytesInMultiByteString))
				{
					continue;
				}

				DllName.Length = (USHORT)BytesInUnicodeString;

				if (0 > RtlAppendUnicodeToString(&DllName, DLL))
				{
					continue;
				}

				const EXPORT_ENTRY e[] = { { Name, entry->pAddress }, {} };

				STATIC_UNICODE_STRING(API, "API-");
				STATIC_UNICODE_STRING(EXT, "EXT-");
				if (!RtlPrefixUnicodeString(&API, &DllName, TRUE) &&
					!RtlPrefixUnicodeString(&EXT, &DllName, TRUE))
				{
					getWowProcs(&DllName, e);
					continue;
				}

				HMODULE hmod;

				if (0 <= LdrLoadDll(0, 0, &DllName, &hmod))
				{
					ANSI_STRING as, *pas;

					if (*Name == '#')
					{
						pas = 0;
						o = strtoul(Name + 1, const_cast<char**>(&Name), 10);
						if (*Name)
						{
							o = 0;
						}
					}
					else
					{
						o = 0;
						RtlInitAnsiString(pas = &as, Name);
					}

					PVOID pv;
					if (0 <= LdrGetProcedureAddress(hmod, pas, o, &pv))
					{
						_LDR_DATA_TABLE_ENTRY* ldte;
						if (0 <= LdrFindEntryForAddress(pv, ldte))
						{
							getWowProcs(&ldte->BaseDllName, e);
						}
					}
					LdrUnloadDll(hmod);
				}
			}
		}
	}
}

VOID getWowProcs(PCUNICODE_STRING DllName, const EXPORT_ENTRY entry[])
{
	STATIC_WSTRING(KnownDlls32, "\\KnownDlls32\\");

	UNICODE_STRING ObjectName = { 
		0, (USHORT)(sizeof(KnownDlls32) + DllName->Length), 
		(PWSTR)alloca(ObjectName.MaximumLength)
	};

	if (0 > RtlAppendUnicodeToString(&ObjectName, KnownDlls32) || 
		0 > RtlAppendUnicodeStringToString(&ObjectName, DllName))
	{
		return ;
	}

	OBJECT_ATTRIBUTES oa = { sizeof(oa), 0, &ObjectName, OBJ_CASE_INSENSITIVE };

	HANDLE hSection;

	if (0 <= ZwOpenSection(&hSection, SECTION_QUERY|SECTION_MAP_READ, &oa))
	{
		SECTION_IMAGE_INFORMATION sii;
		if (0 <= ZwQuerySection(hSection, SectionImageInformation, &sii, sizeof(sii), 0))
		{
			PVOID BaseAddress = 0;
			SIZE_T ViewSize = 0;

			if (0 <= ZwMapViewOfSection(hSection, NtCurrentProcess(), &BaseAddress, 0, 0, 0, &ViewSize, ViewUnmap, 0, PAGE_READONLY))
			{
				__try
				{
					if (PIMAGE_NT_HEADERS32 pinth = (PIMAGE_NT_HEADERS32)RtlImageNtHeader(BaseAddress))
					{
						getWowProcs((PBYTE)sii.TransferAddress - pinth->OptionalHeader.AddressOfEntryPoint, BaseAddress, entry);
					}
				}
				__except(EXCEPTION_EXECUTE_HANDLER)
				{
				}

				ZwUnmapViewOfSection(NtCurrentProcess(), BaseAddress);
			}
		}
		NtClose(hSection);
	}
}

void getWowProcs()
{
	const WOW_DLL* p = WOW_PROCS::a;

	while (PCWSTR name = p->Name)
	{
		UNICODE_STRING DllName;
		RtlInitUnicodeString(&DllName, name);
		getWowProcs(&DllName, p++->entry);
	}
}

_NT_END

#endif