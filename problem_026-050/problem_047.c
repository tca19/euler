#include <stdio.h>
#include <stdint.h>

#define N 1000000

uint8_t sieve[N];

/* init_sieve: initialize the array to test if a number is prime. */
void init_sieve(void)
{
	uint32_t i, j;

	/* at first, every integer is considered to be prime, except 0 and 1 */
	for (i = 0; i < N; ++i)
		sieve[i] = 1;
	sieve[0] = sieve[1] = 0;

	for (i = 2; i < N; ++i)
		if (sieve[i]) /* prime, mark all its multiples as non prime */
			for (j = 2*i; j < N; j += i)
				sieve[j] = 0;
}

/* number_prime_factor: return the number of different prime factor of n */
int32_t number_prime_factor(int64_t n)
{
	int32_t i = n, n_factor = 0;

	while (i > 1)
	{
		if (sieve[i] && n % i == 0)
		{
			++n_factor;
			while (n % i == 0)
				n /= i;
		}
		--i;
	}

	return n_factor;
}

/* find the first 4 consecutive integers that have 4 different prime factors */
int32_t main(void)
{
	int32_t i;

	init_sieve();
	for (i = 0; i < N-4; ++i)
	{
		if (number_prime_factor(i) != 4)
			continue;
		if (number_prime_factor(i+1) != 4)
			continue;
		if (number_prime_factor(i+2) != 4)
			continue;
		if (number_prime_factor(i+3) != 4)
			continue;
		break;
	}

	printf("Problem 47: %d\n", i);

	return 0;
}
