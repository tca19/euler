#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>   /* calloc */
#include <string.h>   /* memset */

#define SIZE 10000

int8_t sieve[SIZE];

void init_sieve(void)
{
	int32_t i, j;

	memset(sieve, 1, SIZE * sizeof sieve[0]);
	sieve[0] = sieve[1] = 0;

	for (i = 2; i < SIZE; ++i)
		if (sieve[i])
			for (j = 2*i; j < SIZE; j += i)
				sieve[j] = 0;
}

int32_t is_prime(int32_t n)
{
	int32_t i;

	if (n%2 == 0)
		return 0;

	if (n < SIZE)
		return sieve[n];

	for (i = 3; i*i <= n; i += 2)
		if (sieve[i] && n%i == 0)
			return 0;

	return 1;
}

int32_t concatenate(int32_t n, int32_t m)
{
	int32_t i, copy_m;

	for (i = 1, copy_m = m; copy_m > 0; i *= 10)
		copy_m /= 10;
	return n*i + m;
}

int32_t is_prime_pair(int32_t p1, int32_t p2)
{
	return is_prime(concatenate(p1, p2)) && is_prime(concatenate(p2, p1));
}

int32_t main(void)
{
	int8_t *pairs;
	int32_t i, j;
	int32_t a, b, c, d, e;
	int32_t answer;


	init_sieve();

	pairs = calloc(SIZE*SIZE, sizeof *pairs);
	for (i = 0; i < SIZE; ++i)
	{
		if (!is_prime(i))
			continue;

		for (j = i+1; j < SIZE; ++j)
		{
			if (!is_prime(j))
				continue;

			if (is_prime_pair(i, j))
			{
				pairs[i*SIZE + j] = 1;
				pairs[j*SIZE + i] = 1;
			}
		}
	}

	answer = 5*SIZE;
	for (a = 0; a < SIZE; ++a)
	{
		if (!is_prime(a))
			continue;

		for (b = a+1; b < SIZE; ++b)
		{
			if (!pairs[a*SIZE + b])
				continue;

			for (c = b+1; c < SIZE; ++c)
			{
				if (!pairs[a*SIZE + c]
				 || !pairs[b*SIZE + c])
					continue;

				for (d = c+1; d < SIZE; ++d)
				{
					if (!pairs[a*SIZE + d]
					 || !pairs[b*SIZE + d]
					 || !pairs[c*SIZE + d])
						continue;

					for (e = d+1; e < SIZE; ++e)
					{
						if (!pairs[a*SIZE + e]
						 || !pairs[b*SIZE + e]
						 || !pairs[c*SIZE + e]
						 || !pairs[d*SIZE + e])
							continue;

						if (a+b+c+d+e < answer)
							answer = a+b+c+d+e;
					}
				}
			}
		}
	}

	printf("Problem 60: %d\n", answer);
	return 0;
}
