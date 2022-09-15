

#include "cub3d.h"

int	ft_check_ext(char *file)
{
	char	*dot;

	dot = ft_strchr(file, '.');
	if (dot == NULL)
		return (0);
	if (ft_strcmp(dot, ".cub") == 0)
		return (1);
	return (0);
}

static char	*ft_get_info(t_data *data, int fd)
{
	char	*line;
	int		res;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strcmp(line, "\n") != 0)
		{
			res = ft_get_identifier(data->elems, line);
			if (res == -1)
				return (line);
			else if (res == 0)
			{
				free(line);
				return (NULL);
			}
		}
		free(line);
	}
	return (NULL);
}

void	ft_parse_file(t_data *data, char *file)
{
	int			fd;
//	t_element	*elem;
	char		*line;

//	elem = data->elems;
	if (!ft_check_ext(file))
		ft_exit_error("Error\nInvalid map extension\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error\nOpening file\n");
	line = ft_get_info(data, fd);
	if (line == NULL || !ft_check_identifiers(data->elems))
	{
		close(fd);
		ft_free_exit_msg(data, "Error\nInvalid file\n");
	}
	if (!ft_parse_map(data, line, fd, file))
	{
		close(fd);
		ft_free_exit_msg(data, "Error\nInvalid map\n");
	}
	close(fd);
	// printf("NO: %s\n", elem->north_txtr);
	// printf("SO: %s\n", elem->south_txtr);
	// printf("WE: %s\n", elem->west_txtr);
	// printf("EA: %s\n", elem->east_txtr);
	// printf("F: %s\n", elem->floor_clr);
	// printf("C: %s\n", elem->ceilling_clr);

	//проверять все ли текстуры есть после назначения
}
