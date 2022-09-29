#include "cub3d.h"

void	ft_free_elems(t_data *data)
{
	ft_memdel(data->elems->north_txtr);
	ft_memdel(data->elems->south_txtr);
	ft_memdel(data->elems->west_txtr);
	ft_memdel(data->elems->east_txtr);
	ft_memdel(data->elems->floor_clr);
	ft_memdel(data->elems->ceiling_clr);
}

void	ft_free_all(t_data *data)
{
	if (data->mlx != (void *)0)
		mlx_destroy_window(data->mlx, data->mlx_win);
	// if (data->mlx_img != (void *)0)
	// 	mlx_destroy_image(data->mlx, data->mlx_img);
	ft_free_elems(data);
	ft_memdel(data->elems);
	ft_free_split(data->map->game_map);
	ft_memdel(data->map);
}

int	ft_free_exit_msg(t_data *data, char *error)
{
	ft_free_all(data);
	getchar();
	if (error != NULL)
		ft_exit_error(error);
	exit(EXIT_SUCCESS);
}

int	ft_free_exit(t_data *data)
{
	ft_free_all(data);
	// getchar();
	exit(EXIT_SUCCESS);
}
