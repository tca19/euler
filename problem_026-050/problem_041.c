#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX 7654321 /* greatest pandigital number that can be prime */

int8_t *sieve;

/* init_sieve: initialize the array to know if a number is prime */
void init_sieve(void)
{
	int32_t i, j;

	/* +1 because there is also the cell for 0. At first, all number are
	 * considered to be prime, except 0 and 1 */
	sieve = malloc((MAX+1) * sizeof *sieve);
	for (i = 0; i <= MAX; ++i)
		sieve[i] = 1;
	sieve[0] = sieve[1] = 0;

	/* each time it finds a prime number, mark all its multiples as
	 * non-prime */
	for (i = 2; i <= MAX; ++i)
		if (sieve[i])
			for (j = 2*i; j <= MAX; j += i)
				sieve[j] = 0;
}

/* is_pandigital: return 1 if n is a pandigital number (use all digits from 1 to
 * k only once, no 0 */
int32_t is_pandigital(int32_t n)
{
	/* count occurrences of each digit in n */
	int8_t digits[10] = {0};

	while (n > 0)
	{
		++digits[n%10];
		n /= 10;
	}

	/* if n is k-pandigital, all occurences of digits from 1 to k are 1.
	 * Find the first digit that has not its occurrence set to 1 */
	for (n = 1; digits[n] == 1; ++n)
		;

	/* all digits after k should have an occurrence set to 0, otherwise it
	 * means that n is not a k-pandigital number */
	for (; n < 10; ++n)
		if (digits[n] != 0)
			return 0;

	/* n should contain no 0 to be pandigital */
	return digits[0] == 0;
}

int32_t main(void)
{
	int32_t i;
	init_sieve();

	/* Numbers that are 9-pandigital can't be prime. The sum of their digits
	 * is 1+2+3+4+5+6+7+8+9 = 45, which is a multiple of 9.
	 *
	 * Numbers that are 8-pandigital can't be prime. The sum of their digits
	 * is 1+2+3+4+5+6+7+8 = 36, which is a multiple of 9.
	 *
	 * So the largest pandigital that can be a prime is 7654321. Start at
	 * this number, go in reverse order, test if prime and pandigital, stops
	 * when it finds such a number. This will be the largest pandigital
	 * prime as no greater number verify the 2 conditions. */
	for (i = MAX; i > 0; --i)
		if (sieve[i] && is_pandigital(i))
		{
			printf("Problem 41: %d\n", i);
			break;
		}

	return 0;
}
