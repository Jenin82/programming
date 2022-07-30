#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void create();
void display();
int search();
void deleteran();
char a[100],c[100],d[100];
int y=1;
struct node {
char data[100];
struct node *link;
} *head=NULL,*head1=NULL,*head2=NULL;

int main(){
  int x;
  printf("Enter the name of root directory :");
  scanf("%s",a);
  printf("Enter the name of first sub directory :");
  scanf("%s",c);
  printf("Enter the name of second sub directory :");
  scanf("%s",d);
  printf("Availiable operations are :\n1. Create file\n2. Display\n3. Search\n4. Delete file\n5. Switch to first directory\n6. Switch to second directory\n7. Exit");
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
    case 5: head = head1; y=1;
    goto loop;
    case 6: head = head2; y=2;
    goto loop;
    case 7: return 0;
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
    if(y==1)
			head1 = newNode;
		if(y==2)
			head2 = newNode;
  }
  else {
    while(temp->link != NULL)
      temp = temp->link;
    temp->link = newNode;
    newNode->link = NULL;
  }
}

void display() {
  struct node *temp1 = head1,*temp2 = head2;
  printf("\n\nRoot Directory name : %s\n",a);
  printf("\nFirst sub Directory name : %s\n",c);
  if(head1 == NULL) 
  printf("\n\nEmpty directory \n");
  else {
    printf("Files are : \n");
    while(temp1 != NULL) {
      printf("%s ",temp1->data);
      temp1 = temp1->link;
    }
  }
	printf("\nSecond sub Directory name : %s\n",d);
  if(head2 == NULL) 
  printf("\n\nEmpty directory \n");
  else {
    printf("Files are : \n");
    while(temp2 != NULL) {
      printf("%s ",temp2->data);
      temp2 = temp2->link;
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
				if(temp->link==NULL) {
					if(y==1)
						head1=NULL;
					if(y==2)
						head2=NULL;
				}
				else { 
					if(y==1)
					head1=head->link;
					if(y==2)
					head2=head->link;
				}
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