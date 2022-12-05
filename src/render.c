/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colinion_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:08:38 by dpaulino          #+#    #+#             */
/*   Updated: 2022/12/01 17:17:35 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colinion.h"

t_point	init_point(int y, int x)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}

void	refresh_matrix(t_data *data, int (*f)(int **, t_point))
{
	int 	**matrix = data->matrix;
	int 	**new_matrix = data->tmp_matrix;

	for (int y = 1; y < data->matrix_size[H] - 1; y++)
	{
		for (int x = 1; x < data->matrix_size[W] - 1; x++)
		{
			new_matrix[y][x] = (*f)(matrix, init_point(y, x));
		}
	}
	data->matrix = new_matrix;
}

void	draw_pixel(t_data *data, t_point p, unsigned int color)
{
	int size = data->render.pix_size;
	t_point	init_pos = init_point(p.y * size, p.x * size);

	for (int y = init_pos.y; y < init_pos.y + size; y++)
	{
		for (int x = init_pos.x; x < init_pos.x + size; x++)
			my_mlx_pixel_put(&data->img, x, y, color);
	}
}

void	print_matrix(int **matrix, int HEIGHT, int WIDTH)
{
	t_point	i_matrix = init_point(1, 1);
	int	cell;

	printf("   ###################################   \n");
	for (i_matrix.y = 1; i_matrix.y < HEIGHT - 1; i_matrix.y++)
	{
		for (i_matrix.x = 1; i_matrix.x < WIDTH - 1; i_matrix.x++)
		{
			cell = matrix[i_matrix.y][i_matrix.x];
			printf("|%d", cell);
		}
		printf("\n");
	}
	printf("   ###################################   \n");
}

void	draw_matrix(t_data *data)
{
	t_point	i_matrix;
	int	**matrix = data->matrix;
	int	cell;
	int	color;

	for (i_matrix.y = 1; i_matrix.y < data->matrix_size[H] - 1; i_matrix.y++)
	{
		for (i_matrix.x = 1; i_matrix.x < data->matrix_size[W] - 1; i_matrix.x++)
		{
			cell = matrix[i_matrix.y][i_matrix.x];
			color = data->render.colors[cell];
			draw_pixel(data, i_matrix, color);
		}
	}
}

int	refresh_image(t_data *data)
{
	refresh_matrix(data, apply_prime_rule);
	//refresh_matrix(data, apply_rule);
	draw_matrix(data);
	usleep(1000000);
	//print_matrix(data->matrix, data->matrix_size[H], data->matrix_size[W]);
	mlx_put_image_to_window(data->window->mlx, data->window->init, data->img.pointeur, 0, 0);
	return (0);
}

int	graphic_loop(t_data *data)
{
	mlx_loop_hook(data->window->mlx, refresh_image, data);
	//mlx_hook(data->window->init, 17, 1L << 17, &exit_game, data);
	mlx_loop(data->window->mlx);
	return (0);
}
