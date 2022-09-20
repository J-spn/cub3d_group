

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

void	ft_exit_error(char *error)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd(BREAK, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_game_msg(char *msg)
{
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_putstr_fd(msg, STDOUT_FILENO);
	ft_putstr_fd(BREAK, STDOUT_FILENO);
}

void	ft_printf_split(char **split)
{
	int	i;

	i = -1;
	if (split == NULL || *split == NULL)
		return ;
	while (split[++i])
		printf("%s\n", split[i]);
}
