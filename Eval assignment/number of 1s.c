#include <stdio.h>

int main() {
    // creating a character array to store the given binary array.
    int n;
    printf("Enter the maximmum size of the array: ");
    scanf("%d",&n);
    char arg[n+1];

    // declaring variables.
    char x;
    int count = 0;
    int max = 0;
    int i = 0;

    // taking binary array input from the user.
    printf("Enter the binary array (without spaces): ");
    scanf(" %c", &x);
    int it = 0; // will be used to check if the given array is longer than the specified size.
    while((x=='0' || x=='1')){
        arg[i]=x;
        i++;
        it++;
        scanf("%c", &x);
    }

    // counting the number of 1s if the array size is less than or equal to specified size.
    if(it<=n){
        for(int j=0; j<(sizeof(arg)/sizeof(arg[0])); j++){
            if(arg[j]=='1'){
                count++;
            } else {
                if(max<=count){
                    max = count;
                }
                count = 0;
            }
        }
        printf("Maximum number of consecutive 1s is %d\n", max);
    } else {
        printf("Array is longer than the specified size.\n");
    }

    return 0;
}