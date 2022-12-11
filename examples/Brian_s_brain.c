#include <collinion.h>

DECLARE_TYPE:	off;
DECLARE_TYPE:	on;
DECLARE_TYPE:	dying;

SET_COLORS
	CELL_COLOR[on] = WHITE;
	CELL_COLOR[off] = BLACK;
	CELL_COLOR[dying] = BLUE;
END



PRIME_ALGO
END_ALGO

/*
 * https://en.wikipedia.org/wiki/Brian%27s_Brain
 */

ALGO
switch(CELL) {
	case (off):
		if (NB_AROUND(on) == 2)
			NEW_CELL = on ;
		break;
	case (on):
			NEW_CELL = dying ;
		break;
	case (dying):
			NEW_CELL = off ;
		break;
}
END_ALGO
