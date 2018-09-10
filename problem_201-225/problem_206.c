#include <stdio.h>
#include <stdint.h>

#define LOW  1010101010
#define HIGH 1389026624

/* is_valid: return 1 if n has the form 1_2_3_4_5_6_7_8_9_0 (_ = 1 digit) */
int32_t is_valid(int64_t n)
{
	int32_t i;
	if (n%10 != 0)
		return 0;

	for (i = 9; i > 0; --i)
	{
		n /= 100; /* only 1 out of 2 digits matters */
		if (n%10 != i)
			return 0;
	}

	return 1;
}

/* find the unique integer n such that n*n is like 1_2_3_4_5_6_7_8_9_0 */
int main(void)
{
	int64_t n;

	/* The lowest possibility for pattern is x1 = 1020304050607080900. Since
	 * this pattern must be n*n, then the lowest possibility for n is
	 * sqrt(x1). The largest possibility for pattern is x2 =
	 * 1929394959697989990. Since this pattern must n*n, then the largest
	 * possibility for n is sqrt(x2).
	 *
	 * n*n must end with 0 (because the given pattern ends with 0). This is
	 * only possible when n%10 = 0. Since LOW already verifies LOW%10 = 10,
	 * increasing step is set to 10. */
        for (n = LOW; n < HIGH; n += 10)
		if (is_valid(n*n))
			break;

	printf("Problem 206: %ld\n", n);
	return 0;
}
