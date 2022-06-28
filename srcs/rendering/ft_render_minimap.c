/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:53:41 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/28 14:27:29 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_draw_circle(int *data, t_circle circle, int color)
{
	int	edge;
	int	x;
	int	y;

	edge = CENTER - circle.radius;
	y = edge;
	while (y <= edge + (circle.radius * 2))
	{
		x = edge;
		while (x <= edge + (circle.radius * 2))
		{
			if (ft_is_in_circle(x, y, circle))
				data[y * WIDTH + x] = color;
			x ++;
		}
		y ++;
	}
}

static void	ft_draw_square(int *data, t_coor coor, t_circle minimap, int color)
{
	int	x;
	int	y;

	y = coor.y + 1;
	while (y < coor.y + C_SIDE_LEN - 1)
	{
		x = coor.x + 1;
		while (x < coor.x + C_SIDE_LEN - 1)
		{
			if (ft_is_in_circle(x, y, minimap) == 1)
				data[y * WIDTH + x] = color;
			x ++;
		}
		y ++;
	}
}

static void	ft_draw_map_components(t_vars *vars, t_circle minimap)
{
	t_coor	coor;
	int		i;
	int		j;

	i = ft_max(0, vars->player.pos.y - (C_VISIBLE / 2));
	while (vars->map.map[i] && i <= vars->player.pos.y + (C_VISIBLE / 2))
	{
		j = ft_max(0, vars->player.pos.x - (C_VISIBLE / 2));
		while (vars->map.map[i][j] && j <= vars->player.pos.x + (C_VISIBLE / 2))
		{
			coor.y = (i * C_SIDE_LEN)
				- (vars->player.pos.y * C_SIDE_LEN) + CENTER;
			coor.x = (j * C_SIDE_LEN)
				- (vars->player.pos.x * C_SIDE_LEN) + CENTER;
			if (vars->map.map[i][j] == '0'
				|| ft_strchr("NSEW", vars->map.map[i][j]))
				ft_draw_square(vars->mlx.img.data, coor, minimap,
					ft_create_trgb(0, 255, 255, 255));
			j ++;
		}
		i ++;
	}
}

void	ft_render_minimap(t_vars *vars)
{
	t_circle	minimap;
	t_circle	player;

	minimap.x = CENTER;
	minimap.y = CENTER;
	minimap.radius = RADIUS;
	ft_draw_circle(vars->mlx.img.data, minimap,
		ft_create_trgb(105, 105, 105, 105));
	ft_draw_map_components(vars, minimap);
	ft_draw_rays(vars, minimap);
	player.x = CENTER;
	player.y = CENTER;
	player.radius = PL_RADIUS;
	ft_draw_circle(vars->mlx.img.data, player,
		ft_create_trgb(0, 255, 0, 0));
}
