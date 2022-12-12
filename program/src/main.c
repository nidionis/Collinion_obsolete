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

#include "collinion.h"

 t_data	*malloc_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit_msg(data, "[malloc_data] no malloc", -1);
	data->window = malloc(sizeof(t_window));
	if (!data)
		exit_msg(data, "[malloc_data] window did no malloc", -1);
	data->window->size[W] = SCREEN_WIDTH;
	data->window->size[H] = SCREEN_HEIGHT;
	return (data);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t_data		*data;
	data = malloc_data();
	init_matrix(data, argv);
	init_colors(&data->render);
	//print_matrix(data->matrix, data->matrix_size[H], data->matrix_size[W]);
	window_init(data);
	graphic_loop(data);
	clean_exit(data, 0);
	return (1);
}
