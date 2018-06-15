#include <stdio.h>
#include <stdint.h>

/* is_pandigital: return 1 if the concatenation of mul1, mul2 and product
 * contains all the digits from 1 to 9 only once (and there is no 0). */
int32_t is_pandigital(int32_t mul1, int32_t mul2, int32_t product)
{
	/* count occurrence of each digit */
	int32_t counter[10] = {0};
	int32_t i;

	for (; mul1 > 0; mul1 /= 10)
		++counter[mul1%10];
	for (; mul2 > 0; mul2 /= 10)
		++counter[mul2%10];
	for (; product > 0; product /= 10)
		++counter[product%10];

	/* look if each digit only appears once */
	for (i = 1; i < 10; ++i)
		if (counter[i] != 1)
			return 0;

	/* there should be no 0 to be pandigital */
	return counter[0] == 0;
}

int32_t main(void)
{
	/* The only triplets a,b,c such that a*b = c is pandigital are like :
	 *   - n * nnnn = nnnn (9 digits in total)
	 *   - nn * nnn = nnnn (9 digits in total)
	 *
	 * Since such triplets must be only counted once, there is an array
	 * `done` to know which triplets are already counted. */
	int32_t a, b, c, answer = 0;
	int8_t done[10000] = {0};

	for (a = 1; a < 10; ++a)
		for (b = 1000; b < 10000; ++b)
			if (is_pandigital(a, b, c=a*b) && !done[c])
			{
				answer += c;
				done[c] = 1;
			}

	for (a = 10; a < 100; ++a)
		for (b = 100; b < 1000; ++b)
			if (is_pandigital(a, b, c=a*b) && !done[c])
			{
				answer += c;
				done[c] = 1;
			}

	printf("Problem 32: %d\n", answer);
	return 0;
}
