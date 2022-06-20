#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int count=0;
        int j;
        for(j=n-i; j>1; j--){
            printf("* ");
            count+=1;
        }
        while(count<n){
            printf("%d ", j);
            count+=1;
            j+=1;
        }
        printf("\n");
    }
    return 0;
}