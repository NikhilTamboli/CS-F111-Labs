#include <stdio.h>

float exp(int num, float total){
    for(int i=1; i<num; i++){
        total *= total;
    }
    return total;
}

int main() {
    float total;
    printf("Enter initial total : ");
    scanf("%f", &total);
    char op;
    int flag = 1;
    while(flag){
        printf("Enter operation (+,-,*,/,^) : ");
        scanf(" %c", &op);
        if(op!='+' && op!='-' && op!='*' && op!='/' && op!='^') break;
        float num;
        if(op=='^'){
            printf("Enter  positive non-zero integer: ");
        } else {
            printf("Enter number : ");
        }
        scanf(" %f", &num);
        switch(op){
            case '+':
            total += num;
            break;
            case '-':
            total -= num;
            break;
            case '*':
            total *= num;
            break;
            case '/':
            total /= num;
            break;
            case '^':
            total = exp(num,total);
            break;
            default:
            flag = 0;
        }
        printf("Total : %f \n", total);
    }
    return 0;
}