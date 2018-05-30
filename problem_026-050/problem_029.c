#include <stdio.h>
#include <stdint.h>

#define MIN 2
#define MAX 100

int32_t main(void)
{
	int32_t a, b, c, i, n, exponent, n_duplicate;
	uint8_t done[MAX-MIN+1] = {0};

	/* Instead of counting the number of distinct terms, we count the number
	 * of duplicates. If there were no duplicates, there would be
	 * (MAX-MIN+1)^2 terms.
	 *
	 * A duplicate term verifies a^k = n^c, with a != n. If we consider a<n,
	 * this means that n is a power of a so n could be written as a^b and
	 * a^k = (a^b)^c = a^(b*c). So we iterate through all numbers that can
	 * be written a^b (in increasing order). For each one, we iterate
	 * c from MIN to MAX and count the number of time (a^b)^c is a
	 * duplicate (i.e. it can be written as a^k).
	 */
	n_duplicate = 0;
	for (a = MIN; a <= MAX; ++a)
	{
		n = a;
		for (b = MIN; b <= MAX; ++b)
		{
			n *= a; /* n = a^b */

			if (n > MAX || done[n-MIN])
				break;

			done[n-MIN] = 1;

			/* if n is a square but no a cube, fourth power... its
			 * exponent is 2. It is a duplicate for c = 1..MAX/2-1
			 * because (a^2)^k = a^(2*k) and 2*k < MAX */
			if (b == 2)
			{
				n_duplicate += MAX/2 - 1;
				continue; /* move to next a^b candidate */
			}

			/* n is cube or fourth power or fifth power... of a. We
			 * iterate each power of n, find the corresponding
			 * exponent of a (because n^c = (a^b)^c = a^(b*c) and
			 * look if it is possible to have the same value a^(b*c)
			 * with a different combination of a^b. In that case it
			 * means it's a duplicate. */
			for (c = MIN; c <= MAX; ++c)
			{
				exponent = b * c;
				if (exponent <= MAX)
				{
					++n_duplicate;
					continue;
				}

				for (i = MIN; i < b; ++i)
					if (!(exponent%i) && exponent/i <= MAX)
					{
						++n_duplicate;
						break;
					}
			}
		}
	}

	n = (MAX-MIN+1) * (MAX-MIN+1); /* #unique a^b if no duplicate */
	printf("Problem 29: %d\n",  n - n_duplicate);

	return 0;
}
