#include <stdio.h>
#include <stdint.h>

#define MAX 1000000

int8_t sieve[MAX];

/* rotate: rotate number n by 1-digit to the right (1234 becomes 4123) */
int64_t rotate(int64_t n)
{
	int32_t n_digits, m;

	/* count number of digits in n. The left-most digit d is made of
	 * 10^n_digits * d, so multiply the right-most digit by 10^n_digits */
	m = n;
	for (n_digits = 0; m > 0; m /= 10)
		++n_digits;

	for (m = 1; n_digits > 1; --n_digits)
		m *= 10;

	return m * (n%10) + n/10;
}

/* init_sieve: initialize the prime number grid with Eratosthene sieve */
void init_sieve(void)
{
	int32_t i, j;

	/* at first, all numbers are considered primes, except 0 and 1 */
	for (i = 0; i < MAX; ++i)
		sieve[i] = 1;
	sieve[0] = sieve[1] = 0;

	for (i = 2; i < MAX; ++i)
		if (sieve[i])
			for (j = 2*i; j < MAX; j += i)
				sieve[j] = 0;
}

/* is_circular: return 1 if n is a circular prime (n and all its 1-digit
 * rotations are also primes). */
int32_t is_circular(int64_t n)
{
	int64_t rotated;

	/* n is not prime, can't be a circular prime */
	if (!sieve[n])
		return 0;

	rotated = rotate(n);
	while (rotated != n)
	{
		if (!sieve[rotated])
			return 0;
		rotated = rotate(rotated);
	}

	return 1;
}


int32_t main(void)
{
	int32_t i, answer;

	init_sieve();
	for (i = 0, answer = 0; i < MAX; ++i)
		if (is_circular(i))
			++answer;

	printf("Problem 35: %d\n", answer);
	return 0;
}
