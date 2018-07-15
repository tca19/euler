#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define HANDSIZE 5
#define FILENAME "problem_051-075/p054_poker.txt"

enum hands {
	HIGH_CARD,       /* 0 */
	PAIR,            /* 1 */
	TWO_PAIR,        /* 2 */
	THREE,           /* 3 */
	STRAIGHT,        /* 4 */
	FLUSH,           /* 5 */
	FULL_HOUSE,      /* 6 */
	FOUR,            /* 7 */
	STRAIGHT_FLUSH,  /* 8 */
	ROYAL_FLUSH      /* 9 */
};

enum suit {DIAMONDS, CLUBS, HEARTS, SPADES};

struct card {
	int8_t value;
	enum suit color;
};

/* parse_card: extract value/suit of card from string `s` ("5C" -> (5, Clubs) */
struct card parse_card(char *s)
{
	int32_t len = strlen(s);
	struct card c;

	if (len != 2)
	{
		printf("ERROR: can't parse %s\n", s);
		exit(1);
	}

	/* parse value */
	else
	{	/* 10 is represented as T, not 10 */
		if (isdigit(s[0]))
			c.value = s[0] - '0';
		else
			switch (s[0])
			{
				case 'T':
					c.value = 10;
					break;
				case 'J':
					c.value = 11;
					break;
				case 'Q':
					c.value = 12;
					break;
				case 'K':
					c.value = 13;
					break;
				case 'A':
					c.value = 14;
					break;
			}
	}

	/* parse suit */
	switch (s[len-1])
	{
		case 'D':
			c.color = DIAMONDS;
			break;
		case 'C':
			c.color = CLUBS;
			break;
		case 'H':
			c.color = HEARTS;
			break;
		case 'S':
			c.color = SPADES;
			break;
	}

	return c;
}

int32_t is_straight(int32_t *count_value)
{
	int32_t i, j;

	for (i = 0; i < 11; ++i)
	{
		if (count_value[i] == 0)
			continue;
		for (j = i+1; j < 15 && count_value[j] == 1; ++j)
			;
		if (j-i == 5)
			return 1;
	}

	return 0;
}

int32_t is_flush(int32_t *count_suit)
{
	return (count_suit[0] == HANDSIZE || count_suit[1] == HANDSIZE
	     || count_suit[2] == HANDSIZE || count_suit[3] == HANDSIZE);
}

int32_t is_three(int32_t *count_value)
{
	int32_t i;
	for (i = 0; i < 15; ++i)
		if (count_value[i] == 3)
			return 1;
	return 0;
}

int32_t is_pair(int32_t *count_value)
{
	int32_t i, n;
	for (i = 0, n = 0; i < 15; ++i)
		if (count_value[i] == 2)
			++n;
	return n;
}

/* find_rank: find the rank of `hand` (PAIR, THREE, FOUR ... ROYAL_FLUSH) */
enum hands find_rank(struct card *hand)
{
	/* count occurrence of each value and suit in hand */
	int32_t i, count_value[15] = {0}, count_suit[4] = {0};
	for (i = 0; i < HANDSIZE; ++i)
	{
		++count_value[hand[i].value];
		++count_suit[hand[i].color];
	}

	/* test if ROYAL_FLUSH */
	if (count_value[10] == 1 && count_value[11] == 1 && count_value[12] == 1
	&&  count_value[13] == 1 && count_value[14] == 1
	&&  is_flush(count_suit))
		return ROYAL_FLUSH;

	/* test STRAIGHT_FLUSH or STRAIGHT */
	if (is_straight(count_value))
		return is_flush(count_suit) ? STRAIGHT_FLUSH : STRAIGHT;

	/* test FOUR (4 cards with same value). Either first or second card of
	 * hand has an occurrence of 4 */
	if (count_value[hand[0].value] == 4 || count_value[hand[1].value] == 4)
		return FOUR;

	/* test FULL_HOUSE (3 of a kind and a pair) or THREE */
	if (is_three(count_value))
		return is_pair(count_value) ? FULL_HOUSE : THREE;

	/* test FLUSH */
	if (is_flush(count_suit))
		return FLUSH;

	/* test if 1 or 2 pairs, or no pairs. Number of pairs match the rank
	 * value of hand (0 for HIGH_CARD, 1 for PAIR, 2 for TWO_PAIR */
	return is_pair(count_value);
}

int32_t handle_tie(struct card *hand_p1, struct card *hand_p2, enum hands rank)
{
	/* count occurrence of each value for hands P1/P2 */
	int32_t count_value1[15] = {0}, count_value2[15] = {0};
	int32_t i, val1, val2;
	for (i = 0; i < HANDSIZE; ++i)
	{
		++count_value1[hand_p1[i].value];
		++count_value2[hand_p2[i].value];
	}

	/* both hands have a single pair, find value of pair and compare them */
	if (rank == 1)
	{
		for (i = 0; i < 15; ++i)
		{
			if (count_value1[i] == 2)
				val1 = i;
			if (count_value2[i] == 2)
				val2 = i;
		}

		if (val1 != val2)
			return val1 > val2 ? 1 : 2;
	}

	/* need to compare highest values to find winner */
	for (i = 14; i >= 0; --i)
	{
		if (count_value1[i] == 1 && count_value2[i] == 0)
			return 1;
		if (count_value2[i] == 1 && count_value1[i] == 0)
			return 2;
	}

	printf("still tie !\n");
	return 1;
}

int32_t main(void)
{
	FILE *fp;
	struct card *hand_p1, *hand_p2;
	int32_t i, victory_p1, r1, r2;
	char buf[10];


	hand_p1 = calloc(HANDSIZE, sizeof *hand_p1);
	hand_p2 = calloc(HANDSIZE, sizeof *hand_p2);

	if ((fp = fopen(FILENAME, "r")) == NULL)
	{
		printf("ERROR: can't open %s\n", FILENAME);
		return 1;
	}

	i = victory_p1 = 0;
	while (fscanf(fp, "%s", buf) != EOF)
	{
		if (i < 5)
			hand_p1[i] = parse_card(buf);
		else
			hand_p2[i-5] = parse_card(buf);
		++i;

		/* if 2*HANDSIZE values are read, compare the 2 hands */
		if (i == 2*HANDSIZE)
		{
			r1 = find_rank(hand_p1);
			r2 = find_rank(hand_p2);

			if (r1 > r2)
				++victory_p1;
			else if (r1 == r2)
			{
				if (handle_tie(hand_p1, hand_p2, r1) == 1)
					++victory_p1;
			}

			i = 0; /* reset i to read next hands for P1/P2 */
		}
	}

	printf("Problem 54: %d\n", victory_p1);
	return 0;
}
