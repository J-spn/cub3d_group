

#include "cub3d.h"

size_t	ft_strlen_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	ft_init_data(t_data *data)
{
	data->elems = ft_calloc(1, sizeof(t_element));
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->elems || !data->map)
		ft_exit_error("Error\nMalloc Errror\n");
}

void	ft_printf_split(char **split)
{
	int	i;

	i = -1;
	if (split == NULL || *split == NULL)
		return ;
	while (split[++i])
		printf("%s", split[i]);
}