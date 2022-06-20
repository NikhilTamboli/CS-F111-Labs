#include <stdio.h>

int main() {
    int flag = 1;
    int one=0,two=0,three=0,four=0,five=0;
    while(flag){
        printf("a. Enter digits.\nb. View digit count.\nc. View average.\nd. Exit.\n");
        char choice;
        printf("Enter an option: ");
        scanf(" %c", &choice);
        if(choice == 'a'){
            int n=1;
            while(1<=n && n<=5){
                printf("Enter digit between 1 and 5: ");
                scanf(" %d", &n);
                switch(n){
                    case 1:
                    one+=1;
                    break;
                    case 2:
                    two+=1;
                    break;
                    three+=1;
                    break;
                    case 4:
                    four+=1;
                    break;
                    case 5:
                    five+=1;
                    break;
                }
            }
        } else if (choice == 'b'){
            printf("Count of 1: %d, count of 2: %d, count of 3: %d, count of 4: %d, count of 5: %d.\n",
             one, two, three, four, five);
        } else if (choice == 'c'){
            float sum = 1*one+2*two+3*three+4*four+5*five;
            float average = sum/(one+two+three+four+five);
            printf("Average is %f \n", average);
        } else if (choice == 'd'){
            flag = 0;
        }
    }
    return 0;
}