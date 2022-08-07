/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:06:14 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/07 21:09:23 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	steps *= C_SIDE_LEN;
	coor.x = minimap.x;
	coor.y = minimap.y;
	while (steps >= 0 && ft_is_in_circle(coor.x, coor.y, minimap) == 1)
	{
		vars->mlx.img.data
		[(int)round(coor.y) * WIDTH + (int)round(coor.x)]
			= ft_create_trgb(0, 0, 255, 0);
		coor.x += inc.x;
		coor.y += inc.y;
		steps --;
	}
}

void	ft_draw_rays(t_vars *vars, t_circle minimap)
{
	double	degree;
	double	angle;
	t_coor	hit_wall;

	degree = 0;
	while (degree <= FOV)
	{
		angle = ft_radian_operations(vars->player.angle,
				ft_dtor(degree - (FOV / 2)));
		hit_wall = ft_get_hit_wall(vars, vars->player.pos, angle, NULL);
		while (vars->map.map[(int)hit_wall.y][(int)hit_wall.x] == O_DOOR)
			hit_wall = ft_get_hit_wall(vars, hit_wall, angle, NULL);
		ft_draw_line(vars, hit_wall, minimap);
		degree += 2;
	}
}
