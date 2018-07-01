#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define N 1000000

uint8_t sieve[N];

/* init_sieve: init the array to test primality of numbers with Eratosthenes
 * sieve */
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

/* generate_number: replace '1' in patern with the repeated digit and '0' with a
 * non-repeated digit (e.g. generate_number([1, 0, 0, 1], 4, 7, 19) = 7917 */
int32_t generate_number(uint8_t *pattern, int32_t len,
		        int32_t repeated, int32_t non_repeated)
{
	uint8_t *digits;
	int32_t i, number;

	/* read the pattern, place the digits according to the rule */
	digits = calloc(len, sizeof *digits);
	for (i = 0; i < len; ++i)
	{
		if (pattern[i] == 1)
			digits[i] = repeated;
		else
		{
			digits[i] = non_repeated%10;
			non_repeated /= 10;
		}
	}

	/* create an integer based on the digits array (like [1, 3, 7] -> 137 */
	for (i = 0, number = 0; i < len; ++i)
		number = 10*number + digits[i];
	return number;
}

/* find_family_length: return the family length of pattern i.e. the number of
 * primes generated when the repeated digit goes from 0 to 9, but the
 * non-repeated digits are fixed */
int32_t find_family_length(uint8_t *pattern, int len, int32_t non_repeated)
{
	int32_t fam_length, repeated;

	if (pattern[0] == 1)
		repeated = 1;
	else
		repeated = 0;

	for (fam_length = 0; repeated < 10; ++repeated)
	{
		if (sieve[generate_number(pattern, len, repeated, non_repeated)])
			++fam_length;
	}

	return fam_length;
}

int32_t main(void)
{
	int32_t i, j, k;
	uint8_t patterns[10][6] = {
		{1, 1, 1, 0, 0, 0},
		{1, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 1, 1, 1, 0, 0},
		{0, 1, 1, 0, 1, 0},
		{0, 1, 0, 1, 1, 0},
		{0, 0, 1, 1, 1, 0},
		{1, 0, 0, 1, 1, 0},
		{1, 1, 0, 0, 1, 0},
		{1, 0, 1, 0, 1, 0},
	};

	init_sieve();

	for (i = 0; i < 10; ++i)
	{
		for (j = 100; j < 1000; ++j)
		{
			if (find_family_length(patterns[i], 6, j) == 8)
				printf("%d %d %d\n", generate_number(patterns[i], 6, k, j), k, j);
		}

	}

	printf("%d\n", find_family_length(patterns[9], 6, 332));
	printf("is prime: %d\n", sieve[929393]);

	return 0;
}

