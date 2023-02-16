.model small
.stack 100h
.data
n1 dd 8444A001h
n2 dd 8888A001h
result dw ?
.code
start:
	mov ax,@data
	mov ds,ax
	mov ax,word ptr n1
	mov bx,word ptr n2
	add ax,bx
	mov result,ax
	mov ax,word ptr n1+2
	mov bx,word ptr n2+2
	adc ax,bx
	mov bx,result
int 3h
end start