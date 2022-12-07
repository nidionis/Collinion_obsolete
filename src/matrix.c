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

#include "collinion.h"

int	matrixlen(int **matrix)
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

	for (int y = ind.y - 1; y <= ind.y + 1; y++)
	{
		for (int x = ind.x - 1; x <= ind.x + 1; x++)
		{
			if (x == ind.x && y == ind.y)
				continue ; // this is the cell itself
			else if (matrix[y][x] == cell_search)
				nb++;
		}
	}
	return (nb);
}

int	side_count(int **matrix, t_point ind, int cell_search, int side)
{
	int	nb = 0;
	int	i_inc;
	int	i_fix;
	int	max;

	switch (side) {
		case SIDE_UP:
			i_fix = ind.y - 1;
			i_inc = ind.x - 1;
			break ;
		case SIDE_DOWN:
			i_fix = ind.y + 1;
			i_inc = ind.x - 1;
			break ;
		case SIDE_LEFT:
			i_fix = ind.x - 1;
			i_inc = ind.y - 1;
			break ;
		case SIDE_RIGHT:
			i_fix = ind.x - 1;
			i_inc = ind.y + 1;
			break ;
	}
	max = i_inc + 3;
	while (i_inc < max)
	{
		if (side == SIDE_UP || side == SIDE_DOWN)
		{
			if (matrix[i_fix][i_inc] == cell_search)
				nb++;
		} else {
			if (matrix[i_inc][i_fix] == cell_search)
				nb++;
		}
		i_inc++;
	}
	return (nb);
}
