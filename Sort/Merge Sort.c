#include <stdio.h>

void Merge(int A[], int low, int mid, int high)
{
	int i = low;
	int j = mid+1;
	int k = low;
	int B[high];
	
	while(i <= mid && j <= high)
	{
		if(A[i] < A[j])
		{
			B[k++] = A[i++];
		}
		else
		{
			B[k++] = A[j++];
		}
	}
	
	while(i <= mid)
	{
		B[k++] = A[i++];
	}
	
	while(j <= high)
	{
		B[k++] = A[j++];
	}
	
	for(int i = low; i <= high; i++)
	{
		A[i] = B[i];
	}
}

void MergeSort(int A[], int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (low+high)/2;
		MergeSort(A,low,mid);
		MergeSort(A,mid+1,high);
		Merge(A,low,mid,high);
	}
}

void Display(int A[],int n)
{
	printf("Sorted Elements are : ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}

int main()
{
	int n;
        printf("Enter the size of the array : ");
        scanf("%d",&n);
        int A[n];
        printf("Enter elements : ");
        for(int i = 0; i < n; i++){
        	scanf("%d",&A[i]);
	}
	
	MergeSort(A,0,n);
	
	Display(A,n);
	
	return 0;
}
