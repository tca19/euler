#include <stdio.h>
#include <stdint.h>

char *read_cypher(char *filename)
{
	/* count number of char un cyphered text */
	char c;
	int32_t len, value;
	FILE *fi;

	if ((fi = open(filename, "r")) == NULL)
	{
		printf("Impossible to read the cyphered text.*\n);
		return -1;
	}


	len = 0,
	while ((c = getchar()) != NULL)
	{

	}
