#include "StdAfx.h"

_NT_BEGIN

#include "task.h"

extern OBJECT_ATTRIBUTES zoa;

DLL_TASK::DLL_TASK()
{
	InitializeSListHead(&_head);
	_hSemaphore = 0;
	_nTaskCount = 0;
}

DLL_TASK::~DLL_TASK()
{
	if (_hSemaphore)
	{
		ZwClose(_hSemaphore);
	}
}

NTSTATUS DLL_TASK::Init()
{
	return ZwCreateSemaphore(&_hSemaphore, SEMAPHORE_ALL_ACCESS, &zoa, 0, MAXLONG);
}

UU* DLL_TASK::PopReadyTask()
{
	return static_cast<UU*>(InterlockedPopEntrySList(&_head));
}

void DLL_TASK::ProcessTask(UU* p)
{
	NTSTATUS status;
	PSYSTEM_PROCESS_INFORMATION pspi = p->GetPSPI();

	if (pspi->InheritedFromUniqueProcessId)
	{
		if (0 <= (status = p->create()))
		{
			status = p->query(p->GetPSPI()->UniqueProcessId);
		}
	}
	else
	{
		ULONG cb = 0x40000;
		do 
		{
			status = STATUS_NO_MEMORY;

			if (PUCHAR buf = new UCHAR [cb])
			{
				if (0 <= (status = ZwQuerySystemInformation(SystemModuleInformation, buf, cb, &cb)))
				{
					status = p->create((PRTL_PROCESS_MODULES)buf);
					break;
				}
				delete [] buf;
			}

		} while (status == STATUS_INFO_LENGTH_MISMATCH);
	}

	p->status = status;

	InterlockedPushEntrySList(&_head, p);

	InterlockedDecrement(&_nTaskCount);

	ZwReleaseSemaphore(_hSemaphore, 1, 0);
}

void DLL_TASK::QueueTask(WorkQueue* queue, PSYSTEM_PROCESS_INFORMATION pspi)
{
	InterlockedIncrement(&_nTaskCount);

	if (!queue->push(_ProcessTask, this, 0, (ULONG_PTR)(new(pspi) UU)))
	{
		InterlockedDecrement(&_nTaskCount);
	}
}

void NTAPI DLL_TASK::_ProcessTask(PVOID Context, NTSTATUS /*Status*/, ULONG_PTR Information)
{
	((DLL_TASK*)Context)->ProcessTask((UU*)Information);
}

_NT_END
