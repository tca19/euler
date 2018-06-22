#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAXLEN 100

/* word_value: return the sum of values of each letter of string s */
int32_t word_value(char *s)
{
	int32_t val;

	for (val = 0; *s != '\0'; ++s)
		val += (*s - 'A' + 1);
	return val;
}

/* is_triangular: return 1 if n is a triangular number (it can be written as
 * n(n+1) / 2 */
int32_t is_triangular(int32_t n)
{
	int32_t m = (int32_t) sqrt(n*2);
	return m*(m+1) / 2 == n;
}

int32_t read_word(FILE *fp, char *dest)
{
	int32_t c;

	while (!isupper(c = fgetc(fp)))
		;

	printf("over? %d\n", feof(fp));
	if (c == EOF)
		return EOF;

	/*printf("%c\n", c);*/
	*dest++ = c;
	while (isupper(c = fgetc(fp)))
	{
		*dest++ = c;
		/*printf("%c\n", c);*/
	}
	*dest = '\0';

	return 1;
}

int32_t main(void)
{
	FILE *fp;
	char word[MAXLEN];
	int32_t value, answer = 0;

	fp = fopen("problem_026-050/p042_words.txt", "r");
	while (read_word(fp, word) != EOF)
	{
		printf("%s\n", word);
		value = word_value(word);
		if (is_triangular(value))
			++answer;
		printf("Problem 42: %d\n", answer);
	}

	printf("Problem 42: %d\n", answer);
	return 0;
}
