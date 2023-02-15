data segment
n1 dd 00000001h
n2 dd 00000001h
result dw ?
data ends
code segment
assume cs:code, ds:data
start:
	mov ax,data
	mov ds,ax
	mov dl,00h
	mov ax, word ptr n1
	mov bx, word ptr n2
	add ax,bx
	mov word ptr result,ax
	mov ax, word ptr n1+2
	mov bx, word ptr n2+2
	adc ax,bx
	mov word ptr result+2,ax
	jnc move
	inc dl
move: 
	mov byte ptr result+4,dl
	int 3
	code ends
	end start