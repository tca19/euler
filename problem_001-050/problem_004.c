#include <stdint.h>
#include <stdio.h>

/* indicates if n is a palindromic number. */
int32_t is_palindrom(int32_t n)
{
	int32_t original = n, reversed = 0;
	while (n > 0)
	{
		reversed = reversed*10 + n%10;
		n /= 10;
	}

	return original == reversed;
}

int32_t main()
{
	/* compute the product of all 3-digit numbers, keep the largest
	 * palindromic one. */
	int32_t answer = -1, product;
	for (int32_t i = 100; i < 1000; ++i)
	{
		for (int32_t j = i; j < 1000; ++j)
		{
			product = i * j;
			if (is_palindrom(product) && product > answer)
				answer = product;
		}
	}

	printf("Problem 4: %d\n", answer);
	return 0;
}
