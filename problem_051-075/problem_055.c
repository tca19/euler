#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define SIZE 40  /* 50 iterations will use numbers with at most 40 digits */
#define N 10000  /* count the Lychrel numbers from 1 to 10'000 */

/* is_palindrom: return 1 if array ar is palindromic, 0 otherwise */
int32_t is_palindrom(uint8_t *ar, int32_t len)
{
	int32_t i;
	for (i = 0; i <= len/2; ++i)
		if (ar[i] != ar[len-1-i])
			return 0;
	return 1;
}

/* sum_reverse: compute n + reverse(n) where digits of n are stored in ar[].
 * Store result in sum[]. Return the number of digits in sum[] */
int32_t sum_reverse(uint8_t *ar, uint8_t *sum, int32_t len)
{
	int32_t carry, i;

	for (i = 0, carry = 0; i < len; ++i)
	{
		carry += ar[i] + ar[len-1 - i];
		sum[i] = carry%10;
		carry /= 10;
	}

	while (carry > 0)
	{
		sum[i++] = carry%10;
		carry /= 10;
	}

	return i;
}

/* is_lychrel: return 1 if n is a Lychrel number (summing n and reverse(n) gives
 * a palindromic number) or n+reverse(n) is a Lychrel number. Return 0 otherwise
 * (not a Lychrel number, even after 50 iterations). */
int32_t is_lychrel(int32_t n)
{
	uint8_t digits[SIZE] = {0}, sum[SIZE] = {0};
	int32_t n_iter, i;

	/* store digits of n into an array */
	for (i = 0; n > 0; ++i)
	{
		digits[i]  = n%10;
		n /= 10;
	}

	for (n_iter = 0; n_iter < 50; ++n_iter)
	{
		i = sum_reverse(digits, sum, i);

		if (is_palindrom(sum, i))
			return 1;

		memcpy(digits, sum, i * sizeof(uint8_t));
		memset(sum, 0, i * sizeof(uint8_t));
	}

	return 0;
}

/* print the number of non-Lychrel numbers between 1..10'000 */
int32_t main(void)
{
	int32_t i, answer = 0;

	for (i = 0; i < N; ++i)
		if (!is_lychrel(i))
			++answer;

	printf("Problem 55: %d\n", answer);
	return 0;
}
