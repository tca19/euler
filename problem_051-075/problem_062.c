#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXLEN 20

/* largest_permutation: return largest permutation formed with digits of n */
char* largest_permutation(int64_t n)
{
	int32_t i, j;
	int8_t digits[10] = {0};
	char *permutation = malloc(MAXLEN);

	/* count digits of n */
	while (n > 0)
	{
		++digits[n%10];
		n /= 10;
	}

	/* add digits into permutation starting with largest digits */
	for (i = 9, j = 0; i > -1 && j < MAXLEN; --i)
	{
		if (digits[i] == 0)
			continue;

		while (digits[i]-- > 0)
			permutation[j++] = '0' + i;
	}

	permutation[j] = '\0';
	return permutation;
}

/* find the smallest cube for which exactly five permutations of its digits are
 * also cube. */
int32_t main(void)
{
	printf("%s\n", largest_permutation(345*345*345));
	printf("%s\n", largest_permutation(405*405*405));

	return 0;
}
