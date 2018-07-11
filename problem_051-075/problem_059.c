#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t *text;
int32_t size;

/* read_ciphered_text: read the ciphered text in `filename` into the global
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

	/* start by counting the number of char to allocate enough memory */
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

int32_t count_occurrence(int32_t *s, int32_t len, int32_t *sub, int32_t sub_len)
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
	int32_t KEYSIZE = 3;
	char key[KEYSIZE+1];
	int32_t *deciphered_text;
	int32_t a, b, c;
	int32_t sub[] = {'t', 'h', 'e'};
	int32_t answer = 0;

	read_ciphered_text("problem_051-075/p059_cipher.txt");
	deciphered_text = calloc(size, sizeof *deciphered_text);

	key[3] = '\0';
	for (a = 0; a < 26; ++a)
		for (b = 0; b < 26; ++b)
			for (c = 0; c < 26; ++c)
			{
				key[0] = 'a' + a;
				key[1] = 'a' + b;
				key[2] = 'a' + c;
				decipher(deciphered_text, key, KEYSIZE);
				if (count_occurrence(deciphered_text, size, sub, 3) > 3)
				{
					printf("%s %d\n", key,
					count_occurrence(deciphered_text, size, sub, 3));
				}
			}


	decipher(deciphered_text, "god", KEYSIZE);
	print_deciphered(deciphered_text);

	for (a = 0; a < size; ++a)
		answer += deciphered_text[a];

	printf("Problem 59: %d\n", answer);
	return 0;
}
