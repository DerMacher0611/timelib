/**
 *Summary: This is the header-file for time functions.
 *date: 18.12.2018
 *author: Konrad Mach
 *last modified on/by : 03.03.2019/Konrad Mach
  **/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

struct date{
    int day;
    int month;
    int year;
};

int is_leapyear(struct date given_date);

int get_days_for_month(struct date given_date);

int get_days_for_month(struct date given_date);

int day_of_the_year(struct date given_date);

void input_date(struct date *given_date);

#endif // TIME_H_INCLUDED
