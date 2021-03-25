#include<stdio.h>

int main()
{
	int n,i,key,low,mid,high;
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	
	int arr[n];
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Enter the Key that you want to search : ");
	scanf("%d",&key);
	
	low = 0; 
	high = n-1;
	mid = (low+high)/2;
	while(low <= high)
	{
		if(arr[mid] == key)
		{
			printf("%d element is found at location %d",key,mid+1);
			break;
		}
		else if(arr[mid] < key)
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
		mid = (low+high)/2;
	}
	if(low > high)
	{
		printf("%d element not found",key);
	}
}
