#include <collinion.h>

CELL_TYPES
	alive,
	dead,
END_CELL_TYPE

ALGO
	case alive :
		if (SUROUNDING(alive) > 3)
		end_case
	case dead :
END_ALGO
