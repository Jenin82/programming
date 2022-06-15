#include <stdio.h>

int s[20],n,top=-1;
int main()
{
  printf("Enter the limit of stack:\n");
  scanf("%d",&n);
  loop: 
  printf("Select a stack operation:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
  int x;
  scanf("%d",&x);
  switch(x)
  {
    case 1: Push(n);
      goto loop;
    case 2: Pop();
      goto loop;
    case 3: Display();
      goto loop;
    case 4: return 0;
    default: printf("Wrong selection, try again");
      goto loop;
  }
}

//Functions

void Push(int a)
{
  if(top==a-1) 
    printf("%d Stack Overflow\n",a);
  else 
  {
    int b;
    printf("Enter the element to be pushed\n");
    scanf("%d",&b);
    top++;
    s[top]=b;
  }
}

void Pop()
{
  if(top>=0) 
  {
    printf("%d is popped from the stack\n",s[top]);
    top--;
  }
  else 
    printf("Stack Underflow\n");
}

void Display()
{
  if(top>=0)
  {
    int i;
    for(i=top;i>=0;i--)
      printf("%d\n",s[i]);
  }
}