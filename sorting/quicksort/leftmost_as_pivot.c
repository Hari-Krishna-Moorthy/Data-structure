#include <stdio.h>

int swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[low], i = low;

    for(int j=low;j<=high;j++){
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i] , &arr[low]);
    return i;
}

void quicksort(int *arr, int low, int high) {
    if(low>=high) return;

    int pi = partition(arr, low, high);
    quicksort(arr, low, pi-1);
    quicksort(arr, pi+1, high);
}

int main() {
    int arr[] = {25, 36, 98, 23, 43, 92, 12};
    int n = 7;

    printf("Before Sorting : \n");
    for(int ind=0;ind<7;ind++) {
        printf("%d ", arr[ind]);
    }   printf("\n");
    quicksort(arr, 0, n-1);
    printf("After Sorting : \n");
    for(int ind=0;ind<7;ind++) {
        printf("%d ", arr[ind]);
    }
    return 0;
}