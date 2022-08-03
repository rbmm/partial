#pragma once

struct DLL_LIST_0 
{	
	struct FUNCTION
	{
		PCSTR lpProcName;
		PVOID pv;
	};

	DLL_LIST_0 *next;

	union {
		PCWSTR lpModuleName;
		HMODULE hmod;
	};

	FUNCTION funcs[];

	static void Process(DLL_LIST_0 *cur);
};

#define BEGIN_DLL_FUNCS(name, prevname) DLL_LIST_0 name { prevname, _CRT_WIDE(_CRT_STRINGIZE(name)), {
#define END_DLL_FUNCS() {}}}

#define FUNC(name) { _CRT_STRINGIZE(name) }
#define ORDN(n) { MAKEINTRESOURCEA(n) }
