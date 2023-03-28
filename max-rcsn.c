#include <stdio.h>

int max(int arr[], int i){
    if(i==0){
        return arr[0];
    } else {
        int m = max(arr, --i);
        if(m < arr[i]){
            return arr[i];
        } else {
            return m;
        }
    }
}

int main() {
    int arr[10] = {256,222,155,45,95,220,700,865,99,10};
    int ans = max(arr, 10);
    printf("%d", ans);
    return 0;
}