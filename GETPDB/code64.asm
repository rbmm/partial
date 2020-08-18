_TEXT SEGMENT

?strnchr@NT@@YAPEAD_KPEBXD@Z proc
	jrcxz @retz
	mov rax,r8
	xchg rdi,rdx
	repne scasb
	mov rax,rdi
	mov rdi,rdx
	cmovne rax,rcx
	ret
?strnchr@NT@@YAPEAD_KPEBXD@Z endp

@retz proc
	xor eax,eax
	ret
@retz endp

?strnstr@NT@@YAPEAD_KPEBX01@Z proc
	jrcxz @retz
	cmp rcx,r8
	jb @retz
	push rdi
	push rsi
	mov rdi,rdx
	mov al,[r9]
	inc r9
	dec r8
	sub rcx,r8
@@1:
	repne scasb
	jne @@2
	mov rsi,r9
	mov rdx,rdi
	mov r10,rcx
	mov rcx,r8
	test ecx,ecx
	repe cmpsb
	je @@2
	mov rcx,r10
	mov rdi,rdx
	jmp @@1
@@2:
	mov rax,rdi
	cmovne rax,rcx
	pop rsi
	pop rdi
	ret
?strnstr@NT@@YAPEAD_KPEBX01@Z endp

_TEXT ENDS
END