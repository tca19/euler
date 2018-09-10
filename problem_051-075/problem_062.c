#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAXLEN  15
#define MAXSIZE 10000

struct permutation
{
	char* repr;
	int8_t count;
	int64_t smallest;
};

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

/* insert: insert the largest permutation formed by n^3 or increment its count.
 * Return the corresponding index (the one inserted or the ones incremented). */
int32_t insert(struct permutation *ar, int64_t n, int32_t *size)
{
	int32_t i;
	char *permutation = largest_permutation(n*n*n);

	for (i = 0; i < *size; ++i, ++ar)
		if (strcmp(ar->repr, permutation) == 0)
		{
			ar->count++;
			return i;
		}

	ar->repr = permutation;
	ar->count = 1;
	ar->smallest = n*n*n;
	(*size)++; /* increase size because 1 more element in ar */
	return *size-1;
}

/* find the smallest cube for which exactly five permutations of its digits are
 * also cube. */
int32_t main(void)
{
	int32_t index, size;
	int64_t i;
	struct permutation *list;

	size = 0;
	list = calloc(MAXSIZE, sizeof *list);

	for (i = 345; i < MAXSIZE; ++i)
	{
		index = insert(list, i, &size);
		if (list[index].count == 5)
		{
			printf("Problem 62: %ld\n", list[index].smallest);
			break;
		}
	}

	return 0;
}
