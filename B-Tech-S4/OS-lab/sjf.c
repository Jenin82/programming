#include<stdio.h>

struct sjf {
	int bt,at,wt,tt,pid;
}p[10],temp;

void main() {
	int i,j,n;
	printf("Enter the no. of process : ");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		p[i].pid = i;
		printf("Enter the Arrival time and Burst time for P%d : ",p[i].pid);
		scanf("%d%d",p[i].at, &p[i].bt);
	}
	for(i=0;i<n;i++) 
		for(j=0;j<n;j++) 
			if(p[i].at > p[j].at) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			} 
	printf("Pid    Arrival-time    Burst-time    Waiting-time    Turnaround-time\n");
	for(i=0;i<n;i++) 
		printf(" %d\t%d\t%d\t%d\t%d\n", p[i].pid,p[i].at, p[i].bt, p[i].wt, p[i].tt);
	
}