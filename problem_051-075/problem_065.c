#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define SIZE 6 /* because need to go to the 100th term */

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

/* continued_fraction: compute n-th term of continued fraction with the coefs */
/*void continued_fraction(int32_t n, int32_t *coef, int32_t *num, int32_t *den)
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
}*/

int32_t main(void)
{
	/*int32_t i, num, den, coefs[SIZE] = {0};*/
	int32_t i;
	int32_t a[SIZE] = {3, 2, 1, 0, 0, 0};
	int32_t b[SIZE] = {6, 5, 4, 0, 0, 0};

	/* init the coef. Start with 2, then pattern is (1,2k,1) repeated */
	/*coefs[0] = 2;
	for (i = 1; i < SIZE; ++i)
	{
		if (i%3 == 2)
			coefs[i] = 2 * (i+1) / 3;
		else
			coefs[i] = 1;
	}*/

	add(a, b, 17);
	for (i = 0; i < 6; ++i)
		printf("%d ", a[i]);
	printf("\n");
	for (i = 0; i < 6; ++i)
		printf("%d ", b[i]);




	/*continued_fraction(10, coefs, &num, &den);
	printf("%d/%d\n", num, den);*/

	return 0;
}
