#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50
#define MAX 30

/* multiply: mutiply the number represented by the array of `digits` by `m` */
void multiply(uint8_t *digits, int32_t m)
{
	int32_t i, carry;

	carry = 0;
	for (i = 0; i < LEN; ++i)
	{
		carry = digits[i] * m + carry;
		digits[i] = carry%10;
		carry /= 10;
	}
}

/* n_digits: return the number of digits in `digits`. (123 is stored as [3, 2,
 * 1, 0, ... 0]) */
int32_t n_digits(uint8_t *digits)
{
	int32_t i;

	for (i = LEN-1; digits[i] == 0; --i)
		;
	return i+1;
}

/* find the number of time n^power is a power-digit number */
int32_t main(void)
{
	uint8_t ar[LEN] = {0};
	int32_t n, power, answer;

	answer = 0;
	for (n = 1; n < MAX; ++n)
	{
		/* reset array with 0, initialize it with 1 */
		memset(ar, 0, LEN * sizeof *ar);
		ar[0] = 1;

		/* compute the successive power of n */
		for (power = 1; power < MAX; ++power)
		{
			multiply(ar, n);
			if (n_digits(ar) == power)
				++answer;
		}

	}

	printf("Problem 63: %d\n", answer);
	return 0;
}
