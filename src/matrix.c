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

#include "colinion.h"

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
