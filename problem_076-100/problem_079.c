#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define FILENAME "problem_076-100/p079_keylog.txt"
#define LEN 10

/* index_score_max: return the index i the largest value
 * scores[i] / occurrences[i]. Skip the cells where occurrence = 0. Return -1 if
 * all scores are equal */
int32_t index_score_max(int8_t *scores, int8_t *occurrences)
{
	int32_t index, i;
	float max_scores;

	index = -1;
	max_scores = 0.0;
	for (i = 0; i < LEN; ++i)
	{
		if (occurrences[i] == 0)
			continue;

		if ((float) scores[i] / occurrences[i] > max_scores)
		{
			index = i;
			max_scores = (float) scores[i] / occurrences[i];
		}
	}

	/* if a max index has been found, set the corresponding score to -1 so
	 * it won't be selected at next call (the 2nd largest score will be) */
	if (index != -1)
		scores[index] = -1;
	return index;
}

/* find the shortest passcode that could be used given the successful logins */
int32_t main(void)
{
	/* The shortest passcode is only composed of digits that are also in the
	 * successful logins. So count occurrence of each digit from the file.
	 * Digits with 0 occurrence won't be a part of the passcode.
	 * Given that digits for login as asked in order, attribute a score
	 * proportionnally to the position of each digit: the first with a
	 * larger score.
	 * Then sort in descending order the digits by their scores weighted by
	 * their number of occurrence. Need to weight scores because a digit
	 * that is frequently in position 3 does not come before a number that
	 * appears only once at the first position. */
	FILE *fp;
	int8_t scores[LEN] = {0}, occurrences[LEN] = {0};
	int32_t val, answer;

	if ((fp = fopen(FILENAME, "r")) == NULL)
	{
		printf("error: can't open %s\n", FILENAME);
		exit(1);
	}

	/* logins are 3-digit numbers */
	while (fscanf(fp, "%d", &val) != EOF)
	{
		/* first digit = first position = large score */
		scores[val/100] += 3;
		++occurrences[val/100];

		/* second digit */
		scores[val%100 / 10] += 2;
		++occurrences[val%100 / 10];

		/* third digit = last position = small score */
		scores[val%10] += 1;
		++occurrences[val%10];
	}

	/* concatenate the digits given their weighted scores */
	answer = 0;
	while ((val = index_score_max(scores, occurrences)) != -1)
		answer = answer * 10 + val;

	printf("Problem 79: %d\n", answer);
	return 0;
}
