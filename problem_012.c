#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

/* return the number of divisors of n */
uint32_t n_divisors(uint64_t n)
{
	uint32_t d = 0, i;
	for (i = 1; i*i < n+1; ++i)
	{
		if (n%i == 0)
		{
			if (n/i == i)
				++d;
			else
				d += 2;
		}
	}

	return d;
}

int32_t main()
{
	uint64_t n = 1, i = 2;

	/* compute triangular numbers until we find one that has more than 500
	 * divisors. */
	do
	{
		n += i;
		++i;
	} while (n_divisors(n) < 500);

	printf("Problem 12: %" PRIu64 "\n", n);
	return 0;
}


