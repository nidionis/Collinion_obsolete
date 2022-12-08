
#include <collinion.h>


DEFINE_TYPE:	good
DEFINE_TYPE:	bad
DEFINE_TYPE:	empty

SET_COLORS
	CELL_COLOR[good] = WHITE;
	CELL_COLOR[bad] = RED;
	CELL_COLOR[empty] = BLACK;
END

/* let's say for infected : n = 3 */
PRIME_ALGO
switch(CELL) {
	case empty:
		if (NB_AROUND(good) >= 2)
			NEW_CELL = rand() % 2;
		break ;
	default:
		if (NB_AROUND(bad) >= 2)
			NEW_CELL = empty;
}
END_ALGO

ALGO
END_ALGO
