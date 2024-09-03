/*Q1. Write a menu driven program for Date in a C. 
Declare a structure Date having data members 
day, month, year. Implement the following functions.
void initDate(struct Date* ptrDate);
void printDateOnConsole(struct Date* ptrDate);
void acceptDateFromConsole(struct Date* ptrDate);
*/
#include<stdio.h>

struct Date
    {
        int day;
        int month;
        int year;
    };

    void initDate(struct Date *d){
        d->day = 0;
        d->month = 0;
        d->year = 1111;
    }

    void acceptDate(struct Date *d){
        printf("Enter the day: \n");
        scanf("%d",&d->day);
        printf("Enter the month: \n");
        scanf("%d",&d->month);
        printf("Enter the year: \n");
        scanf("%d",&d->year);

    }

    void displayDate(struct Date *d){
        printf("Date ==> %d/%d/%d",d->day,d->month,d->year);
    }


int main(){
    struct Date d1;
    initDate(&d1);
    acceptDate(&d1);
    displayDate(&d1);


    return 0;
}