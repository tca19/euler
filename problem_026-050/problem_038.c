#include <stdio.h>
#include <stdint.h>

int32_t is_pandigital(int64_t n)
{
	int8_t digits[10] = {0};

	while (n > 0)
	{
		++digits[n%10];
		n /= 10;
	}

	for (n = 1; n < 10; ++n)
		if (digits[n] != 1)
			return 0;

	return digits[0] == 0;
}

int64_t concatenate_products(int64_t n)
{
	int64_t i, d, product = n;

	for (i = 2; product <= 100000000; ++i)
	{
		d = i * n;
		while (d > 0)
		{
			product = product * 10;
			d /= 10;
		}
		product += i * n;
	}

	return product;
}

int32_t main(void)
{
	int64_t i, p, maximum = 0;

	for (i = 1; i < 100000; ++i)
	{
		p = concatenate_products(i);
		if (is_pandigital(p) && p > maximum)
			maximum = p;
	}

	printf("Problem 38: %ld\n", maximum);
	return 0;
}

