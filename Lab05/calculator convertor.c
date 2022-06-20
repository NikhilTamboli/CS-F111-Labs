#include <stdio.h>

float calculator(){
    int op;
    printf("Select which operation do you want to perform\n1.Addition\n2.Subtraction\n3.Division\n4.Multiplication\n5.Percentage\n6.Modulo\n");
    scanf("%d", &op);
    float x,y;
    printf("Enter two numbers:\n");
    scanf("%f %f", &x, &y);    
    if(op==1){
        printf("Sum = %f\n", x+y);
    } else if(op==2){
        printf("Subtraction = %f\n", x-y);        
    } else if(op==3){
        printf("Division = %f\n", x/y);          
    } else if(op==4){
        printf("Mulitplication = %f\n", x*y);          
    } else if(op==5){
        float pc = x*y/100;
        printf("%d%% of %f = %f\n", (int)y, x, pc);
    } else if(op==6){
        printf("Modulo = %d\n", (int)x%(int)y);  
    } else {
        printf("Invalid Input!\n");
    }
}

float convertor(){
    int op;
    printf("Select which operation do you want to perform\n1.Celsius to Fahrenheit\n2.Meter to Inch\n3.Kilogram to Pound\n");
    scanf(" %d", &op);
    if(op==1){
        float x;
        printf("Enter a number in Celsius\n");
        scanf(" %f", &x);
        float f = 1.8*x+32;
        printf("%f degree C = %f degree F.\n", x, f);
    } else if(op==2){
        float x;
        printf("Enter a number in meters\n");
        scanf(" %f", &x);
        printf("%f m = %f in.\n", x, x*39.37);
    } else if(op==3){
        float x;
        printf("Enter a number in Kilogram\n");
        scanf(" %f", &x);
        printf("%f kg = %f lb\n", x, x*2.2);
    } else {
        printf("Invalid Input!");
    }
}

int main() {
    int op;
    while(op!=3){
        printf("\n");
        printf("Please Select the proper option \n1.Calculator\n2.Conversion\n3.Exit\n");        
        scanf("%d", &op);
        if(op==1){
            calculator();
        } else if(op==2){
            convertor();
        } else if(op==3){
            continue;
        } else {
            printf("Invalid Input!\n");
        }
    }
    
    return 0;
}