#include <stdio.h>

void set(int sz, int n, int b[sz][n], int i){	
	if(i<=sz){
		int it = i;
		int j=n-1;
		for(j;it>0;j--){    
			b[i-1][j]=it%2;    
			it=it/2;    
		}
		for(int k=j; k>=0; k--){
			b[i-1][k]=0;
		}
		i++;
		set(sz, n, b, i);
	}
}

int main(void){
	// taking input from user.
	int n;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements of the array separated by spaces: ");
	for(int i=0; i<n; i++){
		int x;
		scanf(" %d", &x);
		arr[i] = x;
	}

	// get sets of binary array (length equal to total elements in given set)
	// corresponding to numbers ranging from 1 to (2^n)-1
	int sz = 1;
	for(int i=0; i<n; i++){
		sz*=2;
	}
	sz--;
	int b[sz][n];
	set(sz, n, b, 1);
	
	// in the sets of binary arrays computed in the above step,
	// each set is a subset in the power set and 
	// index of each '1' in a set corresponds to the index of the element 
	// in the main set that needs to be included in the subset.
	// printing all these subsets together will form the power set of the given array.
	printf("Required power set is { \n"); 
	for(int k=0; k<sz; k++){
		printf("[ ");
		for(int l=0; l<n; l++){
			if(b[k][l]==1){
				printf("%d ", arr[l]);
			}
		}
		printf("] \n");
	}
	printf("}\n");

	return 0;
}