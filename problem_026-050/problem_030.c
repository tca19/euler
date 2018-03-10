#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

int32_t main()
{
	uint64_t answer = 0, sum_powers, i, n, d;

	/* We are looking for numbers equal to the sum of the fifth power of its
	 * digits. We need to find the upper bound of these numbers (when we can
	 * stop because next numbers can not validate the rule.
	 *
	 * If the number has 6 digits, then the greatest sum of powers we can
	 * possibly compute is 354294 (6 * 9^5). So every numbers n > 354294 can
	 * not validate the rule (no equality is possible since the sum will
	 * always be lower than n). So we can stop at 354294. */
	for (i = 2; i < 354295; ++i)
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
