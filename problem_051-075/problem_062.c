#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAXLEN  15
#define HASHSIZE 10000

struct permutation
{
	char* repr;
	int8_t count;
	int64_t smallest;
	struct permutation *next;
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

struct permutation* insert(struct permutation **hashtab, int64_t n)
{
	char *representation;
	uint32_t hashval;
	struct permutation *p;

	representation = largest_permutation(n*n*n);
	hashval = hash(representation);

	/* never added the representation into hashtab, so add it */
	if (hashtab[hashval] == NULL)
	{
		p = (struct permutation *) malloc(sizeof *p);
		p->repr = representation;
		p->count = 1;
		p->smallest = n*n*n;
		p->next = NULL;
		hashtab[hashval] = p;
		return p;
	}

	/* hashval has already been seen, look if already in hashtab */
	for (p = hashtab[hashval]; p != NULL; p = p->next)
	{
		if (strcmp(p->repr, representation) == 0) /* found */
		{
			p->count++;
			return p;
		}
	}

	/* not already in, add it at top of hashtab[hashval] */
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
