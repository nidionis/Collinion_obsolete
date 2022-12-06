#ifndef COLINION_H
# define COLINION_H

//MACROS 
#  define ECHAP 	65307 //echap

# define CELL matrix[ind.y][ind.x]
# define CELL_UP matrix[ind.y - 1][ind.x]
# define CELL_DOWN matrix[ind.y + 1][ind.x]
# define CELL_RIGTH matrix[ind.y][p.x + 1]
# define CELL_LEFT matrix[ind.y][ind.x - 1]
# define CELL_UP_RIGTH matrix[ind.y - 1][ind.x + 1]
# define CELL_UP_LEFT matrix[ind.y - 1][ind.x - 1]
# define CELL_DOWN_RIGTH matrix[ind.y + 1][ind.x + 1]
# define CELL_DOWN_LEFT matrix[ind.y + 1][ind.x - 1]


# include <stdlib.h>
# include "structures.h"
# include "prototypes.h"
# include "colors.h"
# include "mlx.h"
# include <unistd.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h> // test
# include <time.h>
# include <string.h>
# include <stdint.h>
# include "config.h"

/*   CHEAT MACRO	 */
#define CELL_COLOR render->colors
#define SET_COLORS void	init_colors(t_render *render) {\
	render->colors = malloc(sizeof(int) * NB_TYPES);
#define END }

#define PRIME_ALGO int	apply_prime_rule(int **matrix, t_point ind )\
{\
	int	cell;\
	int	NEW_CELL;\
	(void)ind;\
	(void)matrix;\
	cell = matrix[ind.y][ind.x];\
	NEW_CELL = cell;\
	switch (CELL) {

#define END_ALGO	}\
	return (NEW_CELL);\
}

#define ALGO int	apply_rule(int **matrix, t_point ind )\
{\
	int	cell;\
	int	NEW_CELL;\
	(void)ind;\
	(void)matrix;\
	cell = matrix[ind.y][ind.x];\
	NEW_CELL = cell;\
	switch (CELL) {

#define NB_AROUND(TOKEN) neighbourgh_count(matrix, ind, TOKEN)

#define COUNT neighbourgh_count(matrix, ind, 
#define AROUND )
#endif

