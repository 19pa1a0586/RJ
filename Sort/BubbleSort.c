#include<stdio.h>

//void bubbleSort(int arr[], int n)
//{
//    for(int i = 0; i < n; i++){
//          for(int j = i+1; j < n; j++){
//               if(arr[i] > arr[j]){
//                 int temp = arr[i];
//	             arr[i] = arr[j];
//	             arr[j] = temp;
//             }
//	}
//     }
//}


void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n; i++){
          for(int j = 0; j < n-i-1; j++){
               if(arr[j] > arr[j+1]){
                 int temp = arr[j];
	             arr[j] = arr[j+1];
	             arr[j+1] = temp;
             }
	}
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
    bubbleSort(arr,n);
    Display(arr,n);
    return 0;
}
