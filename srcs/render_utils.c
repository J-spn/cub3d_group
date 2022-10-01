

#include "cub3d.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int *)pixel = color;
}
