#include<stdio.h>

int main() {
	int c,a[100],s,n,cy,co=0,k=0,m;
	printf("Enter the current head position :");
	scanf("%d",&c);
	printf("Enter the no of cylinder size :");
	scanf("%d",&cy);
	printf("Enter the no of requests :");
	scanf("%d",&n);
  printf("Enter the requests :");
  for(int i=0;i<n;i++)  	
  scanf("%d",&a[i]);
  cy=cy-1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i]<a[j]) {
				int t;
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			} 
	for(int i=0;i<n-1;i++) {
		if(a[i]<c)
			co++;
		else {
			k++;
			if(k==1) {
				m=co;
				s=s+a[co]-c;
			}
			else
			s=s+a[co+1]-a[co];
		}
	}
	s=s+cy-a[co+1];
	s=s+cy;
	s=s+a[0]-0;
	for(int h=0;h<m-1;h++)
		s=s+a[h+1]-a[h];
	s=s-6;
	printf("Total head movement:%d",s);
} 
