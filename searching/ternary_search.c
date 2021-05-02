#include <stdio.h>
#include <stdlib.h>

int ternary_search(int *arr, int left, int right, int find ) {
    if (left>right) return -1;

    int mid1 = left + (right - left)/3;
    int mid2 = right - (right - left)/3;

    printf("%d %d\n" , mid1, mid2);
    if(find == arr[mid1]) 
        return mid1;
    else if (find == arr[mid2])
        return mid2;
    
    if(find < arr[mid1]) 
        return ternary_search(arr, left, mid1-1, find);
    else if(find>arr[mid2])
        return ternary_search(arr, mid2+1, right, find);
    return ternary_search(arr, mid1+1, mid2-1, find);
}

int main() {
    int arr[] = {100, 200, 300, 400, 500};
    printf("%d\n", ternary_search(arr, 0, 4, 400));
}