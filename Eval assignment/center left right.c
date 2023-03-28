#include <stdio.h>

int main() {
    // creating an array of the required size.
    printf("Enter the size of the array: ");
    int n;
    scanf("%d", &n);
    int arg[n];

    // taking the space separated digits entered by the user as the given array.
    printf("Enter the digits of the array separated by spaces: ");
    for(int l=0; l<n; l++){
        int x;
        scanf(" %d", &x);
        arg[l]=x;
    }

    // algorithm to make another array which follows the given rule.
    int mid = (n)/2;
    int ans[n];
    ans[0] = arg[mid];
    for(int j=1, k=1; j<=mid; j++, k+=2){
        ans[k]=arg[mid-j];
        ans[k+1]=arg[mid+j];
    }

    // printing the output.
    printf("Output array: ");
    for(int l=0; l<n; l++){
        printf("%d ", ans[l]);
    }
    printf("\n");

    return 0;
}