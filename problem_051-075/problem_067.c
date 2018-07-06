#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define FILENAME "problem_051-075/p067_triangle.txt"

int32_t main()
{
	/* Read file to get the numbers forming the triangle (100 rows) */
	FILE *fo;
	int32_t i, j, **triangle;

	if ((fo = fopen(FILENAME, "r")) == NULL)
	{
		printf("error: can't open %s\n", FILENAME);
		return -1;
	}

	/* Parse each line of file. Line 1 has 1 integer, line 2 has 2 integers,
	 * ... line 100 has 100 integers */
	triangle = calloc(SIZE, sizeof *triangle);
	for (i = 0; i < SIZE; ++i)
	{
		triangle[i] = calloc(i+1, sizeof **triangle);
		for (j = 0; j < i+1; ++j)
			fscanf(fo, "%d", &triangle[i][j]);
	}

	/* At each number, we have 2 choice : left or right. So at each number,
	 * the maximum path either comes from left or right value. We go in
	 * reverse order, starting at bottom row and going to the top. For each
	 * number, we add the value of the longest path between value left or
	 * right. The final answer is the value at the top of the pyramid. */
	for (int32_t i = SIZE-2; i > -1; --i)
		for (int32_t j = 0; j < i+1; ++j)
			triangle[i][j] += (triangle[i+1][j] > triangle[i+1][j+1]) ?
			                   triangle[i+1][j] : triangle[i+1][j+1];

	printf("Problem 67: %d\n", triangle[0][0]);
	return 0;
}
