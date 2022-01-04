org 0x7c00]

mov bx, string

inp:
	mov ah, 0
	int 0x16
	cmp al, 13
	je printString
	mov ah, 0x0e
	int 0x10
	mov [bx], al
	inc bx
	jmp inp
printString:
	mov bx, string
	mov ah, 0x0e
	printLoop:
		mov al, [bx]
		cmp al, 0
		je exit
		int 0x10
		inc bx
		jmp printLoop
exit:
	jmp $
string:
	times 10 db 0
times 510 - ($-$$) db 0
db 0x55, 0xaa