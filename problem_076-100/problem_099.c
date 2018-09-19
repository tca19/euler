#include <math.h>
#include <stdio.h>
#include <stdint.h>

#define FILENAME "problem_076-100/p099_base_exp.txt"

/* fint the pair (base,exp) producing the largest value base^exp */
int32_t main(void)
{
	/* computing the value base^exp for each pair is not feasible in
	 * resonable time (some values have 3 million digits). So instead of
	 * finding the largest base^exp, it applies the log function and finds
	 * the largest log(base^exp) = exp * log(base). Since log is strictly
	 * increasing, it preserves the order (so if base1^exp1 > base2^exp2,
	 * then log(base1^exp1) > log(base2^exp2) */
	FILE *f;
	int32_t base, exp, index, largest_index;
	double val, largest_val;  /* save largest log(base^exp) and its index */

	f = fopen(FILENAME, "r");
	if (f == NULL)
	{
		printf("error: impossible to open " FILENAME ".\n");
		return -1;
	}

	/* init largest_* with first pair of input file */
	fscanf(f, "%d,%d", &base, &exp);
	largest_val   = (float) exp * log(base);
	largest_index = 1; /* when counting line, start at 1, not 0 */

	index = 2;
	while (fscanf(f, "%d,%d", &base, &exp) != EOF)
	{
		val = (float) exp * log(base);
		if (val > largest_val)
		{
			largest_val   = val;
			largest_index = index;
		}
		++index;
	}

	printf("Problem 99: %d\n", largest_index);

	fclose(f);
	return 0;
}
