#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define SIZE 100 /* because need to go to the 100th term */

/* swap: swap the content of arrays a and b */
void swap(int32_t *a, int32_t *b)
{
	int32_t tmp[SIZE];

	memcpy(tmp, a, SIZE * sizeof *a);
	memcpy(a,   b, SIZE * sizeof *b);
	memcpy(b, tmp, SIZE * sizeof *b);
}

/* add: compute x + num/den, store result as a fraction in num and den. Both num
 * and den are arrays representing a number (like [3,2,1] for 123). */
void add(int32_t *num, int32_t *den, int32_t x)
{
	int32_t i, carry;

	/* x + num/den = (x*den + num)/den */
	for (i = 0, carry = 0; i < SIZE; ++i)
	{
		carry += x * den[i] + num[i];
		num[i] = carry%10;
		carry /= 10;
	}
}

/* sum_digits: return the sum of digits in array ar */
int32_t sum_digits(int32_t *ar)
{
	int32_t i, s;

	for (i = 0, s = 0; i < SIZE; ++i)
		s += ar[i];
	return s;
}

/* continued_fraction: compute n-th term of continued fraction with the coefs */
void continued_fraction(int32_t n, int32_t *coef, int32_t *num, int32_t *den)
{
	int32_t i, j;

	if (n < 1)
	{
		printf("error: can't compute a negative n-th term (n=%d)\n", n);
		return;
	}

	/* reset num and den to 0 */
	memset(num, 0, SIZE * sizeof *num);
	memset(den, 0, SIZE * sizeof *den);

	/* copy coef[n-1] into num */
	for (i = 0, j = coef[n-1]; j > 0 && i < SIZE; ++i, j /= 10)
		num[i] = j%10;

	/* init den to 1 */
	den[0] = 1;

	for (i = n-2; i >= 0; --i)
	{
		swap(num, den);
		add(num, den, coef[i]);
	}
}

/* find the sum of digits in the 100th term of continued fraction of e */
int32_t main(void)
{
	int32_t i, num[SIZE], den[SIZE], coefs[SIZE];

	/* init the coef. Start with 2; then pattern is (1,2k,1) repeated */
	coefs[0] = 2;
	for (i = 1; i < SIZE; ++i)
	{
		if (i%3 == 2)
			coefs[i] = 2 * (i+1) / 3;
		else
			coefs[i] = 1;
	}

	/* compute the 100th term, num and den values are set in function */
	continued_fraction(100, coefs, num, den);

	printf("Problem 65: %d\n", sum_digits(num));
	return 0;
}
