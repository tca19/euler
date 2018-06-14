#include <stdio.h>
#include <stdint.h>

int32_t is_pandigital(int32_t multiplicand, int32_t multiplier, int64_t product)
{
	int32_t digits[10] = {0};
	int32_t i;

	while (multiplicand > 0)
	{
		++digits[multiplicand%10];
		multiplicand /= 10;
	}

	while (multiplier > 0)
	{
		++digits[multiplier%10];
		multiplier /= 10;
	}

	while (product > 0)
	{
		++digits[product%10];
		product /= 10;
	}

	for (i = 1; i < 10; ++i)
		if (digits[i] != 1)
			return 0;
	return digits[0] == 0;
}

int32_t main(void)
{
	int32_t a, b, answer = 0;
	int8_t done[10000] = {0};

	for (a = 1; a < 10; ++a)
		for (b = 1000; b < 10000; ++b)
			if (is_pandigital(a, b, a*b) && !done[a*b])
			{
				answer += a*b;
				done[a*b] = 1;
			}

	for (a = 10; a < 100; ++a)
		for (b = 100; b < 1000; ++b)
			if (is_pandigital(a, b, a*b) && !done[a*b])
			{
				answer += a*b;
				done[a*b] = 1;
			}

	printf("Problem 32: %d\n", answer);
	return 0;
}
