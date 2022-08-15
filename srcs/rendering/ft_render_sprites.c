/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:13:42 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/15 12:59:16 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_collectibles_animation(t_vars *vars, t_col *collectible)
{
	double	new_frame;

	new_frame = collectible->frame + (vars->mlx.fspeed * 10);
	if ((int)new_frame < vars->map.collectible.frames)
		collectible->frame = new_frame;
	else
		collectible->frame = 0;
}

void	ft_render_sprites(t_vars *vars)
{
	t_coor	sc;
	int		angle;
	int		ray_angle;
	int		i;
	int		j;
	t_dim	col_spr;
	t_coor	col;
	t_col	*holder;

	holder = vars->map.collectibles;
	while (holder)
	{
		ft_collectibles_animation(vars, holder);
		col.x = (double)holder->x + 0.5;
		col.y = (double)holder->y + 0.5;
		sc.x = vars->player.pos.x - col.x;
		sc.y = vars->player.pos.y - col.y;
		angle = ft_rtod(atan2(sc.y, sc.x));
		if(angle < 0)
			angle += 360;
		ray_angle = ft_rtod(vars->player.angle) + (FOV / 2) - angle;
		if(angle > 270 && ft_rtod(vars->player.angle) < 90)
			ray_angle += 360;
		if(ft_rtod(vars->player.angle) > 270 && angle < 90)
			ray_angle -= 360;
		col_spr.height = (HEIGHT / 2) / ft_get_distance(vars->player.pos, col);
		col_spr.width = (HEIGHT / 2) / ft_get_distance(vars->player.pos, col);
		sc.x = WIDTH - (ray_angle * WIDTH / FOV) - (col_spr.width / 2);
		sc.y = (HEIGHT / 2);
		i = sc.x;
		while (i < sc.x + col_spr.width && i < WIDTH)
		{
			j = sc.y;
			while (i >= 0 && j < sc.y + col_spr.height && j < HEIGHT)
			{
				if (j >= 0)
				{
					int	s_i = (i - sc.x) * (vars->map.collectible.img[(int)holder->frame].width / col_spr.width);
					int	s_j = (j - sc.y) * (vars->map.collectible.img[(int)holder->frame].height / col_spr.height);
					if (s_i >= 0 && s_i < vars->map.collectible.img[(int)holder->frame].width && s_j >= 0 && s_j < vars->map.collectible.img[(int)holder->frame].height)
					{
						int	color = vars->map.collectible.img[(int)holder->frame].data[s_j * vars->map.collectible.img[(int)holder->frame].width + s_i];
						if (color != ft_create_trgb(255, 0, 0, 0))
							vars->mlx.img.data[j * WIDTH + i] = color;
					}
				}
				j ++;
			}
			i ++;
		}
		holder = holder->next;
	}
}
