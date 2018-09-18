#include <math.h>
#include <stdio.h>
#include <stdint.h>

#define FILENAME "problem_076-100/p099_base_exp.txt"

/* fint the pair (base,exp) producing the largest value base^exp */
int32_t main(void)
{
	FILE *f;
	int32_t base, exp, index, best_index;
	double val, best_val;

	f = fopen(FILENAME, "r");
	if (f == NULL)
	{
		printf("error: impossible to open " FILENAME ".\n");
		return -1;
	}

	/* init best_* with first pair */
	fscanf(f, "%d,%d", &base, &exp);
	best_val   = (float) exp * log(base);
	best_index = 1; /* when counting line, start at 1, not 0 */

	index = 2;
	while (fscanf(f, "%d,%d", &base, &exp) != EOF)
	{
		val = (float) exp * log(base);
		if (val > best_val)
		{
			best_val   = val;
			best_index = index;
		}
		++index;
	}

	printf("Problem 99: %d\n", best_index);

	fclose(f);
	return 0;
}
