#pragma once

class QUERY_PROCESS_MODULES
{
	enum { secsize = 0x20000 };

	PRTL_PROCESS_MODULES _psmi;
	HANDLE _hSection;

public:

	QUERY_PROCESS_MODULES();

	~QUERY_PROCESS_MODULES();

	NTSTATUS create();
	NTSTATUS create(PRTL_PROCESS_MODULES psmi);

	NTSTATUS _query(HANDLE UniqueProcess);
	NTSTATUS query(HANDLE UniqueProcess);

	PRTL_PROCESS_MODULES get() { return _psmi; }

#ifdef _WIN64
	static BOOL InitWow();
#endif
};
