#include <collinion.h>

// Vérifie si les coordonnées (x, y) débordent de l'image
int	overflow_image(int y, int x) {
	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return (1);
	return (0);
}

// Met un pixel dans l'image, en gérant les débordements
void	my_mlx_pixel_put(t_image *img, int x, int y, unsigned int color) {
	char	*dst;

	// Vérifie les débordements
	if (overflow_image(y, x)) {
		fprintf(stderr, "[my_pixel_put] Error: Pixel coordinates out of bounds (x=%d, y=%d)\n", x, y);
		return;
	}

	// Calcule la position du pixel dans l'image
	dst = img->address + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
