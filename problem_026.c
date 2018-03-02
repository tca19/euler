#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t main()
{
	int32_t MAX = 1000, longest_cycle = 0, answer, remainder, pos, d, i;
	int32_t *already_seen = (int32_t*)calloc(MAX, sizeof(int32_t));

	/* We look for the consecutive remainders of the division 1/d, and for
	 * each remainder, the position at which it was first seen is saved. We
	 * stop once we find a remainder already seen (or there are no more
	 * remainder). The length of the recurring cycle is the difference
	 * between the current position and the saved position for this
	 * remainder. */
	for (d = MAX; d > 1; --d)
	{
		/* For a given d, the number of possible remainders is d-1. So
		 * the recurring cycle length is at most d-1. We are going in
		 * reverse order (from 1000 to 1) so once d-1 < longest_cycle,
		 * it is impossible that the next i has a longer cycle. We can
		 * stop the loop because we have the maximum recurring cycle we
		 * can achieve. */
		if (longest_cycle > d-1) break;

		/* Reset the array indicating the already seen remainders. */
		for (i = 0; i < MAX; ++i) already_seen[i] = 0;

		remainder = 1;
		pos = 0;
		while (already_seen[remainder] == 0 && remainder != 0)
		{
			already_seen[remainder] = pos;
			remainder = (remainder*10)%d;
			++pos;
		}

		if (pos - already_seen[remainder] > longest_cycle)
		{
			longest_cycle = pos - already_seen[remainder];
			answer = d;
		}
	}

	printf("Problem 26: %d\n", answer);
	free(already_seen);
	return 0;
}
