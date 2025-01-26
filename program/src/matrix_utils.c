#include <collinion.h>

t_point	init_point(int x, int y)
{
	return (t_point){x, y};
}

int	is_border(t_data *data, t_point i)
{
	int	is_true;

	if (i.x == 0)
		is_true = WE;
	else if	(i.y == 0)
		is_true = NO;
	else if (i.x == data->matrix_size[W] - 1)
		is_true = EA;
	else if (i.y == data->matrix_size[H] - 1)
		is_true = SO;
	else
		is_true = FALSE;
	return (is_true);
}

int	matrixlen(int **matrix)
{
	int	len;

	len = 0;
	if (matrix) {
		while (matrix[len])
			len++;
	}
	return (len);
}

void	free_matrix(int	***matrix)
{
	int	**mat;
	int	i = 0;;

	if (*matrix) {
		mat = *matrix;
		while (mat[i]){
			free(mat[i]);
			mat[i++] = NULL;
		}
		free(mat);
		mat = NULL;
	}
}
