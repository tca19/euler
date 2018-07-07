#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* at most 400 digits in numerator or denominator */
#define LEN 400

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

int32_t n_digits(uint8_t *a)
{
	int32_t i;

	for (i = 0; a[LEN-1 - i] == 0; ++i)
		;
	return LEN - i;
}

int32_t main(void)
{
	uint8_t *num, *den, *tmp;;
	int32_t iter, answer;

	num = calloc(LEN, sizeof *num);
	den = calloc(LEN, sizeof *den);
	tmp = calloc(LEN, sizeof *tmp);

	num[0] = 3;
	den[0] = 2;
	iter = 1;
	answer = 0;

	while (iter++ < 1000)
	{
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
