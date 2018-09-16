#include <stdio.h>
#include <stdint.h>

/* swap: swap the content of variables a and b */
void swap(int32_t *a, int32_t *b)
{
	int32_t c;

	c = *b;
	*b = *a;
	*a = c;
}

/* add: compute x + num/den, keep result as a fraction, store it in num, den */
void add(int32_t *num, int32_t *den, int32_t *x)
{
	*num += *x * *den;
}

/* continued_fraction: compute n-th term of continued fraction with the coefs */
void continued_fraction(int32_t n, int32_t *coef, int32_t *num, int32_t *den)
{
	int32_t i;

	if (n < 1)
		return;

	*num = coef[n-1];
	*den = 1;
	for (i = n-2; i >= 0; --i)
	{
		swap(num, den);
		add(num, den, &(coef[i]));
	}
}

int32_t main(void)
{
	int32_t num, den;
	int32_t coefs[] = {2, 1, 2, 1, 1, 4, 1, 1, 6, 1};

	continued_fraction(10, coefs, &num, &den);
	printf("%d/%d\n", num, den);

	return 0;
}
