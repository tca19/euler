#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAX 1000
#define max(a,b) (((a)>(b))?(a):(b))

int32_t main(void)
{
	/* iterate over all (a,b,c) triplets such that a^2 + b^2 = c^2. For each
	 * triplet, increase the counter of a+b+c. Print the perimeter which
	 * have the largest amount of triplets */
	int32_t a, b, c, answer;
	int32_t n_triples[MAX] = {0};

	/* c is greater than a and b, so at least equal to max(a, b) */
	for (a = 1; a < MAX; ++a)
		for (b = a; b <= MAX - a; ++b)
			for (c = max(a, b); c <= MAX - a - b; ++c)
				if (a*a + b*b == c*c)
					n_triples[a+b+c]++;

	b = answer = 0;
	for (a = 0; a < MAX; ++a)
		if (n_triples[a] > n_triples[answer])
			answer = a;

	printf("Problem 39: %d\n", answer);
	return 0;
}
