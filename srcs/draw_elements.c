

#include "cub3d.h"

void	ft_draw_bg_ceiling(t_data *data)
{
	int x;
	int y;

	y = -1;
	while (++y < WIN_HEIGHT / 2)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			ft_mlx_pixel_put(data, x, y, data->map->ceiling);
	}
	while (y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			ft_mlx_pixel_put(data, x, y, data->map->floor);
		y++;
	}
}

void	ft_draw_ray(t_data *data, int x)
{
	t_move	*mv;
	int		clr;
	// int	y;

	// y = data->move.draw_start;
	// while (y < data->move.draw_end)
	// {
	// 	if (data->move.side == 1)
	// 		ft_mlx_pixel_put(data, x, y, PURPLE_INT / 2);
	// 	else
	// 		ft_mlx_pixel_put(data, x, y, PURPLE_INT);
	// 	y++;
	// }
	mv = &data->move;
	clr = PURPLE_INT;
	if (data->move.side == 1)
		clr = GREY_INT;
	ft_draw_line(data, &(t_values){x, mv->draw_start, x, mv->draw_end}, clr);
}
