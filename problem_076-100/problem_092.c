#include <stdio.h>
#include <stdint.h>

#define MAX 10000000

int8_t arrive_at_89[MAX] = {0};

/* square_digits: square each digit of n, return the sum */
int32_t square_digits(int32_t n)
{
	int32_t res = 0;

	while (n > 0)
	{
		res += (n%10) * (n%10);
		n /= 10;
	}

	return res;
}

/* chain_contains_89: compute a chain by recursively calling square_digits() on
 * n. Return 1 if this chain contains the number 89 */
int32_t chain_contains_89(int32_t n)
{
	/* the problem states that EVERY numbers will arrive at 1 or 89 */
	while (n != 1 && n != 89)
	{
		/* look if we have already computed the chain for this number */
		if (arrive_at_89[n])
			return 1;
		n = square_digits(n);
	}

	return n == 89;
}

/* count number of integers that have 89 in the chain created by recursively
 * summing the square of their digits */
int32_t main(void)
{
	int32_t i, count = 0;

	for (i = 1; i < MAX; ++i)
	{
		if (chain_contains_89(i))
		{
			/* mark it as seen so when we encounter it again in a
			 * chain, we know it will ends at 89 */
			arrive_at_89[i] = 1;
			++count;
		}
	}

	printf("Problem 92: %d\n", count);
	return 0;
}
