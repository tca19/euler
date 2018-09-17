#include <stdio.h>
#include <stdint.h>

#define FILENAME "problem_076-100/p099_base_exp.txt"

int32_t main(void)
{
	FILE *f;
	int32_t base, exp, i, best_index;
	float best_result, result;

	f = fopen(FILENAME, "r");
	if (f == NULL)
	{
		printf("error: impossible to open " FILENAME ".\n");
		return -1;
	}

	while (fscanf(f, "%d,%d", &base, &exp) != EOF)
		printf("%d %d\n", base, exp);

	return 0;
}
