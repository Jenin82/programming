#include<stdio.h>
int c,n,a[100],i,j,s,x=0,copy,cy;
void main() {
	printf("Enter the current head position : ");
	scanf("%d",&c);
	printf("Enter the cylinder size : ");
	scanf("%d",&cy);
	cy = cy-1;
	printf("Enter the no of requests : ");
	scanf("%d",&n);
  printf("Enter the requests : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) 
			if(a[i]<a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
		}
	for(i=0;i<n;i++) {
		if(a[i]<c)
			x++;
		else if(x==copy)
			s = a[i]-c;
		else 
			s += a[i]-a[i-1];
		copy = x;
	}
	s += cy-a[i-1];
	s += cy-a[x-1];
	for(i=x-1;i>0;i--) {
		s += a[i]-a[i-1];
	}
	printf("Total cylinder head : %d\n",s);
}