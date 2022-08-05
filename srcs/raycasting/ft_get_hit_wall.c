/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hit_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:06:14 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/03 00:11:42 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_coor	ft_get_horiz_hit_wall(t_coor point, double angle)
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

static t_coor	ft_get_vertic_hit_wall(t_coor point, double angle)
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

static t_coor	ft_get_direc_hit_wall(t_vars *vars, t_coor start_pos,
	double angle, t_coor (*ft_hit_wall)(t_coor, double))
{
	t_coor	wall;
	t_coor	dist;

	wall = ft_hit_wall(start_pos, angle);
	dist = ft_hit_wall(wall, angle);
	dist.x = dist.x - wall.x;
	dist.y = dist.y - wall.y;
	while ((dist.x || dist.y) && (int)wall.y >= 0 && (int)wall.x >= 0
		&& (int)wall.y < (int)ft_arrlen(vars->map.map)
		&& (int)wall.x < (int)ft_strlen(vars->map.map[(int)wall.y])
		&& !ft_strchr(HIT_WALLS, vars->map.map[(int)wall.y][(int)wall.x]))
	{
		wall.x += dist.x;
		wall.y += dist.y;
	}
	if ((int)wall.y >= 0 && (int)wall.x >= 0
		&& (int)wall.y < (int)ft_arrlen(vars->map.map)
		&& (int)wall.x < (int)ft_strlen(vars->map.map[(int)wall.y])
		&& !ft_strchr(HIT_WALLS, vars->map.map[(int)wall.y][(int)wall.x]))
		return (start_pos);
	return (wall);
}

t_coor	ft_get_hit_wall(t_vars *vars, t_coor start_pos,
	double angle, int *direction)
{
	t_coor	h_wall;
	t_coor	v_wall;

	h_wall = ft_get_direc_hit_wall(vars, start_pos,
			angle, &ft_get_horiz_hit_wall);
	v_wall = ft_get_direc_hit_wall(vars, start_pos,
			angle, &ft_get_vertic_hit_wall);
	if (ft_get_distance(vars->player.pos, h_wall)
		< ft_get_distance(vars->player.pos, v_wall))
	{
		if (direction)
			*direction = 'h';
		return (h_wall);
	}
	else
	{
		if (direction)
			*direction = 'v';
		return (v_wall);
	}
}
