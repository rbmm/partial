#include "StdAfx.h"

_NT_BEGIN

#include "wow.h"

void getWowProcs(PVOID Base, ULONG_PTR FixedBase, const EXPORT_ENTRY a[])
{
	if (PIMAGE_NT_HEADERS32 pinth = (PIMAGE_NT_HEADERS32)RtlImageNtHeader(Base))
	{
		if ((FixedBase -= pinth->OptionalHeader.AddressOfEntryPoint) & (PAGE_SIZE - 1))
		{
			return ;
		}

		PIMAGE_DATA_DIRECTORY pidd = &pinth->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];

		if (DWORD VirtualAddress = pidd->VirtualAddress)
		{
			if (PIMAGE_EXPORT_DIRECTORY pied = (PIMAGE_EXPORT_DIRECTORY)RtlAddressInSectionTable((PIMAGE_NT_HEADERS)pinth, Base, VirtualAddress))
			{
				if (DWORD NumberOfNames = pied->NumberOfNames)
				{
					PDWORD AddressOfFunctions = (PDWORD)RtlOffsetToPointer(pied, pied->AddressOfFunctions - VirtualAddress);
					PDWORD AddressOfNames = (PDWORD)RtlOffsetToPointer(pied, pied->AddressOfNames - VirtualAddress);
					PWORD AddressOfNameOrdinals = (PWORD)RtlOffsetToPointer(pied, pied->AddressOfNameOrdinals - VirtualAddress);
					DWORD NumberOfFunctions = pied->NumberOfFunctions;

					do 
					{
						PCSTR name = RtlOffsetToPointer(pied, *AddressOfNames++ - VirtualAddress);
						DWORD iFunc = *AddressOfNameOrdinals++;

						if (iFunc < NumberOfFunctions)
						{
							PVOID Address = RtlOffsetToPointer(FixedBase, AddressOfFunctions[iFunc]);
							const EXPORT_ENTRY* pa = a;

							while (PCSTR Name = pa->Name)
							{
								if (!strcmp(Name, name))
								{
									*pa->pAddress = Address;
									break;
								}
								pa++;
							}
						}

					} while (--NumberOfNames);
				}
			}
		}
	}
}

void getWowProcs()
{
	const WOW_DLL* p = WOW_PROCS::a;

	while (PCWSTR name = p->Name)
	{
		WCHAR sz[256];
		UNICODE_STRING ObjectName = { (USHORT)swprintf(sz, L"\\KnownDlls32\\%s", name) << 1, ObjectName.Length, sz };
		OBJECT_ATTRIBUTES oa = { sizeof(oa), 0, &ObjectName, OBJ_CASE_INSENSITIVE };
		HANDLE hSection;

		if (0 <= ZwOpenSection(&hSection, SECTION_QUERY, &oa))
		{
			SECTION_IMAGE_INFORMATION sii;
			if (0 <= ZwQuerySection(hSection, SectionImageInformation, &sii, sizeof(sii), 0) && sii.TransferAddress)
			{
				swprintf(sz, L"\\\\.\\GLOBALROOT\\systemroot\\syswow64\\%s", name);

				if (HMODULE hmod = LoadLibraryEx(sz, 0, LOAD_LIBRARY_AS_DATAFILE))
				{
					getWowProcs(PAGE_ALIGN(hmod), (ULONG_PTR)sii.TransferAddress, p->entry);
					FreeLibrary(hmod);
				}
			}
			ZwClose(hSection);
		}

		p++;
	}
}

_NT_END