#include <stdio.h>
#include <stdint.h>

#define M 10000000000 /* 10^10 because only interested in the last 10 digits */
#define LEN 10

/* find the last 10 digits of 28433 * 2^7830457 + 1 */
int32_t main(void)
{
	/* start by computing 2^7830457. Instead of going 2 by 2 (i.e.
	 * computing 2^1, 2^2, 2^3...), goes 24 by 24 (2^24, 2^48, 2^72 ...),
	 * it is faster. Then goes 2 by 2 for the remaining exponent. */
	int64_t answer = 1;
	int32_t power  = 7830457, d = 24;

	while (power > d)
	{
		answer = (answer << d) % M;
		power -= d;
	}

	while (power-- > 0)
		answer = (answer << 1) % M;

	/* compute the desired number, only keep its last 10 digits */
	answer = (28433 * answer + 1) % M;

	printf("Problem 97: %ld\n", answer);
	return 0;
}
