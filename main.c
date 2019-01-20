/**
 *Summary: This is a library for time functions.
 *date: 18.12.2018
 *author: Konrad Mach
 *last modified on/by : 20.01.2019/Konrad Mach
  **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
// Global vars.

int DAY;
int MONTH;
int YEAR;

/// Checks if given year is leapyear.
int is_leapyear(int year){
    if(year < 1582 || year > 2400){
        return -1;
    }

    if((year % 4) == 0 ){
        if((year % 100) == 0){
            if((year % 400) == 0){
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
int get_days_for_month(int month, int year){
    if(year < 1582 || year > 2400 || month < 1 || month > 12){
        return -1;
    }

    if(month == 2){
        if(is_leapyear(year) == 1){
            return 29;
        }
        else{
            return 28;
        };
    }

    switch (month){
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
int exist_date(int day, int month, int year){
    if(year < 1582 || year > 2400 || month < 1 || month > 12){
        return -1;
    }

    if(day > get_days_for_month(month,year) || day < 1){
        return -1;
    }

    return 0;
}

/// returns the days of the given year till an specific date.
int day_of_the_year(int day, int month, int year)
{
    if(exist_date(day,month,year)){
        return -1;
    }

    int totalDays = 0;
    int currMonth = month -1;

    for(int i = 0; i < (month - 1); i++ ){
        totalDays += get_days_for_month(currMonth, year);
        currMonth--;
    }
    totalDays += day;

    return totalDays;
}

//void input_date(&day, &month, &year){
//
//do{
//    printf("\n");
//    printf("Bitte geben Sie den Tag ein: ");
//    scanf("%i", &day);
//    printf("\n Bitte geben Sie den Monat ein: ");
//    scanf("%i", & month);
//    printf("\n Bitte geben Sie das Jahr ein: ");
//    scanf("%i", &year);
//
//}while(exist_date(&day, &month, &year) == 0) // To-Do: Checken ob die übergabeparams gehen.
//
//}



int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 2, 2018));
    return 0;
}
