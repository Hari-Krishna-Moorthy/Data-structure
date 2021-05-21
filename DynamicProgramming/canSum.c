#include <stdio.h>
#include <stdbool.h>

bool canSum(int targetSum, int *arr, int n) {
	if(targetSum<0) return false;
	if(targetSum == 0) return true;

	for(int ind=0;ind<n;ind++) {
		if(canSum(targetSum - arr[ind], arr, n) == 1)	return true;
	}
	return false;
}

bool canSum_dp(int targetSum, int *arr, int n, bool *memo){
	if(targetSum<0)		return false;
	if(targetSum==0)	return true;
	if(memo[targetSum]==true) return true;

	for(int ind=0;ind<n;ind++) {
		if(canSum_dp(targetSum - arr[ind], arr, n, memo) == 1) {
			memo[targetSum] = true;
			return true;
		}
	}
	return false;
}

void fillFalse(bool *arr, int n) {
	for(int ind=0;ind<n;ind++)	arr[ind] = false;
}


int main() {

	// int num1 = 7; int arr1[] = {2, 3};
	// int num2 = 7; int arr2[] = {5, 3, 4, 7};
	// int num3 = 7; int arr3[] = {2, 4};
	// int num4 = 8; int arr4[] = {2, 3, 5};
	int num5 = 300; int arr5[] = {7, 14};
	
	// bool memo1[num1+1];
	// bool memo2[num2+1];
	// bool memo3[num3+1];
	// bool memo4[num4+1];
	bool memo5[num5+1]; 

	// fillFalse(memo1, num1+1);
	// fillFalse(memo2, num2+1);
	// fillFalse(memo3, num3+1);
	// fillFalse(memo4, num4+1);
	fillFalse(memo5, num5+1);

	// printf("%s\n", canSum(num1, arr1, 2) ? "True" : "False");
	// printf("%s\n", canSum(num2, arr2, 4) ? "True" : "False");
	// printf("%s\n", canSum(num3, arr3, 2) ? "True" : "False");
	// printf("%s\n", canSum(num4, arr4, 3) ? "True" : "False");
	// printf("%s\n", canSum(num5, arr5, 2) ? "True" : "False");
	printf("\n");

	// printf("%s\n", canSum_dp(num1, arr1, 2, memo1) ? "True" : "False");
	// printf("%s\n", canSum_dp(num2, arr2, 4, memo2) ? "True" : "False");
	// printf("%s\n", canSum_dp(num3, arr3, 2, memo3) ? "True" : "False");
	// printf("%s\n", canSum_dp(num4, arr4, 3, memo4) ? "True" : "False");
	printf("%s\n", canSum_dp(num5, arr5, 2, memo5) ? "True" : "False");



	return 0;
}