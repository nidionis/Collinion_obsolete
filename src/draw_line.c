#include <colinion.h>

int	overflow_image(int y, int x)
{
	if (x < 0 || y < 0 || x > SCREEN_WIDTH || y > SCREEN_HEIGHT)
		return 1;
	else
		return 0;
}
void	my_mlx_pixel_put(t_image *img, int x, int y, unsigned int color)
{
	char	*dst;

	if (overflow_image(y, x))
		fprintf(stderr, "[my_pixel_put] image_overflow\n");
	dst = img->address + (y * img->line_len + x * (img->bpp / 8));
 	*(unsigned int*)dst = color;
}
