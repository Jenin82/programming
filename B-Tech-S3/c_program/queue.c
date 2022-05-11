#include <stdio.h>

int q[20],n,f=-1,r=-1;

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
    int a;
    printf("Enter element to be inserted\n");
    scanf("%d",&a);
    r++;
    q[r]=a;
  }
}

void Dequeue()
{
  if(f==-1||f>r)
    printf("Queue Underflow\n");
  else 
  {
    printf("element %d is deleted from queue\n",q[f]);
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
    for(i=f;i<=r;i++)
    {
      printf("%d ",q[i]);
    }
    printf("\n");
  }
}    