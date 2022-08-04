#include<stdio.h>
int n,m,i,j,k=-1,p[100],b[100];
void main() {
	printf("Enter the no. process and no. memory blocks : ");
	scanf("%d%d",&n,&m);
	int flag[m],allocation[m];
	printf("Enter the size of each process : ");
	for(i=0;i<n;i++) 
		scanf("%d",&p[i]);
	printf("Enter the size of each block : ");
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
		flag[i]=0;
		allocation[i]=-1;
	}
	for(i=0;i<m;i++) 
		for(j=0;j<m;j++)
			if(b[i]<b[j]) {
				int temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
	for(i=0;i<n;i++) 
		for(j=0;j<m;j++) 
			if(flag[j]==0 && b[j]>=p[i]) {
				allocation[j]=i;
				flag[j]=1;
				break;
			}
	printf("Process\t\tProcess Size\n");
	for(i=0;i<n;i++) 
		printf("%d\t\t\t%d\n",i,p[i]);
	printf("Block Size\tAllocated Process\n");
	for(i=0;i<m;i++) {
		if(allocation[i]!=-1) 
			printf("%d\t\t\t%d\n",b[i],allocation[i]);
		else
			printf("%d\t\t\tNot allocated\n",b[i]);
	} 
}