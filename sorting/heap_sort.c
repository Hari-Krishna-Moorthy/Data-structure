#include <stdio.h>

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void heapify(int arr[], int n, int index) {
	int largest = index;        // root
	int left = 2 * index + 1;      // left child
	int right = 2 * index + 2;      // right child

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != index) {
		swap(&arr[index], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	for (int ind = n / 2 - 1; ind >= 0; ind--) heapify(arr, n, ind);
	for (int ind= n - 1;ind > 0;ind--) {
		swap(&arr[0], &arr[ind]);
		heapify(arr, ind, 0);
	}
}

int main() {
    int arr[] = {25, 36, 98, 23, 43, 92, 12};
    printf("Before Sorting : \n");

    for(int ind=0;ind<7;ind++) {
        printf("%d ", arr[ind]);
    }   printf("\n");

    heapSort(arr, 7);

    printf("After Sorting : \n");
    for(int ind=0;ind<7;ind++) {
        printf("%d ", arr[ind]);
    }
    return 0;
}