#include <stdio.h>

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(int A[], int low, int high)
{
	int pivot = A[low];
	int i = low;
	int j = high-1;
	while(i < j)
	{
		while(A[i] <= pivot){
			i++;
		}
		while(A[j] > pivot)
		{
			j--;
		}
		if(i < j)
		{
			Swap(&A[i],&A[j]);
		}
	}
//	do
//	{
//		do{i++;}while(A[i]<=pivot);
//		do{j--;}while(A[j]>pivot);
//		
//		if(i<j)Swap(&A[i],&A[j]);
//	}while(i < j);
	
	Swap(&A[low],&A[j]);
	return j;
}

void QuickSort(int A[], int low, int high)
{
	int j;
	if(low < high)
	{
		j = Partition(A,low,high);
		QuickSort(A,low,j);
		QuickSort(A,j+1,high);
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
	int A[] = {9,5,2,4,8,5,3,2,9,4};
	QuickSort(A,0,10);
	Display(A,10);
	
	return 0;
}
