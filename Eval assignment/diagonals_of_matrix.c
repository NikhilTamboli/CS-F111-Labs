#include <stdio.h>

int main() {
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);
    
    printf("\nEnter n by n array: \n");
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x;
            scanf("%d", &x);
            arr[i][j]=x;
        }
    }

    printf("\nThe required solution: \n");
    for(int i=0; i<=n*n; i++){
        for(int j=0; j<n; j++){
            for(int k=n; k>=0; k--){
                if((j+k)==i && k<n){
                    printf("%d ", arr[j][k]);
                }
            }
        }
    }
    return 0;
}