/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:06:14 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/24 21:47:11 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_draw_line(t_vars *vars, t_coor dest, t_circle minimap)
{
	int		steps;
	t_coor	inc;
	t_coor	coor;

	dest.x -= vars->player.pos.x;
	dest.y -= vars->player.pos.y;
	steps = (int)fmax(fabs(dest.x), fabs(dest.y));
	if (!steps)
		steps = 1;
	inc.x = dest.x / steps;
	inc.y = dest.y / steps;
	steps *= C_SIDE_LEN - 1;
	coor.x = minimap.x;
	coor.y = minimap.y;
	while (steps >= 0 && ft_is_in_circle(coor.x, coor.y, minimap) == 1)
	{
		vars->mlx.img.data[(int)round(coor.y) * WIDTH + (int)round(coor.x)]
			= ft_create_trgb(0, 0, 255, 0);
		coor.x += inc.x;
		coor.y += inc.y;
		steps --;
	}
}

static t_coor	ft_get_vertic_hit_line(t_coor point, double angle)
{
	double	tangent;
	t_coor	hit_line;

	if (angle > M_PI_2 && angle < M_PI + M_PI_2)
		tangent = tan(angle - M_PI);
	else
		tangent = tan(-angle);
	if (isnan(tangent) || errno == HUGE_VALF)
		tangent = 0;
	hit_line.x = floor(point.x);
	if (angle > M_PI_2 && angle < M_PI + M_PI_2)
		hit_line.x += 1;
	else
		hit_line.x -= 0.000000000001;
	hit_line.y = point.y;
	hit_line.y += ft_get_distance(point, hit_line) * tangent;
	return (hit_line);
}

static t_coor	ft_get_horiz_hit_line(t_coor point, double angle)
{
	double	tangent;
	t_coor	hit_line;

	if (angle > M_PI)
		tangent = tan((M_PI + M_PI_2) - angle);
	else
		tangent = tan(angle - M_PI_2);
	if (isnan(tangent) || errno == HUGE_VALF)
		tangent = 0;
	hit_line.x = point.x;
	hit_line.y = floor(point.y);
	if (angle > M_PI)
		hit_line.y += 1;
	else
		hit_line.y -= 0.000000000001;
	hit_line.x += ft_get_distance(point, hit_line) * tangent;
	return (hit_line);
}

t_coor	ft_get_hit_wall(t_vars *vars, double angle, int direction)
{
	t_coor	wall;
	t_coor	dist;

	if (direction == 'h')
	{
		wall = ft_get_horiz_hit_line(vars->player.pos, angle);
		dist = ft_get_horiz_hit_line(wall, angle);
	}
	else
	{
		wall = ft_get_vertic_hit_line(vars->player.pos, angle);
		dist = ft_get_vertic_hit_line(wall, angle);
	}
	dist.x = dist.x - wall.x;
	dist.y = dist.y - wall.y;
	while ((dist.x || dist.y) && (int)wall.y >= 0 && (int)wall.x >= 0
		&& (int)wall.y < (int)ft_arrlen(vars->map.map)
		&& (int)wall.x < (int)ft_strlen(vars->map.map[(int)wall.y])
		&& vars->map.map[(int)wall.y][(int)wall.x] != '1')
	{
		wall.x += dist.x;
		wall.y += dist.y;
	}
	return (wall);
}

void	ft_draw_rays(t_vars *vars, t_circle minimap)
{
	int		sign;
	double	fov;
	double	angle;
	t_coor	h_wall;
	t_coor	v_wall;

	sign = -1;
	while (sign <= 1)
	{
		fov = 0;
		while (fov <= (FOV / 2) * (M_PI / 180.0))
		{
			angle = ft_radian_operations(vars->player.angle, sign * fov);
			h_wall = ft_get_hit_wall(vars, angle, 'h');
			v_wall = ft_get_hit_wall(vars, angle, 'v');
			if (ft_get_distance(vars->player.pos, h_wall)
				< ft_get_distance(vars->player.pos, v_wall))
				ft_draw_line(vars, h_wall, minimap);
			else
				ft_draw_line(vars, v_wall, minimap);
			fov += 0.05;
		}
		sign += 2;
	}
}
