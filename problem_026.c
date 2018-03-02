#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t main()
{
	int32_t MAX = 1000, longest_cycle = 0, answer, remainder, pos, i, j;
	int32_t *already_seen = (int32_t*)calloc(MAX, sizeof(int32_t));

	for (i = MAX; i > 1; --i)
	{
		if (longest_cycle >= i) break;

		/* Reset the array indicating the already seen remainders. */
		for (j = 0; j < MAX; ++j) already_seen[j] = 0;


		remainder = 1;
		pos = 0;
		while (already_seen[remainder] == 0 && remainder != 0)
		{
			already_seen[remainder] = pos;
			remainder = (remainder*10)%i;
			++pos;
		}

		if (pos - already_seen[remainder] > longest_cycle)
		{
			longest_cycle = pos - already_seen[remainder];
			answer = i;
		}
	}

	printf("Problem 26: %d\n", answer);
	free(already_seen);
	return 0;
}
