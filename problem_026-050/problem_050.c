#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define N 1000000

uint8_t sieve[N];

/* init_sieve: initialize the array to test if a number is prime */
void init_sieve(void)
{
	int32_t i, j;

	for (i = 0; i < N; ++i)
		sieve[i] = 1;
	sieve[0] = sieve[1] = 0;

	for (i = 2; i < N; ++i)
		if (sieve[i])
			for (j = 2*i; j < N; j += i)
				sieve[j] = 0;
}

/* find_longest_prime_sum: find the prime number that can be written with the
 * longest sum of consecutive primes */
int32_t find_longest_prime_sum(void)
{
	int32_t i, j, n_primes, longest_length, longest_sum, sum, *primes;

	/* count number of primes */
	n_primes = 0;
	for (i = 0; i < N; ++i)
		if (sieve[i])
			++n_primes;

	/* regroup primes into a single array */
	primes = malloc(sizeof *primes * n_primes);
	for (i = j = 0; i < N; ++i)
		if (sieve[i])
			primes[j++] = i;

	longest_sum = longest_length = 0;
	for (i = 0; i < n_primes; ++i)
	{
		sum = 0;
		for (j = i; j < n_primes; ++j)
		{
			sum += primes[j];

			if (sum > N)
				break;

			/* current sum is a prime and longer than current known
			 * longest sequence. Save its statistics. */
			if (sieve[sum] && j - i > longest_length)
			{
				longest_length = j - i;
				longest_sum = sum;
			}
		}
	}

	return longest_sum;
}

int32_t main(void)
{
	init_sieve();
	printf("Problem 50: %d\n", find_longest_prime_sum());

	return 0;
}
