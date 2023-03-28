#include <stdio.h>

int reverse(int arr[], int i, int n){
	if(i<(n+1)/2) {
		int a = arr[i];
		arr[i] = arr[n-i];
		arr[n-i] = a;
		i++;
		reverse(arr,i,n);
	}

}

int main(){
	int n;
	printf("Enter the size of the integer array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the array separated by spaces: ");
	for(int i=0; i<n; i++){
		int x;
		scanf(" %d", &x);
		arr[i] = x;
	}
	reverse(arr, 0, n-1);
	printf("The reversed array is ");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}