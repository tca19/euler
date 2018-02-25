#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

/* return the binomial coefficient C(n,k) (n choose k) */
uint64_t binomial_coef(uint64_t n, uint64_t k)
{
	uint64_t res = 1;

	if (k > n-k)
		k = n-k;

	for(uint64_t i = 0; i < k; ++i)
	{
		res *= (n-i);
		res /= (i+1);
	}

	return res;
}

int32_t main()
{
	/* To move from top left corner to bottom right corner in a 20x20 grid
	 * requires 40 movements (by only going right or down). We need 20 right
	 * movements and 20 down movements. So the anwser is the number of
	 * combinations of choosing 20 right movements among 40 (so it is the
	 * binomial coefficient C(40, 20)). */
	uint64_t answer = binomial_coef(40, 20);
	printf("Problem 15: %" PRIu64 "\n", answer);

	return 0;
}
