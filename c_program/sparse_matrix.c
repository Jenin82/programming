#include <stdio.h>

struct sparse {
  int a[50][50];
};
struct sparse s1[50][50],s2[50][50],sum[50][50];

void main()
{
  
  printf("FIRST MATRIX\n");
  read(s1);
  print(s1);
  printf("\n\nSECOND MATRIX\n");
  read(s2);
  print(s2);
  printf("\n\nSUM OF SPARSE MATRIX\n");
  sparsesum(s1,s2,sum);
  print(sum);
  printf("\n\nTRANSPOSE OF SPARS MATRIX\n");
  transpose(sum);
}


//FUNCTIONS

int read(struct sparse s[50][50])
{
  int i,j,k=1,r,c,arr[50][50];
  printf("Enter the number of rows and columns\n");
  scanf("%d%d",&r,&c);
  printf("Enter the elements\n");
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      scanf("%d",&arr[i][j]);
    }
  }
  
  //Printing the matrix 
  printf("Matrix is :\n");
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      printf("%d  ",arr[i][j]);
    }
    printf("\n");
  }
  
  //Converting to sparse 
  s[0][0].a[0][0]=r;
  s[0][1].a[0][1]=c;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      if(arr[i][j]!=0)
      {
        s[k][0].a[k][0]=i;
        s[k][1].a[k][1]=j;
        s[k][2].a[k][2]=arr[i][j];
        k++;
      }
    }
  }
  s[0][2].a[0][2]=k-1;
}


void print(struct sparse s[50][50])
{
  printf("Sparse Matrix is :\n");
  for(int i=0;i<=s[0][2].a[0][2];i++)
  {
    printf("%d  %d  %d\n",s[i][0].a[i][0],s[i][1].a[i][1],s[i][2].a[i][2]);
  }
}


int sparsesum(struct sparse x[50][50],struct sparse y[50][50],struct sparse z[50][50])
{
  int i=0,j=0,k=0,row,col;
  if(x[0][0].a[0][0]==y[0][0].a[0][0] && x[0][1].a[0][1]==y[0][1].a[0][1])
  {
    z[0][0].a[0][0]=row=x[0][0].a[0][0];
    z[0][1].a[0][1]=col=y[0][1].a[0][1];
    while(i<=x[0][2].a[0][2] && j<=y[0][2].a[0][2])
    {
      if(x[i][0].a[i][0]==y[j][0].a[j][0])
      {
        if(x[i][1].a[i][1]==y[j][1].a[j][1])
        {
          z[k][0].a[k][0]=x[i][0].a[i][0];
          z[k][1].a[k][1]=y[j][1].a[j][1];
          z[k][2].a[k][2]=x[i][2].a[i][2]+y[j][2].a[j][2];
          i++;
          j++;
          k++;
         }
         else if(x[i][1].a[i][1]<y[j][1].a[j][1])
         {
           z[k][0].a[k][0]=x[i][0].a[i][0];
           z[k][1].a[k][1]=x[i][1].a[i][1];
           z[k][2].a[k][2]=x[i][2].a[i][2];
           i++;
           k++;
         }
         else 
         { 
           z[k][0].a[k][0]=y[j][0].a[j][0];
           z[k][1].a[k][1]=y[j][1].a[j][1];
           z[k][2].a[k][2]=y[j][2].a[j][2];
           j++;
           k++;
         }
      }
      else if(x[i][0].a[i][0]<y[j][0].a[j][0])
      {
        z[k][0].a[k][0]=x[i][0].a[i][0];
        z[k][1].a[k][1]=x[i][1].a[i][1];
        z[k][2].a[k][2]=x[i][2].a[i][2];
        i++;
        k++;
      }
      else 
      { 
        z[k][0].a[k][0]=y[j][0].a[j][0];
        z[k][1].a[k][1]=y[j][1].a[j][1];
        z[k][2].a[k][2]=y[j][2].a[j][2];
        j++;
        k++;
      }
    }
    while(i<=x[0][2].a[0][2])
    {
      z[k][0].a[k][0]=x[i][0].a[i][0];
      z[k][1].a[k][1]=x[i][1].a[i][1];
      z[k][2].a[k][2]=x[i][2].a[i][2];
      i++;
      k++;
    }
    while(j<=y[0][2].a[0][2])
    {
      z[k][0].a[k][0]=y[j][0].a[j][0];
      z[k][1].a[k][1]=y[j][1].a[j][1];
      z[k][2].a[k][2]=y[j][2].a[j][2];
      j++;
      k++;
    }
    z[0][2].a[0][2]=k-1;
  }
  else 
  printf("Addition not possible, matrix are of different size\n");
}


void transpose(struct sparse b1[50][50])
{
  //Transpose 
  int i,j,k,n,b2[50][50];
  b2[0][0]=b1[0][1].a[0][1];
  b2[0][1]=b1[0][0].a[0][0];
  b2[0][2]=b1[0][2].a[0][2];
  k=1;
  n=b1[0][2].a[0][2];
  for(i=0;i<b1[0][1].a[0][1];i++)
  for(j=1;j<=n;j++)
  if(i==b1[j][1].a[j][1])
  {
  b2[k][0]=i;
  b2[k][1]=b1[j][0].a[j][0];
  b2[k][2]=b1[j][2].a[j][2];
  k++;
  }
  printf("Sparse Matrix is :\n");
  for(i=0;i<=b2[0][2];i++)
  {
    printf("%d  %d  %d\n",b2[i][0],b2[i][1],b2[i][2]);
  }
}