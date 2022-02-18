#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node *link;
} *head=NULL;

void insertf();
void insertr();
void deletef();
void deleter();
void insertran();
void deleteran();
void display();
int search();

void main()

{
int x;
loop:
printf("\n\nSelect an operation :\n1. insert(front)\n2. insert(rear)\n3. delete(front)\n4. delete(rear)\n5. insert(specified position)\n6. delete(specified position)\n7. display\n8. search\n");
scanf("%d",&x);
switch (x)
{
case 1: insertf();
goto loop;
case 2: insertr();
goto loop;
case 3: deletef();
goto loop;
case 4: deleter();
goto loop;
case 5: insertran();
goto loop;
case 6: deleteran();
goto loop;
case 7: display();
goto loop;
case 8: x=search();
goto loop;
default : printf("Wrong selection, try again\n");
goto loop;
}
}

//Functions

void insertf()
{
  struct node *newNode;
  newNode = malloc(sizeof(struct node));
  printf("Enter the element to be inserted\n");
  scanf("%d",&newNode->data);
  newNode->link = head;
  head = newNode;
}

void insertr()
{
struct node *newNode,*temp = head;
newNode = malloc(sizeof(struct node));
printf("Enter the element to be inserted\n");
scanf("%d",&newNode->data);
if(head==NULL)
{
newNode->link = head;
head = newNode;
}
else
{
while(temp->link != NULL)
temp = temp->link;
temp->link = newNode;
newNode->link = NULL;
}
}

void deletef()
{
struct node *temp;
if(head == NULL)
{
printf("list is empty\n");
}
else
{
printf("Element %d has been deleted\n",head->data);
head = head->link;
}
}

void deleter()
{
struct node *temp = head,*prev;
if(head == NULL)
{
printf("list is empty\n");
}
else
{
while(temp->link != NULL)
{
prev = temp;
temp = temp->link;
}
if(temp->link == NULL)
{
printf("Element %d has been deleted\n",head->data);
head=head->link;
}
else
{
printf("Element %d has been deleted\n",temp->data);
prev->link = temp->link;
}
}
}

void insertran()
{
struct node *newNode,*prev,*temp = head;
newNode = malloc(sizeof(struct node));
printf("Enter the element to be inserted\n");
scanf("%d",&newNode->data);
int a,i;
printf("Enter the position\n");
scanf("%d",&a);
for(i=0;i<a-1;i++)
{
prev = temp;
temp = temp->link;
}
prev->link = newNode;
newNode->link = temp;
printf("Element %d has been inserted at position %d.\n",newNode->data,a);
}

void deleteran()
{
struct node *next,*prev,*temp = head;
int a,i;
printf("Enter the position\n");
scanf("%d",&a);
for(i=0;i<a-1;i++)
{
prev = temp;
temp = temp->link;
}
prev->link = temp->link;
printf("Element %d has been deleted from position %d.\n",temp->data,a);
free(temp);
}

void display()
{
struct node *temp = head;
if(head == NULL)
{
printf("list is empty\n");
}
else
{
printf("\n\nList elements are : \n");
while(temp != NULL)
{
printf("%d ",temp->data);
temp = temp->link;
}
}
}

int search()
{
struct node *temp = head;
int a,i;
printf("Enter the item to be searched\n");
scanf("%d",&a);
for (i=0;temp != NULL;i++)
{
if(temp->data == a)
{
printf("Element %d has been found at position %d.\n",temp->data,i+1);
return 1;
}
temp = temp->link;
}
printf("Element not found.\n");
return 0;
}