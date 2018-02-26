#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Multiply the number represented by ar (1 digit per cell) per n. */
void mutiply(uint8_t* ar, int32_t size, int32_t n)
{
	int32_t carry = 0, s;
	for (int32_t i = 0; i < size; ++i)
	{
		s = ar[i] * n + carry;
		ar[i] = s%10;
		carry = s/10;
	}
}

int32_t main()
{
	/* Use a large array (1 digit per cell) to simulate Big Integers.
	 * 2^10 ~ 10^3 so 2^1000 ~ 10^300, around 300 cells required to store
	 * the big number. */
	int32_t size = 320, power = 1000;
	uint64_t sum = 0;
	uint8_t* number = (uint8_t*) calloc(size, sizeof(uint8_t));
	number[0] = 1;

	while (power--)
		mutiply(number, size, 2);

	while(size--)
		sum += number[size-1];

	printf("Problem 16: %" PRIu64 "\n", sum);
	free(number);
	return 0;
}
