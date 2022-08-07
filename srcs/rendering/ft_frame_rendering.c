/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame_rendering.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:44:23 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/07 19:06:10 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_init_minimap(t_vars *vars)
{
	int	i;
	int	j;

	vars->mlx.minimap.img = mlx_new_image(vars->mlx.mlx, RADIUS * 2,
			RADIUS * 2);
	if (!vars->mlx.minimap.img)
		return (0);
	vars->mlx.minimap.data = (int *)mlx_get_data_addr(vars->mlx.minimap.img,
			&vars->mlx.minimap.bpp, &vars->mlx.minimap.line_len,
			&vars->mlx.minimap.endian);
	i = 0;
	while (i < RADIUS * 2)
	{
		j = 0;
		while (j < RADIUS * 2)
		{
			vars->mlx.minimap.data[i * (RADIUS * 2) + j]
				= ft_create_trgb(255, 0, 0, 0);
			j ++;
		}
		i ++;
	}
	return (1);
}

int	ft_init_images(t_vars *vars)
{
	vars->mlx.img.img = mlx_new_image(vars->mlx.mlx, WIDTH, HEIGHT);
	if (!vars->mlx.img.img)
		return (printf("Error\nCouldn't create images.\n"), 0);
	vars->mlx.img.data = (int *)mlx_get_data_addr(vars->mlx.img.img,
			&vars->mlx.img.bpp, &vars->mlx.img.line_len,
			&vars->mlx.img.endian);
	if (!ft_init_minimap(vars))
		return (printf("Error\nCouldn't create images.\n"), 0);
	return (1);
}

static void	ft_fps_counter(t_vars *vars)
{
	static long	prev_timestamp;
	static long	counter;
	static int	frames;

	if (!prev_timestamp)
		prev_timestamp = ft_get_current_time();
	vars->mlx.fspeed = (ft_get_current_time() - prev_timestamp) / 1000.0;
	prev_timestamp = ft_get_current_time();
	if (!counter)
		counter = ft_get_current_time() + 1000;
	if (counter <= ft_get_current_time())
	{
		counter = ft_get_current_time() + 1000;
		vars->mlx.fps = frames;
		frames = 0;
	}
	frames ++;
}

int	frame_rendering(t_vars *vars)
{
	ft_fps_counter(vars);
	ft_move_player(vars);
	ft_door_animation(vars);
	ft_render_3d_scene(vars);
	ft_render_minimap(vars);
	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.win,
		vars->mlx.img.img, 0, 0);
	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.win,
		vars->mlx.minimap.img, BORDER, BORDER);
	mlx_string_put(vars->mlx.mlx, vars->mlx.win, FPS_X, FPS_Y,
		ft_create_trgb(0, 0, 255, 0), ft_itoa(vars->mlx.fps));
	return (1);
}
