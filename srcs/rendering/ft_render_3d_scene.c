/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_3d_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:04:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/28 14:27:18 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define RADIAN_INC	0.281250

static void	ft_draw_floor_ceilling(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				vars->mlx.img.data[y * WIDTH + x] = vars->map.ce_color;
			else
				vars->mlx.img.data[y * WIDTH + x] = vars->map.fl_color;
			x ++;
		}
		y ++;
	}
}

static void	ft_draw_wall(t_vars *vars, double degree, double dist, int direc)
{
	double	angle;
	double	width;
	double	height;
	int		x;
	int		y;

	width = WIDTH / (FOV / RADIAN_INC);
	height = HEIGHT;
	if (dist >= 1)
		height = HEIGHT / dist;
	y = (HEIGHT / 2) - (height / 2);
	while (y < (HEIGHT / 2) - (height / 2) + height && y < HEIGHT)
	{
		x = (degree / RADIAN_INC) * width;
		while (x < ((degree / RADIAN_INC) * width) + width && x < WIDTH)
		{
			angle = ft_radian_operations(vars->player.angle,
					(degree - (FOV / 2)) * (M_PI / 180));
			if (direc == 'h' && angle < M_PI)	// North
				vars->mlx.img.data[y * WIDTH + x] = ft_create_trgb(0, 50, 0, 0);
			else if (direc == 'h' && angle < 2 * M_PI)	// South
				vars->mlx.img.data[y * WIDTH + x] = ft_create_trgb(0, 150, 0, 0);
			else if (direc == 'v' && (angle < M_PI_2 || angle > M_PI + M_PI_2))	// East?
				vars->mlx.img.data[y * WIDTH + x] = ft_create_trgb(0, 0, 50, 0);
			else if (direc == 'v' && (angle > M_PI_2 && angle < M_PI + M_PI_2))	// West?
				vars->mlx.img.data[y * WIDTH + x] = ft_create_trgb(0, 0, 150, 0);
			x ++;
		}
		y ++;
	}
}

void	ft_render_3d_scene(t_vars *vars)
{
	double	degree;
	double	angle;
	double	dist;
	t_coor	hit_wall;
	int		direction;

	ft_draw_floor_ceilling(vars);
	degree = 0;
	while (degree <= FOV)
	{
		angle = ft_radian_operations(vars->player.angle,
				(degree - (FOV / 2)) * (M_PI / 180));
		hit_wall = ft_get_hit_wall(vars, angle, &direction);
		dist = ft_get_distance(vars->player.pos, hit_wall)
			* cos(ft_radian_operations(vars->player.angle, -angle));
		ft_draw_wall(vars, degree, dist, direction);
		degree += RADIAN_INC;
	}
}
