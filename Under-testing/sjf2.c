#include<stdio.h>

void sort();
int i,j,n,b,bb=0,k=0,l=1;
struct sjf {
	int bt,at,wt,tt,pid;
}p[10],q[10],temp,r[10];

void main() {
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
	b = p[0].bt;
	r[0].wt = 0; 
	r[0].tt = p[0].bt;
	double ttt, twt;
	for(i=1;i<n;i++) {
		for(j=i;j<n;j++) 
			if(p[j].at <= b /*&& p[j].at > bb*/) {
					q[k] = p[j];
					printf("done\n");
					k++;
			}
		sort();
		//p[l] = q[0];
		//l++;
		k = 0;
		bb = b;
		b += p[j].bt;
	}
	for(i=1;i<n;i++) {
		r[i].wt = r[i-1].wt + r[i-1].bt;
		r[i].tt = r[i].wt + r[i].bt;
		ttt += r[i].tt;
		twt += r[i].wt;
	} 
	ttt = ttt/n;
	twt = twt/n;
	printf("Pid      Arrival-time     Burst-time     Waiting-time     Turnaround-time\n");
	for(i=0;i<n;i++) 
		printf(" %d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid,p[i].at, p[i].bt, p[i].wt, p[i].tt);
	printf("Average Wait time = %f\n",twt);
	printf("Average Turaround time = %f\n",ttt);
}

void sort() {
	int x;
	for(x=0;x<=k;x++)
		for(int y=x+1;y<=k;y++) 
			if(q[x].bt > q[y].bt) {
				temp = q[x];
				q[x] = q[y];
				q[y] = temp;
				printf(" after sort %d\t\t%d\t\t%d\t\t%d\t\t%d\n", q[x].pid,q[x].at, q[x].bt, q[x].wt, q[x].tt);
			}
	r[l] = q[x];			
	l++;
}