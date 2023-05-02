#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * clockKeeper - a clock keeper,
 * Updates the time and if the time
 * reaches midnight it updates the date
 * using the dateUpdate function.
 * @day: a dateAndTime structure called day;
 * @secs: the amount of seconds to update the
 * time with.
 * Return: the updated dateAndTime structure
 */
struct dateAndTime clockKeeper(struct dateAndTime day, int secs)
{
	struct dateAndTime now;

	now.eTime = timeUpdate(day.eTime, secs);
	if (now.eTime.hour == 0 || now.eTime.hour < day.eTime.hour)
		now.eDate = dateUpdate(day.eDate);
	else
		now.eDate = day.eDate;
	return (now);
}
/**
 * main - the main function
 *
 * Return: Always 0.
 */
int main(void)
{
	struct dateAndTime day, now;

	day = (struct dateAndTime) {
		{ 2023, 5, 2 },
		{ 23, 59, 59 },
	};
	
	now = clockKeeper(day, 12000);
	printf("Updated Time: %i:%i:%i\n", now.eTime.hour, now.eTime.minutes, now.eTime.seconds);
	printf("Updated Date: %i/%i/%i\n", now.eDate.day, now.eDate.month, now.eDate.year);
	return (0);
}
