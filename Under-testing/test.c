#include<stdio.h>
int n,i,j,tq,time=0;
struct rrb {
	int id,at,bt,wt,tat,remain;
}p[20],temp;
void main() {
	printf("Enter the no. of process :");
	scanf("%d",&n);
	printf("Enter the time quantum :");
	scanf("%d",&tq);
	for(i=0;i<n;i++) {
		printf("Enter Arrival time and burst time of P%d :",i);
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].remain = p[i].bt;
		p[i].id = i;
	} 
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(p[i].at<p[j].at) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
	//for(i=0;i<n;i++)
		//printf("%d ",p[i].at);
	i=0;
	j=0;
	while(j<n) {
		if(p[i].remain>0 && p[i].remain<=tq) {
			time += p[i].remain;
			p[i].remain = 0;
			p[i].tat = time-p[i].at;
			p[i].wt = time-p[i].at-p[i].bt;
			if(i==n-1)
				i=-1;
			i++;
			printf("%d\n",i);
		}
		if(p[i].remain>0) {
			time += tq;
			p[i].remain = p[i].remain-tq;
			printf("%d\n",time);
			if(i==n-1)
				i=-1;
			i++;
		}
	}
	for(i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].wt,p[i].tat);
}