#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

int32_t main()
{
	/* We need to add the 4 numbers in the corner of each square. If the
	 * square has a side of length n, then top-rigth corner is n^2, top-left
	 * corner is n^2-(n-1), bottom-left corner is n^2-2(n-1) and
	 * bottom-right corner is n^2-3(n-1). So when we increase the spiral
	 * size with 1 square, we add 4n^2 - 6(n-1) to the answer. */
	uint64_t answer, n;

	answer = 1; /* center of grid, need to be added to the sum. */

	/* Size increases by 2 at each new square, until we reach a size of 1001
	 * by 1001. */
	for (n = 3; n < 1002; n += 2) answer += 4*n*n - 6*(n-1);

	printf("Problem 28: %" PRIu64 "\n", answer);
	return 0;
}
