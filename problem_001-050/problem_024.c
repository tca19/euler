#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Return the factorial of n. */
int32_t factorial(int32_t n)
{
	int32_t p = 1;
	while (n-- > 1) p *= (n+1);
	return p;
}

int32_t main()
{
	/* We want the 1000000th permutation, so we need to skip 999999
	 * permutations, and take the next one. */
	int32_t N = 1000000-1, SIZE = 10, digits_left = SIZE, i, d;
	uint64_t answer = 0;
	uint8_t* digits = (uint8_t*)calloc(SIZE, sizeof(uint8_t));

	/* Fill array with available digits (0 to 9). */
	for (i = 0; i < SIZE; ++i) digits[i] = i;

	/* If there are SIZE digits in the permutation, then once sorted
	 * alphabetically, there are (SIZE-1)! starting with 0, (SIZE-1)!
	 * starting with 1 ...  So we find the first digit of Nth permutation by
	 * selecting the N/(SIZE-1)! among all available digits. Remove this
	 * digit used, then repeat the process with SIZE-2 and N%(SIZE-1)! as N.
	 */
	for (i = 1; i < SIZE; ++i)
	{
		d = N/factorial(SIZE-i);
		N %= factorial(SIZE-i);
		answer = answer*10 + digits[d];

		/* remove the digit used */
		for (int32_t j = d; j < digits_left; ++j)
			digits[j] = digits[j+1];
		--digits_left;

		if (N == 0) /* we skipped all required permutations. */
			break;
	}

	/* Add remaining digits in alphabetical order. */
	for (int32_t j = 0; j < digits_left; ++j)
		answer = answer*10 + digits[j];

	printf("Problem 24: %" PRIu64 "\n", answer);
	free(digits);
	return 0;
}
