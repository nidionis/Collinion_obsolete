#include <colinion.h>

void	init_colors(t_render *render)
{
	render->colors = malloc(sizeof(int) * NB_TYPES);
	render->colors[0] = RED;
	render->colors[1] = BLUE;
}

int	apply_prime_rule(int **matrix, t_point ind )
{
	int n;
	int	cell;
	int	new_cell;

	cell = matrix[ind.y][ind.x];
	new_cell = cell;
	switch (cell) {
		case alive:
			n = neighbourgh_count(matrix, ind, alive);
			if (n < 3 || n > 4)
				new_cell = (int)dead;
			break ;
		case dead:
			n = neighbourgh_count(matrix, ind, alive);
			if (n == 3)
				new_cell = (int)alive;
			break ;
		default:
			new_cell = cell; //matrix[ind.y][ind.x];
			break ;
	}
	return (new_cell);
}

int	apply_rule(int **matrix, t_point ind )
{
	(void)ind;
	(void)matrix;
	int	new_cell = matrix[ind.y][ind.x];

	return (new_cell);
}

/*
CELL_TYPES
	alive,
	dead,
END_CELL_TYPE

ALGO
	case alive :
		if (SUROUNDING(alive) > 4 || SUROUNDING(alive) < 3)
			CELL = dead;
		end_case
	case dead :
		if (SUROUNDING(alive) == 3)
			CELL = alive;

		end_case
END_ALGO
*/
