#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "main.h"
/**
 * timeUpdate - updates a time by the
 * amount of seconds given to it.
 * @struct time now: the time given by the user
 * Return: the updated time
 */
struct time timeUpdate(struct time now, int secsCount)
{
	int temp;

	now.seconds += secsCount;


	if (now.seconds == 60)
	{
		now.seconds = 0;
		now.minutes++;
	}
	else if (now.seconds > 60)
	{
		temp = now.seconds / 60;
		now.minutes += temp;
		now.seconds = now.seconds - (temp * 60);
	}
	if (now.minutes == 60)
	{
		now.minutes = 0;
		now.hour++;
	}
	else if (now.minutes > 60)
	{
		temp = now.minutes / 60;
		now.hour += temp;
		now.minutes = now.minutes - (temp * 60);
	}
	if (now.hour == 24)
	{
		now.hour = 0;
		now.minutes = 0;
		now.seconds = 0;
	}
	if (now.hour > 24)
	{
		temp = now.hour / 24;
		now.hour = now.hour - (temp * 24);
	}
	return (now);
}
