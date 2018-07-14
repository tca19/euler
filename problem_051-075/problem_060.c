#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX 100000000
#define SIZE 10000

int8_t sieve[MAX];

void init_sieve(void)
{
	int32_t i, j;

	for (i = 0; i < MAX; ++i)
		sieve[i] = 1;
	sieve[0] = sieve[1] = 0;

	for (i = 0; i < MAX; ++i)
		if (sieve[i])
			for (j = 2*i; j < MAX; j += i)
				sieve[j] = 0;
}

int32_t concatenate(int32_t n, int32_t m)
{
	int32_t reverse_m = 0;

	while (m > 0)
	{
		reverse_m = 10*reverse_m + m%10;
		m /= 10;
	}

	while (reverse_m > 0)
	{
		n = 10*n + reverse_m%10;
		reverse_m /= 10;
	}

	return n;
}

int32_t is_prime_pair(int32_t p1, int32_t p2)
{
	return sieve[concatenate(p1, p2)] && sieve[concatenate(p2, p1)];
}

int32_t main(void)
{
	int8_t *pairs;
	int32_t i, j;
	int32_t a, b, c, d, e;
	int32_t answer;


	init_sieve();

	/* initialize graph, edges represent prime pairs */
	pairs = calloc(SIZE*SIZE, sizeof *pairs);
	for (i = 0; i < SIZE; ++i)
	{
		if (!sieve[i])
			continue;

		for (j = i+1; j < SIZE; ++j)
		{
			if (!sieve[j])
				continue;

			if (is_prime_pair(i, j))
			{
				pairs[i*SIZE + j] = 1;
				pairs[j*SIZE + i] = 1;
			}
		}
	}

	/* find clique of size 5 */
	answer = 5*SIZE;
	for (a = 0; a < SIZE; ++a)
	{
		if (!sieve[a])
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
