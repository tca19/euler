#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAXLEN  15
#define HASHSIZE 10000

struct permutation
{
	char* repr;          /* string representation of the permutation */
	int8_t count;        /* number of time this permutation has been seen */
	int64_t smallest;    /* smallest integer producing this permutation */
	struct permutation *next; /* pointer to next permutation (in hashtab) */
};

/* hash: return the hash of string s */
uint32_t hash(char *s)
{
	uint32_t hashval;

	for (hashval = 0; *s != '\0'; ++s)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* largest_permutation: return largest permutation formed with digits of n */
char* largest_permutation(int64_t n)
{
	int32_t i, pos;
	int8_t digits[10] = {0};
	char *permutation = malloc(MAXLEN);

	/* count occurrence of each digit (0-9) in n */
	while (n > 0)
	{
		++digits[n%10];
		n /= 10;
	}

	/* add digits into permutation, start with largest digits */
	for (i = 9, pos = 0; i > -1 && pos < MAXLEN; --i)
	{
		if (digits[i] == 0) /* not added if not present in n */
			continue;

		while (digits[i]-- > 0)
			permutation[pos++] = '0' + i;
	}

	permutation[pos] = '\0';
	return permutation;
}

/* insert: insert the largest permutation created with n*n*n into hastab. If
 * already in, increment its count. Return the created or existing permutation
 * produced with n*n*n */
struct permutation* insert(struct permutation **hashtab, int64_t n)
{
	char *representation;
	uint32_t hashval;
	struct permutation *p;

	representation = largest_permutation(n*n*n);
	hashval = hash(representation);

	/* look into hashtab if the representation is already in */
	for (p = hashtab[hashval]; p != NULL; p = p->next)
	{
		if (strcmp(p->repr, representation) == 0) /* found */
		{
			p->count++;
			return p;
		}
	}

	/* not already in, add it at the top of hashtab[hashval] */
	p = (struct permutation *) malloc(sizeof *p);
	p->repr = representation;
	p->count = 1;
	p->smallest = n*n*n;
	p->next = hashtab[hashval];
	hashtab[hashval] = p;
	return p;
}

/* find the smallest cube for which exactly five permutations of its digits are
 * also cube. */
int32_t main(void)
{
	int64_t i;
	struct permutation *current, **hashtab;

	hashtab = calloc(HASHSIZE, sizeof *hashtab);

	for (i = 345; i < HASHSIZE; ++i)
	{
		current = insert(hashtab, i);
		if (current->count == 5)
		{
			printf("Problem 62: %ld\n", current->smallest);
			break;
		}
	}

	return 0;
}
