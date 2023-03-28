#include <stdio.h>

int main(void){
	// taking required inputs from the user.
	int n, s;
	printf("Enter N and S: ");
	scanf("%d %d", &n,&s);
	printf("Enter the array elements separated by spaces: ");
	int arr[n];
	for(int i=0; i<n; i++){
		int x;
		scanf("%d", &x);
		arr[i] = x;
	}

	// algorithm to find the first and last position of the subarray that adds up to s.
	int c=0; // used to print comma at appropriate places.
	for(int j=0; j<n; j++){
		int sum = 0;
		int k=j;
		while(sum<s){
			sum+=arr[k];
			k++;
		}
		if(sum==s){
			if(c>0) printf(", ");
			printf("%d %d", j+1,k);
			c++;
		}
	}
	printf("\n");

	return 0;
}