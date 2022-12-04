/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:03:28 by dpaulino          #+#    #+#             */
/*   Updated: 2022/11/28 10:46:04 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_square(t_data *data, int size, int pos_y, int pos_x, int color)
{
	int	y;
	int	x;

	x = pos_x;
	y = pos_y;
	while (y < pos_y + size)
	{
		while (x < pos_x + size)
		{
			my_mlx_pixel_put(data->img, x, y, color);
			x++;
		}
		x = pos_x;
		y++;
	}
}
