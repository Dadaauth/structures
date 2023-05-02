#ifndef MAIN_H
#define MAIN_H

/**
 * struct date - a date structure
 * @year: year
 * @month: month
 * @day: day
 */
struct date
{
	int year;
	int month;
	int day;
};
/**
 * struct time - a time structure
 * @hour: hour
 * @minutes: minutes
 * @seconds: seconds
 */
struct time
{
	int hour;
	int minutes;
	int seconds;
};
/**
 * struct dateAndTime - a structure containing a date
 * and a time stucture
 * @struct date sdate: event date
 * @struct time stime: event time
 */
struct dateAndTime
{
	struct date sdate;
	struct time stime;
};

#endif
