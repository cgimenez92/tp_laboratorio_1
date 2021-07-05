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

/** \brief Verify if year is Leap
 * \param int year
 * \return int Return (1) if OK (!=1) if Error
 */
int  isLeapYear(int year);

/** \brief create a new Customer in list in the first empty position
 * \param Date *validDate
 * \return int Return (-1) if Day out of range [1-31]; Return (-2) if Month out of range [1-12]; Return (-3) if Year out of range [1900-2500]; Return (-4) if Leap years cannot have more than 29 days in February; Return (-5) if NON-leap years cannot have more than 28 days in February; Return (-6) if The months of April - June - September - November cannot have more than 30 days; Return (1) if validDate is OK
 */
int isValidDate(Date *validDate);

#endif /* DATE_H_ */
