#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t main()
{
	/* Find all primes below 1M with the sieve of Eratosthenes. i is
	 * prime if sieve[i-1] is 1. */
	uint64_t N = 1000000, i, j;
	uint8_t *sieve = (uint8_t*)calloc(N, sizeof(uint8_t));
	for (i = 0; i < N; ++i) sieve[i] = 1;

	for (i = 2; i < N; ++i) /* start at 2 because 1 is not prime */
		if (sieve[i-1])
			for (j = 2*i; j < N+1; j += i)
				sieve[j-1] = 0;

	/* For all pairs (a,b), find the number of consecutive primes generated
	 * by n^2 + a*n + b (starting with n=0). Save the product a*b of the
	 * pair that generates the maximum number of consecutive primes. */
	int32_t MAX = 1000, max_num_primes = 0, product, a, b, n, tmp;
	for (a = -MAX+1; a < MAX; ++a)
		for (b = -MAX+1; b < MAX; ++b)
		{
			n = 0;
			tmp = b; /* n*n + a*n + b when n=0 */

			/* We use the array sieve to know if tmp is a prime
			 * number, but this array only contains positive prime
			 * numbers, so we need the absolute value of tmp. */
			if (tmp < 0) tmp *= -1;

			while (sieve[tmp-1])
			{
				++n;
				tmp = n*n + a*n + b;
				if (tmp < 0) tmp *= -1;
			}

			if (n > max_num_primes)
			{
				max_num_primes = n;
				product = a*b;
			}
		}

	printf("Problem 27: %d\n", product);

	free(sieve);
	return 0;
}

