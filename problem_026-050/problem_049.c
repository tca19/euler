#include <stdio.h>
#include <stdint.h>

#define N 10000 /* only need to test 4-digits numbers primality */

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

/* is_permutation: return 1 if b is a permutation of a, 0 otherwise */
int32_t is_permutation(int32_t a, int32_t b)
{
	/* count the occurrence of each digit of a and b. They are permutation
	 * if they have the same number of occurrence of each digit */
	uint8_t i, digits_a[10] = {0}, digits_b[10] = {0};

	while (a > 0)
	{
		++digits_a[a%10];
		a /= 10;
	}

	while (b > 0)
	{
		++digits_b[b%10];
		b /= 10;
	}

	for (i = 0; i < 10; ++i)
		if (digits_a[i] != digits_b[i])
			return 0;

	return 1;
}

/* find the arithmetic sequence of prime 4-digits number that are all
 * permutation of each others (like 1487, 4817, 8147) */
int32_t main(void)
{
	int32_t i, step;

	init_sieve();
	for (i = 1000; i < N; ++i)
	{
		if (i == 1487) /* example given, do not find it again */
			continue;
		if (!sieve[i])
			continue;
		for (step = 1; i + 2*step < N; ++step)
			if (sieve[i+step]     /* sequence terms are prime ... */
			 && sieve[i+2*step]
			 && is_permutation(i, i+step)  /* ... and permutation */
			 && is_permutation(i, i+2*step))
				printf("Problem 49: %d%d%d\n", i, i+step, i+2*step);
	}

	return 0;
}
