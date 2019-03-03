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
int is_leapyear(struct date given_date){
    if(given_date.year < 1582 || given_date.year > 2400){
        return -1;
    }

    if((given_date.year % 4) == 0 ){
        if((given_date.year % 100) == 0){
            if((given_date.year % 400) == 0){
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
int get_days_for_month(struct date given_date){
    if(given_date.year < 1582 || given_date.year > 2400 || given_date.month < 1 || given_date.month > 12){
        return -1;
    }

    if(given_date.month == 2){
        if(is_leapyear(given_date) == 1){
            return 29;
        }
        else{
            return 28;
        };
    }

    switch (given_date.month){
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
int exists_date(struct date given_date){
    if(given_date.year < 1582 || given_date.year > 2400 || given_date.month < 1 || given_date.month > 12){
        return 0;
    }

    if(given_date.day > get_days_for_month(given_date) || given_date.day < 1){
        return 0;
    }

    return 1;
}

/// returns the days of the given year till an specific date.
int day_of_the_year(struct date given_date)
{
    if(exists_date(given_date) == 0){
        return -1;
    }

    int total_days = 0;
    struct date curr_count;
    curr_count.month = given_date.month;
    curr_count.year = given_date.year;

    for(int i = 0; i < (given_date.month - 1); i++ ){
        curr_count.month = curr_count.month - 1;
        total_days += get_days_for_month(curr_count);
    }
    total_days += given_date.day;

    return total_days;
}

/// function for get date by Console-Inputs. Loop till valid date is given.
void input_date(struct date *given_date){

    do{
        printf("\n");
        printf("Bitte geben Sie den Tag ein: ");
        scanf("%i", &given_date->day);
        printf("\nBitte geben Sie den Monat ein: ");
        scanf("%i", &given_date->month);
        printf("\nBitte geben Sie das Jahr ein: ");
        scanf("%i", &given_date->year);

    }while(exists_date(*given_date) == 0);
}


