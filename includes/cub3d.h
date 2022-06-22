/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:43:14 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/22 18:16:21 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../Libft/libft.h"

# define USAGE	"Usage: ./cub3d <file.cub>"

# define PI	3.141592653589793238

enum e_window_res {
	WIDTH = 640,
	HEIGHT = 480
};

enum e_minimap {
	BORDER = 10,
	RADIUS = 225,
	SIDE_LEN = (RADIUS * 2) / 10,
	PL_RADIUS = 4
};

enum e_keycodes {
	KEY_ESC = 65307,
	KEY_A = 97,
	KEY_W = 119,
	KEY_D = 100,
	KEY_S = 115,
	KEY_LEFT = 65361,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364
};

typedef struct s_circle {
	double	x;
	double	y;
	double	radius;
}	t_circle;

typedef struct s_coor {
	double	x;
	double	y;
}	t_coor;

typedef struct s_player {
	t_coor	pos;
	double	angle;
	t_coor	dir;
	t_coor	move;
	double	rotate;
}	t_player;

typedef struct s_img {
	void	*img;
	int		*data;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map {
	char	**map;
	int		ce_color;
	int		fl_color;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_map;

typedef struct s_vars {
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_img		window;
	t_player	player;
}	t_vars;

int		ft_create_trgb(int t, int r, int g, int b);

int		ft_import_map(t_map *map, char *file);
int		ft_parse_textures(t_map *map, int fd);
int		ft_parse_map(t_map *map, int fd);
int		ft_component_surroundings(char **map, int i, int j);
void	ft_get_player_position(t_vars *vars);
int		ft_loop_hook(t_vars *vars);
void	ft_render_minimap(t_vars *vars);
void	ft_move_player(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_vars *vars);

#endif