#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX 7654321

int8_t *sieve;

void init_sieve(void)
{
	int32_t i, j;

	sieve = malloc((MAX+1) * sizeof *sieve);
	for (i = 0; i <= MAX; ++i)
		sieve[i] = 1;
	sieve[0] = sieve[1] = 0;

	for (i = 2; i <= MAX; ++i)
		if (sieve[i])
			for (j = 2*i; j <= MAX; j += i)
				sieve[j] = 0;
}

int32_t is_pandigital(int64_t n)
{
	int8_t digits[10] = {0};

	while (n > 0)
	{
		++digits[n%10];
		n /= 10;
	}

	for (n = 1; digits[n] == 1; ++n)
		;
	for (; n < 10; ++n)
		if (digits[n] != 0)
			return 0;

	return digits[0] == 0;
}

int32_t main(void)
{
	int32_t i;
	init_sieve();

	for (i = MAX; i > 0; --i)
		if (sieve[i] && is_pandigital(i))
		{
			printf("Problem 41: %d\n", i);
			break;
		}

	return 0;
}
