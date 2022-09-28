

#include "cub3d.h"

/* rotation is calculated using rotation matrice */
void	ft_rotate_right(t_data *data, t_move *mv)
{
	double	dir_x_tmp;
	double	dir_y_tmp;
	double	plane_x_tmp;
	double	plane_y_tmp;

	(void)data;
	dir_x_tmp = mv->dir_x;
	dir_y_tmp = mv->dir_y;
	mv->dir_x = dir_x_tmp * cos(ROT_ANG) - dir_y_tmp * sin(ROT_ANG);
	mv->dir_y = dir_y_tmp * cos(ROT_ANG) + dir_x_tmp * sin(ROT_ANG);
	plane_x_tmp = mv->plane_x;
	plane_y_tmp = mv->plane_y;
	mv->plane_x = plane_x_tmp * cos(ROT_ANG) - plane_y_tmp * sin(ROT_ANG);
	mv->plane_y = plane_y_tmp * cos(ROT_ANG) + plane_x_tmp * sin(ROT_ANG);
}

void	ft_rotate_left(t_data *data, t_move *mv)
{
	double	dir_x_tmp;
	double	dir_y_tmp;
	double	plane_x_tmp;
	double	plane_y_tmp;

	(void)data;
	dir_x_tmp = mv->dir_x;
	dir_y_tmp = mv->dir_y;
	mv->dir_x = dir_x_tmp * cos(-ROT_ANG) - dir_y_tmp * sin(-ROT_ANG);
	mv->dir_y = dir_y_tmp * cos(-ROT_ANG) + dir_x_tmp * sin(-ROT_ANG);
	plane_x_tmp = mv->plane_x;
	plane_y_tmp = mv->plane_y;
	mv->plane_x = plane_x_tmp * cos(-ROT_ANG) - plane_y_tmp * sin(-ROT_ANG);
	mv->plane_y = plane_y_tmp * cos(-ROT_ANG) + plane_x_tmp * sin(-ROT_ANG);
}
