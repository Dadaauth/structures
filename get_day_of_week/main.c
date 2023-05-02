#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * f - a function that takes year and month as
 * arguments and performs some operations
 * @year: year
 * @month: month
 * Return: the calculated result
 */
int f(int year, int month)
{
	if (month <= 2)
		year = year - 1;
	else
		year = year;
	return (year);
}
/**
 * g - a function that takes month as an argument
 * and performs some operations
 * @month: month
 * Return: the calculated result.
 */
int g(int month)
{
	if (month <= 2)
		month += 13;
	else
		month += 1;
	return (month);
}
/**
 * main -  the main function
 *
 * Return: Always 0.
 */
int main(void)
{
	struct date uDate;
	int N, i;

	char *days[] = {
		"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" 
	};

	printf("Type a date (yy mm dd): ");
	scanf("%i%i%i", &uDate.year, &uDate.month, &uDate.day);
	N =  1461 * f(uDate.year, uDate.month) / 4 + 153 * g(uDate.month) / 5 + uDate.day;
	i = (N - 621049) % 7;
	printf("Day of the week for the entered date is %s\n", days[i]);
	return (0);
}
