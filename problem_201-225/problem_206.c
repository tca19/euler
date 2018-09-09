#include <stdio.h>
#include <stdint.h>

int32_t is_valid(int64_t n)
{
	int32_t i;
	if (n%10 != 0)
		return 0;

	for (i = 9; i > 0; --i)
	{
		n /= 100;
		if (n%10 != i)
			return 0;
	}

	return 1;
}

int main(void)
{
	int64_t i;

	for (i = 0; ; ++i)
		if (is_valid(i*i))
			break;

	printf("Problem 206: %ld\n", i);
	return 0;
}
