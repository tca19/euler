#include <stdio.h>
#include <stdint.h>

#define LIM 60000
#define MOD 1000000 /* 10^6 */

/* find the least value for which p(n) is divisible by 10^6 (where p(n) is the
 * number of ways to partition the integer n) */
int32_t main(void)
{
	int32_t i, j, partitions[LIM] = {0}, pentagonal[LIM] = {0};

	/* init the array with generalized pentagonal numbers. Stop once
	 * pentagonal[i] > LIM because the formula to compute partitions[n],
	 * uses partitions[n-k] where k is a pentagonal number and n=1..LIM, so
	 * at one point, n-k will be negative and partitions[<0] = 0. */
	for (i = 1, j = 0; j < LIM; ++i)
	{
		pentagonal[j++] = i * (3*i-1) / 2;
		pentagonal[j++] = i * (3*i+1) / 2;
		if (pentagonal[j] > LIM)
			break;
	}

	/* use the recurrence formula to compute the number of partitions:
	 *   partitions[n] = partitions[n-penta_1] + partitions[n-penta_2]
	 *                 - partitions[n-penta_3] - partitions[n-penta_4]
	 *                 + partitions[n-penta_5] + partitions[n-penta_6]...
	 */
	partitions[0] = 1;
	for (i = 1; i < LIM; ++i)
	{
		for (j = 0; j < LIM; ++j)
		{
			if ((i-pentagonal[j]) < 0)
				break;
			if ((j&2) == 0) /* simulate + + - - + + - - ... */
				partitions[i] += partitions[i-pentagonal[j]];
			else
				partitions[i] -= partitions[i-pentagonal[j]];
		}

		/* need to find the first one which is divisible by
		 * 10^6, so only keep the last 6 digits. Since we are
		 * only adding, it is not a problem to do all operations
		 * with % 10^6 */
		partitions[i] %= MOD;
	}

	/* find the first one divisible by 10^6 */
	for (i = 0; i < LIM; ++i)
		if (partitions[i] == 0) /* partitions[i] is already % MOD */
		{
			printf("Problem 78: %d\n", i);
			break;
		}

	return 0;
}
