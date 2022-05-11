#include <stdio.h>

int main()
{
  int i,j,a[50],n,temp=0,s=0,item,mid;
  printf("Enter the size of array\n");
  scanf("%d",&n);
  printf("Enter the elements of array\n");
  for(i=0;i<n;i++)
    {scanf("%d",&a[i]);}
  for(i=0;i<n;i++)
    for(j=0;j<n-i-1;j++)
      if(a[j]>a[j+1])
      {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
  printf("Sorted array is\n");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\nEnter the item to be searched\n");
  scanf("%d",&item);
  while(s<=n)
  {
    mid=(s+n)/2;
    if(a[mid]==item)
      goto found;
    if(a[mid]<item)
      s=mid+1;
    if(a[mid]>item)
      n=mid-1;
  }
  printf("Element not found\n");
  return 0;
  found:
  printf("Element found at position %d\n",mid + 1);
}