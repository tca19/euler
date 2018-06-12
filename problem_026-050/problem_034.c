#include <stdio.h>
#include <stdint.h>

#define MAX 2177280

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

	for (n = 3, answer = 0; n <= MAX; ++n)
		if (is_sum_factorial(n))
			answer += n;

	printf("Problem 34: %d\n", answer);
	return 0;
}
