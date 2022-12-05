#include <colinion.h>

SET_COLORS
	CELL_COLOR[alive] = WHITE;
	CELL_COLOR[dead] = BLACK;
END

PRIME_ALGO
case alive:
	if (COUNT alive AROUND < 2 || COUNT alive AROUND > 3)
	{
		NEW_CELL = dead;
	}
	break ;
case dead:
	if (COUNT alive AROUND == 3)
	{
		NEW_CELL = alive;
	}
	break ;
/* optional */
default:
	NEW_CELL = CELL;
	break ;
END_ALGO
