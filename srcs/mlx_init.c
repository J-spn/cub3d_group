
#include "cub3d.h"

void	ft_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == (void *)0)
		ft_exit_error("Error\nmlx_init failed\n");
	data->mlx_win = mlx_new_window(data->mlx, 1000, 500, PROG_NAME);
	if (data->mlx_win == (void *)0)
		ft_exit_error("Error\nmlx_window failed\n");
	mlx_hook(data->mlx_win, 17, 0, ft_free_exit, data);
	mlx_loop(data->mlx);
}
