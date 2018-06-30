#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define N 1000000

uint8_t sieve[N];

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

int32_t generate_number(uint8_t *pattern, int32_t len,
		        int32_t repeated, int32_t non_repeated)
{
	uint8_t *digits;
	int32_t i, number;

	digits = calloc(len, sizeof *digits);

	for (i = 0; i < len; ++i)
	{
		if (pattern[i] == 0)
			digits[i] = repeated;
		else
		{
			digits[i] = non_repeated%10;
			non_repeated /= 10;
		}
	}

	for (i = 0, number = 0; i < len; ++i)
		number = 10*number + digits[i];
	return number;
}

int32_t find_family_length(uint8_t *pattern, int len,
		           int32_t repeated, int32_t non_repeated)
{
	int32_t length;

	for (length = 0; repeated < 10; ++repeated)
	{
		if (sieve[generate_number(pattern, len, repeated, non_repeated)])
		{
			printf("got prime %d (repeated=%d, non=%d\n",
			       generate_number(pattern, len, repeated, non_repeated),
			       repeated, non_repeated);
			++length;
		}
		else
			break;
	}

	return length;
}

int32_t main(void)
{
	int32_t i, j, k;
	uint8_t patterns[10][6] = {
		{0, 0, 0, 1, 1, 1},
		{0, 0, 1, 0, 1, 1},
		{0, 1, 0, 0, 1, 1},
		{1, 0, 0, 0, 1, 1},
		{1, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 1},
		{1, 1, 0, 0, 0, 1},
		{0, 1, 1, 0, 0, 1},
		{0, 0, 1, 1, 0, 1},
		{0, 1, 0, 1, 0, 1},
	};

	init_sieve();

	for (i = 0; i < 10; ++i)
	{
		for (j = 100; j < 1000; ++j)
		{
			for (k = 0; k <= 2; ++k)
			{
				if (find_family_length(patterns[i], 6, k, j) == 8)
					printf("%d %d %d\n", generate_number(patterns[i], 6, k, j), k, j);
			}
		}
	}

	printf("%d\n", find_family_length(patterns[9], 6, 1, 332));
	printf("is prime: %d\n", sieve[727373]);

	return 0;
}

