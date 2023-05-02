#include <stdio.h>
#include <stdlib.h>
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

/**
 * main - the main function
 * Return: Always 0.
 */
int main(void)
{
	struct time testTimes[5] = 
	{ { 11, 59, 59 }, { 12, 0, 0 }, { 1, 29, 59 },
	  { 23, 59, 59 }, { 19, 12, 27 }};
	int i;

	for (i = 0; i < 5; ++i)
	{
		printf("Time is %.2i:%.2i:%.2i", testTimes[i].hour, testTimes[i].minutes, testTimes[i].seconds);

		testTimes[i] = timeUpdate(testTimes[i], 1);
		printf("...one second later it's %.2i:%.2i:%.2i\n", testTimes[i].hour, testTimes[i].minutes, testTimes[i].seconds);
	}
	return (0);
}
