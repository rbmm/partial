#pragma once

_NT_BEGIN

BOOL  CreateProcessWithShim
(
 IN LPCWSTR lpApplicationName, 
 IN LPWSTR lpCommandLine, 
 IN LPSECURITY_ATTRIBUTES lpProcessAttributes, 
 IN LPSECURITY_ATTRIBUTES lpThreadAttributes, 
 IN BOOL bInheritHandles, 
 IN DWORD dwCreationFlags, 
 IN LPVOID lpEnvironment, 
 IN LPCWSTR lpCurrentDirectory, 
 IN LPSTARTUPINFOW lpStartupInfo, 
 OUT LPPROCESS_INFORMATION lpProcessInformation,
 LPCWSTR lpShimDll,
 LPCVOID lpExtraData,
 DWORD cbExtraData,
 DWORD_PTR InheritFromProcessId
 );

_NT_END