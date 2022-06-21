/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:53:41 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/21 23:30:36 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_is_in_circle(double x, double y, t_circle circle)
{
	double	distance_to_center;

	distance_to_center = sqrtf(powf(x - circle.x, 2) + powf(y - circle.y, 2));
	if (distance_to_center <= circle.radius)
	{
		if (distance_to_center <= circle.radius - 2)
			return (1);
		return (2);
	}
	return (0);
}

static void	ft_draw_circle(int *data, t_circle circle, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
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

	y = coor.y;
	while (y < coor.y + SIDE_LEN)
	{
		x = coor.x;
		while (x < coor.x + SIDE_LEN)
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

	i = 0;
	while (vars->map.map[i])
	{
		j = 0;
		while (vars->map.map[i][j])
		{
			coor.y = (i * SIDE_LEN)
				- (vars->player.pos.y * SIDE_LEN - RADIUS) + BORDER;
			coor.x = (j * SIDE_LEN)
				- (vars->player.pos.x * SIDE_LEN - RADIUS) + BORDER;
			if (vars->map.map[i][j] == '0'
				|| ft_strchr("NSEW", vars->map.map[i][j]))
				ft_draw_square(vars->window.data, coor, minimap,
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

	minimap.x = RADIUS + BORDER;
	minimap.y = RADIUS + BORDER;
	minimap.radius = RADIUS;
	ft_draw_circle(vars->window.data, minimap,
		ft_create_trgb(0, 105, 105, 105));
	ft_draw_map_components(vars, minimap);
	player.x = RADIUS + BORDER;
	player.y = RADIUS + BORDER;
	player.radius = PL_RADIUS;
	ft_draw_circle(vars->window.data, player,
		ft_create_trgb(0, 255, 0, 0));
}
