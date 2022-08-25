/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:13:42 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/15 20:50:47 by hel-makh         ###   ########.fr       */
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

static int	ft_is_visible(t_vars *vars, t_col *holder, int x)
{
	t_coor	spr;

	spr.x = (double)holder->x + 0.5;
	spr.y = (double)holder->y + 0.5;
	if (ft_get_distance(vars->player.pos, spr) < vars->map.depth[x])
		return (1);
	return (0);
}

static void
	ft_draw_sprite(t_vars *vars, t_rend_spr *rend, t_img *img, t_col *holder)
{
	int	i;
	int	j;
	int	c;

	i = rend->sc.x;
	while (i < rend->sc.x + rend->spr.width && i < WIDTH)
	{
		j = rend->sc.y;
		while (i >= 0 && j < rend->sc.y + rend->spr.height && j < HEIGHT
			&& ft_is_visible(vars, holder, i))
		{
			rend->tex.x = (i - rend->sc.x) * (img->width / rend->spr.width);
			rend->tex.y = (j - rend->sc.y) * (img->height / rend->spr.height);
			if (j >= 0 && rend->tex.x >= 0 && rend->tex.x < img->width
				&& rend->tex.y >= 0 && rend->tex.y < img->height)
			{
				c = img->data[(int)rend->tex.y * img->width + (int)rend->tex.x];
				if (c != ft_create_trgb(255, 0, 0, 0))
					vars->mlx.img.data[j * WIDTH + i] = c;
			}
			j ++;
		}
		i ++;
	}
}

void	ft_render_sprites(t_vars *vars)
{
	t_rend_spr	rend;
	t_col		*holder;
	double		angle;

	holder = vars->map.collectibles;
	while (holder)
	{
		ft_collectibles_animation(vars, holder);
		rend.col.x = (double)holder->x + 0.5;
		rend.col.y = (double)holder->y + 0.5;
		rend.sc.x = vars->player.pos.x - rend.col.x;
		rend.sc.y = vars->player.pos.y - rend.col.y;
		angle = ft_radian_operations(vars->player.angle,
				ft_dtor(FOV / 2.0) - atan2(rend.sc.y, rend.sc.x));
		rend.spr.height = (HEIGHT / 2)
			/ ft_get_distance(vars->player.pos, rend.col);
		rend.spr.width = (HEIGHT / 2)
			/ ft_get_distance(vars->player.pos, rend.col);
		rend.sc.x = WIDTH - (angle * WIDTH / ft_dtor(FOV))
			- (rend.spr.width / 2);
		rend.sc.y = (HEIGHT / 2);
		ft_draw_sprite(vars, &rend,
			&vars->map.collectible.img[(int)holder->frame], holder);
		holder = holder->next;
	}
}
