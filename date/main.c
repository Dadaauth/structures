#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
/**
 * isLeapYear - checks if a year is a leap year
 * @struct date d: the date to perform the check on
 * Return: True or False
 */
bool isLeapYear(struct date d)
{
	bool leapYearFlag;

	if ((d.year % 4 == 0 && d.year % 100 != 0) | d.year %400 == 0)
		leapYearFlag = true;
	else
		leapYearFlag = false;
	return (leapYearFlag);
}
/**
 * numberOfDays - gets the number of days in a month
 * @struct date d: the date given by the user
 * Return: the number of days in the month given by the user
 */
int numberOfDays(struct date d)
{
	int days;
	int daysPerMonth[12] =  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (isLeapYear(d) && d.month == 2)
		days = 29;
	else
		days = daysPerMonth[d.month - 1];
	return (days);
}
/**
 * dateUpdate - takes in a date and returns the date
 * of the following day
 * @struct date today
 * Return: tommorow's date
 */
struct date dateUpdate(struct date today)
{
	struct date tomorrow;
	int td = today.day;
	int tm = today.month;
	int ty = today.year;

	if (today.day != numberOfDays(today))
	{
		tomorrow = (struct date) {.day = td + 1, .month = tm, .year = ty};
	}
	else if (today.month == 12)
	{
		tomorrow = (struct date) {.day = 1, .month = 1, .year = ty + 1};
	}
	else
	{
		tomorrow = (struct date) {.day = 1, .month = tm + 1, .year = ty};
	}
	return (tomorrow);
}
/**
 * main - the main function
 *
 * Return: Always 0.
 */
int main(void)
{
	struct date today, tomorrow;


	printf("Enter today's date (mm dd yy): ");
	scanf("%i%i%i", &today.month, &today.day, &today.year);

	tomorrow = dateUpdate(today);

	printf("Tomorrow's date is %i/%i/%.2i.\n", tomorrow.month, tomorrow.day, tomorrow.year % 100);
	return (0);
}
