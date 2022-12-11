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
		if ((NB_SIDE_UP(alive) > 3) || (NB_SIDE_DOWN(alive) < 3)){
			NEW_CELL = alive;
		}
		else if (NB_AROUND(alive) > 3) {
			NEW_CELL = dead;
		}
		break;
}
END_ALGO
