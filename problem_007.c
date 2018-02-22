#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t main()
{
	/* find all primes below 1M with the sieve of Eratosthenes. Stop once
	 * we find the 10001st prime. */
	uint64_t N = 1000000, c = 10001, i;
	uint8_t *sieve = (uint8_t*)calloc(N, sizeof(uint8_t));
	for (i = 0; i < N; ++i) sieve[i] = 1;

	for (i = 2; i < N; ++i) /* start at 2 because 1 is not prime */
	{
		if (sieve[i-1])
		{
			if (--c < 1) break;
			for (uint64_t j = 2*i; j < N+1; j += i)
				sieve[j-1] = 0;
		}
	}

	printf("Problem 7: %" PRIu64 "\n", i);
	free(sieve);
	return 0;
}
