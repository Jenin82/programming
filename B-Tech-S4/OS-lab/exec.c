#include<stdio.h>
#include<unistd.h>

int main() {
	int pid;
	pid=fork();
	if(pid==0) {
		printf("exec starts");
		execl("/bin/ls","ls","-l",(char)(0));
		printf("exec didn't work");
	}
	else {
		wait(0);
		printf("parent = ls is completed in child");
	}
}