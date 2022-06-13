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
		scanf("%d%d",&p[i].at, &p[i].bt);
	}
	for(i=0;i<n;i++) 
		for(j=0;j<n;j++) 
			if(p[i].at < p[j].at) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			} 
	for(i=0;i<n;i++) 
		for(j=0;j<n;j++) 
			if(p[i].at == p[j].at)
				if(p[i].bt < p[j].bt) {
					temp = p[i];
					p[i] = p[j];
					p[j] = temp;
				}
	for(i=1;i<n;i++) 
		for(j=1;j<n;j++) 
			if(p[i].bt < p[j].bt) {
					temp = p[i];
					p[i] = p[j];
					p[j] = temp;
			}
	p[0].wt = 0; 
	p[0].tt = p[0].bt;
	double ttt, twt;
	for(i=1;i<n;i++) {
		p[i].wt = p[i-1].wt + p[i-1].bt;
		p[i].tt = p[i].wt + p[i].bt;
		ttt += p[i].tt;
		twt += p[i].wt;
	} 
	ttt = ttt/n;
	twt = twt/n;
	printf("Pid      Arrival-time     Burst-time     Waiting-time     Turnaround-time\n");
	for(i=0;i<n;i++) 
		printf(" %d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid,p[i].at, p[i].bt, p[i].wt, p[i].tt);
	printf("Average Wait time = %f\n",twt);
	printf("Average Turaround time = %f\n",ttt);
}