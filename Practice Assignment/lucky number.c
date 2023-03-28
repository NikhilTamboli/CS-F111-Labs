#include <stdio.h>

int main(void){
	// int arr[19] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

	int n;
	printf("Enter the number of digits: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the digits separated by spaces: ");
	for(int i=0; i<n; i++){
		int x;
		scanf(" %d", &x);
		arr[i] = x;
	}

	int jump=2, count;
	count = n;
	int size = sizeof(arr)/sizeof(arr[0]);
	while(jump<size){
		int i=1;
		while(jump*i<size){
			int ind = jump*i;
			for(int k = ind-1; k<size-1; k++){
				arr[k] = arr[k+1];
			}
			i++;
		}
		count -= count/jump;
		jump++;
	}

	printf("The lucky numbers are: ");
	for(int j=0;j<count; j++){
		printf("%d ", arr[j]);
	}
	printf("\n");
	
	return 0;
}
