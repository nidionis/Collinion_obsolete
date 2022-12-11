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
		if (NB_AROUND(alive) < 2) {
			NEW_CELL = dead;
		}
		if (NB_AROUND(alive) > 3) {
			NEW_CELL = dead;
		}
		if (NB_AROUND(alive) == 3) {
			NEW_CELL = alive;
		}
		if (CELL == alive && NB_AROUND(zombie) >= NB_AROUND(alive)) {
			NEW_CELL = zombie;
		}
		if (CELL == zombie && NB_AROUND(zombie) <= NB_AROUND(alive)) {
			NEW_CELL = dead;
		}
		break;
}
END_ALGO
