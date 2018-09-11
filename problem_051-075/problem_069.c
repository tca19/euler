#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAX 1000000

/* phi: return the Euler's Totient function value of n */
float phi(int32_t n)
{
	int32_t p;
	float result = (float) n;

	/* use the formula phi(n) = prod_{p prime divisor of n} (1 - 1/p)
	 * Each prime divisor is only counted once */
	for (p = 2; p * p <= n; ++p)
	{
		if (n%p == 0)
		{
			result *= (1.0 - 1.0 / p);
			while (n%p == 0)
				n /= p;
		}
	}

	/* if n has a prime divisor greater than sqrt(n), it is unique (there
	 * can't be more than one prime divisor greater than sqrt(n) */
	if (n > 1)
		result *= (1.0 - 1.0 / n);

	return result;
}

/* find the number n below 1M such that the ratio n/phi(n) is the largest */
int32_t main(void)
{
	int32_t n, p, max_val;
	float max_ratio;

	max_val = -1;
	max_ratio = 0.0;
	for (n = 2; n < MAX; ++n)
	{
		p = phi(n);
		if ( (float) n / p > max_ratio)
		{
			max_ratio = (float) n / p;
			max_val = n;
		}
	}

	printf("Problem 62: %d\n", max_val);
	return 0;
}

