/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:45:24 by dpaulino          #+#    #+#             */
/*   Updated: 2022/12/01 17:55:14 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	window_init(t_data *data)
{
	t_window *window;

	window = data->window;
	window->mlx = mlx_init();
	data->img = malloc(sizeof(t_img_data));
	data->img->img = mlx_new_image(window->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	window->init = mlx_new_window(window->mlx, \
		SCREEN_WIDTH, SCREEN_HEIGHT, "colinion");
	data->img->line_len = data->img->line_len >> 2;
	data->img->adress = mlx_get_data_addr(data->img->img,&data->img->bpp, &data->img->line_len, &data->img->endian);
	return (0);
}
