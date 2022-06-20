#include <stdio.h>

char grade(int m){
    if(m>=75){
        return 'A';
    } else if(m>=60 && m<75){
        return 'B';
    } else if(m>=50 && m<60){
        return 'C';
    } else if(m>=40 && m<50){
        return 'D';
    } else if(m<40){
        return 'E';
    }
}

char promo(char grd){
    if(grd == 'E'){
        return 'N';
    } else {
        return 'Y';
    }
}

int schlPcnt(int m){
    if(m>=95){
        return 80;
    } else if(m>=80 && m<95){
        return 50;
    } else if(m>=40 && m<80){
        return 10;
    } else {
        return 0;
    }
}

int main() {
    int m;
    printf("Enter Marks: \n");
    scanf(" %d", &m);
    if(m<0 || m>100){
        printf("Invalid Score!");
    } else {
        char grd = grade(m); 
        char prm = promo(grd);
        float fees = 100000;
        float schl = schlPcnt(m);
        float schlAmount = fees*(schl/100);
        float final = fees - schlAmount;
        printf("%f \n", (schl/100));
        printf("Grade: %c, Scholarship: %f percent, Promotion: %c, Fees Payable: %f \n", grd, schl, prm, final);
    }
    return 0;
}