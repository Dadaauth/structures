#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
 * elapsed_time - calculates the elapsed time between two time intervals.
 * @sTime: start time
 * @eTime: end time
 * Return: a time structure of the elapsed time
 */
struct time elapsed_time(struct time sTime, struct time eTime)
{
	struct time time_i;
	int temp = 0;

	int iTH = 0;
	int iTM = 0;
	int iTS = 0;

	int sTH = sTime.hour;
	int sTM = sTime.minutes;
	int sTS = sTime.seconds;

	int eTH = eTime.hour;
	int eTM = eTime.minutes;
	int eTS = eTime.seconds;

	while ((sTS != eTS) || (sTM != eTM) || (sTH != eTH))
	{
		sTS++;
		iTS++;
		if (sTS == 60)
		{
			sTS = 0;
			sTM++;
			if (sTM == 60)
			{
				sTM = 0;
				sTH++;
				if (sTH == 24)
					sTH = 0;
			}
		}
		/**
		  * printf("s = %i \t m = %i \t h = %i\n", sTS, sTM, sTH);
		  */
		if (iTS == 60)
		{
			iTS = 0;
			iTM++;
			if (iTM == 60)
			{
				iTM = 0;
				iTH++;
			}
		}
		if (sTM == eTM && sTS == eTS && sTH == eTH)
			break;
	}
	time_i = (struct time) {iTH, iTM, iTS};
	return (time_i);
}
/**
 * main - the main function
 *
 * Reuturn: Always 0.
 */
int main(void)
{
	struct time sTime, eTime, time_i;

	printf("Start Time (hh mm ss): ");
	scanf("%i%i%i", &sTime.hour, &sTime.minutes, &sTime.seconds);
	printf("End Time (hh mm ss): ");
	scanf("%i%i%i", &eTime.hour, &eTime.minutes, &eTime.seconds);
	time_i = elapsed_time(sTime, eTime);
	printf("Elapsed time is: %dh:%dm:%ds\n", time_i.hour, time_i.minutes, time_i.seconds);
	return (0);

}
