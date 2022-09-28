#include "cub3d.h"

int main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
		ft_exit_error("Error\nToo few arguments. Try this: ./cub3D [map.cub]\n");
	else if (argc > 2)
		ft_exit_error("Error\nToo many arguments. Try this: ./cub3D [map.cub]\n");
	ft_bzero(&data, sizeof(t_data));
	ft_init_data(&data);
	ft_parse_file(&data, argv[1]);
	ft_draw(&data);
	ft_free_exit(&data);
	return (0);
}
