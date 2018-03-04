#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

int32_t main()
{
	uint64_t answer, n;

	answer = 1;
	for (n = 3; n <= 1001; n += 2)
	{
		answer += 4*n*n - 6*(n-1);
	}

	printf("Problem 28: %" PRIu64 "\n", answer);
	return 0;
}
