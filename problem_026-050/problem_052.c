#include <stdio.h>
#include <stdint.h>

/* is_permutation: return 1 if b is a permutation of a, 0 otherwise */
int32_t is_permutation(int32_t a, int32_t b)
{
	/* count the occurrence of each digit of a and b. They are permutation
	 * if they have the same number of occurrence of each digit */
	uint8_t i, digits_a[10] = {0}, digits_b[10] = {0};

	while (a > 0)
	{
		++digits_a[a%10];
		a /= 10;
	}

	while (b > 0)
	{
		++digits_b[b%10];
		b /= 10;
	}

	for (i = 0; i < 10; ++i)
		if (digits_a[i] != digits_b[i])
			return 0;

	return 1;
}

/* find the smallest integer n such that 2n, 3n, 4n, 5n and 6n are all
 * permutations of n */
int32_t main(void)
{
	int32_t n;

	for (n = 1; ; ++n)
		if (is_permutation(n, 2*n)
		 && is_permutation(n, 3*n)
		 && is_permutation(n, 4*n)
		 && is_permutation(n, 5*n)
		 && is_permutation(n, 6*n))
		{
			printf("Problem 52: %d\n", n);
			break;
		}

	return 0;
}
