

#include "cub3d.h"

int	ft_validate_color(char *color)
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
		j = -1;
		while (split[i][++j])
		{
			if (split[i][j] != ' ' && !ft_isdigit(split[i][j]))
				return (ft_free_split(split));
		}
		if (ft_atoll(split[i]) < 0 || ft_atoll(split[i]) > 255)
			return (ft_free_split(split));
	}
	ft_free_split(split);
	return (1);
}

int	ft_set_color(char ***texture, const char *id, char *line)
{
	int		count;
	char	*trim;
	int		i;

	count = 0;
	i = -1;
	while (line[++i] != '\0' && line[i] != '\n')
	{
		if (line[i] == ',')
			++count;
	}
	if (count != 2)
		return (ft_memdel(line));
	trim = ft_strtrim(line, id);
	ft_memdel(line);
	(**texture) = ft_strtrim(trim, "\n");
	ft_memdel(trim);
	return (1);
}
