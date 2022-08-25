/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_3d_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <ybensell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:04:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/25 10:50:09 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define RADIAN_INC	0.06

static int
	ft_get_texture_pixel(t_img img, t_render *render, int ty)
{
	int		tx;
	double	ty_step;
	double	ty_off;

	if (render->direc == 'h')
		tx = img.width * (render->hit_wall.x - (int)render->hit_wall.x);
	else
		tx = img.width * (render->hit_wall.y - (int)render->hit_wall.y);
	ty_step = img.height / render->wall_orig_height;
	ty_off = 0;
	if (render->wall_orig_height > HEIGHT)
		ty_off = (render->wall_orig_height - HEIGHT) / 2;
	ty = ty_off * ty_step + (ty * ty_step);
	return (img.data[abs(ty) * img.width + abs(tx)]);
}

static void	ft_draw_pixel(t_vars *vars, t_render *render, int *data, int ty)
{
	t_img	*img;
	int		color;

	if (render->direc == 'h' && render->angle < M_PI)
		img = &vars->map.north;
	else if (render->direc == 'h' && render->angle < 2 * M_PI)
		img = &vars->map.south;
	else if (render->direc == 'v'
		&& (render->angle < M_PI_2 || render->angle > M_PI + M_PI_2))
		img = &vars->map.west;
	else
		img = &vars->map.east;
	color = ft_get_texture_pixel(*img, render, ty);
	if (color != ft_create_trgb(255, 0, 0, 0))
		*data = color;
}

static void	ft_draw_walls(t_vars *vars, t_render *render)
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
			ft_draw_pixel(vars, render,
				&vars->mlx.img.data[y * WIDTH + x], ty - 1);
			x ++;
		}
		ty ++;
		y ++;
	}
}

static void	ft_get_wall_dims(t_vars *vars, t_render *render,
	t_coor start_pos, double degree)
{
	render->degree = degree;
	render->hit_wall = ft_get_hit_wall(vars, start_pos,
			render->angle, &render->direc);
	render->dist = ft_get_distance(vars->player.pos, render->hit_wall)
		* cos(ft_radian_operations(vars->player.angle, -render->angle));
	render->wall_dim.width = WIDTH / (FOV / RADIAN_INC);
	render->wall_dim.height = HEIGHT;
	if (render->dist > 0)
		render->wall_dim.height = HEIGHT / render->dist;
	render->wall_orig_height = render->wall_dim.height;
	if (render->wall_dim.height > HEIGHT)
		render->wall_dim.height = HEIGHT;
}

void	ft_render_3d_scene(t_vars *vars)
{
	t_render	render;
	double		degree;

	ft_draw_floor_ceilling(vars);
	degree = 0;
	while (degree <= FOV)
	{
		render.angle = ft_radian_operations(vars->player.angle,
				ft_dtor(degree - (FOV / 2)));
		ft_get_wall_dims(vars, &render, vars->player.pos, degree);
		ft_draw_walls(vars, &render);
		degree += RADIAN_INC;
	}
}
