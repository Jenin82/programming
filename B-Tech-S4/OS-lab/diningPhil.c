#include<stdio.h>
int n,i,j;
void main(){
	printf("Enter the number of philosophers :");
	scanf("%d",&n);
	printf("One person eats at a time\n");
	for(i=1;i<n+1;i++) {
		printf("\nDining :%d\nPhilosopher %d is Eating\n",i,i);
		for(j=i+1;j<n+1;j++) 
			printf("Philosopher %d is Waiting\n",j);
		int k = i;
		for(i=1;i<k;i++) 
			printf("Philosopher %d is Thinking\n",i);
	}
	printf("\nAll philosophers are now Thinking\n");
}