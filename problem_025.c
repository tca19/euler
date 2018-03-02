#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/* Copy array a to array b. */
void copy(uint8_t* a, uint8_t* b, int32_t size)
{
	for (int32_t i = 0; i < size; ++i) b[i] = a[i];
}

/* Add array a to array b (cell by cell, propagate carry if any). */
void add(uint8_t* a, uint8_t* b, int32_t size)
{
	int32_t carry = 0, d;
	for (int32_t i = 0; i < size; ++i)
	{
		d = a[i] + b[i] + carry;
		b[i] = d%10;
		carry = d/10;
	}
}

int32_t main()
{
	int32_t SIZE = 1000, n;
	uint8_t *a, *b, *c;
	a = (uint8_t*)calloc(SIZE, sizeof(uint8_t));
	b = (uint8_t*)calloc(SIZE, sizeof(uint8_t));
	c = (uint8_t*)calloc(SIZE, sizeof(uint8_t));

	a[0] = 1; /* 1st Fibonacci term */
	b[0] = 1; /* 2nd Fibonacci term */

	n = 2;
	while (b[SIZE-1] == 0) /* last cell is 0 => b has not enough digits */
	{
		/* a,b becomes b,(a+b) */
		copy(b, c, SIZE);
		add(a, b, SIZE);
		copy(c, a, SIZE);
		++n;
	}

	printf("Problem 25: %d\n", n);

	free(a);
	free(b);
	free(c);
	return 0;
}
