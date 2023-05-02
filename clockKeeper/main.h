#ifndef MAIN_H
#define MAIN_H

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
 * struct dateAndTime - a date and time structure
 * @eDate: event Date
 * @eTime: event time
 */
struct dateAndTime
{
	struct date eDate;
	struct time eTime;
};
struct date dateUpdate(struct date today);
struct time timeUpdate(struct time now, int secsCount);
#endif
