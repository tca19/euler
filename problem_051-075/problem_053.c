#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define N 100
#define MAX 1000000

/* count the number of binomial coefficients C(n, k) that are larger than 1M
 * when n goes from 1 to 100 */
int32_t main(void)
{
	/* use the recursive formula C(n, k) = C(n-1, k) + C(n-1, k-1) to
	 * compute the binomial coefficients. Need to store the previously
	 * computed coefficients, use an array of N+1 x N+1 (easier for
	 * indexing, binomial coefficient of C(23, j) will be stored in
	 * binomial[23][j] rather than binomial[22][j]) */
	int32_t i, j, answer, binomial[N+1][N+1] = {0};

	answer = 0;
	binomial[1][0] = binomial[1][1] = 1;

	for (i = 2; i <= N; ++i)
	{
		binomial[i][0] = 1;
		for (j = 1; j < i; ++j)
		{
			binomial[i][j] = binomial[i-1][j] + binomial[i-1][j-1];

			/* if binomial[i][j] is larger than 1M, no need to
			 * compute the other coefficients. Since
			 * binomial[i][j] = binomial[i][i-j], the coefficients
			 * larger than 1M are those between j and i-j */
			if (binomial[i][j] > MAX)
			{
				answer += i-j - j + 1;
				break;
			}
		}
		binomial[i][i] = 1;
	}

	printf("Problem 53: %d\n", answer);
	return 0;
}
