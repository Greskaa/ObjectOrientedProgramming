#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

typedef struct Date date;

int Date_Comparison(date d1, date d2)
{
    //-1 if d1 < d2
    //0 if d1==d2
    //1 if d1 > d2
    if (d1.year > d2.year)
        return 1;
    else if (d1.year < d2.year)
        return -1;
    else
    {
        if (d1.month > d2.month)
            return 1;
        else if (d1.month < d2.month)
            return -1;
        else
        {
            if (d1.day > d2.day)
                return 1;
            else if (d1.day < d2.day)
                return -1;
            else
                return 0;
        }
    }
}

void Read_Date(date *d)
{
    scanf("%d %d %d", &d->day, &d->month, &d->year);
}

void Print_Date(date d)
{
    printf("%02d.%02d.%04d", d.day, d.month, d.year);
}

int main()
{
    date date_1;
    date date_2;

    printf("Enter first date: "); //First Date
    Read_Date(&date_1);
    //Print_Date(date_1);

    printf("Enter second date: "); //Second Date
    Read_Date(&date_2);
    //Print_Date(date_2);

    int result = Date_Comparison(date_1, date_2);

    //Check comparison of dates and print out text accordingly
    if (result)
    {
        Print_Date(date_1); printf(" is smaller than "); Print_Date(date_2);
    }
    else if (result==-1)
    {
        Print_Date(date_2); printf(" is smaller than "); Print_Date(date_1);
    }
    else
    {
        printf("Both dates "); Print_Date(date_1); printf(" and "); Print_Date(date_2); printf(" are equal.");
    }

    return 0;
}
