#include <stdio.h>

struct node {
	int priority,element;
} q[20];

int n,f=-1,r=-1;

int main()
{
  printf("Enter the limit of queue\n");
  scanf("%d",&n);
  loop:
  printf("\nSelect a queue operation\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
  int x;
  scanf("%d",&x);
  switch(x) 
  {
    case 1: Enqueue();
      goto loop;
    case 2: Dequeue();
      goto loop;
    case 3: Display();
      goto loop;
    case 4: return 0;
    default: printf("Wrong selection, try again\n");
      goto loop;
  }
}

//Functions

void Enqueue()
{
  if(r==n-1)
    printf("Queue Overflow\n");
  else 
  {
    if(f==-1)
      f=0;
    int a,b;
    printf("Enter element to be inserted\n");
    scanf("%d",&a);
    printf("Enter the priority\n");
    scanf("%d",&b);
    r++;
    q[r].element = a;
  	q[r].priority = b;
  }
}

void Dequeue()
{
  if(f==-1||f>r)
    printf("Queue Underflow\n");
  else 
  {
  int i,j;
  for(i=f;i<=r;i++)
		for(j=i;j<=r-i-1;j++)
			if(q[j].priority < q[j+1].priority){
				q[20] = q[j];
				q[j] = q[j+1];
				q[j+1] = q[20];
			}
	printf("element %d is deleted from queue\n",q[f].element);
  f++;
  }
}

void Display()
{
  int i;
  if(f==-1||f>r)
   printf("Queue Underflow\n");
  else 
  {
	  printf("Elements : ");
    for(i=f;i<=r;i++)
    {
      printf("%d ",q[i].element);
    }
    printf("\n");
	  printf("Priority : ");
    for(i=f;i<=r;i++)
    {
      printf("%d ",q[i].priority);
    }
    printf("\n");
  }
}    