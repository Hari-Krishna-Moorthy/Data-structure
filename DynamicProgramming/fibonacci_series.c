#include <stdio.h>

/* 	So, The idea of Dynamic programming is dividing the complex programe into 
serveral 

*/

static long long int count = 0 ; 

long long int fib(int n){
	count++;

	if(n<=0) return 0;
	else if(n==1) return 1;
	else return fib(n-1) + fib(n-2);	
}


int fib_dp(long long int *arr, int n, int term){
	count++;
	if(term==n) return arr[n-1]+arr[term-2];
	else arr[term] = arr[term-1] + arr[term-2];
	fib_dp(arr, n, term+1);
}

int main() {
	printf("Normal Recusion method : \n");
	int term = 43;
	printf("%d th element in Fibonacci is %lld", term, fib(term));
	printf("\nNumber of times funtion executed is %lld\n\n" , count);

	count = 0;
	long long int arr[term+1] ;
	arr[0] = 0, arr[1] = 1;

	printf("Dynamic Programming method : \n");
	printf("%d th element in Fibonacci is %d", term, fib_dp(arr, term, 2));
	printf("\nNumber of times funtion executed is %lld\n\n" , count);
	return 0;
}