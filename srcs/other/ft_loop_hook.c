/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:44:23 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/24 23:50:57 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_fps_counter(t_vars *vars)
{
	static long	next_check;
	static int	fps;

	if (!next_check)
		next_check = ft_get_current_time() + 1000;
	if (next_check <= ft_get_current_time())
	{
		next_check = ft_get_current_time() + 1000;
		vars->mlx.fps = fps;
		fps = 0;
	}
	fps ++;
}

int	ft_loop_hook(t_vars *vars)
{
	ft_fps_counter(vars);
	if (vars->mlx.img.img)
		mlx_destroy_image(vars->mlx.mlx, vars->mlx.img.img);
	vars->mlx.img.img = mlx_new_image(vars->mlx.mlx, WIDTH, HEIGHT);
	vars->mlx.img.data = (int *)mlx_get_data_addr(vars->mlx.img.img,
			&vars->mlx.img.bpp, &vars->mlx.img.line_len, &vars->mlx.img.endian);
	ft_move_player(vars);
	ft_render_minimap(vars);
	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.win,
		vars->mlx.img.img, 0, 0);
	mlx_string_put(vars->mlx.mlx, vars->mlx.win, WIDTH - 25, 20,
		ft_create_trgb(0, 0, 255, 0), ft_itoa(vars->mlx.fps));
	return (1);
}
