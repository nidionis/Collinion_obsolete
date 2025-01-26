/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:08:38 by dpaulino          #+#    #+#             */
/*   Updated: 2025/01/26 15:40:32 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/collinion.h"

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

// Dessine un carré correspondant à un pixel de la matrice
void	draw_pixel(t_data *data, t_point p, unsigned int color) {
	int		size = data->render.pix_size;
	t_point	init_pos = init_point(p.x * size, p.y * size);

	for (int y = init_pos.y; y < init_pos.y + size; y++) {
		for (int x = init_pos.x; x < init_pos.x + size; x++) {
			my_mlx_pixel_put(&data->img, x, y, color);
		}
	}
}

// Dessine la matrice entière
void	draw_matrix(t_data *data) {
	t_point	i_matrix;
	int		**matrix = data->matrix;
	int		cell;
	int		color;

	for (i_matrix.y = 1; i_matrix.y < data->matrix_size[H] - 1; i_matrix.y++) {
		for (i_matrix.x = 1; i_matrix.x < data->matrix_size[W] - 1; i_matrix.x++) {
			cell = matrix[i_matrix.y][i_matrix.x];
			color = (cell < NB_TYPES) ? data->render.colors[cell]
									  : data->render.colors[NB_TYPES];
			draw_pixel(data, i_matrix, color);
		}
	}
}

// Rafraîchit l'image à chaque itération
int	refresh_image(t_data *data) {
	refresh_matrix(data, apply_prime_rule);
	refresh_matrix(data, apply_rule);
	draw_matrix(data);
	usleep(1000 * SLEEP_TIME);
	mlx_put_image_to_window(data->window->mlx, data->window->init, data->img.pointeur, 0, 0);
	return (0);
}

// Gère les événements clavier
int	manage_keystroke(int keystroke, void *param) {
	t_data	*data = (t_data *)param;

	if (keystroke == 65307) { // Touche Échap (keycode spécifique à X11)
		mlx_destroy_window(data->window->mlx, data->window->init);
		clean_exit(data, 0);
	}
	return (keystroke);
}

// Boucle graphique principale
int	graphic_loop(t_data *data) {
	mlx_loop_hook(data->window->mlx, refresh_image, data);
	mlx_key_hook(data->window->init, manage_keystroke, data);
	mlx_loop(data->window->mlx);
	return (0);
}

// Initialise la fenêtre et l'image
int	window_init(t_data *data) {
	t_window *window = data->window;

	window->mlx = mlx_init();
	data->window->mlx = mlx_init();
	if (!data->window->mlx)
		exit_msg(data, "Failed to initialize mlx", -1);
	data->img.pointeur = mlx_new_image(window->mlx, window->size[W], window->size[H]);

	if (!data->img.pointeur)
		exit_msg(data, "Failed to create image", -1);


	//window->init = mlx_new_window(window->mlx, window->size[W], window->size[H], "collinion");
	data->window->init = mlx_new_window(
										data->window->mlx,
										data->window->size[W],
										data->window->size[H],
										"Collinion"
			);
	if (!data->window->init)
		exit_msg(data, "Failed to create window", -1);

	data->img.address = mlx_get_data_addr(
		data->img.pointeur,
		&data->img.bpp,
		&data->img.line_len,
		&data->img.endian
	);
	return (0);
}
