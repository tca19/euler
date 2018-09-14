#include <stdio.h>
#include <stdint.h>

#define MAXINT 100

/* find the number of ways to write 100 as a sum of at least 2 integers */
int32_t main(void)
{
	/* Solution is similar to the one of problem 31 (finding the number of
	 * ways to give 2£ using coins of 1p, 2p, 5p, 10p...)
	 * In this case, we have more coins (with value from 1 to 99).
	 * Example: 53 can be written as:
	 *   63 = 62 + 1
	 *   63 = 61 + 2 (and 2 can be 2 = 1 + 1)
	 *   63 = 60 + 3 (and 3 can be 3 = 2 + 1 or 3 = 1 + 1 + 1)
	 *   63 = 59 + 4 (and 4 can be 4 = 3 + 1, 4 = 2 + 2, 4 = 2 + 1 + 1...)
	 *   ...
	 *
	 *   At each step, we add the number of ways to do 63 - X where
	 *   X = 62..1. */
	int32_t i, j;
	int32_t ways[MAXINT+1] = {0};

	ways[0] = 1;
	/* for each integer j=1..100, add the number of ways to write j as a sum
	 * of at least 2 integers with integers at most equal to i */
	for (i = 1; i < MAXINT; ++i)
		for (j = i; j <= MAXINT; ++j)
			ways[j] += ways[j-i];

	printf("Problem 76: %d\n", ways[MAXINT]);
	return 0;
}
