#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

int32_t main()
{
	uint64_t answer = 0, sum_powers, i, n, d;

	for (i = 2; i < 1000000; ++i)
	{
		n = i; /* copy because we need to modify it */
		sum_powers = 0;

		/* for each digit d of i, compute d^5 then add it to the sum of
		 * digit powers */
		while (n > 0)
		{
			d = n%10;
			n /= 10;
			d = d*d*d*d*d;
			sum_powers += d;
		}

		if (sum_powers == i)
			answer += i;
	}

	printf("Problem 30: %" PRIu64 "\n", answer);
	return 0;
}
