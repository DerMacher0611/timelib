/**
 *Summary: This is the main class to test time functions.
 *date: 18.12.2018
 *author: Konrad Mach
 *last modified on/by : 20.01.2019/Konrad Mach
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
    printf("Tag des Jahres: %i\n", day_of_the_year(25, 6, 2018));
    return 0;
}
