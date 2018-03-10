#include <stdio.h>
#include <stdint.h>

int32_t main()
{
	/* 1900 is a not a leap year and Jan 1 is a Monday so Dec 31 is also a
	 * Monday (365%7 = 1). So Jan 1 1901 is a Tuesday. We represent day of
	 * week with an integer (1 for Monday, 2 for Tuesday...0 for Sunday).
	 * We add the number of days of each month and look what is the starting
	 * day of the month. We increment a counter everytime it is a Sunday. */
	int32_t days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int32_t weekday = 2, c = 0, year, month;

	for (year = 1901; year < 2001; ++year)
		for (month = 0; month < 12; ++month)
		{
			/* only century year is 2000, which is also divisible by
			 * 400, so no special case to handle. */
			if (year%4 == 0 && month == 1) /* leap year */
				weekday += 29;
			else
				weekday += days[month];

			weekday %= 7;
			if (weekday == 0)
				++c;
		}

	printf("Problem 19: %d\n", c);
	return 0;
}
