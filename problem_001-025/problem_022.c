#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VOCAB_SIZE 6000

/* Function used by qsort to sort alphabetically names. */
int32_t cmp_names(const void *a, const void *b)
{
	return strcmp(*(const char **) a, *(const char **) b);
}

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

	while ((c = getc(file)) != EOF)
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

	/* No ',' after last word, but counter needs to be incremented. */
	++n_words;

	/* Sort words alphabetically. */
	qsort(names, n_words, sizeof(const uint8_t*), cmp_names);

	/* Compute total sum of scores of all names. */
	uint64_t total = 0, score;
	for (int32_t pos = 0; pos < n_words; ++pos)
	{
		score = 0;
		for (int32_t i = 0; names[pos][i] != 0; ++i)
			score += names[pos][i] - 'A' + 1;

		total += score * (pos+1);
	}

	printf("Problem 22: %" PRIu64 "\n", total);

	/* Clear allocated memory. */
	for (int32_t i = 0; i < n_words; ++i) free(names[i]);
	free(names);
	fclose(file);

	return 0;
}
