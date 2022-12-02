.model small
.stack 100h
.data
num1 dw 6785h
num2 dw 1234h
result dw 00
.code
start:
	mov ax,@data
	mov ds,ax
	mov ax,00h
	mov ax,num1
	add ax,num2
	mov result,ax
int 03h
end start
end
