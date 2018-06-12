#include <stdio.h>
#include <stdint.h>

/* The upper search bound is 2540160. If the upper bound has 6 digits, the
 * maximum factorial sum that can be obtained is 6*9! = 2177280 > 999999. So
 * every numbers between 1 and 999999 can be a curious number. If the upper
 * bound has 7 digits, the maximum achievable sum is 7*9! = 2540160, so all
 * the numbers after 2540160 can not be a curious number as the sum of the
 * factorial of its digits will be less than 2540160 so less than itself
 * (therefore not equal).
 */
#define MAX 2540160

int32_t factorial[] = {
	1,        /* 0! */
	1,        /* 1! */
	2,        /* 2! */
	6,        /* 3! */
	24,       /* 4! */
	120,      /* 5! */
	720,      /* 6! */
	5040,     /* 7! */
	40320,    /* 8! */
	362880    /* 9! */
};

/* is_sum_factorial: return 1 if n is equal to the sum of the factorial of its
 * digits. */
int32_t is_sum_factorial(int32_t n)
{
	int32_t sum, i;

	for (sum = 0, i = n; n != 0; n /= 10)
		sum += factorial[n%10];
	return sum == i;
}

int32_t main(void)
{
	int32_t n, answer;

	/* start at 3 because 1! and 2! are no included according to the problem
	 * statement. */
	for (n = 3, answer = 0; n <= MAX; ++n)
		if (is_sum_factorial(n))
			answer += n;

	printf("Problem 34: %d\n", answer);
	return 0;
}
