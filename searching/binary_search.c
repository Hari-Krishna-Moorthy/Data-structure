#include <stdio.h>

int binary_search(int *arr, int left, int right, int find ) {
    if (left>right) return -1;
    int mid = left + (right - left)/2;

    if(find == arr[mid]) 
        return mid;
    else if(find < arr[mid])
        return binary_search(arr, left, mid-1, find);
    return binary_search(arr, mid+1, right, find);
}

int main() {
    int arr[] = {100, 200, 300, 400, 500};
    printf("%d\n", binary_search(arr, 0, 4, 500));
}