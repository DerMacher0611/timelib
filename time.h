#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

struct date{
    int day;
    int month;
    int year;
};

int is_leapyear(struct date);

int get_days_for_month(struct date);

int get_days_for_month(struct date);

int day_of_the_year(struct date);

void input_date(struct date*);

#endif // TIME_H_INCLUDED
