#include <stdio.h>
#include <stdint.h>

#define TOTAL 200 /* 2 pounds = 200p */

int32_t main(void)
{
	/* Suppose we want to know the number of ways to make 63p. Two options :
	 *   - use no coins of 50p (A)
	 *   - use at least one coin of 50p (B)
	 *
	 * The first case is the number of ways to make 63p without using a coin
	 * of 50. The second is the number of ways to make 63-50 = 13p. Total
	 * number of ways is A + B.
	 *
	 * Start by counting the number of ways to make 1p to 200p with only 1p
	 * coins. Then do the same if 1p and 2p coins are available. Then do the
	 * same with 1p, 2p and 5p. Then repeat until all type of coins are
	 * available. For each step, the number of ways to make `i` is the sum
	 * of :
	 *   - number of ways to make `i` without using new coin (computed at
	 *     previous step)
	 *   - number of ways to make `i` - `value of new availabe coin` */
	int32_t coins[8]      = {1, 2, 5, 10, 20, 50, 100, 200};
	int64_t ways[TOTAL+1] = {0};
	int32_t i, j;

	ways[0] = 1; /* only one way to make 0p, it's to give 0 coins */
	for (i = 0; i < 8; ++i)
		for (j = coins[i]; j <= TOTAL; ++j)
			ways[j] += ways[j - coins[i]];

	printf("Problem 31: %ld\n", ways[TOTAL]);
	return 0;
}
