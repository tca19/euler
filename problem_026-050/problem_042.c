#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAXLEN 100

/* word_value: return the sum of each letter value in string s */
int32_t word_value(char *s)
{
	int32_t val;

	for (val = 0; *s != '\0'; ++s)
		val += (*s - 'A' + 1);
	return val;
}

/* is_triangular: return 1 if n is a triangular number (it can be written as
 * m(m+1) / 2 ) */
int32_t is_triangular(int32_t n)
{
	int32_t m = (int32_t) sqrt(n*2);
	return m*(m+1) / 2 == n;
}

/* read_word: read a word from a file that is like "A","ABILITY","ABLE"... */
int32_t read_word(FILE *fp, char *dest)
{
	int32_t c;

	/* skip quotes and comma */
	while ((c = fgetc(fp)) != EOF && !isupper(c))
		;
	*dest++ = c;

	/* read letters until it finds a comma or a quote */
	while ((c = fgetc(fp)) != EOF && isupper(c))
		*dest++ = c;
	*dest = '\0';

	return c;
}

int32_t main(void)
{
	FILE *fp;
	char word[MAXLEN];
	int32_t answer = 0;

	fp = fopen("problem_026-050/p042_words.txt", "r");
	while (read_word(fp, word) != EOF)
		if (is_triangular(word_value(word)))
			++answer;

	printf("Problem 42: %d\n", answer);
	return 0;
}
