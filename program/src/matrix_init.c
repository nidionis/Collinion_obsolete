#include <collinion.h>

void	init_matrix_size_from_macros(t_data *data)
{
	data->matrix_size[H] = data->window->size[H] / PIX_PER_SQUARE;
	data->matrix_size[W] = data->window->size[W] / PIX_PER_SQUARE;
	data->render.pix_size = PIX_PER_SQUARE;
}

int	**malloc_matrix(t_data *data)
{
	int	**matrix;
	int	size[2];
	int i;

	size[W] = data->matrix_size[W];
	size[H] = data->matrix_size[H];
	matrix = malloc((size[H] + 1) * sizeof(int *));
	if (!matrix)
		exit_msg(data, "[random_matrix] did not malloc", 1);
	for (i = 0; i < size[H]; i++)
	{
		matrix[i] = malloc(size[W] * sizeof(int));
		if (!matrix)
			exit_msg(data, "[random_matrix] did not malloc", 1);
	}
	matrix[size[H]] = NULL;
	return matrix;
}

void	random_matrix(t_data *data)
{
	t_point	i;
	int	**matrix;
	int	cell;
	int	border;

	init_matrix_size_from_macros(data);
	matrix = malloc_matrix(data);
	data->tmp_matrix = malloc_matrix(data);
	for (i.y = 0; i.y < data->matrix_size[H]; i.y++) {
		for (i.x = 0; i.x < data->matrix_size[W]; i.x++) {
			border = is_border(data, i);
			if (border) {
				matrix[i.y][i.x] = WALL;
				data->tmp_matrix[i.y][i.x] = WALL;
			}
			else {
				cell =  rand() % (int)NB_TYPES;
				matrix[i.y][i.x] = cell;
			}
		}
	}
	data->matrix = matrix;
}

int	**ft_append_tab(int **matrix, int *cell_line)
{
	int	tab_len;
	int	**new_tab;

	if (!cell_line)
		return (matrix);
	tab_len = 0;
	if (matrix)
	while (matrix[tab_len])
		tab_len++;
	new_tab = malloc((tab_len++ + 2) * sizeof(int *));
	if (!new_tab)
		return (NULL);
	new_tab[tab_len--] = NULL;
	new_tab[tab_len] = cell_line;
	while (tab_len--)
		new_tab[tab_len] = matrix[tab_len];
	free(matrix);
	matrix = NULL;
	return (new_tab);
}

int	*convert_line_to_cell_line(t_data *data, char *line)
{
	int	*cell_line;
	int	i;

	cell_line = malloc(sizeof(int) * strlen(line)); 
	if (!cell_line)
		exit_msg(data, "[convert_line_to_cell_line] pb malloc", 1);
	i = 0;
	while(line[i])
	{
		cell_line[i] = (int)(line[i] - '0');
		i++;
	}
	return cell_line;
}

void	init_matrix_size_post_import(t_data *data, int width)
{
	int **matrix = data->matrix;
	int pix_size[2];

	data->matrix_size[W] = width;
	data->matrix_size[H] = matrixlen(matrix);
	pix_size[W] = data->window->size[W] / data->matrix_size[W];
	pix_size[H] = data->window->size[H] / data->matrix_size[H];

	data->render.pix_size = pix_size[H];
	if (pix_size[W] < pix_size[H])
		data->render.pix_size = pix_size[W];
}

void	import_matrix(t_data *data, char *file_name)
{
	int 		fd;
	unsigned int 	width;
	char		*line;
	int		*cell_line;
	int		**matrix;

	fd = open(file_name, O_RDONLY);
	matrix = NULL;
	if (fd < 3)
		exit_msg(data, "[import_matrix] wrong file desctiptor", 1);
	line = get_next_line(fd);
	width = strlen(line);
	while (line) {
		if (strlen(line) != width)
			exit_msg(data, \
	"[import_matrix] warning: lines have different lens\n\
	make shure your map is a rectangle\n\
	Full some space with a useless value ('z')\n\
					", 1);
		cell_line = convert_line_to_cell_line(data, line);
		matrix = ft_append_tab(matrix, cell_line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	data->matrix = matrix;
	init_matrix_size_post_import(data, width);
	data->tmp_matrix = malloc_matrix(data);
}

void	init_matrix(t_data *data, char *argv[])
{
	(void)argv;

	if (argv[1])
		import_matrix(data, argv[1]);
	else
		random_matrix(data);
}

