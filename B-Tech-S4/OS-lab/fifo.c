#include<stdio.h>

int ref[50],p[10],i,j,k=0,f,n,s=-1,m=0,temp=0,o;
void enqueue(int a);
int pageFaultCheck();
void main() {
  printf("Enter the no. of reference string :");
  scanf("%d",&n);
  printf("Enter the reference string :");
  for(i=0;i<n;i++)
    scanf("%d",&ref[i]);
  printf("Enter the no. of frames :");
  scanf("%d",&f);
  for(i=0;i<f;i++)
    p[i]=-1;
  for(i=0;i<n;i++){
    enqueue(ref[i]);
  }
  printf("Page fault = %d\n",k);
}

void enqueue(int a){
  int e = f-1;
  m = pageFaultCheck(a);
  if(m==1)
    printf("No page fault\n");
  else {
    if(s==e)
      s=0;
    else 
      s++;
    p[s]=a;
    for(j=0;j<f;j++)
      printf("%d ",p[j]);
    printf("\n");
    k++;
  }
}

int pageFaultCheck(int b){
  for(o=0;o<f;o++)
    if(b==p[o])
      temp++;
  if(temp!=0){
    temp=0;
    return 1;
  }
  return 0;
}