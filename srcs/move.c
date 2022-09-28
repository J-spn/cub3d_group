

#include "cub3d.h"

void	ft_move_up(t_data *data, t_move *mv)
{
	int	x;
	int	y;

	x = (int)(mv->pos_x + mv->dir_x * MOVE_SPEED);
	y = mv->pos_y;
	if (data->map->game_map[y][x] != '1')
		mv->pos_x += mv->dir_x * MOVE_SPEED;
	x = mv->pos_x;
	y = (int)(mv->pos_y + mv->dir_y * MOVE_SPEED);
	if (data->map->game_map[y][x] != '1')
		mv->pos_y += mv->dir_y * MOVE_SPEED;
}

void	ft_move_down(t_data *data, t_move *mv)
{
	int	x;
	int	y;

	x = (int)(mv->pos_x - mv->dir_x * MOVE_SPEED);
	y = mv->pos_y;
	if (data->map->game_map[y][x] != '1')
		mv->pos_x -= mv->dir_x * MOVE_SPEED;
	x = mv->pos_x;
	y = (int)(mv->pos_y - mv->dir_y * MOVE_SPEED);
	if (data->map->game_map[y][x] != '1')
		mv->pos_y -= mv->dir_y * MOVE_SPEED;
}

void	ft_move_right(t_data *data, t_move *mv)
{
	int	x;
	int	y;

	x = (int)(mv->pos_x - mv->dir_y * MOVE_SPEED);
	y = (int)mv->pos_y;
	if (data->map->game_map[y][x] != '1')
		mv->pos_x -= mv->dir_y * MOVE_SPEED;
	x = (int)mv->pos_x;
	y = (int)(mv->pos_y + mv->dir_x * MOVE_SPEED);
	if (data->map->game_map[y][x] != '1')
		mv->pos_y += mv->dir_x * MOVE_SPEED;
}

void	ft_move_left(t_data *data, t_move *mv)
{
	int	x;
	int	y;

	x = (int)(mv->pos_x + mv->dir_y * MOVE_SPEED);
	y = mv->pos_y;
	if (data->map->game_map[y][x] != '1')
		mv->pos_x += mv->dir_y * MOVE_SPEED;
	x = mv->pos_x;
	y =(int)(mv->pos_y - mv->dir_x * MOVE_SPEED);
	if (data->map->game_map[y][x] != '1')
		mv->pos_y -= mv->dir_x * MOVE_SPEED;
}
