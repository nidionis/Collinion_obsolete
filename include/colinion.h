/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suplayerko <suplayerko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:19:05 by suplayerko          #+#    #+#             */
/*   Updated: 2022/11/13 18:09:07 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLINION_H
# define COLINION_H

# ifdef __APPLE__
#  include "../minilibx_mac/mlx.h"

# else   // LINUX
#  include <X11/keysym.h>   // 
#  include "../minilibx_linux/mlx.h"
#  include "../minilibx_linux/mlx_int.h"
#  define KEY_ESC 65307
#  define EXPOSE_X 65293
#  define ON_DESTROY 	17
# endif

//MACROS 
# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 720
/* should be eaual to windows width*/
# define PIX_PER_SQUARE 30
# define CELL_TYPES "enum blabla { "
# define END_CELL_TYPES "NB_TYPES};"
# define end_case break;
# define PRIME_ALGO "int	apply_prime_rule(int **matrix, t_point ind ) { switch (matrix[ind.y][ind.x]) :"
# define ALGO "int	apply_rule(int **matrix, t_point ind ) { switch (matrix[ind.y][ind.x]) :"
# define END_ALGO " return (1); }"
# define CELL "matrix[ind.y][ind.x]"
# define CELL_UP "matrix[ind.y - 1][ind.x]"
# define CELL_DOWN "matrix[ind.y + 1][ind.x]"
# define CELL_RIGTH "matrix[ind.y][p.x + 1]"
# define CELL_LEFT "matrix[ind.y][ind.x - 1]"
# define CELL_UP_RIGTH "matrix[ind.y - 1][ind.x + 1]"
# define CELL_UP_LEFT "matrix[ind.y - 1][ind.x - 1]"
# define CELL_DOWN_RIGTH "matrix[ind.y + 1][ind.x + 1]"
# define CELL_DOWN_LEFT "matrix[ind.y + 1][ind.x - 1]"

# define NB_OF_( neighbourgh_count(matrix, ind, 

# include <stdlib.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h> // test
# include <time.h>
# include <stdint.h>
# include "../MY_ALGO"

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
	int	width;
	int	height;
}	t_window;

typedef struct s_image
{
	void 	*pointeur;
	char 	*address;
	int	bpp;
	int 	img_len;
	int 	img_height;
	int 	endian;
}	t_image;

typedef struct s_data
{
	t_windo		*window;
	int		**matrix;
	int		**tmp_matrix;
	t_image		img;
}	t_data;
#endif

