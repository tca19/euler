#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

int32_t main()
{
	/* iterate over all (a, b, c) triples verifying a+b+c = 1000, keep the
	 * one that also verify Pythagor relation */
	int32_t MAX = 1000, a, b, c, product;

	for (a = 0; a < MAX; ++a)
		for (b = a+1; b < MAX; ++b)
		{
			c = MAX - a - b;
			if (a*a + b*b == c*c)
				product = a*b*c;
		}

	printf("Problem 9: %d\n", product);
	return 0;
}
