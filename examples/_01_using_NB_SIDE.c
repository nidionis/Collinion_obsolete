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
		if ((NB_SIDE_UP(alive) == 1)) {
			NEW_CELL = dead;
		}
		else if ((NB_SIDE_LEFT(alive) == 1)) {
			NEW_CELL = dead;
		}
		else if ((NB_SIDE_DOWN(alive) == 1)) {
			NEW_CELL = alive;
		}
		else if ((NB_SIDE_RIGHT(alive) == 1)) {
			NEW_CELL = alive;
		}
		break;
}
END_ALGO
