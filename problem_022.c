#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_VOCAB_SIZE 6000

int32_t main()
{
	/* Open file. */
	FILE *file = fopen("p022_names.txt", "r");
	if (file == NULL)
	{
		printf("[ERROR] Impossible to open p022_names.txt, exiting.\n");
		return 1;
	}

	/* Parse and store names. */
	uint8_t **names, MAX_LENGTH = 50, l = 0;
	int32_t n_words = 0, c;
	names    = (uint8_t**)calloc(MAX_VOCAB_SIZE, sizeof(uint8_t*));
	names[0] = (uint8_t*)calloc(MAX_LENGTH, sizeof(uint8_t));

	while ((c = fgetc(file)) != EOF)
	{
		if (c == ',') /* word separator */
		{
			l = 0;
			names[++n_words] = (uint8_t*)calloc(MAX_LENGTH, sizeof(uint8_t));
		}

		else if (c == '"')
			continue;
		else
			names[n_words][l++] = c;
	}

	/* no ',' after last word, but counter needs to be incremented. */
	++n_words;

	printf("n_words: %d\n", n_words);

	/* Clear allocated memory. */
	for (int32_t i = 0; i < n_words; ++i) free(names[i]);
	free(names);
	fclose(file);

	return 0;
}
