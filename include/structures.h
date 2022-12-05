#include <colinion.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

//struct for window
typedef struct s_window
{
	void	*mlx;
	void	*init;
	int	size[2];
}	t_window;

typedef struct s_image
{
	void 	*pointeur;
	char 	*address;
	int	bpp;
	int 	endian;
	int 	line_len;
}	t_image;

typedef struct s_render
{
	int		pix_size;
	unsigned int	*colors;
}	t_render;

typedef struct s_data
{
	t_window	*window;
	t_image		img;
	t_render	render;
	int		**matrix;
	int		**tmp_matrix;
	int		matrix_size[2];
}	t_data;

enum e_matrix_size { H, W };
enum e_matrix_sides { FALSE, NO, SO, EA, WE };
