#include <collinion.h>

DECLARE_TYPE:	dead   ;
DECLARE_TYPE:	alive;

SET_COLORS
	CELL_COLOR[alive] = WHITE;
	CELL_COLOR[dead] = BLACK;
END



PRIME_ALGO
	/* this algo is empty for now */
END_ALGO



ALGO
/* declare variables at the beging of the algo
 * above switch and below ALGO */
switch(CELL) {
	default:
		if (CELL_UP == WALL) {
			NEW_CELL = alive;
		} else if (NB_SIDE_DOWN(WALL) > 0) {
			NEW_CELL = dead;
		} else if (NB_AROUND(alive) < 2) {
			NEW_CELL = dead;
		} else if (NB_AROUND(alive) > 3) {
			NEW_CELL = dead;
		} else if (NB_AROUND(alive) == 3) {
			NEW_CELL = alive;
		}
		break;
}
END_ALGO
