#include <stdio.h>
#include <stdint.h>

/* is_valid: return 1 if n has the form 1_2_3_4_5_6_7_8_9_0 (_ = 1 digit) */
int32_t is_valid(int64_t n)
{
	int32_t i;
	if (n%10 != 0)
		return 0;

	for (i = 9; i > 0; --i)
	{
		n /= 100; /* only 1 out of 2 digits is interesting */
		if (n%10 != i)
			return 0;
	}

	return 1;
}

/* find the unique integer n such that t n*n is like 1_2_3_4_5_6_7_8_9_0 */
int main(void)
{
	int64_t i;

	for (i = 0; ; ++i)
		if (is_valid(i*i))
			break;

	printf("Problem 206: %ld\n", i);
	return 0;
}
