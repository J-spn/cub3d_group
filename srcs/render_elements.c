

#include "cub3d.h"

static unsigned int	ft_str_to_inthex(char *str)
{
	unsigned int	hex;
	unsigned int	byte;
	int				i;

	hex = 0;
	i = 0;
	while (str[i])
	{
		byte = str[i];
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		hex = hex << 4;
		hex |= byte;
		i++;
	}
	return (hex);
}

unsigned int	ft_convert_color(char *rgb)
{
	char			**split;
	char			*color;
	char			*itoa;
	int				i;
	unsigned int	num;

	split = ft_split(rgb, ',');
	color = malloc(sizeof(char) * 9);
	if (color == NULL)
		return (-1);
	color[0] = '\0';
	i = -1;
	while (split[++i])
	{
		itoa = ft_itoa_base(ft_atoi(split[i]), 16, 'u');
		ft_strcat(color, itoa);
		ft_memdel(itoa);
	}
	ft_free_split(split);
	num = ft_str_to_inthex(color);
	ft_memdel(color);
	return (num);
}

void	ft_mlx_image(t_data *data)
{
	(void)data;
	// data->mlx_img = mlx_new_image(data->mlx, w, h);
	// data->addr = mlx_get_data_addr(data->mlx_img, &data->bits_per_pixel, \
	// 					&data->line_len, &data->endian);
	// h = y;
	// while (h < y + ASSET_SIZE)
	// {
	// 	w = x;
	// 	while (w < x + ASSET_SIZE)
	// 	{
	// 		ft_mlx_pixel_put(data, w, h, data->map->floor);
	// 		w++;
	// 	}
	// 	h++;
	// }
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, x * ASSET_SIZE, y * ASSET_SIZE);
	// mlx_destroy_image(data->mlx, data->mlx_img);
}
