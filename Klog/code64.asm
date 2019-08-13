
extern __imp_ObfDereferenceObject:QWORD

extern ?LogRoutine@LogData@NT@@YAXXZ : PROC ; void __cdecl NT::LogData::LogRoutine(void)

_TEXT segment

?LogRoutine@LogData@NT@@YAXPEAX@Z proc

	mov [rsp + 8],rcx ; DriverObject
	sub rsp,28h
	call ?LogRoutine@LogData@NT@@YAXXZ
	add rsp,28h
	mov rcx,[rsp + 8] ; DriverObject
	jmp __imp_ObfDereferenceObject
	
?LogRoutine@LogData@NT@@YAXPEAX@Z endp

_TEXT ends
end