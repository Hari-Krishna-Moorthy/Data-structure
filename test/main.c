#include <stdio.h>

// int linear_search(int *arr, int n,int find){
// 	for(int ind=0;ind<n;ind++) {
// 		if(arr[ind]==find) return ind;
// 	}
// 	return -1;
// }

// int binary_search(int *arr, int low, int high, int find){
// 	if(low>high) return -1;

// 	int mid = low + (high-low)/2;
// 	if(arr[mid]==find) return mid;
// 	else if(arr[mid]<find) return binary_search(arr, mid+1, high, find);
// 	return binary_search(arr, low, mid-1, find);

// }
// int trinary_search(int *arr, int low, int high, int find){
// 	if(low>high) return -1;

// 	int mid1 = low + (high-low)/3;
// 	int mid2 = high - (high-low)/3;

// 	if(arr[mid1]==find)	return mid1;
// 	else if(arr[mid2]==find) return mid2;

// 	if(arr[mid1]>find) return trinary_search(arr, low, mid1-1, find);
// 	else if (arr[mid2]<find) return trinary_search(arr, low, mid2+1, find);
// 	return trinary_search(arr, mid1+1, mid2-1, find);
// }

void swap(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

// void bouble_sort(int *arr, int n) {
// 	for(int row=0; row<n-1;row++) {
// 		for (int col=row+1;col< n; col++){
// 			if(arr[row]>arr[col]) swap(&arr[row], &arr[col]);
// 		}
// 	}
// }

// void selection_sort(int *arr, int n) {
// 	for(int row=0;row<n-1;row++) {
// 		int min_ind = row;
// 		for(int col=row+1;col<n;col++) {
// 			if(arr[col]<arr[min_ind]) min_ind = col;
// 		}
// 		if(row!=min_ind)
// 			swap(&arr[row], &arr[min_ind]);
// 	}
// }

void merge_util(int *arr, int left, int right, int mid){
	int len1 = mid - left+1, len2 = right-mid;
	int i =0,  j = 0;
	int k = left;
	int LeftArray[len1], RightArray[len2];

	for(int ind=0;ind<len1;ind++)
		LeftArray[ind] = arr[left+ind];
	for(int ind=0;ind<len2;ind++)
		RightArray[ind] = arr[mid+1+ind];

	while(i<len1 && j<len2) arr[k++] = (LeftArray[i] < RightArray[j]) ? LeftArray[i++] : RightArray[j++];
	while(i<len1) arr[k++] = LeftArray[i++];
	while(j<len2) arr[k++] = RightArray[j++];


}

void merge_sort(int *arr, int low, int high) {
	if(low>=high) return ;
	int mid = low + (high-low)/2;
	merge_sort(arr, low, mid);
	merge_sort(arr, mid+1, high);
	merge_util(arr, low, high, mid);

}


int main() {

	// int arr[] = {12, 34, 54, 76, 90};
	// int n = 5;
	// int find = 34;
	// printf("%d \n", linear_search(arr, n,  find));
	// printf("%d \n", binary_search(arr, 0, n-1, find));
	// printf("%d \n", trinary_search(arr, 0, n-1, find));
	
	int arr[] = {90, 73, 22, 98, 24, 12};
	int n = 6;

	printf("Before Sorting : \n");
	for(int ind=0;ind<n;ind++)
		printf("%d " , arr[ind]);
	printf("\n");

	// bouble_sort(arr, n);
	// selection_sort(arr, n);
	merge_sort(arr, 0, n-1);


	printf("Before Sorting : \n");
	for(int ind=0;ind<n;ind++)
		printf("%d " , arr[ind]);
	printf("\n");

	return 0;
}