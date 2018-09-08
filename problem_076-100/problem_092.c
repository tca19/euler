#include <stdio.h>
#include <stdint.h>

#define MAX 10000000

int32_t square_digits(int32_t n)
{
	int32_t res = 0;

	while (n > 0)
	{
		res += (n%10) * (n%10);
		n /= 10;
	}

	return res;
}

int32_t chain_contains_89(int32_t n)
{
	while (n != 1 && n != 89)
		n = square_digits(n);

	return n == 89;
}

int32_t main(void)
{
	int32_t i, count = 0;

	for (i = 1; i < MAX; ++i)
	{
		if (chain_contains_89(i))
			++count;
	}

	printf("Problem 92: %d\n", count);
	return 0;
}
