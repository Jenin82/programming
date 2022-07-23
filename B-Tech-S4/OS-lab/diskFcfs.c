#include<stdio.h>

int main() {
	int c,a[100],s,n;
	printf("Enter the current head position : ");
	scanf("%d",&c);
	printf("Enter the no of requests : ");
	scanf("%d",&n);
  printf("Enter the requests : ");
  for(int i=0;i<n;i++)  	
    scanf("%d",&a[i]);
  if(c < a[0])
		s=a[0]-c;
	else
		s=c-a[0]; 
  for(int i=0;i<n-1;i++)
		if(a[i]<a[i+1])
			s=s+a[i+1]-a[i];
		else
			s=s+a[i]-a[i+1];  
	printf("Total head movement: %d\n",s);
}
