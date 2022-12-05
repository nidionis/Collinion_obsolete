#include "colinion.h"

/* where all pointers are cleaned, especially in a emergency exit */
void	clean_exit(t_data *data, int exit_code)
{
	int	i;
	(void)i;

	if (data)
	{
		//ft_free_matrix();
		free(data->render.colors);
		free(data->window);
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
