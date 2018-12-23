/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
// Globale variablen.

int DAY;
int MONTH;
int YEAR;

int day_of_the_year(int day, int month, int year)
{

    return 0;
}

int is_leapyear(int year){
    // Hier auch möglich exists_date mti 01.01.year übergeben um nach Jahr zu prüfen.
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

void input_date(&day, &month, &year){

do{
    printf("\n");
    printf("Bitte geben Sie den Tag ein: ");
    scanf("%i", &day);
    printf("\n Bitte geben Sie den Monat ein: ");
    scanf("%i", & month);
    printf("\n Bitte geben Sie das Jahr ein: ");
    scanf("%i", &year);

}while(exist_date(&day, &month, &year) == 0) // To-Do: Checken ob die übergabeparams gehen.

}

int get_days_for_month(int month, int year){
    if(year < 1582 || year > 2400 || month < 1 || month > 12){
        return -1;
    }

    switch (month){
        case 1: return 31; break;
        case 2: return 28; break; // To-Do: Prüfung Schaltjahr
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

int exist_date(int day, int month, int year){
    if(year < 1582 || year > 2400){
        return -1;
    }
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
