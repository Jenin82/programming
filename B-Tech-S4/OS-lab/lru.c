#include<stdio.h>

int ref[50],p[10],i,j,k=0,f,n,s=-1,m=0,temp=0,o,time[100],h,t,z,y=0;
void enqueue(int a);
int test();
int gtcheck();
int lru();
void main() {
  printf("Enter the no. of reference string :");
  scanf("%d",&n);
  printf("Enter the reference string :");
  for(i=0;i<n;i++){
    scanf("%d",&ref[i]);
    time[ref[i]]=0;
  }
  printf("Enter the no. of frames :");
  scanf("%d",&f);
  for(i=0;i<f;i++)
    p[i]=-1;
  for(i=0;i<n;i++){
    y++;
		time[ref[i]]=y;
    enqueue(ref[i]);
  }
  printf("Page fault = %d\n",k);
}

void enqueue(int a){
  int e = f-1;
  m = test(a);
  if(m==1)
    printf("No page fault\n");
  else {
    h=gtcheck();
    if(h==2) {
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
    else {
      z = lru();
      p[z]=a;
      for(j=0;j<f;j++)
        printf("%d ",p[j]);
      printf("\n");
      k++;
    }
  }
}

int test(int b){
  for(o=0;o<f;o++)
    if(b==p[o])
      temp++;
  if(temp!=0){
    temp=0;
    return 1;
  }
  else 
    return 0;
}

int gtcheck() {
  for(t=0;t<f-1;t++) 
    if(p[t+1]==-1)
      return 2;
  return 0;
}

int lru() {
  int tmp=0;
  for(t=0;t<f-1;t++){
    if(time[p[tmp]]>time[p[t+1]]){
      tmp=t+1;
    }
  }
  return tmp;
}