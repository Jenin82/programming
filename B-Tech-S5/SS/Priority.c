#include<stdio.h>

struct prio {
  int id,at,bt,prio,wt,tt;
}p[100],temp;

int n,i,j,bt=0;

void main () {
  printf("Enter the no. of process\n");
  scanf("%d",&n);
  printf("Enter the Arrival time, Burst time and priority of each process\n");
  for(i=0;i<n;i++) {
    scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].prio);
    p[i].id=i;
  }
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(p[i].at<p[j].at){
      temp=p[i];
      p[i]=p[j];
      p[j]=temp;
    }
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(p[i].at==p[j].at)
        if(p[i].prio<p[j].prio){
          temp=p[i];
          p[i]=p[j];
          p[j]=temp;
        }
  for(i=1;i<n;i++)
    for(j=1;j<n;j++)
      if(p[i].prio<p[j].prio){
        temp=p[i];
        p[i]=p[j];
        p[j]=temp;
      }
  p[0].wt=0;
  p[0].tt=p[0].bt;
  double twt=0,ttt=0;
  ttt+=p[0].bt;
  for(i=1;i<n;i++){
    bt=bt+p[i-1].bt;
    p[i].wt=bt-p[i].at;
    p[i].tt=p[i].bt+p[i].wt;
    twt+=p[i].wt;
    ttt+=p[i].tt;
  }
  printf("Pid      Arrival-time     Burst-time     Priority     Waiting-time     Turnaround-time\n");
	for(i=0;i<n;i++) 
		printf(" %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id,p[i].at, p[i].bt,p[i].prio, p[i].wt, p[i].tt);
	printf("\nAverage Waiting time = %f\n",twt/n);
	printf("Average Turaround time = %f\n",ttt/n);
}