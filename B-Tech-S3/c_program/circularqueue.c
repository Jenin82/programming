#include<stdio.h>
int Q[20],f=-1,r=-1,i,b;
void insert();
void delete();
void display();
void main()
{
	int n;
	printf("\nEnter the limit of Queue : ");
	scanf("%d",&b);
	l:
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
	printf("\nEnter the choice : ");
	scanf("%d",&n);
	switch(n)
	{
		case 1:insert();
			goto l;
		case 2:delete();
			goto l;
		case 3:display();
			goto l;
		case 4:break;
		default:printf("\nWrong Selection");
			goto l;
	}
}
void insert()
{
	if((r+1)%b==f)
	{
		printf("\nQueue is Overflow ");	
	}
	else 
	{
		if(f==-1&&r==-1)
			{f=0;r=0;}	
		else
			{r=(r+1)%b;}
		printf("\nEnter the Element : ");
		scanf("%d",&Q[r]);
	}	
}
void delete()
{
	if(f==-1&&r==-1)
		printf("\nQueue is Underflow ");
	else if(f==r) {
		printf("\n%d is deleted",Q[f]);
		f=r=-1;		
	}
	else {
		printf("\n%d is deleted",Q[f]);
		f=(f+1)%b;
	}	
}
void display()
{
	if(f==-1&&r==-1) 
		printf("\nQueue is empty ");
	else if(r>=f) {
		printf("\nQueue : ");
		for(i=f;i<=r;i++)
			printf("%d\t",Q[i]);
	}
	else {
		printf("\nQueue : ");
		for(i=f;i<b;i++)
			printf("%d\t",Q[i]);
		for(i=0;i<=r;i++)
			printf("%d\t",Q[i]);
	}	
}