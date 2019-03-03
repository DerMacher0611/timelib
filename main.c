/**
 *Summary: This is the main class to test time functions.
 *date: 18.12.2018
 *author: Konrad Mach
 *last modified on/by : 20.01.2019/Konrad Mach
 *                      03.02.2019/Konrad Mach / Added function input_date
  **/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

/**
 *
 *
 **/

int main()
{
    struct date input_date;
    input_date(&input_date);
    printf("Tag des Jahres: %i\n", day_of_the_year(input_date));

    return 0;
}
