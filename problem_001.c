#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

int main()
{
	uint32_t MAX = 999; /* below 1000 = not equal to 1000 */

	/* answer is the sum of all multiples of 3 + the sum of all multiples of
	 * 5 minus the sum of all multiples of 15 (because we add them twice).
	 *
	 * Sum of all multiples of k is given with:
	 *
	 *   s_k = (first multiple + last multiple) * (nb of multiple) / 2
	 */

	uint64_t s_3  = (3 + (MAX - MAX%3)) * (MAX/3) / 2;
	uint64_t s_5  = (5 + (MAX - MAX%5)) * (MAX/5) / 2;
	uint64_t s_15 = (15 + (MAX - MAX%15)) * (MAX/15) / 2;

	uint64_t answer = s_3 + s_5 - s_15;
	printf("Problem 1: %" PRIu64 "\n", answer);

	return 0;
}
