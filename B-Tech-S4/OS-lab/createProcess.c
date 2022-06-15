#include <stdio.h>
#include <unistd.h>

void create() {
	if(fork() == 0)	{
		printf("Child Process Created..!\n");
		printf("Process ID : %d \n\n",getpid());
	}
	else {
		printf("Parent Process Created..!\n");
		printf("Process ID : %d \n\n",getpid());
	}
}

void main() {
	printf("Processing.....\n\n");
	create();
	printf("Process Completed\n\n");
}