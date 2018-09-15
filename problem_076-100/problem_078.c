#include <stdio.h>
#include <stdint.h>

#define LIM 60000
#define MOD 1000000 /* 10^6 */

/* find the least value for which p(n) is divisible by 10^6 (where p(n) is the
 * number of ways to partition the integer n) */
int32_t main(void)
{
	int32_t i, j, partitions[LIM+1];

	/* The integer j can be partitioned as j = i + (j-1) for i=1..j. The
	 * integer j-i can also be partitioned in some ways, but since the
	 * computations are done with increasing j, it has already been
	 * computed. So partitions[j] = sum_{1}^j partitions[j-i] */
	partitions[0] = 1;
	for (i = 1; i < LIM; ++i)
		for (j = i; j <= LIM; ++j)
		{
			partitions[j] += partitions[j-i];

			/* need to find the first one which is divisible by
			 * 10^6, so only keep the last 6 digits. Since we are
			 * only adding, it is not a problem to do all operations
			 * with % 10^6 */
			partitions[j] %= MOD;
		}

	for (i = 0; i <= LIM; ++i)
		if (partitions[i] == 0) /* partitions[i] is already % MOD */
		{
			printf("Problem 78: %d\n", i);
			break;
		}

	return 0;
}
