#include "StdAfx.h"

//#define _PRINT_CPP_NAMES_
#include "../inc/asmfunc.h"

_NT_BEGIN

#include "log.h"

extern "C"
NTSYSAPI
BOOLEAN
NTAPI
KeAlertThread(
  IN  PKTHREAD Thread,
  IN  KPROCESSOR_MODE AlertMode
  );

namespace LogData
{
	NPAGED_LOOKASIDE_LIST gLookaside;
	LARGE_INTEGER ByteOffset = {};
	FILE_END_OF_FILE_INFORMATION eof = {};
	EX_RUNDOWN_REF gRunRef;
	PKTHREAD gLogThread;
	HANDLE ghLog;
	volatile BOOLEAN gExit;

	enum { max_log_entry_size = 0x400 };

	VOID NTAPI KernelRoutine(
		PKAPC /*Apc*/, 
		PKNORMAL_ROUTINE * /*NormalRoutine*/,
		PVOID * /*NormalContext*/, 
		PVOID * /*SystemArgument1*/, 
		PVOID * /*SystemArgument2*/
		)
	{
	}

	VOID NTAPI IoApcRoutine (
		_In_ PVOID ApcContext,
		_In_ PIO_STATUS_BLOCK IoStatusBlock,
		_In_ ULONG /*Reserved*/
		)
	{
		if (0 > IoStatusBlock->Status)
		{
			DbgPrint("NtWriteFile(%x, %p)\n", IoStatusBlock->Status, IoStatusBlock->Information);
		}

		ExFreeToNPagedLookasideList(&gLookaside, ApcContext);
		ExReleaseRundownProtection(&gRunRef);
	}

	VOID NTAPI NormalRoutine(PVOID Apc, PVOID Buffer, PVOID Length)
	{
		LONGLONG NewByteOffset = ByteOffset.QuadPart + (ULONG)(ULONG_PTR)Length;

		if (eof.EndOfFile.QuadPart < NewByteOffset)
		{
			eof.EndOfFile.QuadPart = (NewByteOffset + 0xffff) & ~0xffff;
			IO_STATUS_BLOCK iosb;
			NtSetInformationFile(ghLog, &iosb, &eof, sizeof(eof), FileEndOfFileInformation);
			NtSetInformationFile(ghLog, &iosb, &eof, sizeof(eof), FileAllocationInformation);
		}

		// we insert APC to own created thread, which already hold driver
		NTSTATUS status = NtWriteFile(ghLog, 0, IoApcRoutine, Apc, (PIO_STATUS_BLOCK)Apc, Buffer, (ULONG)(ULONG_PTR)Length, &ByteOffset, 0);
		
		if (NT_ERROR(status))
		{
			reinterpret_cast<PIO_STATUS_BLOCK>(Apc)->Status = status;
			reinterpret_cast<PIO_STATUS_BLOCK>(Apc)->Information = 0;
			IoApcRoutine(Apc, (PIO_STATUS_BLOCK)Apc, 0);
		}
		else
		{
			if (status != STATUS_PENDING)
			{
				DbgPrint("NtWriteFile(%x)\n", status);
			}

			ByteOffset.QuadPart = NewByteOffset;
		}
	}

	void NTAPI LogRoutine(PVOID DriverObject)ASM_FUNCTION;

	void LogRoutine()
	{
		CPP_FUNCTION;

		static LARGE_INTEGER Interval = { MAXULONG, -1 };//infinite

		DbgPrint("++LogRoutine()\n");

		do 
		{
			KeDelayExecutionThread(KernelMode, TRUE, &Interval);
		} while (!gExit);

		DbgPrint("--LogRoutine()\n");

		IO_STATUS_BLOCK iosb;
		NtSetInformationFile(ghLog, &iosb, &ByteOffset, sizeof(ByteOffset), FileEndOfFileInformation);

		NtClose(ghLog);

		DbgPrint("{%x/%x %x/%x %x-%x}\n", 
			gLookaside.L.TotalAllocates, gLookaside.L.TotalFrees,
			gLookaside.L.Depth, gLookaside.L.MaximumDepth,
			gLookaside.L.AllocateMisses, gLookaside.L.FreeMisses);

		ExDeleteNPagedLookasideList(&gLookaside);
	}

	NTSTATUS StartLogThread(PDRIVER_OBJECT DriverObject)
	{
		ObfReferenceObject(DriverObject);

		HANDLE hThread;
		NTSTATUS status = PsCreateSystemThread(&hThread, 0, 0, 0, 0, LogRoutine, DriverObject);

		if (0 <= status)
		{
			status = ObReferenceObjectByHandle(hThread, 0, *PsThreadType, KernelMode, (void**)&gLogThread, 0);

			NtClose(hThread);

			DbgPrint("gLogThread=%p\n", gLogThread);
			
			if (0 <= status)
			{
				return STATUS_SUCCESS;
			}

			gLogThread = 0;
		}

		ObfDereferenceObject(DriverObject);

		return status;
	}

	NTSTATUS CreateLogFile()
	{
		IO_STATUS_BLOCK iosb;
		UNICODE_STRING ObjectName;
		OBJECT_ATTRIBUTES oa = { sizeof(oa), 0, &ObjectName, OBJ_CASE_INSENSITIVE };
		RtlInitUnicodeString(&ObjectName, L"\\systemroot\\temp\\{A8467BE8-A379-459e-A853-39D76B1EBAAB}");

		NTSTATUS status = NtCreateFile(&oa.RootDirectory, FILE_ADD_FILE, 
			&oa, &iosb, 0, 0, FILE_SHARE_READ|FILE_SHARE_WRITE, FILE_OPEN_IF, FILE_DIRECTORY_FILE, 0, 0);

		if (0 <= status)
		{
			LARGE_INTEGER SystemTime;
			KeQuerySystemTime(&SystemTime);
			ExSystemTimeToLocalTime(&SystemTime, &SystemTime);
			TIME_FIELDS tf;
			RtlTimeToTimeFields(&SystemTime, &tf);

			WCHAR name[16];
			swprintf_s(name, L"%02u.log", tf.Day);

			RtlInitUnicodeString(&ObjectName, name);

			if (0 <= (status = NtCreateFile(&ghLog, FILE_WRITE_DATA|FILE_READ_ATTRIBUTES, 
				&oa, &iosb, 0, 0, FILE_SHARE_READ, FILE_OPEN_IF, FILE_NON_DIRECTORY_FILE, 0, 0)))
			{
				if (iosb.Information == FILE_OPENED)
				{
					union{
						FILE_BASIC_INFORMATION fbi;
						FILE_STANDARD_INFORMATION fsi;
					};

					if (0 <= NtQueryInformationFile(ghLog, &iosb, &fbi, sizeof(fbi), FileBasicInformation))
					{
						// trancate file to 0 if older ~16 days
						if (SystemTime.QuadPart - fbi.LastWriteTime.QuadPart > 10000000LL*3600*24*16)
						{
							NtSetInformationFile(ghLog, &iosb, &eof, sizeof(eof), FileEndOfFileInformation);
						}
					}

					if (0 <= NtQueryInformationFile(ghLog, &iosb, &fsi, sizeof(fsi), FileStandardInformation))
					{
						ByteOffset.QuadPart = fsi.EndOfFile.QuadPart;
					}
				}
			}

			NtClose(oa.RootDirectory);
		}

		return status;
	}

	NTSTATUS Create(PDRIVER_OBJECT DriverObject)
	{
		ExInitializeRundownProtection(&gRunRef);
		ExInitializeNPagedLookasideList(&gLookaside, 0, 0, 0, max_log_entry_size, '>..<', 0);

		NTSTATUS status = CreateLogFile();

		if (0 <= status)
		{
			if (0 <= (status = StartLogThread(DriverObject)))
			{
				return STATUS_SUCCESS;
			}

			NtClose(ghLog);
		}

		ghLog = 0;

		ExDeleteNPagedLookasideList(&gLookaside);
		ExRundownCompleted(&gRunRef);

		return status;
	}

	void StopLog()
	{
		ExWaitForRundownProtectionRelease(&gRunRef);

		if (gLogThread)
		{
			DbgPrint("StopLog()\n");

			gExit = TRUE;
			KeAlertThread(gLogThread, KernelMode);
			ObfDereferenceObject(gLogThread);
		}
	}

	void print(const char* format, ...)
	{
		va_list args;
		va_start(args, format);

		vDbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_INFO_LEVEL, format, args);

		if (ExAcquireRundownProtection(&gRunRef))
		{
			if (PKAPC Apc = (PKAPC)ExAllocateFromNPagedLookasideList(&gLookaside))
			{
				// we insert APC to own created thread, which already hold driver
				KeInitializeApc(Apc, gLogThread, OriginalApcEnvironment, 
					KernelRoutine, 0, NormalRoutine, KernelMode, Apc);

				PSTR buf = (PSTR)(Apc + 1);

				int len = _vsnprintf_s(buf, max_log_entry_size - sizeof(KAPC), _TRUNCATE, format, args);

				if (0 < len)
				{
					if (KeInsertQueueApc(Apc, buf, (void*)(ULONG_PTR)len, IO_NO_INCREMENT))
					{
						return ;
						// NormalRoutine 
						// IoApcRoutine
						// ExFreeToNPagedLookasideList
						// ExReleaseRundownProtection
					}
				}

				ExFreeToNPagedLookasideList(&gLookaside, Apc);
			}

			ExReleaseRundownProtection(&gRunRef);
		}
	}
};

_NT_END