#include<stdio.h>

int n,ch,i,x=0,req[100],sum=0;

void main() {
  printf("Enter the no. of requests :");
  scanf("%d",&n);
  printf("Enter the current head :");
  scanf("%d",&ch);
  printf("Enter the requests :\n");
  for(i=0;i<n;i++)
    scanf("%d",&req[i]);
  if(ch>req[0])
    sum+=ch-req[0];
  else
    sum+=req[0]-ch;
  for(i=1;i<n;i++){
    if(req[i-1]>req[i])
      sum+=req[i-1]-req[i];
    else
    sum+=req[i]-req[i-1];
  }
  printf("Total seek time = %d cylinders\n",sum);
}