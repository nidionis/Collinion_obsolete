/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suplayerko <suplayerko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:17:56 by suplayerko          #+#    #+#             */
/*   Updated: 2022/10/26 16:24:32 by suplayerko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_matrixlen(char **matrix)
{
	int	len;

	len = 0;
	if (matrix)
	{
		while (matrix[len])
			len++;
	}
	return (len);
}

int	neighbourgh_count(int **matrix, t_point ind, int cell_search)
{
	int	nb = 0;
	t_point	ind_cpy = ind;

	if (matrix[ind.y--][ind.x--] == cell_search)
		nb--;
	while (ind.y <= ind_cpy + 1)
	{
		ind.x = ind_cpy.x - 1;
		while (ind.x <= ind_cpy.x + 1)
		{
			if (matrix[ind.y][ind.x++] == cell_search)
				nb++;
		}
		ind.y++;
	}
	return (nb);
}
