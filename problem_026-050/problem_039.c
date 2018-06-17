#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAX 1000
#define max(a,b) (((a)>(b))?(a):(b))

int32_t main(void)
{
	int32_t a, b, c, result;
	int32_t n_solutions[MAX] = {0};

	for (a = 1; a < MAX; ++a)
		for (b = a; b <= MAX - a; ++b)
			for (c = max(a, b); c <= MAX - a - b; ++c)
				if (a*a + b*b == c*c)
					n_solutions[a+b+c]++;

	b = 0;
	for (a = 0; a < MAX; ++a)
		if (n_solutions[a] > b)
		{
			b = n_solutions[a];
			result = a;
		}

	printf("%d\n", result);
	return 0;
}
