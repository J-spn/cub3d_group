
#include "cub3d.h"

void	ft_draw_loop(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ft_calc_ray_pos_dir(&data->move, x);
		ft_calc_intersection_dist(&data->move);
		data->move.is_wall = 0;
		ft_calc_step_first_intersect(&data->move);
		ft_dda(&data->move, data->map->game_map);
		ft_calc_wall_dist_and_ray_height(&data->move);
		ft_draw_ray(data, x);
		x++;
	}
}

int	ft_render(t_data *data)
{
	// mlx_clear_window(data->mlx, data->mlx_win);
	data->mlx_img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->mlx_img, &data->bpp, \
									&data->size_line, &data->endian);
	ft_draw_bg_ceiling(data);
	ft_draw_loop(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
	mlx_destroy_image(data->mlx, data->mlx_img);
	return (1);
}

//Algorithm

// each square of a map has width 1