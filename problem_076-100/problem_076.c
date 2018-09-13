#include <stdio.h>
#include <stdint.h>

#define MAXINT 100

int32_t main(void)
{
	int32_t i, j;
	int32_t ways[MAXINT+1] = {0};

	ways[0] = 1;
	for (i = 1; i < MAXINT; ++i)
	{
		for (j = i; j <= MAXINT; ++j)
			ways[j] += ways[j-i];

	}

	printf("Problem 76: %d\n", ways[MAXINT]);
	return 0;
}
