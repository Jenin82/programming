.model small
.stack 100h
.data
	str1 db 'Jenin$'
	strlen1 dw $-str1
	strrev db ?
.code
start:
	mov ax,@data 
	mov ds,ax
	mov cx,strlen1
	add cx,-2
	lea si,str1
	lea di,strrev
  add si,strlen1
  add si,-2
	l1:
		mov al,[si]
		mov [di],al
		dec si
		inc di
		loop l1
	mov al,[si]
  mov [di],al
  inc di
  mov al,'$'
  mov [di],al
	Print:
    mov ah,09h
    lea dx,strrev
    int 21h
	Exit:
    mov ah,4ch
    int 21h
end start