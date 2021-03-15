#include<stdio.h>

int main()
{
	int n, i, key;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	
	int arr[n];
	
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Enter the element you want to search : ");
	scanf("%d",&key);
	
	for(i = 0 ; i < n; i++)
	{
		if(arr[i] == key)
		{
			printf("%d element is found at location %d",key,i+1);
			break;
		}
	}
	
	if(i == n)
	{
		printf("%d element not found",key);
	}
}
