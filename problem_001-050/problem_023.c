#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/* Return the sum of all divisors of n (n is not included in the sum). */
int32_t sum_divisors(int32_t n)
{
	int32_t s = 1; /* 1 is ALWAYS a divisor of n */
	for (int32_t i = 2; i*i < n+1; ++i)
		if (n%i == 0)
		{
			if (n/i == i)
				s += i;
			else
				s += i + n/i;
		}

	return s;
}

int32_t main()
{
	uint64_t total = 0;
	int32_t SIZE = 28124, i, j;
	int32_t* abundant = (int32_t*)calloc(SIZE, sizeof(int32_t));

	/* Find abundant numbers below 28124. Start at 2 because 0 and 1 are not
	 * abundant. */
	for (i = 2; i < SIZE; ++i)
		abundant[i] = sum_divisors(i) > i ? 1 : 0;

	/* Find if each integer is a sum of abundant numbers. */
	uint8_t is_sum_abundants;
	for (i = 1; i < SIZE; ++i)
	{
		is_sum_abundants = 0;
		for (j = 1; j < i/2+1; ++j)
			if (abundant[j] && abundant[i-j])
			{
				is_sum_abundants = 1;
				break;
			}

		if (!is_sum_abundants)
			total += i;
	}

	printf("Problem 23: %" PRIu64 "\n", total);
	free(abundant);
	return 0;
}
