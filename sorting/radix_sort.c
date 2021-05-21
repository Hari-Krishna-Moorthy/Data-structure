#include <stdio.h>

int getMax(int *arr, int n) {
	int max = 0;
	for(int ind=0;ind<n;ind++){
		if(arr[ind] > max) max = arr[ind];
	}
	return max;
}

void count_sort(int *arr, int n, int exp) {
	int output[n]; 
	int count[10] = {0};

	for(int ind=0;ind<n;ind++)
		count[(arr[ind]/exp)%10]++;

	// for(int ind=0;ind<10;ind++)
	// 	printf("%d " , count[ind]);
	// printf("\n");

	for(int ind=1; ind<10;ind++)
		count[ind] += count[ind-1];

	for(int ind=n-1; ind>=0; ind--) {
		output[count[(arr[ind]/exp)%10]-1] = arr[ind];
		count[(arr[ind]/exp)%10]--;
	}

	// for(int ind=0;ind<n;ind++)
	// 	printf("%d " , output[ind]);
	// printf("\n");

	for(int ind=0;ind<n;ind++) 
		arr[ind] = output[ind];
}

int radix_sort(int *arr, int n) {
	int max_num = getMax(arr, n);

	for(int exp=1;max_num/exp > 0 ; exp*=10) {
		count_sort(arr, n, exp);
	}
}


int main() {
	int arr[] = {12, 898, 323, 544, 100, 34, 23, 99};
	int n  = 8;

	printf("Before Sorting : \n");
	for(int ind=0;ind<n;ind++)
		printf("%d " , arr[ind]);
	printf("\n");

	radix_sort(arr, n);


	printf("Before Sorting : \n");
	for(int ind=0;ind<n;ind++)
		printf("%d " , arr[ind]);
	printf("\n");


	return 0;
}