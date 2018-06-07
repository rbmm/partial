_TEXT SEGMENT

strnstr proc
	jrcxz @@3
	push rdi
	push rsi
	mov rdi,rdx
	mov al,[r9]
	inc r9
	dec r8
@@1:
	repne scasb
	jne @@2
	cmp rcx,r8
	jb @@2
	mov rsi,r9
	mov rdx,rdi
	mov r10,rcx
	mov rcx,r8
	repe cmpsb
	je @@2
	mov rcx,r10
	mov rdi,rdx
	jmp @@1
@@2:
	sete al
	movzx rax,al
	neg rax
	and rax,rdi
	pop rsi
	pop rdi
	ret
@@3:
	xor rax,rax
	ret
	 
strnstr endp

strnchr proc
	jrcxz @@1
	push rdi
	mov al,r8b
	mov rdi,rdx
	repne scasb
	sete al
	movzx rax,al
	neg rax
	and rax,rdi
	pop rdi
	ret
@@1:
	xor rax,rax
	ret
strnchr endp

_TEXT ENDS
END