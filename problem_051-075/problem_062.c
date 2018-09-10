#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAXLEN  20
#define MAXSIZE 20000

struct pair
{
	char* permutation;
	int32_t count;
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

/* insert: insert permutation in table ar. If already in, return its
 * count */
int32_t insert(struct pair *ar, char *permutation, int64_t n, int32_t *size)
{
	int32_t i;
	for (i = 0; i < *size; ++i)
		if (strcmp(ar[i].permutation, permutation) == 0)
		{
			ar[i].count++;
			return i;
		}

	ar[*size].permutation = permutation;
	ar[*size].count = 1;
	ar[*size].smallest = n*n*n;
	(*size)++; /* increase size because have put 1 more element in ar */
	return *size-1;
}

/* find the smallest cube for which exactly five permutations of its digits are
 * also cube. */
int32_t main(void)
{
	int32_t index, size;
	int64_t i;
	struct pair *list;

	size = 0;
	list = calloc(MAXSIZE, sizeof *list);
	for (i = 345; i < MAXSIZE; ++i)
	{
		index = insert(list, largest_permutation(i*i*i), i, &size);
		if (list[index].count == 5)
		{
			printf("Problem 62: %ld\n", list[index].smallest);
			break;
		}
	}

	return 0;
}
