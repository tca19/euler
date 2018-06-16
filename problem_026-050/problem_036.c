#include <stdio.h>
#include <stdint.h>

#define MAX 1000000

/* is_palindrom: return 1 if n is a palindrom in base ̣`base` */
int32_t is_palindrom(int32_t n, int32_t base)
{
	int32_t m, p;

	m = n;   /* copy n because need to modify it */
	for (p = 0; n > 0; n /= base)
		p = base * p + n%base;

	return p == m;
}

int32_t main(void)
{
	int i, answer;

	for (i = 1, answer = 0; i < MAX; ++i)
		if (is_palindrom(i, 10) && is_palindrom(i, 2))
			answer += i;

	printf("Problem 36: %d\n", answer);

	return 0;
}
