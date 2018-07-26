#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define FILENAME "problem_076-100/p079_keylog.txt"

int32_t main(void)
{
	FILE *fp;
	int32_t val;

	if ((fp = fopen(FILENAME, "r")) == NULL)
	{
		printf("error: can't open %s\n", FILENAME);
		exit(1);
	}

	while (fscanf(fp, "%d", &val) != EOF)
		printf("%d\n", val);

	return 0;
}
