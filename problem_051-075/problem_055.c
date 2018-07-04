#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define LEN 200
#define N 10000

/* is_palindrom: return 1 if array ar is palindromic, 0 otherwise */
int32_t is_palindrom(uint8_t *ar, int32_t len)
{
	int32_t i;
	for (i = 0; i <= len/2; ++i)
		if (ar[i] != ar[len-1-i])
			return 0;
	return 1;
}

/* is_lychrel: return 1 if n is a Lychrel number (summing n and reverse(n) gives
 * a palindromic number) or n+reverse(n) is a Lychrel number. Return 0 otherwise
 * (not a Lychrel number, even after 50 iterations). */
int32_t is_lychrel(int32_t n)
{
	uint8_t digits[LEN] = {0}, sum[LEN] = {0};
	int32_t carry, iteration, i, j;

	/* store digits of n into an array */
	for (i = 0; n > 0; ++i)
	{
		digits[i]  = n%10;
		n /= 10;
	}

	/* compute n+reverse(n) */
	for (j = 0, carry = 0; j != i; j++)
	{
		carry += digits[j] + digits[i-1-j];
		sum[j] = carry%10;
		carry /= 10;
	}
	while (carry > 0)
	{
		sum[j++] = carry%10;
		carry /= 10;
	}

	if (is_palindrom(sum, j))
		return 1;

	iteration = 1;
	while (iteration < 51)
	{
		memcpy(digits, sum, LEN * sizeof(uint8_t));
		memset(sum, 0, LEN * sizeof(uint8_t));
		i = j;

		/* compute n+reverse(n) */
		for (j = 0, carry = 0; j != i; j++)
		{
			carry += digits[j] + digits[i-1-j];
			sum[j] = carry%10;
			carry /= 10;
		}
		while (carry > 0)
		{
			sum[j++] = carry%10;
			carry /= 10;
		}

		if (is_palindrom(sum, j))
			return 1;

		++iteration;
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
