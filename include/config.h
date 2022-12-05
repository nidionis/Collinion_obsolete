#include <colinion.h>

# define SCREEN_WIDTH 	600
# define SCREEN_HEIGHT 	400
# define PIX_PER_SQUARE 1
/* value given at surrounding in random map */
# define WALL (-1) 
/* time waiting between each frames */
# define SLEEP_TIME 	0

enum WRITE_YOUR_CELLS_TYPE_BELOW {
/* The first have value 0, the second is 1 and so on */
	dead,
       	alive,
	NB_TYPES // leave this line
}; 

