#include <stdio.h>
#include <stdint.h>

#define SIZE 200000

int32_t contains(int64_t *ar, int64_t v, int32_t size)
{
	while (size-- > 0)
		if (*ar++ == v)
			return 1;
	return 0;
}

int32_t main(void)
{
	int64_t triangular[SIZE], pentagonal[SIZE], hexagonal[SIZE];
	int32_t i;

	for (i = 1; i < SIZE; ++i)
		triangular[i] = i * (i+1) / 2;
	for (i = 1; i < SIZE; ++i)
		pentagonal[i] = i * (3*i - 1) / 2;
	for (i = 1; i < SIZE; ++i)
		hexagonal[i] = i * (2*i - 1);

	for (i = 1; i < SIZE; ++i)
	{
		if (contains(pentagonal, hexagonal[i], SIZE))
			printf("%ld\n", hexagonal[i]);
	}

	return 0;
}
