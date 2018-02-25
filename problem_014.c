#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

int32_t main()
{
	/* for each integer i under 1M, compute the length of its Collatz
	 * sequence.  Only save the integer with the longest sequence. */
	uint64_t longest = 0, answer, n, i, s;

	for (i = 1; i < 1000001; ++i)
	{
		n = i; /* need a copy because we are going to modify it. */
		s = 1; /* initial sequence length */
		while (n > 1)
		{
			if (n&1)
				n = 3*n + 1;
			else
				n >>= 1;
			++s;
		}

		if (s > longest)
		{
			longest = s;
			answer = i;
		}
	}

	printf("Problem 14: %" PRIu64 "\n", answer);
	return 0;
}
