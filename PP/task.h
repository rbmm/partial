#pragma once

#include "qpm.h"
#include "Queue.h"

//////////////////////////////////////////////////////////////////////////
// Embedded in SYSTEM_PROCESS_INFORMATION

struct UU : SLIST_ENTRY, QUERY_PROCESS_MODULES
{
	PSYSTEM_PROCESS_INFORMATION pspi;
	NTSTATUS status;

	PSYSTEM_PROCESS_INFORMATION GetPSPI()
	{
		return pspi;
	}

	static UU* _get(PSYSTEM_PROCESS_INFORMATION pspi)
	{
		// SLIST_ENTRY mast be aligned on 16
		return (UU*)((15 + (ULONG_PTR)&pspi->ReadOperationCount) & ~15);
	}

	void* operator new(size_t, PSYSTEM_PROCESS_INFORMATION pspi)
	{
		UU* p = _get(pspi);
		p->pspi = pspi;
		p->status = STATUS_PENDING;
		return p;
	}

	void operator delete(void*)
	{
	}
};

//////////////////////////////////////////////////////////////////////////
// DLL_TASK

struct DLL_TASK 
{
	SLIST_HEADER _head;
	HANDLE _hSemaphore;
	LONG _nTaskCount;

	void BeginTasks()
	{
		_nTaskCount = 1;
	}

	void EndTasks()
	{
		InterlockedDecrement(&_nTaskCount);
	}

	BOOL IsAllTasksDone()
	{
		return !_nTaskCount && !QueryDepthSList(&_head);
	}

	DLL_TASK();

	~DLL_TASK();

	NTSTATUS Init();

	UU* PopReadyTask();

	void ProcessTask(UU* p);

	void QueueTask(WorkQueue* queue, PSYSTEM_PROCESS_INFORMATION pspi);

	static void NTAPI _ProcessTask(PVOID Context, NTSTATUS Status, ULONG_PTR Information);
};

