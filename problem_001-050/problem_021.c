#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/* Return the sum of all divisors of n (n is not included in the sum). */
int32_t sum_divisors(int32_t n)
{
	int32_t s = 1; /* 1 is ALWAYS a divisor of n */
	for (int32_t i = 2; i*i < n+1; ++i)
	{
		if (n%i == 0)
		{
			if (n/i == i)
				s += i;
			else
				s += i + n/i;
		}
	}

	return s;
}

int32_t main()
{
	int32_t SIZE = 10000, sum_amicable = 0, i;
	int32_t* sum_div = (int32_t*) calloc(SIZE, sizeof(int32_t));
	sum_div[0] = 0; /* special case, 1 has no proper divisors. */

	/* Find sum of proper divisors for integers below 10000. */
	for (i = 1; i < SIZE; ++i)
		sum_div[i] = sum_divisors(i+1);

	/* Find amicable numbers (same sum of divisors but different numbers).
	 * There is -1 because d(i) is stored at the cell i-1. */
	for (i = 1; i < SIZE+1; ++i)
		if (sum_div[sum_div[i-1]-1] == i && i != sum_div[i-1])
			sum_amicable += i;

	printf("Problem 21: %d\n", sum_amicable);
	free(sum_div);
	return 0;
}
