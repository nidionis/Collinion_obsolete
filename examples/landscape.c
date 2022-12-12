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
/* rain generator */
if (CELL_UP == WALL) {
	if (rand()% 4 == 0)
		return (water);
	else
		return(empty);
}
/* and earth absorbtion */
if (CELL_DOWN == WALL) {
	return (empty);
}
/* gravity:
 * if cell have higer value (I sorted them by density), it drop */
switch(CELL) {
	default:
		if (CELL < CELL_UP)
			NEW_CELL = CELL_UP;
		else if (CELL > CELL_DOWN)
			NEW_CELL = CELL_DOWN;
		break;
}
END_ALGO

ALGO
switch(CELL) {
	case (empty):
		if (NB_AROUND(plant) > 4)
			NEW_CELL = plant;
		break ;
	case (water):
		if (NB_SIDE_DOWN(earth) > 0)
			NEW_CELL = plant;
		break ;
	case (plant):
		if (NB_AROUND(plant) >= 5)
			NEW_CELL = earth;
		break ;
	case (earth):
		break ;
	default:
		break;
}
END_ALGO
