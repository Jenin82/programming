#include<stdio.h>

int main()
{
	int i,n,a[20],item;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for ( i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched\n");
	scanf("%d",&item);
	for ( i = 0; i < n; i++)
	{
		if (a[i] == item)
		{
			printf("Element %d is found at position %d\n",a[i],i+1);
			return 0;
		}
	}
	printf("Element not found in the array\n");
}