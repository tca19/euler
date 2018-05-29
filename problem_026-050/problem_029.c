#include <stdio.h>
#define LOWER 2
#define UPPER 100

int main(void)
{
	int a, b, duplicate, temp;

	duplicate = 0;

	for (a = LOWER; a <= UPPER; ++a)
	{
		temp = a;
		for (b = LOWER; b <= UPPER; ++b)
		{
			temp *= a;
			if (temp > UPPER)
				break;

			printf("a: %d, b: %d, temp: %d, dup: %d\n",
			        a, b, temp, UPPER/b-1);
			duplicate += UPPER / b - 1;
			/* temp can possibly generate duplicates */
		}
	}

	printf("duplicate: %d\n", duplicate);
	printf("max: %d\n", (UPPER-LOWER+1) * (UPPER-LOWER+1));
	printf("unique: %d\n", (UPPER-LOWER+1) * (UPPER-LOWER+1) - duplicate);

	return 0;
}
