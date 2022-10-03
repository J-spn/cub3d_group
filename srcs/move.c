/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:22:47 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/10/03 15:22:48 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_up(t_data *data, t_move *mv)
{
	int		x;
	int		y;
	double	speed;

	speed = mv->move_speed;
	x = (int)(mv->pos_x + mv->dir_x * speed);
	y = (int)mv->pos_y;
	if (data->map->game_map[y][x] != '1')
		mv->pos_x += mv->dir_x * speed;
	x = (int)mv->pos_x;
	y = (int)(mv->pos_y + mv->dir_y * speed);
	if (data->map->game_map[y][x] != '1')
		mv->pos_y += mv->dir_y * speed;
}

void	ft_move_down(t_data *data, t_move *mv)
{
	int		x;
	int		y;
	double	speed;

	speed = mv->move_speed;
	x = (int)(mv->pos_x - mv->dir_x * speed);
	y = (int)mv->pos_y;
	if (data->map->game_map[y][x] != '1')
		mv->pos_x -= mv->dir_x * speed;
	x = (int)mv->pos_x;
	y = (int)(mv->pos_y - mv->dir_y * speed);
	if (data->map->game_map[y][x] != '1')
		mv->pos_y -= mv->dir_y * speed;
}

void	ft_move_right(t_data *data, t_move *mv)
{
	int		x;
	int		y;
	double	speed;

	speed = mv->move_speed;
	x = (int)(mv->pos_x - mv->dir_y * speed);
	y = (int)mv->pos_y;
	if (data->map->game_map[y][x] != '1')
		mv->pos_x -= mv->dir_y * speed;
	x = (int)mv->pos_x;
	y = (int)(mv->pos_y + mv->dir_x * speed);
	if (data->map->game_map[y][x] != '1')
		mv->pos_y += mv->dir_x * speed;
}

void	ft_move_left(t_data *data, t_move *mv)
{
	int		x;
	int		y;
	double	speed;

	speed = mv->move_speed;
	x = (int)(mv->pos_x + mv->dir_y * speed);
	y = (int)mv->pos_y;
	if (data->map->game_map[y][x] != '1')
		mv->pos_x += mv->dir_y * speed;
	x = (int)mv->pos_x;
	y = (int)(mv->pos_y - mv->dir_x * speed);
	if (data->map->game_map[y][x] != '1')
		mv->pos_y -= mv->dir_x * speed;
}
