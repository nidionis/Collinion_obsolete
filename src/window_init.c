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

#include "../include/collinion.h"

int	window_init(t_data *data)
{
	t_window *window;

	window = data->window;
	window->mlx = mlx_init();
	//r data->img = malloc(sizeof(t_image));
	data->img.pointeur = mlx_new_image(window->mlx, window->size[W], window->size[H]);
	window->init = mlx_new_window(window->mlx, \
		window->size[W], window->size[H], "collinion");
	//data->img->line_len = data->img->line_len >> 2;
	data->img.address = mlx_get_data_addr(data->img.pointeur,&data->img.bpp, &data->img.line_len, &data->img.endian);
	return (0);
}
