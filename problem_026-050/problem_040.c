#include <stdio.h>
#include <stdint.h>

#define MAX 1000000

/* d: return the n-th digit of 0.1234567891011121314... */
int32_t d(int32_t n)
{
	/* The Champernowne's constant can be seen as:
	 *   - a block of all 1-digit numbers: 1 2 3 4 5 6 7 8 9
	 *   - a block of all 2-digits numbers: 10 11 12 13....98 99
	 *   - a block of all 3-digits numbers: 100 101 102...998 999
	 *   - a block of all 4-digits numbers: 1000 1001...9998 9999
	 *   - ...
	 *
	 * The first block has 9 numbers, so its length is 9 * 1 = 9
	 * The second block has 90 numbers, its length is 90 * 2 = 180
	 * The third block has 900 numbers, its length is 900 * 3 = 2700...
	 *
	 * The first step is to find the block where the n-th digit is located.
	 * Then find the number that has the n-th digit. */
	int32_t block_length, digit, number, i;

	if (n < 10)       /* simple case, the n-th number is n when n < 10 */
		return n;

	for (block_length = 9, digit = 1;
	     n > block_length * digit;
	     n -= block_length * digit, block_length *= 10, ++digit)
		;

	/* block_length/9 is the starting number of the block (like 100 for
	 * the 3rd block). Since all numbers of this block have the same number
	 * of digits, the n-th digit is in start + n/digit number. */
	number = block_length / 9 + n / digit;

	/* The correct digit is the (n%digit)-th digit of ̣̣̣̣`number`. Instead of
	 * taking the (n%digit)-th digit, take the digit - (n%digit) (easier,
	 * simply remove trailing digits by dividing by 10). */
	for (i = 0; i < digit - n%digit; ++i)
		number /= 10;
	return number%10;
}

int32_t main(void)
{
	int32_t i, answer;

	for (answer = 1, i = 1; i <= MAX; i *= 10)
		answer *= d(i);
	printf("Problem 40: %d\n", answer);

	return 0;
}
