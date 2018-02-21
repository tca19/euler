#include <stdio.h>
#include <stdint.h>

int32_t main()
{

	/* answer is the least common multiple of all integers from 2 to 20. We
	 * find it with : p1^m1 * p2^m2 [...] where pi are prime numbers and mi
	 * are the greatest exponent for each pi among the prime factor
	 * decomposition of integers between 2 and 20.
	 */
	int32_t N = 20;
	int32_t primes[8] = {2, 3, 5, 7, 11, 13, 17, 19}; /* primes below 20 */
	int32_t powers[8] = {0, 0, 0, 0,  0,  0,  0,  0};

	for (int32_t i = 2; i < N+1; ++i)
	{
		/* for each integer i, for each prime primes[k], find its
		 * exponent in prime decomposition of i. */
		int32_t j = i, p;
		for (int32_t k = 0; k < 8; k++)
		{
			p = 0;
			while (j > 0 && j%primes[k] == 0)
			{
				++p;
				j /= primes[k];
			}

			/* save exponent if greater than current one */
			if (p > powers[k]) powers[k] = p;
		}
	}

	/* compute p1^m1 * p2^m2 * [...] */
	int32_t answer = 1;
	for (int32_t k = 0; k < 8; ++k)
		while (powers[k]-- > 0)
			answer *= primes[k];

	printf("Problem 5: %d\n", answer);
	return 0;
}
