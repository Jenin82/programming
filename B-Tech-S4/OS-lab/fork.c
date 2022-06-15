#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main() {
	int p,p1,p2,p3;
	p=fork();
	if(p==-1) {
		printf("error");
		exit(1);
	}
	if(p!=0) {
		p1= getpid();
		printf("process id of parent is %d\n",p1);
	}
	else {
		p2=getpid();
		printf("process id of child is %d\n",p2);
	}
}