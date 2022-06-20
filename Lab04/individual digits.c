#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    printf("%d \n", (num/1)%10);
    printf("%d \n", (num/10)%10);
    printf("%d \n", (num/100)%10);
    printf("%d \n", (num/1000)%10);
    printf("%d \n", (num/10000)%10);
    switch(num%10){
        case 1:
        case 3:
        case 5:
        case 7:
        printf("1\n");
        break;
        default:
        printf("0\n");
    }
    if(((num/100)%10)%2==0){
        printf("0\n");
    } else {
        printf("1\n");
    }
}