#include<stdio.h>

void Enqueue();
void Dequeue();
void Enqueuef();
void Dequeuer();
void Display();

int n,f=-1,r=-1,q[20];

int main() {
  int x;
  printf("Enter the limit limit of queue\n");
  scanf("%d",&n);
  loop:
  printf("\nSelect a queue operation :\n1. Enqueue\n2. Dequeue\n3. Enqueue(front)\n4. Dequeue(rear)\n5. Display\n6. Exit\n\n");
  scanf("%d",&x);
  switch (x) {
    case 1: Enqueue();
      goto loop;
    case 2: Dequeue();
      goto loop;
    case 3: Enqueuef();
      goto loop;
    case 4: Dequeuer();
      goto loop;
    case 5: Display();
        goto loop;
    case 6: return 0;
        goto loop;
    default: printf("Wrong selection, try again\n");
        goto loop;
  }
}

//Functions

void Enqueue() {
  int a;
  if(r==n-1||r+1==f)
    printf("Queue overflow\n");
  else if(r==-1) {
    r=f=0;
    printf("Enter the element to be inserted\n");
    scanf("%d",&a);
    q[r]=a;
  }
  else {
    r=r+1;
    printf("Enter the element to be inserted\n");
    scanf("%d",&a);
    q[r]=a;
  }
}

void Dequeue() {
  if(f==-1)
    printf("Queue underflow\n");
  else if(f==r) {
    printf("Element %d has been deleted\n",q[f]);
    f=r=-1;
    }
  else if(f==n-1) {
    printf("Element %d has been deleted\n",q[f]);
    f=0;
  }
  else {
    printf("Element %d has been deleted\n",q[f]);
    f++;
  }
}

void Enqueuef() {
  int a;
  if(f-1==r||(f==0&&r==n-1))
    printf("Queue overflow\n");
  else if(f==0) {
    f=n-1;
    printf("Enter the element to be inserted\n");
    scanf("%d",&a);
    q[f]=a;
  }
  else if(f==-1) {
    f=r=0;
    printf("Enter the element to be inserted\n");
    scanf("%d",&a);
    q[f]=a;
  }
  else {
    f--;
    printf("Enter the element to be inserted\n");
    scanf("%d",&a);
    q[f]=a;
  }
}

void Dequeuer() {
  if(f==-1)
    printf("Queue underflow\n");
  else if(f==r) {
    printf("Element %d has been deleted\n",q[r]);
    f=r=-1;
  }
  else if(f>r&&r==0) {
    printf("Element %d has been deleted\n",q[r]);
    r=n-1;
  }
  else {
    printf("Element %d has been deleted\n",q[r]);
    r--;
  }
}

void Display() {
  int i;
  printf("Queue is :\n");
  if(f>r) {
    for(i=f;i<n;i++)
      printf("%d ",q[i]);
    for(i=0;i<=r;i++)
      printf("%d ",q[i]);
  printf("\n");
  }
  else {
    for(i=f;i<=r;i++)
      printf("%d ",q[i]);
  printf("\n");
  }
}
