#pragma once

struct EXPORT_ENTRY 
{
	PCSTR Name;
	void** pAddress;
};

struct WOW_DLL 
{
	PCWSTR Name;
	const EXPORT_ENTRY* entry;
};

#define WOW_DLL_NAME(dll_name) dll_name##_WOW

#define BEGIN_WOW_DLL(dll_name) namespace WOW_DLL_NAME(dll_name) { const WCHAR name[] = L ## #dll_name L".dll"; const EXPORT_ENTRY a[] = {
#define WOW_FUNC(func) { #func, &g_ ## func ## Wow },

#define WOW_PROCS_BEGIN() namespace WOW_PROCS { const WOW_DLL a[] = {
#define WOW_DLL(dll_name) { WOW_DLL_NAME(dll_name)::name, WOW_DLL_NAME(dll_name)::a },

#ifndef END_HOOK
#define END_HOOK() {}};}
#endif

namespace WOW_PROCS { extern const WOW_DLL a[]; };

void getWowProcs();