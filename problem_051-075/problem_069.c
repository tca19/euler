#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAX 1000000

int32_t gcd(int32_t a, int32_t b)
{
	int32_t tmp;

	while (b)
	{
		tmp = a;
		a = b;
		b = tmp%b;
	}
	return a;
}

float phi(int32_t n)
{
	int32_t p;
	float result = (float) n;

	for (p = 2; p * p <= n; ++p)
	{
		if (n%p == 0)
		{
			result *= (1.0 - 1.0 / p);
			while (n%p == 0)
				n /= p;
		}
	}

	if (n > 1)
		result *= (1.0 - 1.0 / n);

	return result;
}

int32_t main(void)
{
	int32_t n, p, max_val;
	float max_ratio = 0.0;

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

