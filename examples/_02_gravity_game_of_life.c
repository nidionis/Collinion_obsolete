#include <collinion.h>

DECLARE_TYPE:	dead;
DECLARE_TYPE:	alive;

SET_COLORS
	CELL_COLOR[alive] = WHITE;
	CELL_COLOR[dead] = BLACK;
END



PRIME_ALGO
switch(CELL) {
	default:
		if (CELL == alive && CELL_DOWN == dead) {
			NEW_CELL = dead;
		}
		if (CELL == dead && CELL_UP == alive) {
			NEW_CELL = alive;
		}
		break;
}
END_ALGO



ALGO
switch(CELL) {
	default:
		/* uncomment to have a CELL generator :) */
		// if (CELL_UP == WALL) { NEW_CELL = alive ; } else
		if (NB_AROUND(alive) < 2) {
			NEW_CELL = dead;
		} if (NB_AROUND(alive) > 3) {
			NEW_CELL = dead;
		} if (NB_AROUND(alive) == 3){
			NEW_CELL = alive;
		}
		break;
}
END_ALGO
