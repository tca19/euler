#include <stdio.h>
#include <stdint.h>

#define N 1000000

uint8_t number_prime_factor[N];

/* init_NPF: initialize the Number of Prime Factor (NPF) array. */
void init_NPF(void)
{
	uint32_t i, j;

	/* similar to Eratosthene sieve. Initialize all numbers with 0 prime
	 * factors counter. Goes from 2 to N. If the current number has 0 prime
	 * factor, it means it's a prime, so increment the counter for all
	 * multiples of this prime (e.g. 2 is prime so every even number has
	 * at least 2 as a prime factor).
	 */
	for (i = 0; i < N; ++i)
		number_prime_factor[i] = 0;

	for (i = 2; i < N; ++i)
		if (number_prime_factor[i] == 0)
			for (j = 2*i; j < N; j += i)
				++number_prime_factor[j];
}

/* find the first 4 consecutive integers that have 4 different prime factors */
int32_t main(void)
{
	int32_t i;

	init_NPF();
	for (i = 0; i < N-4; ++i)
	{
		if (number_prime_factor[i] != 4)
			continue;
		if (number_prime_factor[i+1] != 4)
			continue;
		if (number_prime_factor[i+2] != 4)
			continue;
		if (number_prime_factor[i+3] != 4)
			continue;
		break;
	}

	printf("Problem 47: %d\n", i);
	return 0;
}
