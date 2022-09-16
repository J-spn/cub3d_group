

#include "cub3d.h"

/*
* NO
* SO
* WE
* EA
* F
* C
*/

static int	ft_set_identifier(char **texture, const char *id, char *line)
{
	char	*trim;
	char	**split;

	trim = ft_strtrim(line, " ");
	if (!trim)
		return (0);
	split = ft_split(trim, ' ');
	if (ft_splitlen(split) != 2 || ft_strcmp(split[0], id) != 0)
	{
		free(trim);
		ft_free_split(split);
		return (0);
	}
	ft_memdel(trim);
	trim = ft_strtrim(split[1], "\n");
	ft_free_split(split);
	*texture = ft_strdup(trim);
	ft_memdel(trim);
	return (1);
}

int	ft_get_identifier(t_element *elem, char *line)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		return(ft_set_identifier(&(elem->north_txtr), "NO", line));
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		return(ft_set_identifier(&(elem->south_txtr), "SO", line));
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
		return(ft_set_identifier(&(elem->west_txtr), "WE", line));
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
		return(ft_set_identifier(&(elem->east_txtr), "EA", line));
	else if (ft_strchr(line, 'F'))
		return(ft_set_identifier(&(elem->floor_clr), "F", line));
	else if (ft_strchr(line, 'C'))
		return(ft_set_identifier(&(elem->ceilling_clr), "C", line));
	return (-1);
}

static int	ft_open_texture(char *texture)
{
	int	fd;

	if (texture == NULL)
		return (0);
	fd = open(texture, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static int	ft_validate_color(char *color)
{
	char	**split;
	int		i;
	int		j;

	if (color == NULL || ft_strlen(color) == 0)
		return (0);
	split = ft_split(color, ',');
	if (!split)
		return (0);
	if (ft_splitlen(split) != 3)
		return (ft_free_split(split));
	i = -1;
	while (split[++i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j++]))
				return (ft_free_split(split));
		}
		if (ft_atoll(split[i]) < 0 || ft_atoll(split[i]) > 255)
			return (ft_free_split(split));
	}
	ft_free_split(split);
	return (1);
}

int	ft_check_identifiers(t_element *elem)
{
	if (!ft_open_texture(elem->north_txtr))
		return (0);
	if (!ft_open_texture(elem->south_txtr))
		return (0);
	if (!ft_open_texture(elem->east_txtr))
		return (0);
	if (!ft_open_texture(elem->west_txtr))
		return (0);
	if (!ft_validate_color(elem->floor_clr))
		return (0);
	if (!ft_validate_color(elem->ceilling_clr))
		return (0);
	return (1);
}
