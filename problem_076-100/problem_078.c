#include <stdio.h>
#include <stdint.h>

#define LIM 60000
#define MOD 1000000 /* 10^6 */

int32_t main(void)
{
	int32_t i, j, partitions[LIM+1];

	partitions[0] = 1;
	for (i = 1; i < LIM; ++i)
		for (j = i; j <= LIM; ++j)
		{
			partitions[j] += partitions[j-i];
			partitions[j] %= MOD;
		}

	for (i = 0; i <= LIM; ++i)
		if ((partitions[i] % 1000000) == 0)
		{
			printf("Problem 78: %d\n", i);
			break;
		}

	return 0;
}
