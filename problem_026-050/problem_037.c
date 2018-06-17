#include <stdio.h>
#include <stdint.h>

#define MAX 1000000

int8_t sieve[MAX];

/* is_truncatable_prime: return 1 if n is a truncatable prime (removing digits
 * from right and left gives also prime numbers, like 3797, 797, 97, 7, 379, 37
 * and 3) */
int32_t is_truncatable_prime(int64_t n)
{
	int64_t m;

	/* remove digits from right */
	for (m = n; m > 0; m /= 10)
		if (!sieve[m])
			return 0;

	/* remove digits from left */
	/* get largest 10^k s.t. 10^k < n < 10^(k+1) */
	for (m = 1; n / m > 10; m *= 10)
		;
	/* remove leftmost digit with n % (10^k), then reduce value of k */
	for (n %= m; n > 0; m /= 10, n %= m)
		if (!sieve[n])
			return 0;

	return 1;
}

void init_sieve(void)
{
	int32_t i, j;

	for (i = 0; i < MAX; ++i)
		sieve[i] = 1;
	sieve[0] = sieve[1] = 0;

	for (i = 2; i < MAX; ++i)
		if (sieve[i])
			for (j = 2*i; j < MAX; j += i)
				sieve[j] = 0;
}

int32_t main(void)
{
	int32_t i, answer;

	init_sieve();
	for (i = 8, answer = 0; i < MAX; ++i)
		if (is_truncatable_prime(i))
			answer += i;

	printf("Problem 37: %d\n", answer);
	return 0;
}
