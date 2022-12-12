#include "collinion.h"

int	quit(t_data *data)
{
	clean_exit(data, 0);
	return 0;
}

/* where all pointers are cleaned, especially in a emergency exit */
void	clean_exit(t_data *data, int exit_code)
{
	int	i;
	(void)i;

	if (data)
	{
		free(data->render.colors);
		free(data->window);
		free_matrix(&data->matrix);
		free_matrix(&data->tmp_matrix);
		free(data);
	}
	exit(exit_code);
}

void	error_msg(char *msg)
{
	while (*msg)
		write(2, msg++, 1);
	write(2, "\n", 1);
}

void	exit_msg(t_data *data, char *msg, int ret_exit)
{
	error_msg(msg);
	clean_exit(data, ret_exit);
}
