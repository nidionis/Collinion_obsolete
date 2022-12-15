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
			if (CELL < CELL_UP)
				NEW_CELL = CELL_UP;
			else if (CELL > CELL_DOWN && CELL_DOWN != empty)
				NEW_CELL = CELL_DOWN;
			break;
		}
}
END_ALGO

ALGO
int nb_wood = NB_AROUND(wood);
switch(CELL) {
	case (empty):
		break ;
	case (water):
		if (CELL_UP == water && CELL_DOWN == water)
			NEW_CELL = empty;
		else if (nb_wood || NB_AROUND(leaves))
			NEW_CELL = leaves;
		break ;
	case (wood):
		if (!(rand() % 200))
				NEW_CELL = earth;
		break ;
	case (leaves):
		if (!nb_wood && !NB_AROUND(empty)) {
			if (!(rand() % 10))
				NEW_CELL = wood;
		} else if (!(rand() % 100))
				NEW_CELL = earth;
		break;
	case (earth):
		if (NB_AROUND(earth) == 8)
			NEW_CELL = empty;
		break ;
	default:
		break;
	//PRINT(SLEEP_TIME);
}
END_ALGO
