#include <collinion.h>

DECLARE_TYPE:	empty;
DECLARE_TYPE:	water;
DECLARE_TYPE:	leaves;
DECLARE_TYPE:	wood;
DECLARE_TYPE:	earth;

SET_COLORS
	CELL_COLOR[water] = AQUA;
	CELL_COLOR[earth] = BROWN;
	CELL_COLOR[leaves] = GREEN;
	CELL_COLOR[wood] = MAROON;
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
	return (earth);
}
/* gravity:
 * if cell have higer value (I sorted them by density), it drop */
switch(CELL) {
	default:
		if (CELL_UP != WALL && CELL_DOWN != WALL){
			if (CELL > CELL_DOWN)
				NEW_CELL = empty;
			else if (CELL < CELL_UP)
				NEW_CELL = CELL_UP;
			break;
		}
}
END_ALGO

ALGO
switch(CELL) {
	case (empty):
		if (NB_AROUND(leaves) > 3)
			NEW_CELL = leaves;
		else if (NB_SIDE_DOWN(wood) > 1)
			NEW_CELL = leaves;
		break ;
	case (water):
		if (NB_AROUND(earth))
			NEW_CELL = wood;
		else if (NB_AROUND(wood))
			NEW_CELL = leaves;
		else if (CELL_UP == water && CELL_DOWN == water && (CELL_LEFT == empty || CELL_RIGHT == empty))
			NEW_CELL = empty;
		else if (NB_AROUND(water) == 8)
			NEW_CELL = empty;
		else if (NB_SIDE_DOWN(leaves) >= 1)
			NEW_CELL = leaves;
		break ;
	case (wood):
		if (CELL_UP == wood && CELL_DOWN == wood && !(rand() % 10))
			NEW_CELL = leaves;
		break ;
	case (leaves):
		if (!NB_AROUND(wood)) {
			if (rand() % 2 == 0)
				NEW_CELL = wood;
			else
				NEW_CELL = empty;
		}
		break;
	case (earth):
		//if (NB_AROUND(water))
		//	NEW_CELL = wood;
		//else if (NB_AROUND(earth) == 8 && !(rand() % 10))
		//	NEW_CELL = empty;
		break ;
	default:
		break;
}
END_ALGO
