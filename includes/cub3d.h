/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:43:14 by hel-makh          #+#    #+#             */
/*   Updated: 2022/07/03 12:09:06 by hel-makh         ###   ########.fr       */
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
# include <libft.h>
# include <mlx.h>

# define USAGE	"Usage: ./cub3d <file.cub>"

/***********************[ Enumeration ]***********************/
# if defined(__linux__)

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

# elif defined(__APPLE__) && defined(__MACH__)

enum e_keycodes {
	KEY_ESC = 53,
	KEY_A = 0,
	KEY_W = 13,
	KEY_D = 2,
	KEY_S = 1,
	KEY_LEFT = 123,
	KEY_UP = 126,
	KEY_RIGHT = 124,
	KEY_DOWN = 125
};

# endif

enum e_window {
	WIDTH = 1280,
	HEIGHT = 720,
	FPS_X = 5,
	FPS_Y = 15
};

enum e_minimap {
	BORDER = 10,
	RADIUS = 75,
	CENTER = RADIUS,
	C_VISIBLE = 10,
	C_SIDE_LEN = (RADIUS * 2) / C_VISIBLE,
	PL_RADIUS = 2
};

enum e_player {
	SPEED = 15,
	ROT_SPEED = 10,
	MOUSE_ROT_SPEED = 13,
	FOV	= 60
};

/************************[ Structers ]************************/
typedef struct s_circle {
	double	x;
	double	y;
	double	radius;
}	t_circle;

typedef struct s_dim {
	double	width;
	double	height;
}	t_dim;

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
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_map {
	char	**map;
	int		ce_color;
	int		fl_color;
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
}	t_map;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	t_img	img;
	t_img	minimap;
	int		fps;
}	t_mlx;

typedef struct s_vars {
	t_mlx		mlx;
	t_map		map;
	t_player	player;
}	t_vars;

typedef struct s_render {
	double	degree;
	double	angle;
	t_coor	hit_wall;
	int		direc;
	double	dist;
	t_dim	wall_dim;
	double	wall_orig_height;
}	t_render;

/**************************[ Utils ]**************************/
long	ft_get_current_time(void);
int		ft_create_trgb(int t, int r, int g, int b);
double	ft_radian_operations(double radian, double amout);
double	ft_get_distance(t_coor poin1, t_coor point2);
int		ft_is_in_circle(double x, double y, t_circle circle);

/*************************[ Parsing ]*************************/
int		ft_import_map(t_vars *vars, char *file);
int		ft_parse_textures(t_vars *vars, int fd);
int		ft_parse_map(t_map *map, int fd);
int		ft_component_surroundings(char **map, int i, int j);

/************************[ Movements ]************************/
void	ft_get_player_position(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_vars *vars);
int		mouse_rotation(int x, int y, t_vars *vars);
void	ft_move_player(t_vars *vars);

/************************[ RayCasting ]***********************/
t_coor	ft_get_hit_wall(t_vars *vars, double angle, int *direction);

/************************[ Rendering ]************************/
int		ft_init_images(t_vars *vars);
int		frame_rendering(t_vars *vars);
void	ft_render_minimap(t_vars *vars);
void	ft_draw_rays(t_vars *vars, t_circle minimap);
void	ft_render_3d_scene(t_vars *vars);
void	ft_draw_floor_ceilling(t_vars *vars);

/**************************[ Other ]**************************/
int		ft_exit_game(t_vars *vars, int exit_status);

#endif