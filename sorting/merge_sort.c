#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int len1 = mid - left + 1;
    int len2 = right - mid;
    int i = 0, j = 0, k = left;

    int LeftArray[len1], RightArray[len2];
    for (int ind = 0; ind < len1; ind++) LeftArray[ind] = arr[left + ind];
    for (int ind = 0; ind < len2; ind++) RightArray[ind] = arr[mid + 1 + ind];

    while (i < len1 && j < len2) arr[k++] = (LeftArray[i] <= RightArray[j]) ? LeftArray[i++] : RightArray[j++];
    while (i < len1) arr[k++] = LeftArray[i++];
    while (j < len2) arr[k++] = RightArray[j++];
}

void mergesort(int arr[],int left,int right){
    if(left>=right) return;
    int mid =left+ (right-left)/2;
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main() {
    int arr[] = {25, 36, 98, 23, 43, 92, 12};
    int n = 7;

    printf("Before Sorting : \n");
    for(int ind=0;ind<7;ind++) {
        printf("%d ", arr[ind]);
    }   printf("\n");
    mergesort(arr, 0, n-1);
    printf("After Sorting : \n");
    for(int ind=0;ind<7;ind++) {
        printf("%d ", arr[ind]);
    }
    return 0;
}