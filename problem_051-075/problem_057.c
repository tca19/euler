#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* at most 400 digits in numerator or denominator */
#define LEN 400

/* add: add b to a. Both are represented as an array of digits, in reverse order
 * (123 is [3, 2, 1]) */
void add(uint8_t *a, uint8_t *b)
{
	int32_t i, carry;

	for (i = 0, carry = 0; i < LEN; ++i)
	{
		carry += a[i] + b[i];
		a[i] = carry%10;
		carry /= 10;
	}
}

/* n_digits: count the number of digits in a (array of digits) */
int32_t n_digits(uint8_t *a)
{
	int32_t i;

	/* find the right-most digit that is non zero */
	for (i = LEN-1; a[i] == 0 && i > 0; --i)
		;
	return i;
}

/* compute the 1000 first expansions of sqrt(2). Find the number of time the
 * numerator has more digits than the denominator */
int32_t main(void)
{
	uint8_t *num, *den, *tmp;;
	int32_t iter, answer;

	num = calloc(LEN, sizeof *num);
	den = calloc(LEN, sizeof *den);
	tmp = calloc(LEN, sizeof *tmp);

	/* 3/2 is the first expansion of sqrt(2), given in problem statement */
	num[0] = 3;
	den[0] = 2;
	iter = 1;
	answer = 0;

	while (iter++ < 1000)
	{
		/* at step n:
		 *   num/den
		 *
		 * at step n+1:
		 *   1 + 1/(num/den + 1) = 1 + 1/((num+den)/den)
		 *                       = 1 + den/(num+den)
		 *                       = (num+den+den) / (num+den)
		 */
		memcpy(tmp, num, LEN * sizeof *tmp);
		add(num, den);
		add(num, den);
		add(den, tmp);

		if (n_digits(num) > n_digits(den))
			++answer;
	}

	printf("Problem 57: %d\n", answer);
	return 0;
}
