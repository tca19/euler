#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define KEYSIZE 3

int32_t *text;
int32_t size;

/* read_ciphered_text: read the ciphered text from `filename` into the global
 * variable `̣text`. Set the global variable `size` with the text length */
void read_ciphered_text(char *filename)
{
	char c;
	int32_t i;
	FILE *fp;

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Impossible to read the ciphered text.\n");
		size = 0;
	}

	/* start by counting the number of chars to allocate enough memory. The
	 * file is composed of ascii values separated by commas, so count the
	 * number of commas to get the number of ascii values */
	size = 0;
	while ((c = fgetc(fp)) != EOF)
		if (c == ',')
			++size;
	++size; /* because last ascii value not counted (no ',' after it) */

	/* read each ascii value, store it in text */
	text = calloc(size, sizeof *text);
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < size; ++i)
		fscanf(fp, "%d,", &text[i]);
}

void decipher(int32_t *deciphered_text, char *key, int32_t key_size)
{
	int32_t i;

	for (i = 0; i < size; ++i)
		deciphered_text[i] = text[i] ^ key[i%key_size];
}

int32_t count_occurrence(int32_t *s, int32_t len, char *sub, int32_t sub_len)
{
	int32_t i, j, count = 0;

	for (i = 0; i < len-sub_len+1; ++i)
	{
		for (j = 0; j < sub_len && s[i+j] == sub[j]; ++j)
			;
		if (j == sub_len)
			++count;
	}
	return count;
}

void print_deciphered(int32_t *deciphered_text)
{
	int32_t i;

	for (i = 0; i < size; ++i)
		printf("%c", deciphered_text[i]);
	printf("\n");
}

int32_t main(void)
{
	char key[KEYSIZE], best_key[KEYSIZE];
	char the[] = {'t', 'h', 'e'};
	int32_t i, j, k, n, *deciphered_text, max_count_occ, answer;

	read_ciphered_text("problem_051-075/p059_cipher.txt");
	deciphered_text = calloc(size, sizeof *deciphered_text);

	answer = max_count_occ = 0;
	for (i = 0; i < 26; ++i)
	{
		key[0] = 'a' + i;
		for (j = 0; j < 26; ++j)
		{
			key[1] = 'a' + j;
			for (k = 0; k < 26; ++k)
			{
				key[2] = 'a' + k;
				decipher(deciphered_text, key, KEYSIZE);
				n = count_occurrence(deciphered_text, size, the, 3);
				if (n > max_count_occ)
				{
					printf("ok with %d\n", max_count_occ);
					memcpy(best_key, key, KEYSIZE);
					max_count_occ = n;
				}
			}
		}
	}


	printf("%s\n", key);

	for (i = 0; i < size; ++i)
		answer += deciphered_text[i];

				if (count_occurrence(deciphered_text, size, the, 3) > 3)
	printf("Problem 59: %d\n", answer);
	return 0;
}
