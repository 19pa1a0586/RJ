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
        int n;
        printf("Enter the size of the array : ");
        scanf("%d",&n);
        int A[n];
        printf("Enter elements : ");
        for(int i = 0; i < n; i++){
    	     scanf("%d",&A[i]);
	}
	QuickSort(A,0,n);
	Display(A,n);
	
	return 0;
}
