#include <stdio.h>
#include <stdlib.h>
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
 * main - the main function
 *
 * Return - Always 0.
 */
int main(void)
{
	struct date sDate;
	struct date eDate;
	int n1, n2, noOfDays;

	printf("Enter Start Date: (yy mm dd): ");
	scanf("%i%i%i", &sDate.year, &sDate.month, &sDate.day);
	printf("Enter End Date: (yy mm dd): ");
	scanf("%i%i%i", &eDate.year, &eDate.month,&eDate.day);

	n1 = 1461 * f(sDate.year, sDate.month) / 4 + 153 * g(sDate.month) / 5 + sDate.day;
	n2 = 1461 * f(eDate.year, eDate.month) / 4 + 153 * g(eDate.month) / 5 + eDate.day;
	noOfDays = n2 - n1;
	printf("Number of elapsed days => %i\n", noOfDays);
	return (0);
}
