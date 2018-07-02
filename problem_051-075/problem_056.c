#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* multiply: multiply n by m where each digit of n is stored in a different cell
 * of digits. n is stored in reverse order (1234 is stored as [4,3,2,1]). */
void multiply(uint8_t *digits, int32_t len, int32_t m)
{
	int32_t i, carry;

	carry = 0;
	for (i = 0; i < len; ++i)
	{
		carry = digits[i] * m + carry;
		digits[i] = carry%10;
		carry /= 10;
	}
}

/* sum: return the sum of all cells of ar */
int32_t sum(uint8_t *ar, int32_t len)
{
	int32_t result = 0;

	while (--len >= 0)
		result += ar[len];
	return result;
}

/* sum the digits of each product a^b, print the largest sum */
int32_t main(void)
{
	uint8_t *digits;
	int32_t a, b, tmp, max_sum;

	digits  = calloc(200, sizeof *digits);
	max_sum = 0;

	for (a = 1; a < 100; ++a)
		for (b = 1; b < 100; ++b)
		{
			/* reset array */
			for (tmp = 0; tmp < 200; ++tmp)
				digits[tmp] = 0;
			digits[0] = 1;

			/* compute a^b */
			tmp = b;
			while (--tmp)
				multiply(digits, 200, a);

			tmp = sum(digits, 200);
			if (tmp > max_sum)
				max_sum = tmp;
		}

	printf("Problem 56: %d\n", max_sum);
	return 0;
}
