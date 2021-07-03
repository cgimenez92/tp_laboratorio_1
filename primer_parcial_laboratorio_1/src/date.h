#ifndef DATE_H_
#define DATE_H_

#define MIN_YEAR 1900
#define MAX_YEAR 2500
#define MIN_MONTH  1
#define MAX_MONTH  12
#define MIN_DAY  1
#define MAX_DAY  31

typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;

int  isLeapYear(int year);
int isValidDate(Date *validDate);

#endif /* DATE_H_ */
