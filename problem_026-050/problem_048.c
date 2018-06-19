#include <stdio.h>
#include <stdint.h>

#define M 10000000000 /* 10^10 */

/* power: return a^b, only the last 10 digits */
int64_t power(int64_t a, int64_t b)
{
	int64_t p;

	for (p = 1; b-- > 0; p *= a)
		p %= M;

	return p % M;
}

int32_t main(void)
{
	/* only need the last 10 digits to solve the problem, so compute the a^b
	 * terms but only add the last 10 digits to answer. */
	int64_t a, answer;

	for (a = 1, answer = 0; a < 1000; ++a)
	{
		answer += power(a, a);
		answer %= M;
	}

	printf("Problem 48: %ld\n", answer);
	return 0;
}

