#include <stdio.h>

void InsertionSort(int A[], int n)
{
	int i,j,x;
	for(i = 1; i < n; i++)
	{
		x = A[i];
		j = i-1;
		while(j >= 0 && A[j] > x)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = x;
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
	
	InsertionSort(A,n);
	
	Display(A,n);
	
	return 0;
}
