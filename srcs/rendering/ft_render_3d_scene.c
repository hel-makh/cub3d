/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_3d_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <ybensell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:04:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/07/02 11:27:56 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define RADIAN_INC	0.06

static int
	ft_get_texture_pixel(t_img img, t_render *render, double hit_point, int ty)
{
	int		tx;
	double	ty_step;
	double	ty_off;

	tx = img.width * (hit_point - (int)hit_point);
	ty_step = img.height / render->wall_orig_height;
	ty_off = 0;
	if (render->wall_orig_height > HEIGHT)
		ty_off = (render->wall_orig_height - HEIGHT) / 2;
	ty = ty_off * ty_step + (ty * ty_step);
	return (img.data[ty * img.width + tx]);
}

static void	ft_draw_pixel(t_vars *vars, t_render *render, int *data, int ty)
{
	if (render->direc == 'h' && render->angle < M_PI)
		*data = ft_get_texture_pixel(vars->map.north, render,
				render->hit_wall.x, ty);
	else if (render->direc == 'h' && render->angle < 2 * M_PI)
		*data = ft_get_texture_pixel(vars->map.south, render,
				render->hit_wall.x, ty);
	else if (render->direc == 'v'
		&& (render->angle < M_PI_2 || render->angle > M_PI + M_PI_2))
		*data = ft_get_texture_pixel(vars->map.east, render,
				render->hit_wall.y, ty);
	else if (render->direc == 'v'
		&& (render->angle > M_PI_2 && render->angle < M_PI + M_PI_2))
		*data = ft_get_texture_pixel(vars->map.west, render,
				render->hit_wall.y, ty);
}

static void	ft_draw_wall(t_vars *vars, t_render *render)
{
	int	x;
	int	y;
	int	ty;

	
	ty = 0;
	y = (HEIGHT / 2) - (render->wall_dim.height / 2);
	while (y < (HEIGHT / 2) - (render->wall_dim.height / 2)
		+ render->wall_dim.height && y < HEIGHT)
	{
		x = (render->degree / RADIAN_INC) * render->wall_dim.width;
		while (x < ((render->degree / RADIAN_INC) * render->wall_dim.width)
			+ render->wall_dim.width && x < WIDTH)
		{
			ft_draw_pixel(vars, render, &vars->mlx.img.data[y * WIDTH + x], ty);
			x ++;
		}
		ty ++;
		y ++;
	}
	
}

void	ft_render_3d_scene(t_vars *vars)
{
	t_render	render;

	ft_draw_floor_ceilling(vars);
	render.degree = 0;
	while (render.degree <= FOV)
	{
		render.angle = ft_radian_operations(vars->player.angle,
				(render.degree - (FOV / 2)) * (M_PI / 180));
		render.hit_wall = ft_get_hit_wall(vars, render.angle, &render.direc);
		render.dist = ft_get_distance(vars->player.pos, render.hit_wall)
			* cos(ft_radian_operations(vars->player.angle, -render.angle));
		render.wall_dim.width = WIDTH / (FOV / RADIAN_INC);
		render.wall_dim.height = HEIGHT;
		if (render.dist > 0)
			render.wall_dim.height = HEIGHT / render.dist;
		render.wall_orig_height = render.wall_dim.height;
		if (render.wall_dim.height > HEIGHT)
			render.wall_dim.height = HEIGHT;
		ft_draw_wall(vars, &render);
		render.degree += RADIAN_INC;
	}
}
