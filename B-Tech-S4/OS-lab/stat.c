#include<stdio.h>
#include<sys/stat.h>

void main() {
	struct stat file;
	stat("stat.c",&file);
	printf("ST_Mode : %o \n",file.st_mode);
}