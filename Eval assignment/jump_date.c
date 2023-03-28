
#include <stdio.h>

struct date{
    int day;
    int month;
    int year;
};

typedef struct date Date;

void store(Date * d, char dt[11]){
    int day = 10*(dt[0]-48)+(dt[1]-48);
    int month = 10*(dt[3]-48)+(dt[4]-48);
    int year = 1000*(dt[6]-48)+100*(dt[7]-48)+10*(dt[8]-48)+(dt[9]-48);
    d->day = day;
    d->month = month;
    d->year = year;
}

int month_changed = 0;

Date * jump(Date * d, int nprev, int ncurr){
    if(month_changed>12) d->month=month_changed%12;
    int dy = d->day;
    int mn = d->month;
    int yr = d->year;
    if (ncurr<=0){
        if(month_changed!=0) d->day = nprev;
        else d->day += nprev;
    } else if (mn==2){
        if(yr%4==0 && ncurr>29-dy){
            d->month += 1;
            d->day=0;
            month_changed++;
            jump(d,ncurr,ncurr-29+dy);
        } else if (yr%4!=0 && ncurr>28-dy){
            d->month += 1; 
            d->day=0;
            month_changed++;
            jump(d,ncurr,ncurr-28+dy);
        } else {
            jump(d,ncurr,-1);
        }
    } else if (mn==1 || mn==3 || mn==5 || mn==7 || mn==8 || mn==10) {
        if(ncurr>31-dy){
            d->month+=1;
            d->day=0;
            month_changed++;
            jump(d, ncurr, ncurr-31+dy);
        } else {
            jump(d, ncurr, -1);
        }
    } else if(mn==4 || mn==6 || mn==9 || mn==11) {
        if(ncurr>30-dy){
            d->month+=1;   
            d->day=0;
            month_changed++;
            jump(d, ncurr, ncurr-30+dy);
        } else {
            jump(d, ncurr, -1);
        }        
    } else if (mn>=12){
        if(ncurr>31-dy){
            d->month=1;
            d->day=0;
            d->year+=1;
            month_changed++;
            jump(d, ncurr, ncurr-31+dy);
        } else {
            jump(d, ncurr, -1);
        }
    }
}

int main(void){
    Date d;
    printf("Please enter the date in dd/mm/yyyy format: ");
    char dt[11];
    fgets(dt, sizeof(dt), stdin);
    fflush(stdin);
    store(&d,dt);
    int flag;
    if(d.month==1||d.month==3||d.month==5||d.month==7||d.month==8||d.month==10||d.month==12) {
        if(d.day<1||d.day>31) flag = 0;
    } else if (d.month==2){
        if(d.year%4==0){
            if(d.day<1||d.day>29) flag = 0;
        } else {
            if(d.day<1||d.day>28) flag = 0;
        }
    } else {
        if(d.day<1||d.day>30) flag = 0;
    }
    if(d.month<1 || d.month>12||(flag==0)){
        printf("Invalid date.");
    } else {
        int n;
        printf("Enter an integer n: ");
        scanf(" %d", &n);
        Date *dtptr = jump(&d, n,n);
        printf("After %d days, the date will be %d/%d/%d.", n,d.day,d.month,d.year);
    }
    printf("\n");
    return 0;
}
