#include <stdio.h>
#include <stdint.h>

#define N 10000

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

/* is_goldbach: return 1 if n respects the Goldbach conjecture (can be written
 * as the sum of a prime and twice a square), 0 otherwise. */
int32_t is_goldbach(int32_t n)
{
	int32_t i;

	for (i = 1; i*i*2 < n; ++i)
		if (sieve[n - i*i*2])
			return 1;

	return 0;
}

/* print the smallest odd non-prime number that does not respect Goldbach's
 * conjecture */
int32_t main(void)
{
	int32_t i;
	init_sieve();

	/* last given example is 33, so start at next odd number */
	for (i = 35; i < N; i += 2)
		if (!sieve[i] && !is_goldbach(i))
		{
			printf("Problem 46: %d\n", i);
			break;
		}

	return 0;
}
