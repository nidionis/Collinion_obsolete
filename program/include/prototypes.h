#include <collinion.h>

/* graphic */
int	window_init(t_data *data);
void	my_mlx_pixel_put(t_image *img, int x, int y, unsigned int color);
int	graphic_loop(t_data *data);
void	refresh_matrix(t_data *data, int (*f)(int **, t_point));
void	init_colors(t_render *render);

/* algo */
int	neighbourgh_count(int **matrix, t_point ind, int cell_search);
int	side_count(int **matrix, t_point ind, int cell_search, int side);
int	apply_prime_rule(int **matrix, t_point ind);
int	apply_rule(int **matrix, t_point ind);

/* utils */
int	quit(t_data *data);
void	clean_exit(t_data *data, int exit_code);
void	exit_msg(t_data *data, char *msg, int ret_exit);
char	*get_next_line(int fd);
int	is_border(t_data *data, t_point i);

/* debug */
void	print_matrix(int **matrix, int HEIGHT, int WIDTH);

/* matrix */
void	init_matrix_size_from_macros(t_data *data);
int	**malloc_matrix(t_data *data);
void	random_matrix(t_data *data);
int	**ft_append_tab(int **matrix, int *cell_line);
int	*convert_line_to_cell_line(t_data *data, char *line);
void	init_matrix_size_post_import(t_data *data, int width);
void	import_matrix(t_data *data, char *file_name);
void	init_matrix(t_data *data, char *argv[]);
/* matrix utils */
t_point	init_point(int y, int x);
int	matrixlen(int **matrix);
void	free_matrix(int	***matrix);
