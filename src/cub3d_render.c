/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:08:38 by dpaulino          #+#    #+#             */
/*   Updated: 2022/12/01 17:17:35 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	refresh_matrix(data, (*f)(int **, t_point))
{
	int 	**matrix = data->matrix;
	int 	**new_matrix = data->tmp_matrix;
	t_point	index;

	index.x = 1;
	index.y = 1;
	while (index.y < MATRIX_HEIGHT - 1)
	{
		while (index.x < MATRIX_WIDTH - 1)
		{
			new_matrix[index.y][index.x] = *f(matrix, index);
		}
		index.y++;
	}
	data->matrix = new_matrix;
}

int	refresh_image(t_data *data)
{
	int	i;

	refresh_matrix(data, apply_prime_rule);
	refresh_matrix(data, apply_rule);
	draw_matrix(data);
	mlx_put_image_to_window(data->window->mlx, data->window->init,data->img->img, 0, 0);
	return (0);
}

int	graphic_loop(t_data *data)
{
	mlx_loop_hook(data->window->mlx, refresh_image, data);
	mlx_hook(data->window->init, 17, 1L << 17, &exit_game, data);
	mlx_loop(data->window->mlx);
	return (0);
}
