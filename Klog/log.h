#pragma once

namespace LogData
{
	NTSTATUS Create(PDRIVER_OBJECT DriverObject);

	void StopLog(); // call Release in the end

	// IRQL <= DISPATCH_LEVEL
	// the Unicode format codes (%C, %S, %lc, %ls, %wc, %ws, and %wZ) can only be used with IRQL = PASSIVE_LEVEL. 
	void print(const char* format, ...);
};