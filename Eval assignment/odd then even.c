#include <stdio.h>

int main() {
    int n,k,i;
    scanf("%d %d", &n,&k);
    if(n%2==0){
        if(k<=(n/2)){
            i = 2*k-1;
        } else {
            i = 2*(k-(n/2));
        }
    } else {
        if(k<=((n+1)/2)){
            i = 2*k-1;
        } else {
            i = 2*(k-((n+1)/2));
        }
    }
    printf("%d", i);
    return 0;
}