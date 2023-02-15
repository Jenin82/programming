.model small
.stack 100h
.data
str1 db 'Hello '
str2 db 'World$'
.code
start:
	mov ax,@data
	mov ds,ax
	mov ax,offset str1
	mov ah,09h
	mov al,'$'
	lea di,str2
next:
	cmp al,[di]
	jz exit
	mov bl,[di]
	mov ah,09h
	inc di
	jmp next	
exit:
	int 21h
	mov ah,4ch
	end start
