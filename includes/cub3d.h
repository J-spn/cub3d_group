#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//delete
#include <stdio.h>

# define PROG_NAME "|--cub3D--|"

/*---COLORS---*/
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define BREAK	"\033[0m"

typedef struct s_element {
	char	*north_txtr;
	char	*south_txtr;
	char	*west_txtr;
	char	*east_txtr;
	char	*floor_clr;
	char	*ceilling_clr;
}			t_element;

typedef struct s_map {
	char	**game_map;
	int		height;
	int		player_x;
	int		player_y;
	int		player_start_dir;
}			t_map;

typedef struct s_data {
	void		*mlx_img;
	void		*mlx_win;
	void		*mlx;
	t_element	*elems;
	t_map		*map;
}				t_data;

/*errors.c*/
void	ft_exit_error(char *error);

/*mlx_init.c*/
void	ft_mlx(t_data *data);

/*utils.c*/
size_t	ft_strlen_nl(char *str);
void	ft_init_data(t_data *data);

// delete!!!
void	ft_printf_split(char **str);

/*clear.c*/
int		ft_free_exit(t_data *data);
int		ft_free_exit_msg(t_data *data, char *error);
void	ft_free_all(t_data *data);

/*parsing.c*/
void	ft_parse_file(t_data *data, char *file);

/*parse_identifiers.c*/
int		ft_get_identifier(t_element *elem, char *line);
int		ft_check_identifiers(t_element *elem);

/*parse_map.c*/
int		ft_parse_map(t_data *data, char *line, int fd, char *file);
char	**ft_map_cpy(int height, char **map);

/*check_map.c*/
int		ft_check_map(t_map *map);

#endif
