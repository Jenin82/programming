#include <stdio.h>

struct polynomial {
  int coeff;
  int expo;
};
struct polynomial p1[10],p2[10],p3[20];


void main()
{
  int a,b,c;
  printf("FIRST POLYNOMIAL\n");
  a = readpoly(p1);
  printf("First polynomial is :\n");
  printpoly(p1,a);
  printf("\n\nSECOND POLYNOMIAL\n");
  b = readpoly(p2);
  printf("Second polynomial is :\n");
  printpoly(p2,b);
  printf("\n\nRESULTANT POLYNOMIAL\n");
  c = addpoly(p1,p2,a,b,p3);
  printf("Sum = ");
  printpoly(p3,c);
}

//Functions

int readpoly(struct polynomial p[10])
{
  int t,i,k=0;
  printf("Enter the highest exponent of polynomial\n");
  scanf("%d",&t);
  for(i=t;i>=0;i--)
  {
    printf("Enter the coefficient of X^%d\n",i);
    scanf("%d",&p[i].coeff);
    p[i].expo = i;
  }
  return t;
}


void printpoly(struct polynomial p[10],int t)
{
  int i;
  for(i=t;i>0;i--)
  {
    printf("%d(X^%d)+",p[i].coeff,p[i].expo);
  }
  printf("%d(X^%d)\n",p[0].coeff,p[0].expo);
}


int addpoly(struct polynomial x[10],struct polynomial p2[10],int a,int b,struct polynomial p3[20])
{
  int i=a,j=b,k,n;
  if(a>b)
  {k=a;}
  else 
  {k=b;}
  n=k;
  while(i>=0 && j>=0)
  {
    if(x[i].expo == p2[j].expo)
    {
      p3[k].coeff = x[i].coeff + p2[i].coeff;
      p3[k].expo = x[i].expo;
      i--;
      j--;
      k--;
    }
    else if(x[i].expo > p2[j].expo)
    {
      p3[k].coeff = x[i].coeff;
      p3[k].expo = x[i].expo;
      i--;
      k--;
    }
    else if(x[i].expo < p2[j].expo)
    {
      p3[k].coeff = p2[j].coeff;
      p3[k].expo = p2[j].expo;
      j--;
      k--;
    }
  }
  while(i>=0)
  {
    p3[k].coeff = x[i].coeff;
    p3[k].expo = x[i].expo;
    i--;
    k--;
  }
  while(j>=0)
  {
    p3[k].coeff = p2[j].coeff;
    p3[k].expo = p2[j].expo;
    j--;
    k--;
  }
  return n;
}