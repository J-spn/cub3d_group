
#include "cub3d.h"

int	ft_key(int key, t_data *data)
{
	if (key == ESC)
	{
		ft_game_msg("Quit\n");
		ft_free_exit(data);
	}
	else if (key == W)
		ft_move_up(data, &data->move);
	else if (key == S)
		ft_move_down(data, &data->move);
	else if (key == A)
		ft_move_left(data, &data->move);
	else if (key == D)
		ft_move_right(data, &data->move);
	else if (key == LEFT)
		ft_rotate_left(data, &data->move);
	else if (key == RIGHT)
		ft_rotate_right(data, &data->move);
	return (1);
}

void	ft_mlx(t_data *data)
{
	// int size_x;
	// int size_y;

	// size_x = data->map->width * WALL_SIZE;
	// size_y = data->map->height * WALL_SIZE;
	data->mlx = mlx_init();
	if (data->mlx == (void *)0)
		ft_exit_error("Error\nmlx_init failed\n");
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, GAME_NAME);
	if (data->mlx_win == (void *)0)
		ft_exit_error("Error\nmlx_window failed\n");
	mlx_loop_hook(data->mlx, &ft_render, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, &ft_key, data);
	mlx_hook(data->mlx_win, 17, 0, &ft_free_exit, data);
	mlx_loop(data->mlx);
}
