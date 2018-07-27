#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define FILENAME "problem_076-100/p079_keylog.txt"
#define LEN 10

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

	if (index != -1)
		scores[index] = -1;
	return index;
}
int32_t main(void)
{
	FILE *fp;
	int8_t scores[LEN] = {0}, occurrences[LEN] = {0};
	int32_t val, answer;

	if ((fp = fopen(FILENAME, "r")) == NULL)
	{
		printf("error: can't open %s\n", FILENAME);
		exit(1);
	}

	while (fscanf(fp, "%d", &val) != EOF)
	{
		scores[val/100] += 3;
		++occurrences[val/100];

		scores[val%100 / 10] += 2;
		++occurrences[val%100 / 10];

		scores[val%10] += 1;
		++occurrences[val%10];
	}

	answer = 0;
	while ((val = index_score_max(scores, occurrences)) != -1)
		answer = answer * 10 + val;

	printf("Problem 79: %d\n", answer);
	return 0;
}
