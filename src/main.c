/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suplayerko <suplayerko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:17:56 by suplayerko          #+#    #+#             */
/*   Updated: 2022/12/01 18:48:48 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colinion.h"

 t_data	*malloc_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		clean_exit(data, -1);
	return (data);
}

int	is_border(t_data *data, t_point i)
{
	int	is_true;

	if (i.x == 0)
		is_true = WE;
	else if	(i.y == 0)
		is_true = NO;
	else if (i.x == data->matrix_size[W])
		is_true = EA;
	else if (i.y == data->matrix_size[H])
		is_true = SO;
	else
		is_true = FALSE;
	return (is_true);
}

void	init_matrix_size(t_data *data)
{
	data->matrix_size[H] = SCREEN_HEIGHT / PIX_PER_SQUARE;
	data->matrix_size[W] = SCREEN_WIDTH / PIX_PER_SQUARE;
	data->render.pix_size = PIX_PER_SQUARE;
}

int	**malloc_matrix(t_data *data)
{
	int	**matrix;
	int	size[2];

	size[W] = data->matrix_size[W];
	size[H] = data->matrix_size[H];
	matrix = malloc(size[H] * sizeof(int *));
	if (!matrix)
		exit_msg(data, "[random_matrix] did not malloc", 1);
	for (int i = 0; i < size[H]; i++)
	{
		matrix[i] = malloc(size[W] * sizeof(int));
		if (!matrix)
			exit_msg(data, "[random_matrix] did not malloc", 1);
	}
	return matrix;
}

void	random_matrix(t_data *data)
{
	t_point	i;
	int	**matrix;
	init_matrix_size(data);
	matrix = malloc_matrix(data);
	data->tmp_matrix = malloc_matrix(data);
	for (i.y = 0; i.y < data->matrix_size[H]; i.y++)
	{
		for (i.x = 0; i.x < data->matrix_size[W]; i.x++)
		{
			if (is_border(data, i))
				matrix[i.y][i.x] = WALL;
			else
				matrix[i.y][i.x] = rand() % NB_TYPES;
		}
	}
	data->matrix = matrix;
}

void	init_matrix(t_data *data, char *argv[])
{
	(void)argv;

	//if (argv[1])
	//	import_matrix(data, argv[]);
	//else
		random_matrix(data);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t_data		*data;
	data = malloc_data();
	init_matrix(data, argv);
	init_colors(&data->render);
	//print_matrix(data->matrix, data->matrix_size[H], data->matrix_size[W]);
	data->window = malloc(sizeof(t_window));
	window_init(data);
	graphic_loop(data);
	clean_exit(data, 0);
	return (1);
}
