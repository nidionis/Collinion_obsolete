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
#  define KEY_RIGHT 124 
#  define KEY_LEFT 123 
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_ESC 53
#  define KEY_IN 69
#  define KEY_OUT 78
#  include "../minilibx_mac/mlx.h"

# else   // LINUX
#  include <X11/keysym.h>   // 
#  include "../minilibx_linux/mlx.h"
#  include "../minilibx_linux/mlx_int.h"
#  define KEY_RIGHT 65363 
#  define KEY_LEFT 65361 
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_ESC 65307
#  define KEY_IN 61
#  define KEY_OUT 45
#  define EXPOSE_X 65293
#  define ON_DESTROY 	17
# endif

//MACROS 
# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 720
/* should be eaual to windows width*/
# define PIX_PER_SQUARE

//COLORS 
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"

# include <stdlib.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h> // test
# include <time.h>
# include <stdint.h>

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
	int		width;
	int		height;
}	t_window;

#endif

