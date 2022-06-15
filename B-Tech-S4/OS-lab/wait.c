#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main() {
	pid_t cpid;
	if(fork()==0) {
		exit(0);
	}
	else {
		cpid=wait(NULL);
	}
	printf("Parent PID : %d\n",getpid());
	printf("Child PID : %d\n",cpid);
}