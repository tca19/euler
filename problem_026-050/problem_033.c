#include <stdio.h>
#include <stdint.h>

/* is_curious: return 1 if fraction num/den is a curious fraction (removing one
 * common digit in num and den does not change the value of the fraction) */
int32_t is_curious(int32_t num, int32_t den)
{
	/* num and den are both 2-digits numbers, so num can be written as num =
	 * ab and den = cd. Look if there is a common digit that can be removed
	 * between a,b and c,d. If so, compute fraction with remaining digits
	 * and check if the value of the original fraction has not changed. */
	int32_t a, b, c, d;

	a = num/10;
	b = num%10;
	c = den/10;
	d = den%10;

	/* trivial example, not considered to be a curious fraction */
	if (b == 0 && d == 0)
		return 0;

	if (a == c)
		return (float) b / d == (float) num / den;
	else if (a == d)
		return (float) b / c == (float) num / den;
	else if (b == c)
		return (float) a / d == (float) num / den;
	else if (b == d)
		return (float) a / c == (float) num / den;

	return 0;
}

/* simplify: simplify the fraction num/den (divide by common divisors) */
void simplify(int64_t *num, int64_t *den)
{
	int64_t i;

	for (i = *num; i > 1; --i)
		if (*num%i == 0 && *den%i == 0)
		{
			*num /= i;
			*den /= i;
		}
}

int32_t main(void)
{
	int32_t a, b;
	int64_t num, den;
	num = den = 1;

	for (a = 10; a < 100; ++a)
		for (b = a+1; b < 100; ++b)
			if (is_curious(a, b))
			{
				num *= a;
				den *= b;
			}

	simplify(&num, &den);
	printf("Problem 33: %ld\n", den);

	return 0;
}
