#include <colinion.h>

/* graphic */
int	window_init(t_data *data);
void	my_mlx_pixel_put(t_image *img, int x, int y, unsigned int color);
int	graphic_loop(t_data *data);
void	refresh_matrix(t_data *data, int (*f)(int **, t_point));
void	init_colors(t_render *render);

/* algo */
int	neighbourgh_count(int **matrix, t_point ind, int cell_search);
int	apply_prime_rule(int **matrix, t_point ind);
int	apply_rule(int **matrix, t_point ind);

/* utils */
void	clean_exit(t_data *data, int exit_code);
void	exit_msg(t_data *data, char *msg, int ret_exit);

/* debug */
void	print_matrix(int **matrix, int HEIGHT, int WIDTH);
