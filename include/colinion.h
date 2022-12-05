#ifndef COLINION_H
# define COLINION_H

//MACROS 
# define SCREEN_WIDTH 220
# define SCREEN_HEIGHT 222
/* should be eaual to windows width*/
# define PIX_PER_SQUARE 30

# define CELL "matrix[ind.y][ind.x]"
# define CELL_UP "matrix[ind.y - 1][ind.x]"
# define CELL_DOWN "matrix[ind.y + 1][ind.x]"
# define CELL_RIGTH "matrix[ind.y][p.x + 1]"
# define CELL_LEFT "matrix[ind.y][ind.x - 1]"
# define CELL_UP_RIGTH "matrix[ind.y - 1][ind.x + 1]"
# define CELL_UP_LEFT "matrix[ind.y - 1][ind.x - 1]"
# define CELL_DOWN_RIGTH "matrix[ind.y + 1][ind.x + 1]"
# define CELL_DOWN_LEFT "matrix[ind.y + 1][ind.x - 1]"

# define WALL -1

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
# include <stdint.h>
# include "cell_config.h"
#endif

