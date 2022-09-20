
#include "cub3d.h"

int	ft_key(int key, t_data *data)
{
	if (key == ESC || key == Q)
	{
		ft_game_msg("Quit\n");
		ft_free_exit(data);
	}
	return (1);
}

void	ft_mlx(t_data *data)
{
	int size_x;
	int size_y;

	size_x = data->map->width * ASSET_SIZE;
	size_y = data->map->height * ASSET_SIZE;
	data->mlx = mlx_init();
	if (data->mlx == (void *)0)
		ft_exit_error("Error\nmlx_init failed\n");
	data->mlx_win = mlx_new_window(data->mlx, size_x, size_y, GAME_NAME);
	if (data->mlx_win == (void *)0)
		ft_exit_error("Error\nmlx_window failed\n");
	ft_render(data);
	// mlx_loop_hook(data->mlx_win, ft_render, data);
	mlx_key_hook(data->mlx_win, ft_key, data);
	mlx_hook(data->mlx_win, 17, 0, ft_free_exit, data);
	mlx_loop(data->mlx);
	// mlx_destroy_image(data->mlx, data->mlx_img);
}
