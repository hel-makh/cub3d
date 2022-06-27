/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:43:14 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/27 18:15:36 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <sys/time.h>
# include <mlx.h>
# include "../Libft/libft.h"

# define USAGE	"Usage: ./cub3d <file.cub>"

/***********************[ Enumeration ]***********************/
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

enum e_window {
	WIDTH = 640,
	HEIGHT = 480,
	FPS_X = 5,
	FPS_Y = 15
};

enum e_minimap {
	BORDER = 10,
	RADIUS = 75,
	CENTER = BORDER + RADIUS,
	C_VISIBLE = 10,
	C_SIDE_LEN = (RADIUS * 2) / C_VISIBLE,
	PL_RADIUS = 2
};

enum e_player {
	SPEED = 3,
	ROT_SPEED = 4,
	FOV	= 90
};

/************************[ Structers ]************************/
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

typedef struct s_map {
	char	**map;
	int		ce_color;
	int		fl_color;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_map;

typedef struct s_img {
	void	*img;
	int		*data;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	t_img	img;
	int		fps;
}	t_mlx;

typedef struct s_vars {
	t_mlx		mlx;
	t_map		map;
	t_player	player;
}	t_vars;

/**************************[ Utils ]**************************/
long	ft_get_current_time(void);
int		ft_create_trgb(int t, int r, int g, int b);
double	ft_radian_operations(double radian, double amout);
double	ft_get_distance(t_coor poin1, t_coor point2);
int		ft_is_in_circle(double x, double y, t_circle circle);

/*************************[ Parsing ]*************************/
int		ft_import_map(t_map *map, char *file);
int		ft_parse_textures(t_map *map, int fd);
int		ft_parse_map(t_map *map, int fd);
int		ft_component_surroundings(char **map, int i, int j);

/************************[ Movements ]************************/
void	ft_get_player_position(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_vars *vars);
void	ft_move_player(t_vars *vars);

/************************[ RayCasting ]***********************/
t_coor	ft_get_hit_wall(t_vars *vars, double angle, int *direction);

/************************[ Rendering ]************************/
int		frame_rendering(t_vars *vars);
void	ft_render_minimap(t_vars *vars);
void	ft_draw_rays(t_vars *vars, t_circle minimap);
void	ft_render_3d_scene(t_vars *vars);

#endif