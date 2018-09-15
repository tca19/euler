#include <stdio.h>
#include <stdint.h>

#define SIZE     80 /* input is a 80x80 matrix */
#define FILENAME "problem_076-100/p081_matrix.txt"

/* find the minimal path sum when moving down/right in matrix (from TL to BR) */
int32_t main(void)
{
	FILE *f;
	int32_t i, j, matrix[SIZE][SIZE];

	f = fopen(FILENAME, "r");
	if (f == NULL)
	{
		printf("Error: impossible to open " FILENAME ".\n");
		return 1;
	}

	/* read input file to get values in matrix (file is CSV) */
	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j)
			fscanf(f, "%d,", &matrix[i][j]);

	fclose(f);
	return 0;
}
