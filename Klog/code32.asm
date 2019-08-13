.686
extern __imp_@ObfDereferenceObject@4:DWORD

extern ?LogRoutine@LogData@NT@@YGXXZ : PROC ; void __stdcall NT::LogData::LogRoutine(void)

_TEXT SEGMENT

?LogRoutine@LogData@NT@@YGXPAX@Z proc

	call ?LogRoutine@LogData@NT@@YGXXZ
	pop ecx ; return address
	xchg [esp],ecx
	jmp __imp_@ObfDereferenceObject@4
	
?LogRoutine@LogData@NT@@YGXPAX@Z endp

_TEXT ENDS

END