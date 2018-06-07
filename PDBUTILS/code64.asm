
_TEXT segment 'CODE'

strnlen proc
	xor eax,eax
	jecxz @@2
	push rdi
	mov rdi,rdx
	repne scasb
	jne @@1
	dec rdi
@@1:
	sub rdi,rdx
	mov rax,rdi
	pop rdi
@@2:
	ret
strnlen endp

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

_TEXT ends
end