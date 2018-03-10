#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
	/* find all primes below 1M with the sieve of Eratosthenes */
	uint64_t MAX = 1000000;
	uint8_t  sieve[MAX];
	for (uint64_t i = 0; i < MAX; ++i) sieve[i] = 1;

	for (uint64_t i = 2; i < MAX; ++i)
	{
		if (sieve[i-1])
			for (uint64_t j = 2*i; j < MAX; j += i)
				sieve[j-1] = 0;
	}

	/* test all primes to find the largest one that divides N. Go in reverse
	 * order and stop once we find one = it is the largest */
	uint64_t N = 600851475143, answer;
	for (uint64_t i = MAX-1; i > 0; --i)
	    if (sieve[i] && (N%(i+1) == 0)) /* prime and factor of N */
	    {
		answer = i+1;
		break;
	    }

	printf("Problem 3: %" PRIu64 "\n", answer);
	return 0;
}
