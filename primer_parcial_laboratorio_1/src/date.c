#include "date.h"

int isLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}

int isValidDate(Date *validDate)
{
	int ret = 1;
    //check range of year,month and day
    if (validDate->yyyy < MIN_YEAR || validDate->yyyy > MAX_YEAR)
    {
    	ret = -1;
    }
    if (validDate->mm < MIN_MONTH || validDate->mm > MAX_MONTH)
    {
    	ret = -2;
    }
    if (validDate->dd < MIN_DAY || validDate->dd > MAX_DAY)
	{
    	ret = -3;
	}

    if (validDate->mm == 2)
    {
        if (isLeapYear(validDate->yyyy))
		{
        	if(validDate->dd > 29)
        	{
        		ret = -4;
        	}
		}
		else
			{
				if(validDate->dd > 28)
				{
					ret = -5;
				}
			}
    }
    //handle months which has only 30 days
    if ((validDate->mm == 4
    	|| validDate->mm == 6
		|| validDate->mm == 9
		|| validDate->mm == 11) && validDate->dd > 30)
        {
    		ret = -6;
        }

    return ret;
}
