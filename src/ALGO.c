#include <colinion.h>

SET_COLORS
	CELL_COLOR[alive] = WHITE;
	CELL_COLOR[dead] = BLACK;
END

/* implement a gravity */
PRIME_ALGO
default:
	if (CELL_UP == alive) {
		NEW_CELL = alive;
	}
	else if (CELL == alive && CELL_DOWN == dead) {
		NEW_CELL = dead;
	}
	break ;
END_ALGO

ALGO
case alive:
	if (NB_AROUND(alive) < 2 || NB_AROUND(alive) > 3) {
		NEW_CELL = dead;
	}
	break ;
case dead:
	if (NB_AROUND(alive) == 3) {
		NEW_CELL = alive;
	}
	break ;
/* optional */
default:
	NEW_CELL = CELL;
	break ;
END_ALGO
