#include <stdio.h>

int main() {
	int n, i, a[10], temp=0, item;
	printf("Enter the limit\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	printf("Enter the item to be searched\n");
	scanf("%d",&item);
	for(i=0; i<n; i++) {
		if(a[i]==item){
			printf("Element %d found at psition %d\n",a[i], i+1);
			return 0;
		}
	}
	printf("Element not found\n");
	return 0;
}