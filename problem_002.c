#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	/* 1   2   3   5   8   13   21   34   55
	 *     E           E              E
	 *
	 * even (E) Fibonacci numbers happen every 4 numbers. So we can compute and
	 * sum only those numbers instead of computing them all. We also have:
	 *
	 * a   b  (a+b)  (a+2b)  (2a+3b)
	 *     E                    E
	 */

	uint64_t MAX = 4000000, answer = 0;
	uint64_t a = 1, b = 2, temp;

	while (b < MAX)
	{
		answer += b;
		temp = a + 2*b;
		b = temp + a + b;
		a = temp;
	}

	printf("Problem 2: %" PRIu64 "\n", answer);

	return 0;
}
