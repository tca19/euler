#include <stdint.h>
#include <stdio.h>
#define SIZE 15

int32_t main()
{
	/* At each number, we have 2 choice : left or right. So at each number,
	 * the maximum path either comes from left or right value. We go in
	 * reverse order, starting at bottom row and going to the top. For each
	 * number, we add the value of the longest path between value left or
	 * right. The final answer is the value at the top of the pyramid. */
	int32_t triangle[SIZE][SIZE] = {
		{75,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{95, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{17, 47, 82,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{18, 35, 87, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{20, 04, 82, 47, 65,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{19, 01, 23, 75, 03, 34,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{88, 02, 77, 73, 07, 63, 67,  0,  0,  0,  0,  0,  0,  0,  0},
		{99, 65, 04, 28, 06, 16, 70, 92,  0,  0,  0,  0,  0,  0,  0},
		{41, 41, 26, 56, 83, 40, 80, 70, 33,  0,  0,  0,  0,  0,  0},
		{41, 48, 72, 33, 47, 32, 37, 16, 94, 29,  0,  0,  0,  0,  0},
		{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,  0,  0,  0,  0},
		{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,  0,  0,  0},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,  0,  0},
		{63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,  0},
		{04, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60, 04, 23}
	};

	for (int32_t i = SIZE-2; i > -1; --i)
		for (int32_t j = 0; j < i+1; ++j)
			triangle[i][j] += (triangle[i+1][j] > triangle[i+1][j+1]) ?
			                   triangle[i+1][j] : triangle[i+1][j+1];

	printf("Problem 18: %d\n", triangle[0][0]);
	return 0;
}
