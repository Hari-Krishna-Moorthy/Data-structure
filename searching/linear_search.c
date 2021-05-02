#include <stdio.h>

int linear_search(int *arr, int index, int size, int find ) {
    if(index==size) return -1;
    else if(arr[index] == find) return index;
    return linear_search(arr, index+1, size, find);
}

int main() {
    int arr[] = {100, 200, 300, 400, 500};
    int size = sizeof(arr) / sizeof(int);
    printf("%d\n", linear_search(arr, 0, size, 1100));
}