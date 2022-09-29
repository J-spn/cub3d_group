
#include "cub3d.h"

static double	ft_ticks_per_frame(t_move *mv, int newtick)
{
	mv->ticksum -= mv->ticks[mv->tick_index];
	mv->ticksum += newtick;
	mv->ticks[mv->tick_index] = newtick;
	if (++mv->tick_index == MAXSAMPLES)
		mv->tick_index = 0;
	return (mv->ticksum / MAXSAMPLES);
}

static void	ft_draw_loop(t_data *data)
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
		ft_draw_ray(data, &data->move, x);
		x++;
	}
}

int	ft_render(t_data *data)
{
	static int	tick;
	int			old_tick;

	data->mlx_img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->mlx_img, &data->bpp, \
									&data->size_line, &data->endian);
	old_tick = (int)ft_ticks_per_frame(&data->move, tick);
	data->move.move_speed = (double)((tick - old_tick) / 1000.0 * MOVE_SPEED);
	data->move.rot_ang = (double)((tick - old_tick) / 1000.0 * ROT_ANG);
	ft_draw_bg_ceiling(data);
	ft_draw_loop(data);
	ft_key_hooks(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
	mlx_destroy_image(data->mlx, data->mlx_img);
	tick += 2;
	return (1);
}

//Algorithm

// each square of a map has width 1