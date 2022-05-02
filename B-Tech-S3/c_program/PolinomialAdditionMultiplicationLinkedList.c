#include<stdio.h>
#include<stdlib.h>

struct node
{
  int coeff,expo;
  struct node *link;
} *head1, *head2, *head3, *head4;

struct node * readpoly();
void display(struct node *head);
struct node * addpoly();
struct node * multiply();

void main(){
  printf("First polynomial :\n");
  head1 = readpoly();
  display(head1);
  printf("\nSecond polynomial :\n");
  head2 = readpoly();
  display(head2);
  printf("\n\nSum of polynomials is :\n");
  head3 = addpoly();
  display(head3);
  printf("\n\nMultiplication of polynomials is :\n");
  head4 = multiply();
  display(head4);
}

//Functions

struct node * readpoly(){
  int n,i;
  printf("Enter the highest exponent of the polynomial\n");
  scanf("%d",&n);
  struct node *new, *ptr, *head = NULL;
  for (i=n;i>=0;i--)
  {
    new = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the coefficient of X^%d :",i);
    scanf("%d",&new->coeff);
    new->expo = i;
    new->link = NULL;
    if(head == NULL){
      head = new;
      ptr = head;
      //For first node
    }
    else{
      ptr->link = new;
      ptr = new;
      //For remaining nodes
    }
  }
  return(head);
}

void display(struct node *head){
  struct node *ptr = head;
  if(ptr == NULL)
    printf("Polynomial is empty\n");
  else {
    while(ptr->link != NULL){
      printf("%d(X^%d)+",ptr->coeff,ptr->expo);
      ptr = ptr->link;
    }
    printf("%d(X^%d)",ptr->coeff,ptr->expo);
  }
}

struct node * addpoly(){
  struct node *new, *p, *q, *r, *head = NULL;
  p = head1;
  q = head2;
  while(p != NULL && q != NULL){
    if(p->expo == q->expo){
      new = (struct node *)malloc(sizeof(struct node *));
      new->coeff = p->coeff+q->coeff;
      new->expo = p->expo;
      p = p->link;
      q = q->link;
    }
    else if(p->expo > q->expo){
      new = (struct node *)malloc(sizeof(struct node *));
      new->coeff = p->coeff;
      new->expo = p->expo;
      p = p->link;
    }
    else{
      new = (struct node *)malloc(sizeof(struct node *));
      new->coeff = q->coeff;
      new->expo = q->expo;
      q = q->link;
    }
    if(head == NULL){
      head = new;
      new->link = NULL;
      r=head;
    }
    else{
      r->link = new;
      new->link = NULL;
      r = new;
    }
  }
  while(p != NULL){
    new = (struct node *)malloc(sizeof(struct node *));
    new->coeff = p->coeff;
    new->expo = p->expo;
    p = p->link;
    new->link = NULL;
    if(head == NULL){
      head = new;
      r=head;
    }
    else{
      r->link = new;
      r = new;
    }
  }
  while(q != NULL){
    new = (struct node *)malloc(sizeof(struct node *));
    new->coeff = q->coeff;
    new->expo = q->expo;
    q = q->link;
    new->link = NULL;
    if(head == NULL){
      head = new;
      r=head;
    }
    else{
      r->link = new;
      r = new;
    }
  }
  return(head);
}

struct node * multiply(){
  struct node *new, *p, *q, *r, *head = NULL, *prev;
  p = head1;
  q = head2;
  while(p != NULL){
    while(q != NULL){
      new = (struct node *)malloc(sizeof(struct node *));
      new->coeff = p->coeff * q->coeff;
      new->expo = p->expo + q->expo;
      new->link = NULL;
      if(head == NULL){
        head = new;
        r = head;
      }
      else {
        r->link = new;
        r = new;
      }
      q = q->link;
    }
    p = p->link;
    q = head2;
  }
  p = head;
  while(p != NULL){
    prev = p;
    q = p->link;
    while(q != NULL){
      if(q->expo == p->expo){
        p->coeff = p->coeff + q->coeff;
        prev->link = q->link;
        free(q);
        q = prev->link;
      }
      else{
        prev = q;
        q = q->link;
      }
    }
    p = p->link;
  }
  return(head);
}