#include <stdio.h>
#include <stdint.h>

#define M 10000000000
#define LEN 10

/* multiply: mutiply the number represented by the array of `digits` by `m` */
void multiply(uint8_t *digits, int32_t m)
{
	int32_t i, carry;

	carry = 0;
	for (i = 0; i < LEN; ++i)
	{
		carry = digits[i] * m + carry;
		digits[i] = carry%10;
		carry /= 10;
	}
}

int32_t main(void)
{
	uint8_t ar[LEN] = {0};
	int32_t i, power = 7830457;
	int64_t answer = 0;

	ar[0] = 1;
	while (power-- > 0)
		multiply(ar, 2);

	multiply(ar, 28433);

	for (i = 0; i < LEN; ++i)
		answer = 10 * answer + ar[LEN-1 - i];

	printf("Problem 97: %ld\n", (answer+1) % M);
	return 0;
}
