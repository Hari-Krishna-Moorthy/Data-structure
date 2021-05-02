#include <stdio.h>

void swap(int *num1, int *num2) {
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}

void bubblesort(int *arr, int n){
    for(int row=0;row<n-1;row++) {
        for(int col=row+1;col<n;col++) {
            if(arr[row] > arr[col]) {
                swap(&arr[row], &arr[col]);
            }
        }
    }
}

int main() {
    int arr[] = {25, 36, 98, 23, 43, 92, 12};
    printf("Before Sorting : \n");
    for(int ind=0;ind<7;ind++) {
        printf("%d ", arr[ind]);
    }   printf("\n");
    bubblesort(arr, 7);
    printf("After Sorting : \n");
    for(int ind=0;ind<7;ind++) {
        printf("%d ", arr[ind]);
    }
    return 0;
}