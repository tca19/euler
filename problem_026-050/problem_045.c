#include <stdio.h>
#include <stdint.h>
#include <math.h>

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
	/* Hexagonal numbers are also triangular numbers, so only need to find a
	 * number which is both hexagonal and pentagonal. */

	int64_t i = 144; /* example given is H_143, need to find the next one */
	while (!is_pentagonal(i * (2*i - 1)))
		++i;

	printf("Problem 45: %ld\n", i * (2*i - 1));

	return 0;
}
