/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collinion_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:08:38 by dpaulino          #+#    #+#             */
/*   Updated: 2022/12/01 17:17:35 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/collinion.h"

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
			if (cell < NB_TYPES)
				color = data->render.colors[cell];
			else
				color = data->render.colors[NB_TYPES];
			draw_pixel(data, i_matrix, color);
		}
	}
}

int	refresh_image(t_data *data)
{
	refresh_matrix(data, apply_prime_rule);
	refresh_matrix(data, apply_rule);
	draw_matrix(data);
	usleep(1000 * SLEEP_TIME);
	mlx_put_image_to_window(data->window->mlx, data->window->init, data->img.pointeur, 0, 0);
	return (0);
}

int	manage_keystroke(int keystroke, void *param)
{
	t_data	*data = (t_data *)param;
	//printf("keystroke %d\n", keystroke);	
	if (keystroke == ECHAP)
	{
		mlx_destroy_window(data->window->mlx, data->window->init);
		clean_exit(data, 0);
	}
	return (keystroke);
}

int	graphic_loop(t_data *data)
{
	mlx_loop_hook(data->window->mlx, refresh_image, data);
	mlx_key_hook(data->window->init, manage_keystroke, data);
	mlx_loop(data->window->mlx);
	return (0);
}

int	window_init(t_data *data)
{
	t_window *window;

	window = data->window;
	window->mlx = mlx_init();
	data->img.pointeur = mlx_new_image(window->mlx, window->size[W], window->size[H]);
	window->init = mlx_new_window(window->mlx, \
		window->size[W], window->size[H], "collinion");
	data->img.address = mlx_get_data_addr(data->img.pointeur,&data->img.bpp, &data->img.line_len, &data->img.endian);
	return (0);
}

/* was usefull for debuging */
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
