.model small
.stack 100h
.data
str1 db 'Hello $'
str2 db 'World$'
.code
start:
	mov ax,@data
	mov ds,ax
string1:
	mov ah,09h
	lea dx,str1
	int 21h
string2:
	mov ah,09h
	lea dx,str2
	int 21h
exit:
	mov ah,4ch
	int 21h
end start