#include<stdio.h>

struct rrb {
  int id,at,bt,wt,tt,rt;
}p[100],temp;

int n,i,j,bt=0,remain,tq,time=0;
float twt=0,ttt=0;

void main () {
  printf("Enter the no. of process\n");
  scanf("%d",&n);
  remain=n;
  printf("Enter the time quantum\n");
  scanf("%d",&tq);
  printf("Enter the Arrival time and Burst time of each process\n");
  for(i=0;i<n;i++) {
    scanf("%d%d",&p[i].at,&p[i].bt);
    p[i].id=i;
    p[i].rt=p[i].bt;
  }
  printf("Pid      Arrival-time     Burst-time     Waiting-time     Turnaround-time\n");
  for(i=0;remain!=0;){
    if(p[i].rt>0 && p[i].rt<=tq){
      time+=p[i].rt;
      p[i].rt=0;
      remain--;
      p[i].wt=time-p[i].at-p[i].bt;
      p[i].tt=time-p[i].at;
      twt+=time-p[i].at-p[i].bt;
      ttt+=time-p[i].at;
      printf(" %d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id,p[i].at, p[i].bt, p[i].wt, p[i].tt);
    }
    else if(p[i].rt>0){
      time+=tq;
      p[i].rt-=tq;
    }
    if(i==n-1)
      i=0;
    else if(p[i+1].at<=time)
      i++;
    else {
      i=0;
    }
  }
  printf("\nAverage Waiting time = %f\nAverage Turnaround time = %f\n",twt/n,ttt/n);
}