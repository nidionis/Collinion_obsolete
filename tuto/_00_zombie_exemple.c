#include <collinion.h>

DECLARE_TYPE:	dead   ;
DECLARE_TYPE:	alive;
DECLARE_TYPE:	zombie ;

SET_COLORS
	CELL_COLOR[alive] = WHITE;
	CELL_COLOR[dead] = BLACK;
	CELL_COLOR[zombie] = GREEN;
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
		/*
		CELL == zombie && NB_AROUND(zombie) == NB_AROUND(alive)
		CELL == zombie && NB_AROUND(zombie) < NB_AROUND(alive)
		give slightly different results
		*/
		if (CELL == zombie && NB_AROUND(zombie) <= NB_AROUND(alive)) {
			NEW_CELL = dead;
		}
		break;
}
END_ALGO
