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
/**
 * main - the main function
 *
 * Return: Always 0.
 */
int main(void)
{
		struct time now, later;
		int secsToUpdate = 0;
		bool loop = true;

		while (loop)
		{
			printf("Enter the time: hh mm ss, seconds to update: ");
			scanf("%i:%i:%i,%i", &now.hour, &now.minutes, &now.seconds, &secsToUpdate);
			if (now.hour > 24 || now.minutes > 59 || now.seconds > 59)
			{
				printf("hour cannot be greater than 23,\nminutes cannot be greater than 59,\n");
				printf("seconds cannot be greater than 59,\nTherefore please check your input:\n");
			}
			else
			{
				loop = false;
			}

		}

		later = timeUpdate(now, secsToUpdate);
		printf("updated time by %d secs: %.2i:%.2i:%.2i.\n", secsToUpdate, later.hour, later.minutes, later.seconds);
		return (0);
}
