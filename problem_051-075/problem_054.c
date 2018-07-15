#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define HANDSIZE 5

enum hands {
	HIGH_CARD,
	PAIR,
	TWO_PAIR,
	THREE,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR,
	STRAIGHT_FLUSH,
	ROYAL_FLUSH
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

	if (len < 2 || len > 3)
	{
		printf("ERROR: can't parse %s\n", s);
		exit(1);
	}

	/* parse value */
	if (len == 3) /* value is obviously 10 */
		c.value = 10;
	else          /* value can be a digit (2, 3..) or Jack, Queen... */
	{
		if (isdigit(s[0]))
			c.value = s[0] - '0';
		else
			switch (s[0])
			{
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

/* parse_hand: return an array of cards parsed from `s` (space separated) */
void parse_hand(char *s, struct card *hand)
{
	int32_t i;
	char *pch;
	pch = strtok(s, " ");

	for (i = 0; i < HANDSIZE; ++i)
	{
		hand[i] = parse_card(pch);
		pch = strtok(NULL, " ");
	}
}

int32_t main(void)
{
	char ss[] = "4D 6S 10H JH QC";
	struct card *hand;
	int32_t i;

	hand = calloc(HANDSIZE, sizeof *hand);
	parse_hand(ss, hand);

	for (i = 0; i < HANDSIZE; ++i)
	{
		printf("%d %d\n", hand[i].value, hand[i].color);
	}

	return 0;
}
