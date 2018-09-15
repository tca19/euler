#include <stdio.h>
#include <stdint.h>

#define MIN(a,b)   (((a)<(b))?(a):(b))
#define SIZE       80 /* input is a 80x80 matrix */
#define FILENAME   "problem_076-100/p081_matrix.txt"

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

	/* each cell is either accessed from left or from top. So at each cell,
	 * the minimal path sum to reach this cell is min(left, top) + value of
	 * this cell. For first line (resp. first column), simply add the value
	 * from left (resp. top) cell. */
	for (i = 1; i < SIZE; ++i)
	{
		matrix[0][i] += matrix[0][i-1]; /* first line */
		matrix[i][0] += matrix[i-1][0]; /* first columne */
	}

	for (i = 1; i < SIZE; ++i)
		for (j = 1; j < SIZE; ++j)
			matrix[i][j] += MIN(matrix[i][j-1],matrix[i-1][j]);

	printf("Problem 81: %d\n", matrix[SIZE-1][SIZE-1]);
	return 0;
}
