
#include "StdAfx.h"

#ifdef _WIN64

_NT_BEGIN

#include "wow.h"

int GetNameOrdinal(PVOID Base, PDWORD AddressOfNames, DWORD NumberOfNames, PCSTR Name)
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

	return -1;
}

VOID getWowProcs(PCWSTR szDllName, const EXPORT_ENTRY entry[])
{
	STATIC_WSTRING(KnownDlls32, "\\KnownDlls32\\");

	SIZE_T cb = wcslen(szDllName) * sizeof(WCHAR);

	UNICODE_STRING ObjectName = { 
		(USHORT)(sizeof(KnownDlls32) + cb - sizeof(WCHAR)), 
		ObjectName.Length, 
		(PWSTR)alloca(ObjectName.Length)
	};

	memcpy(RtlOffsetToPointer(memcpy(
		ObjectName.Buffer, KnownDlls32, sizeof(KnownDlls32) - sizeof(WCHAR)), 
		sizeof(KnownDlls32) - sizeof(WCHAR)), szDllName, cb);

	OBJECT_ATTRIBUTES oa = { sizeof(oa), 0, &ObjectName, OBJ_CASE_INSENSITIVE };

	HANDLE hSection;

	if (0 <= ZwOpenSection(&hSection, SECTION_QUERY|SECTION_MAP_READ, &oa))
	{
		SECTION_IMAGE_INFORMATION sii;
		if (0 <= ZwQuerySection(hSection, SectionImageInformation, &sii, sizeof(sii), 0))
		{
			VirtualAllocEx(NtCurrentProcess(), (PVOID)0x74b10000,1, MEM_RESERVE, PAGE_NOACCESS);
			PVOID BaseAddress = 0;
			SIZE_T ViewSize = 0;

			if (0 <= ZwMapViewOfSection(hSection, NtCurrentProcess(), &BaseAddress, 0, 0, 0, &ViewSize, ViewUnmap, 0, PAGE_READONLY))
			{
				__try 
				{
					if (PIMAGE_NT_HEADERS32 pinth = (PIMAGE_NT_HEADERS32)RtlImageNtHeader(BaseAddress))
					{
						*(ULONG_PTR*)&sii.TransferAddress -= pinth->OptionalHeader.AddressOfEntryPoint;

						DWORD Size, exportRVA;

						if (PIMAGE_EXPORT_DIRECTORY pied = (PIMAGE_EXPORT_DIRECTORY)
							RtlImageDirectoryEntryToData(BaseAddress, TRUE, IMAGE_DIRECTORY_ENTRY_EXPORT, &Size))
						{
							exportRVA = RtlPointerToOffset(BaseAddress, pied);

							DWORD NumberOfFunctions = pied->NumberOfFunctions;
							DWORD NumberOfNames = pied->NumberOfNames;

							if (0 < NumberOfNames && NumberOfNames <= NumberOfFunctions)
							{
								PDWORD AddressOfFunctions = (PDWORD)RtlOffsetToPointer(BaseAddress, pied->AddressOfFunctions);
								PDWORD AddressOfNames = (PDWORD)RtlOffsetToPointer(BaseAddress, pied->AddressOfNames);
								PWORD AddressOfNameOrdinals = (PWORD)RtlOffsetToPointer(BaseAddress, pied->AddressOfNameOrdinals);

								while (PCSTR Name = entry->Name)
								{
									int i = GetNameOrdinal(BaseAddress, AddressOfNames, NumberOfNames, Name);
									if (0 <= i)
									{
										DWORD Rva = AddressOfFunctions[AddressOfNameOrdinals[i]];
										*entry->pAddress = (ULONG_PTR)Rva - (ULONG_PTR)exportRVA < Size 
											? 0 : RtlOffsetToPointer(sii.TransferAddress, Rva);
									}
									entry++;
								}
							}
						}
					}

				}
				__except( EXCEPTION_EXECUTE_HANDLER) 
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
		getWowProcs(name, p++->entry);
	}
}

_NT_END

#endif