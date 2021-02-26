#include<stdio.h>

void selectionSort(int arr[], int n){
     for(int i = 0; i < n-1; i++){
           int ind = i;
           for(int j = i+1; j < n; j++){
                   if(arr[j] < arr[ind]){
                         ind = j;
                    }
           }
           int temp = arr[ind];
           arr[ind] = arr[i];
           arr[i] = temp;  
      }
} 

void Display(int arr[], int n){
    printf("After Sorting : ");
    for(int i = 0; i < n; i++){
          printf("%d ",arr[i]);
     }
     printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements : ");
    for(int i = 0; i < n; i++){
    	scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);
    Display(arr,n);
    return 0;
}