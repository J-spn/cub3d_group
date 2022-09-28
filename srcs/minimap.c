

#include "cub3d.h"

void	ft_draw_cell(t_data *data, int x, int y, int color)
{
	int x_start;
	int y_start;

	y_start = y;
	while (y_start < y + 10 - 1)
	{
		x_start = x;
		while (x_start < x + 10 - 1)
		{
			ft_mlx_pixel_put(data, x_start, y_start, color);
			x_start++;
		}
		y_start++;
	}
}

void	ft_set_player_pos(t_data *data, t_move *mv)
{
	int	x;
	int	y;

	mv->pos_x /= 100 * 10;
	mv->pos_y /= 100 * 10;
	y = mv->pos_y;
	while (y++ < mv->pos_y + (WIN_HEIGHT / 100) - 1)
	{
		x = mv->pos_x;
		while (x < mv->pos_x + (WIN_WIDTH / 100) - 1)
			ft_mlx_pixel_put(data, x++, y, YELLOW_INT);
	}
}

void	ft_draw_2Dmap(t_data *data)
{
	int	x;
	int y;
	int	mini_x;
	int	mini_y;

	mini_x = WIN_WIDTH / 100;
	mini_y = WIN_HEIGHT / 100;
	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < (int)ft_strlen_nl(data->map->game_map[y]))
		{
			if (data->map->game_map[y][x] == '1')
				ft_draw_cell(data, x * mini_x + 1, y * mini_y - 1, PURPLE_INT);
			else if (data->map->game_map[y][x] != ' ')
				ft_draw_cell(data, x * mini_x + 1, y * mini_y - 1, 0XFFFFF);
		}
	}
}
