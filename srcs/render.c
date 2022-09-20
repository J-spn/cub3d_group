

#include "cub3d.h"

/*
void	ft_draw_floor(t_data *data, char **map)
{
	int	y;
	int	x;

	int w;
	int h;

	y = 0;
	w = 0;
	h = 0;
	while (y < data->map->height)
	{
		printf("%s", map[y]);
		x = 0;
		while (x < (int)ft_strlen_nl(map[y]))
		{
			if (map[y][x] == '0')
			{
				data->mlx_img = mlx_new_image(data->mlx, w, h);
				data->addr = mlx_get_data_addr(data->mlx_img, &data->bits_per_pixel, \
									&data->line_len, &data->endian);
				h = y;
				while (h < y + ASSET_SIZE)
				{
					w = x;
					while (w < x + ASSET_SIZE)
					{
						ft_mlx_pixel_put(data, w, h, data->map->floor);
						w++;
					}
					h++;
				}
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, x * ASSET_SIZE, y * ASSET_SIZE);
				mlx_destroy_image(data->mlx, data->mlx_img);
			}
			else
			{
				data->mlx_img = mlx_new_image(data->mlx, w, h);
				data->addr = mlx_get_data_addr(data->mlx_img, &data->bits_per_pixel, \
									&data->line_len, &data->endian);
				h = y;
				while (h < y + ASSET_SIZE)
				{
					w = x;
					while (w < x + ASSET_SIZE)
					{
						// mlx_pixel_put(data->mlx, data->mlx_win, w, h, data->map->floor);
						ft_mlx_pixel_put(data, w, h, data->map->ceiling);
						w++;
					}
					h++;
				}
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, x * 48, y * 48);
				mlx_destroy_image(data->mlx, data->mlx_img);
			}
			x++;
		}
		y++;
	}
}
*/

void	ft_color_to_image_test(t_data *data, int x, int y, unsigned int color)
{
	int	w;
	int	h;

	data->mlx_img = mlx_new_image(data->mlx, ASSET_SIZE, ASSET_SIZE);
	data->addr = mlx_get_data_addr(data->mlx_img, &data->bpp, \
						&data->line_bytes, &data->endian);
	// printf("data->endian: %d\n", data->endian);
	// printf("data->line_bytes: %d\n", data->line_bytes);
	// printf("data->bbp: %d\n", data->bpp);
	h = y;
	while (h < y + ASSET_SIZE)
	{
		w = x;
		while (w < x + ASSET_SIZE)
		{
			ft_mlx_pixel_put(data, w, h, color);
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, \
								x * ASSET_SIZE, y * ASSET_SIZE);
	mlx_destroy_image(data->mlx, data->mlx_img);
}

void	ft_draw_floor(t_data *data, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map->height)
	{
		// printf("%s", map[y]);
		x = 0;
		while (x < (int)ft_strlen_nl(map[y]))
		{
			ft_color_to_image_test(data, x, y, data->map->floor);
			x++;
		}
		y++;
	}
}

int	ft_render(t_data *data)
{
	data->map->floor = ft_convert_color(data->elems->floor_clr);
	data->map->ceiling = ft_convert_color(data->elems->ceiling_clr);

	mlx_clear_window(data->mlx, data->mlx_win);
	data->mlx_img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->mlx_img, &data->bpp, \
									&data->line_bytes, &data->endian);
	// ft_mlx_image(data);
	// ft_draw_background(data);
	ft_draw_floor(data, data->map->game_map);
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
	return (1);
}

/* TODO
 try put colors as images

*/
