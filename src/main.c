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
	data->render.pix_size = PIX_PER_SQUARE;
	return (data);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t_data		*data;
	data = malloc_data();
		if (!data)
			exit(-1);
	data->window = malloc(sizeof(t_window));
	window_init(data);
	graphic_loop(data);
	clean_exit(data, 0);
}
