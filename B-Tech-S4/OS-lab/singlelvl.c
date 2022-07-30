#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void create();
void display();
int search();
void deleteran();
char a[100];
struct node {
char data[100];
struct node *link;
} *head=NULL;

int main(){
  int x;
  printf("Enter the name of directory :");
  scanf("%s",a);
  printf("Availiable operations are :\n1. Create file\n2. Display\n3. Search\n4. Delete file\n5. Exit");
  loop:
  printf("\n\nSelect an operation :");
  scanf("%d",&x);
  switch(x) {
    case 1: create();
    goto loop;
    case 2: display();
    goto loop;
    case 3: x=search();
    goto loop;
    case 4: deleteran();
    goto loop;
    case 5: return 0;
    default : printf("Wrong selection, try again\n");
    goto loop;
  }
}

void create() {
  struct node *newNode,*temp = head;
  newNode = malloc(sizeof(struct node));
  printf("Enter the name of file\n");
  scanf("%s",newNode->data);
  if(head==NULL) {
    newNode->link = head;
    head = newNode;
  }
  else {
    while(temp->link != NULL)
      temp = temp->link;
    temp->link = newNode;
    newNode->link = NULL;
  }
}

void display() {
  struct node *temp = head;
  printf("\n\nDirectory name : %s\n",a);
  if(head == NULL) 
  printf("\n\nEmpty directory \n");
  else {
    printf("Files are : \n");
    while(temp != NULL) {
      printf("%s ",temp->data);
      temp = temp->link;
    }
  }
}

int search() {
  struct node *temp = head;
  int i;
  char b[100];
  printf("Enter the file to be searched\n");
  scanf("%s",b);
  for (i=0;temp != NULL;i++) {
    int t = strcmp(temp->data,b);
    if(t == 0) {
      printf("File %s has been found at position %d.\n",temp->data,i+1);
      return 1;
    }
    temp = temp->link;
  }
  printf("File not found.\n");
  return 0;
}

void deleteran() {
  struct node *next,*prev = NULL,*temp = head;
  int j;
  char k[100];
  printf("Enter the file to be deleted : \n");
  scanf("%s",k);
	while(temp!=NULL) {
		int t = strcmp(temp->data,k);
		if(t == 0) {
			if(temp==head){
				printf("File %s has been deleted\n",temp->data);
				if(temp->link==NULL)
					head=NULL;
				else 
					head=head->link;
				return NULL;
			}
			else {
				printf("File %s has been deleted\n",temp->data);
				prev->link=temp->link;
				free(temp);
				return NULL;
			}
		}
		prev=temp;
		temp=temp->link;
	}
}