#include <colinion.h>

 t_data	*malloc_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		clean_exit(data, -1);
	return (data);
}

void	free_matrix(char ***m)
{
	char	*line;

	if (m && *m)
	{
		line = **m;
		while (*line)
		{
			free(line);
			line++;
		}
		free(*m);
		*m = NULL;
	}
}

void	clean_exit(t_data *data, int exit_code)
{
	int	i;

	if (data)
	{
		if (data->matrix)
			free(&data->matrix);
		if (data->next_matrix)
			free(&data->matrix);
		free(data);
	}
	exit(exit_code);
}

void	exit_msg(t_data *data, char *msg, int ret_exit)
{
	error_msg(msg);
	clean_exit(data, ret_exit);
}

char	**malloc_matrix(int	len[2])
{
	char	**mat;
	int		i = 0;

	mat = malloc(sizeof(char *) * len[_y]);
	if (!mat)
		clean_exit(data, -1);
	while (i < len[_y])
	{
		mat[i] = malloc(sizeof(char) * len[_x]);
		i++;
	}
	return (mat);
}

void	malloc_matrixes(t_data *data)
{
	data->matrix_len[_y] = (int)SCREEN_HEIGHT / (int)PIX_PER_SQUARE;
	data->matrix_len[_x] = (int)SCREEN_WIDTH / (int)PIX_PER_SQUARE;
	data->matrix = malloc_matrix(data->matrix_len);
	data->next_matrix = malloc_matrix(data->matrix_len);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = malloc_data();
	malloc_matrixes(data);
	enum case_type { ALIVE, DEAD, NB_CASE_TYPE };

}
