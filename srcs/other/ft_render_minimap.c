/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:53:41 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/24 17:28:45 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

	i = 0;
	while (vars->map.map[i])
	{
		j = 0;
		while (vars->map.map[i][j])
		{
			coor.y = (i * C_SIDE_LEN)
				- (vars->player.pos.y * C_SIDE_LEN - RADIUS) + BORDER;
			coor.x = (j * C_SIDE_LEN)
				- (vars->player.pos.x * C_SIDE_LEN - RADIUS) + BORDER;
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

	minimap.x = RADIUS + BORDER;
	minimap.y = RADIUS + BORDER;
	minimap.radius = RADIUS;
	ft_draw_circle(vars->mlx.img.data, minimap,
		ft_create_trgb(105, 105, 105, 105));
	ft_draw_map_components(vars, minimap);
	ft_draw_rays(vars, minimap);
	player.x = RADIUS + BORDER;
	player.y = RADIUS + BORDER;
	player.radius = PL_RADIUS;
	ft_draw_circle(vars->mlx.img.data, player,
		ft_create_trgb(0, 255, 0, 0));
}
