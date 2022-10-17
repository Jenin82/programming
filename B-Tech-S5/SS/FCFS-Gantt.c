#include<stdio.h>

struct fcfs {
  int id,at,bt,wt,tt;
}p[100],temp;

int n,i,j,ct=0,a=0;

void main () {
  printf("Enter the no. of process\n");
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    printf("Enter the Arrival time and Burst time of Process P[%d]\n",i);
    scanf("%d%d",&p[i].at,&p[i].bt);
    p[i].id=i;
  }
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
			if(p[i].at<p[j].at){
      	temp=p[i];
      	p[i]=p[j];
      	p[j]=temp;
    }
  p[0].wt=0;
  p[0].tt=p[0].bt;
  double twt=0,ttt=0;
  ttt+=p[0].bt;
  for(i=1;i<n;i++){
    ct=ct+p[i-1].bt;
    p[i].wt=ct-p[i].at;
    p[i].tt=p[i].bt+p[i].wt;
    twt+=p[i].wt;
    ttt+=p[i].tt;
  }
	//GANT chart starts here
  printf("\n\n                GANTT CHART\n");
  printf("**********************************************\n ");
  for(i=0;i<n;i++){
    for(j=0;j<p[i].bt;j++)
      printf("--");
  }
  printf("\n|");
  for(i=0;i<n;i++){
    for(j=0;j<p[i].bt-1;j++)
      printf(" ");
    printf("p%d",p[i].id);
    for(j=0;j<p[i].bt-1;j++)
      printf(" ");
    printf("\b|");
  }
  printf("\n ");
  for(i=0;i<n;i++){
    for(j=0;j<p[i].bt;j++)
      printf("--");
  }
  printf("\n0");
  a=p[0].bt;
  for(i=0;i<n;i++){
    for(j=0;j<p[i].bt-1;j++)
      printf(" "); 
    for(j=0;j<p[i].bt-1;j++)
      printf(" ");
    printf("%d",a);
    printf(" ");
    a+=p[i+1].bt;
  }
  printf("\n\n\n");

	// GANT chart ends here
  ttt = ttt/n;
	twt = twt/n;
  printf("Pid      Arrival-time     Burst-time     Waiting-time     Turnaround-time\n");
	for(i=0;i<n;i++) 
		printf(" %d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id,p[i].at, p[i].bt, p[i].wt, p[i].tt);
	printf("\nAverage Wait time = %f\n",twt);
	printf("Average Turaround time = %f\n",ttt);
}
