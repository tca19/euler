#include <stdio.h>
#define MIN 2
#define MAX 100

int main(void)
{
	int a, b, c, i, n, exponent, n_duplicate;
	unsigned char done[MAX-MIN+1] = {0};

	n_duplicate = 0;
	for (a = MIN; a <= MAX; ++a)
	{
		n = a;
		for (b = MIN; b <= MAX; ++b)
		{
			n *= a; /* n = a^b */
			if (n > MAX || done[n-MIN])
				break;

			if (b == 2)
			{
				n_duplicate += MAX/2 - 1;
				continue;
			}

			done[n-MIN] = 1;

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

	n = (MAX-MIN+1) * (MAX-MIN+1);
	printf("Problem 29: %d\n",  n - n_duplicate);

	return 0;
}
