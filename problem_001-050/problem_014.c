#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t main()
{
	/* Compute the length of Collatz sequence for each integer under 1M. Save
	 * the sequence lengths for fast retrieval - so no need to recompute the
	 * whole sequence everytime. */
	uint64_t N = 1000000, longest = 0, answer, n, i, s;
	uint64_t *lengths = (uint64_t*) calloc(N, sizeof(uint64_t));
	for (i = 0; i < N; ++i)
		lengths[i] = 0;

	for (i = 1; i < N+1; ++i)
	{
		n = i; /* need a copy because we are going to modify it */
		s = 1; /* initial sequence length */

		while (n > 1)
		{
			/* look if we already know the length of sequence
			 * starting at n */
			if (n < N && lengths[n-1] > 0)
			{
				s += lengths[n-1] - 1;
				break;
			}

			/* else, compute new term and increment sequence length */
			if (n&1)
				n = 3*n + 1;
			else
				n >>= 1;
			++s;
		}

		lengths[i-1] = s;

		if (s > longest)
		{
			longest = s;
			answer = i;
		}
	}

	printf("Problem 14: %" PRIu64 "\n", answer);
	free(lengths);
	return 0;
}
