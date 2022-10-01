

#include "cub3d.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	ft_draw_line(t_data *data, t_values *vals, int color)
{
	float	delta_x;
	float	delta_y;
	int		pixels;
	float	pixel_x;
	float	pixel_y;

	delta_x = vals->x2 - vals->x1;
	delta_y = vals->y2 - vals->y1;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));

	delta_x /= pixels;
	delta_y /= pixels;

	pixel_x = vals->x1;
	pixel_y = vals->y1;
	while (pixels)
	{
		ft_mlx_pixel_put(data, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}
