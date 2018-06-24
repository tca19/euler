#include <stdio.h>
#include <stdint.h>

/* find the sum of all 0-9 pandigital numbers such that:
 * d2 d3 d4 is divisible by 2
 * d3 d4 d5 is divisible by 3
 * d4 d5 d6 is divisible by 5
 * d5 d6 d7 is divisible by 7
 * d6 d7 d8 is divisible by 11
 * d7 d8 d9 is divisible by 13
 * d8 d9 d10 is divisible by 17
 */
int32_t main(void)
{
	/* d4 d5 d6 is divisible by 5 => d6 is 0 or 5
	 *
	 * If d6 is 0, then d6 d7 d8 can be 011, 022, 033 ... 099 (must be
	 * divisible by 11) => impossible because number is pandigital (so no
	 * digit is repeated). d6 must be 5.
	 *
	 * The possibilites for d6 d7 d8 are: 506, 517, 528, ..., 594. If it's
	 * 506 then d9 is 5 (because 0 6 d9 must be divisible by 13) =>
	 * impossible because 5 would be repeated. If it's 517, then there is no
	 * digit such that 1 7 d9 is divisible by 13, so impossible. If it's
	 * 528, then d9 is 6 (286 is divisible by 13). With the same reasoning,
	 * the only choices for d6 d7 d8 d9 are: 5286, 5390, 5728, 5832.
	 *
	 * With the same reasoning for d10, 5832 is impossible (that would give
	 * d10 = 3, and 3 would be reapeated). The choices for d6-d10 are then:
	 * 52867, 53901 and 57289.
	 *
	 * To find d5, we need to find digits X such that X52 or X53 or X57 are
	 * multiples of 7. That gives 952, 553 and 357. Because of repeated 5,
	 * the only choices for d5-d10 are then 952867 and 357289.
	 *
	 * For the first choice, the digits left are: 0, 1, 3 and 4. Since d2 d3
	 * d4 must be divisible by 2, d4 can only be 0 or 4. d4 cannot be 4,
	 * because d3+d4+d5 must be divisible by 3 and given that d5=9, there is
	 * no right choice for d3 to fulfill this condition. So d4 is 0, d3 is 3
	 * (because of divisibility by 3 condition). So d1 d2 can be 14 or 41.
	 * That gives {14, 41}30952867.
	 *
	 * For the second case, the digits left are: 0, 1, 4 and 6. For the same
	 * reasons, d4 can only be 0 or 4 or 6, and also for the same reasons
	 * (divisibility by 3 for d3 d4 d5) it cannot be 4. So either d4 is 0
	 * (and d3 is 6) or d4 is 6 (and d3 is 0). For both cases, d1 d2 can
	 * either be 14 or 41. That gives {14, 41}{60, 06}357289.
	 */
	int64_t answer = 1430952867 + 4130952867 +
	                 1460357289 + 4160357289 +
			 1406357289 + 4106357289;

	printf("Problem 43: %ld\n", answer);
	return 0;
}
