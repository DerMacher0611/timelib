/**
 *Summary: This is a library for time functions.
 *date: 18.12.2018
 *author: Konrad Mach
 *last modified on/by : 20.01.2019/Konrad Mach
  **/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"


// Global vars.

/// Checks if given year is leapyear.
int is_leapyear(struct date givenDate){
    if(givenDate.year < 1582 || givenDate.year > 2400){
        return -1;
    }

    if((givenDate.year % 4) == 0 ){
        if((givenDate.year % 100) == 0){
            if((givenDate.year % 400) == 0){
                return 1;
            }
        }
        else{
            return 1;
        }
    }
        return 0;
}

///returns days of month, needs month and year.
int get_days_for_month(struct date givenDate){
    if(givenDate.year < 1582 || givenDate.year > 2400 || givenDate.month < 1 || givenDate.month > 12){
        return -1;
    }

    if(givenDate.month == 2){
        if(is_leapyear(givenDate) == 1){
            return 29;
        }
        else{
            return 28;
        };
    }

    switch (givenDate.month){
        case 1: return 31; break;
        case 3: return 31; break;
        case 4: return 30; break;
        case 5: return 31; break;
        case 6: return 30; break;
        case 7: return 31; break;
        case 8: return 31; break;
        case 9: return 30; break;
        case 10: return 31; break;
        case 11: return 30; break;
        case 12: return 31; break;
    }
return 0;
}

/// Checks if the given date is valid.
int exists_date(struct date givenDate){
    if(givenDate.year < 1582 || givenDate.year > 2400 || givenDate.month < 1 || givenDate.month > 12){
        return 0;
    }

    if(givenDate.day > get_days_for_month(givenDate) || givenDate.day < 1){
        return 0;
    }

    return 1;
}

/// returns the days of the given year till an specific date.
int day_of_the_year(struct date givenDate)
{
    if(exists_date(givenDate) == 0){
        return -1;
    }

    int totalDays = 0;
    struct date currCount;
    currCount.month = givenDate.month;
    currCount.year = givenDate.year;

    for(int i = 0; i < (givenDate.month - 1); i++ ){
        currCount.month = currCount.month - 1;
        totalDays += get_days_for_month(currCount);
    }
    totalDays += givenDate.day;

    return totalDays;
}

/// function for get date by Console-Inputs. Loop till valid date is given.
struct date input_date(struct date givenDate){

    do{
        printf("\n");
        printf("Bitte geben Sie den Tag ein: ");
        scanf("%i", &givenDate.day);
        printf("\nBitte geben Sie den Monat ein: ");
        scanf("%i", &givenDate.month);
        printf("\nBitte geben Sie das Jahr ein: ");
        scanf("%i", &givenDate.year);

    }while(exists_date(givenDate) == 0);

    return givenDate;
}


