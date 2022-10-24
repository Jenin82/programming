#include<stdio.h>

int n,ch,i,j,temp,x=0,cy,req[100],sum=0;

void main() {
  printf("Enter the no. of requests :");
  scanf("%d",&n);
  printf("Enter the current head :");
  scanf("%d",&ch);
  printf("Enter the cylinder size :");
  scanf("%d",&cy);
  cy--;
  printf("Enter the requests :\n");
  for(i=0;i<n;i++)
    scanf("%d",&req[i]);
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(req[i]<req[j]){
        temp=req[i];
        req[i]=req[j];
        req[j]=temp;
      }
  for(i=0;i<n;i++)
    if(ch>req[i])
      x++;
  sum+=cy-ch;
  sum+=cy;
  sum+=req[x-1];
  printf("Total seek time = %d cylinders\n",sum);
}