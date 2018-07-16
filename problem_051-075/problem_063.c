#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define LEN 200

/* multiply_and_sum: multiply n by m where each digit of n is stored in a
 * different cell of array digits[]. n is stored in reverse order (1234 is
 * stored as [4,3,2,1]). */
void multiply(int32_t *digits, int32_t m)
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

int32_t main(void)
{
	printf("Problem 63: %d\n", 0);
	return 0;
}
