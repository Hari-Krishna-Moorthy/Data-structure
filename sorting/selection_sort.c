#include <stdio.h>

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void selectionsort(int *arr, int n){
    int min_ind = 0;
    for(int row=0;row<n-1;row++) {
        min_ind = row;
        for(int col=row+1;col<n;col++) {
            if(arr[min_ind] > arr[col])
                min_ind = col;
        }
        swap(&arr[row], &arr[min_ind]);
    }
}

int main() {
    int arr[] = {25, 36, 98, 23, 43, 92, 12};
    printf("Before Sorting : \n");
    for(int ind=0;ind<7;ind++) {
        printf("%d ", arr[ind]);
    }   printf("\n");
    selectionsort(arr, 7);
    printf("After Sorting : \n");
    for(int ind=0;ind<7;ind++) {
        printf("%d ", arr[ind]);
    }
    return 0;
}