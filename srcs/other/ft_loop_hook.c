/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:44:23 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/23 10:55:56 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_loop_hook(t_vars *vars)
{
	if (vars->mlx.img.img)
		mlx_destroy_image(vars->mlx.mlx, vars->mlx.img.img);
	vars->mlx.img.img = mlx_new_image(vars->mlx.mlx, WIDTH, HEIGHT);
	vars->mlx.img.data = (int *)mlx_get_data_addr(vars->mlx.img.img,
			&vars->mlx.img.bpp, &vars->mlx.img.line_len, &vars->mlx.img.endian);
	ft_move_player(vars);
	ft_render_minimap(vars);
	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.win,
		vars->mlx.img.img, 0, 0);
	return (1);
}
