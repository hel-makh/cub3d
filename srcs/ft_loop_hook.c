/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:44:23 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/21 23:18:50 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_loop_hook(t_vars *vars)
{
	if (vars->window.img)
		mlx_destroy_image(vars->mlx, vars->window.img);
	vars->window.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->window.data = (int *)mlx_get_data_addr(vars->window.img,
			&vars->window.bpp, &vars->window.line_length, &vars->window.endian);
	ft_move_player(vars);
	ft_render_minimap(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->window.img, 0, 0);
	return (1);
}
