#include <collinion.h>

DECLARE_TYPE:	dead;
DECLARE_TYPE:	male;
DECLARE_TYPE:	female;
DECLARE_TYPE:	child;
DECLARE_TYPE:	teenager;

SET_COLORS
	CELL_COLOR[male] = BLUE;
	CELL_COLOR[female] = RED;
	CELL_COLOR[child] = PURPLE;
	CELL_COLOR[teenager] = MAROON;
END

PRIME_ALGO
	/* if over populated */
int	child_around = NB_AROUND(child);
int	male_around = NB_AROUND(male);
int	female_around = NB_AROUND(female);

if (child_around + male_around + female_around >= 5)
	NEW_CELL = dead ;
END_ALGO

ALGO
int	child_around = NB_AROUND(child) + NB_AROUND(teenager);
int	male_around = NB_AROUND(male);
int	female_around = NB_AROUND(female);
switch(CELL) {
	case (child):
		NEW_CELL = teenager;
		break ;
	/* this specimen produce 2 female for one male */
	case (teenager):
		if (rand() % 3 == 0)
	       		NEW_CELL = male ;
		else
			NEW_CELL = female;
		break ;
	case (male):
		if (male_around && female_around == 1) {
			NEW_CELL = dead;
		}
		break ;
	case (female):
		if (!male_around)
			NEW_CELL = dead;
		break ;
	case (dead):
		if (!child_around && male_around && female_around)
			NEW_CELL = child;
		break ;
}
END_ALGO
