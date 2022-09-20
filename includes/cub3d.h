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

# define GAME_NAME "|--cub3D--|"
# define WIN_HEIGHT	500
# define WIN_WIDTH	500

# define ASSET_SIZE	48

/*KEYS*/
# define ESC	53
# define Q		12

/*---COLORS---*/
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define BREAK	"\033[0m"

// typedef strcut s_image {

// }

typedef struct s_element {
	void	*north_txtr;
	void	*south_txtr;
	void	*west_txtr;
	void	*east_txtr;
	void	*floor_clr;
	void	*ceiling_clr;
}			t_element;

typedef struct s_map {
	char			**game_map;
	int				height;
	int				width;
	int				player_x;
	int				player_y;
	char			player_start_dir;
	unsigned int	floor;
	unsigned int	ceiling;
}					t_map;

typedef struct s_data {
	void		*mlx_img;
	void		*mlx_win;
	void		*mlx;
	int			bpp;
	int			line_bytes;	//amount of bytes taken by one row of our image
							//image_width * (bpp / 8).
	int			endian;
	char		*addr;
	t_element	*elems;
	t_map		*map;
}				t_data;

/*errors.c*/
// void	ft_exit_error(char *error);

/*mlx_init.c*/
void			ft_mlx(t_data *data);

/*utils.c*/
size_t			ft_strlen_nl(char *str);
void			ft_init_data(t_data *data);
void			ft_exit_error(char *error);
void			ft_game_msg(char *msg);

// delete!!!
void			ft_printf_split(char **str);

/*clear.c*/
int				ft_free_exit(t_data *data);
int				ft_free_exit_msg(t_data *data, char *error);
void			ft_free_all(t_data *data);
void			ft_free_elems(t_data *data);

/*parsing.c*/
void			ft_parse_file(t_data *data, char *file);

/*parse_identifiers.c*/
int				ft_get_identifier(t_element *elem, char *line);
int				ft_check_identifiers(t_element *elem);

/*parse_colors.c*/
int				ft_set_color(char ***texture, const char *id, char *line);
int				ft_validate_color(char *color);

/*parse_map.c*/
int				ft_parse_map(t_data *data, char *line, int fd, char *file);
char			**ft_map_cpy(int height, char **map);

/*check_map.c*/
int				ft_check_map(t_map *map);

/*render.c*/
int				ft_render(t_data *data);

/*render_utils.c*/
void			ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_color_to_image(t_data *data, int x, int y, unsigned int color);

/*render_elements.c*/
unsigned int	ft_convert_color(char *rgb);
void			ft_mlx_image(t_data *data);

#endif
