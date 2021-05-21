#include <math.h>
#include <stdio.h>

void insertionSort(int *arr, int n) {
    int key;
    for (int ind = 1;ind < n;ind++) {
        key = arr[ind];
        int j = ind - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

 
int main() {
    int arr[] = {25, 36, 98, 23, 43, 92, 12};

    printf("Before Sorting : \n");

    for(int ind=0;ind<7;ind++) {
        printf("%d ", arr[ind]);
    }   printf("\n");

    insertionSort(arr, 7);

    printf("After Sorting : \n");
    for(int ind=0;ind<7;ind++) {
        printf("%d ", arr[ind]);
    }
    return 0;
}