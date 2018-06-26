#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAX 5000

/* is_pentagonal: return 1 if N is a pentagonal number, else 0 */
int64_t is_pentagonal(int64_t N)
{
	/* If N is a pentagonal number, there exists an integer n such that
	 * N = P(n) = (3n^2 - n) / 2
	 *
	 * So n is a solution of the equation 3n^2 - n - 2N = 0.
	 * We have D = (-1)^2 - 4(3 * (-2N)) = 24N + 1
	 * Two solutions:
	 *   - X1 = (1 - (sqrt(24N+1) ) / 6
	 *   - X2 = (1 + (sqrt(24N+1) ) / 6
	 *
	 * Only X2 is a positive solution. So if N is a pentagonal number, the
	 * solution X2 must be an integer. */
	double val = (sqrt(24*N+1) + 1) / 6;
	return val == (int) val;
}

int32_t main(void)
{
	int64_t i, j;
	uint64_t min_diff, p[MAX];

	/* pre-compute the first 5000 pentagonal numbers */
	for (i = 1; i < MAX; ++i)
		p[i-1] = i * (3*i - 1) / 2;

	min_diff = INT64_MAX;
	for (j = 1; j < MAX; ++j)
		for (i = j-1; i >= 0; --i)
			if (is_pentagonal(p[j] - p[i]) &&
			    is_pentagonal(p[j] + p[i]) &&
			    p[j] - p[i] < min_diff)
				min_diff = p[j] - p[i];

	printf("Problem 44: %ld\n", min_diff);
	return 0;
}
