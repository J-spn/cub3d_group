
#include "cub3d.h"

static int	ft_check_eachchar(char **map)
{
	int	x;
	int	y;
	int	ground;
	int	player;

	y = -1;
	ground = 0;
	player = 0;
	while (map[++y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == '0' || map[y][x] == '1')
				ground++;
			if (map[y][x] == 'N' || map[y][x] == 'S' || \
				map[y][x] == 'W' || map[y][x] == 'E')
				player++;
			x++;
		}
	}
	if (ground == 0 || (player == 0 | player > 1))
		return (0);
	return (1);
}

static int	ft_check_chars(char **map, const char *set)
{
	int		x;
	int		y;
	char	*trim;

	y = 0;
	while (map[y])
	{
		x = 0;
		trim = ft_strtrim(map[y], " ");
		if (ft_strcmp(trim, "\n") == 0)
			return (ft_memdel(trim));
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (ft_strchr(set, map[y][x]) == NULL)
				return (0);
			x++;
		}
		ft_memdel(trim);
		y++;
	}
	return (1);
}

char	**ft_map_cpy(int height, char **map)
{
	int		x;
	int		y;
	char	**map_tmp;

	map_tmp = (char **)malloc(sizeof(char *) * (height + 1));
	if (map_tmp == NULL)
		return (NULL);
	y = -1;
	while (map[++y])
		map_tmp[y] = ft_strdup(map[y]);
	map_tmp[y] = NULL;
	y = -1;
	while (map_tmp[++y])
	{
		x = 0;
		while (map_tmp[y][x])
		{
			if (map_tmp[y][x] == ' ')
				(map_tmp)[y][x] = '0';
			x++;
		}
	}
	return (map_tmp);
}

// int	ft_check_walls_bottom_left(char **map_tmp, int y, int x)
// {
// 	while (map_tmp[y])
// 	{
// 		printf("%s", map_tmp[y]);
// 		while ()
// 	}
// }
/*
int	ft_check_walls(t_map *map, char **map_tmp)
{
	int		x;
	int		y;
	int		up;

	y = 0;
	x = 0;
	up = 0;
	while (map_tmp[y][x] && map_tmp[y][x] == '0')
		x++;
	while (map_tmp[y] && y <= (map->height / 2) - 1)
	{
		// x = 0;
		printf("%s", map_tmp[y]);
		while (map_tmp[y][x] && map_tmp[y][x] != '\n')
		{
			while (map_tmp[y][x] == '1')
			{
				printf("%c", map_tmp[y][x]);
				x++;
			}
			if (map_tmp[y][x] != '1' && map_tmp[y][x] != '\n')
				return (0);
			if (map_tmp[y + 1][x] == '1')
				break ;
			x++;
		}
		y++;
	}
	return (1);
}
*/

int	ft_is_surrounded(char **map_tmp, int y, int x)
{
	int	yes;

	yes = 0;
	if (!map_tmp[y][x])
		return (0);
	if (map_tmp[y + 1][x] && map_tmp[y + 1][x] == '1')
		yes += 1;
	if (y > 0 && map_tmp[y - 1][x] && map_tmp[y - 1][x] == '1')
		yes += 1;
	if (map_tmp[y][x - 1] && map_tmp[y][x - 1] == '1')
		yes += 1;
	if (map_tmp[y][x + 1] && map_tmp[y][x + 1] == '1')
		yes += 1;
	// printf("yes: %d\n", yes);
	return (yes);
}

int	ft_check_walls(t_map *map, char **map_tmp)
{
	int		x;
	int		y;

	x = 0;
	y = (map->height / 2) - 1;
	while (map_tmp[y][x] && map_tmp[y][x] == ' ')
		x++;
	while (map_tmp[y])
	{
		printf("%s", map_tmp[y]);
		while (map_tmp[y][x] && map_tmp[y][x] != '\n')
		{
			if (!ft_is_surrounded(map_tmp, y, x))
			{
				printf("not surrounded\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_map(t_map *map)
{
	int		i;
	char	**map_tmp;

	i = 0;
	if (!ft_check_chars(map->game_map, "01NSWE "))
		return (0);
	if (!ft_check_eachchar(map->game_map))
		return (0);
	map_tmp = ft_map_cpy(map->height, map->game_map);
	// ft_printf_split(map_tmp);
	ft_printf_split(map->game_map);
	if (!ft_check_walls(map, map->game_map))
	{
		ft_free_split(map_tmp);
		return (0);
	}
	ft_free_split(map_tmp);
	return (1);
}
