/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hit_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <ybensell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:27:22 by ybensell          #+#    #+#             */
/*   Updated: 2022/08/11 10:39:35 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_coor	ft_intersec_y(t_coor pos, double angle)
{
	t_coor	tmp;

	tmp.x = floor(pos.x);
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
		tmp.x += 1;
	else
		tmp.x -= 0.00000000001;
	tmp.y = pos.y + (tan(angle) * (tmp.x - pos.x));
	return (tmp);
}

static t_coor	ft_intersec_x(t_coor pos, double angle)
{
	t_coor	tmp;

	tmp.y = floor(pos.y);
	if (angle > M_PI)
		tmp.y += 1;
	else
		tmp.y -= 0.00000000001;
	tmp.x = pos.x + (tmp.y - pos.y) / tan(angle);
	return (tmp);
}

static t_coor	get_intersect_pt(t_vars *vars, t_coor start_pos,
	double angle, t_coor (*interfunc)(t_coor, double))
{
	int		map_height;
	t_coor	first_inter;
	t_coor	delta;

	map_height = ft_arrlen(vars->map.map);
	first_inter = interfunc(start_pos, angle);
	delta = interfunc(first_inter, angle);
	delta.x -= first_inter.x;
	delta.y -= first_inter.y;
	while ((first_inter.x || first_inter.y)
		&& first_inter.x > 0 && first_inter.y > 0
		&& first_inter.y < map_height
		&& first_inter.x < (int)ft_strlen(vars->map.map[(int)first_inter.y])
		&& !ft_strchr(HIT_WALLS,
			vars->map.map[(int)first_inter.y][(int)first_inter.x]))
	{
		first_inter.x += delta.x;
		first_inter.y += delta.y;
	}
	return (first_inter);
}

t_coor	ft_get_hit_wall(t_vars *vars, t_coor start_pos,
	double angle, int *direction)
{
	t_coor	x_wall;
	t_coor	y_wall;

	x_wall = get_intersect_pt(vars, start_pos, angle, &ft_intersec_x);
	y_wall = get_intersect_pt(vars, start_pos, angle, &ft_intersec_y);
	if (ft_get_distance(start_pos, x_wall) < ft_get_distance(start_pos, y_wall))
	{		
		if (direction)
			*direction = 'h';
		return (x_wall);
	}
	else
	{
		if (direction)
			*direction = 'v';
		return (y_wall);
	}
}
