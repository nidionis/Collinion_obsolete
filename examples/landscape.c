#include <collinion.h>

DECLARE_TYPE:	empty;
DECLARE_TYPE:	water;
DECLARE_TYPE:	plant;
DECLARE_TYPE:	earth;

SET_COLORS
	CELL_COLOR[water] = AQUA;
	CELL_COLOR[earth] = BROWN;
	CELL_COLOR[plant] = GREEN;
	CELL_COLOR[empty] = BLACK;
END

PRIME_ALGO
if (CELL_UP == WALL) {
	if (rand()%3 == 0)
		return (water);
	else
		return(empty);
}
if (CELL_DOWN == WALL) {
	return(empty);
}
switch(CELL) {
	default:
		if (CELL > CELL_DOWN)
			NEW_CELL = CELL_DOWN;
		if (CELL < CELL_UP)
			NEW_CELL = CELL_UP;
		break;
}
END_ALGO

ALGO
switch(CELL) {
	case (water):
		break ;
	case (earth):
		break ;
	case (plant):
		break ;
	default:
		break;
}
END_ALGO
