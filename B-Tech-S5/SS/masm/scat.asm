.model small
.stack 100h
.data
str1 db 'Hello$'
str2 db 'World$'
.code
start:
	mov ax,@data
	mov ds,ax
	mov si,00
	mov di,00
	lea si,str1
	lea di,str2
	mov al,'$'
	cmp al,[si]
	jz next
next:
	cmp al,[di]
	jz exit
	mov bl,[di]
	mov [si],bl
	inc si
	inc di
	jmp next
exit:
	mov [si],al
	mov ah,09h	
	int 21h
end start
