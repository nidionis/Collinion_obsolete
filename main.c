#include <colinion.h>

 t_data	*malloc_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		clean_exit(data, -1);
	return (data);
}

void	clean_exit(t_data *data, int exit_code)
{
	int	i;

	if (data)
	{
		if (data->map)
			ft_free_split(&data->map);
		free(data);
	}
	exit(exit_code);
}

void	exit_msg(t_data *data, char *msg, int ret_exit)
{
	error_msg(msg);
	clean_exit(data, ret_exit);
}
int	main(int argc, char *argv[])
{
	t_image		img;
	t_data		*data;

	(void)img;
	data = NULL;
	if (argc != 2)
	{
		error_msg("Needs a path to the map file only");
		clean_exit(data, -2);
	}
	else
	{
		data = malloc_data();
		data->window = malloc(sizeof(t_window));
		window->mlx = mlx_init();
		window->init = mlx_new_window(window->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "colinion");
		mlx_hook(data->window->init, 2, 1L << 0, &key_event, data);
		mlx_loop_hook(data->window->mlx, &ray_cast, data);
		mlx_hook(data->window->init, 17, 1L << 17, &exit_game, data);
		mlx_loop(data->window->mlx);
	}
//	clean_exit(data, 0);
}
