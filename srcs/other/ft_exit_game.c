/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:24:09 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/29 19:40:38 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_exit_game(t_vars *vars, int exit_status)
{
	if (vars->mlx.win)
		mlx_destroy_window(vars->mlx.mlx, vars->mlx.win);
	if (vars->mlx.img.img)
		mlx_destroy_image(vars->mlx.mlx, vars->mlx.img.img);
	if (vars->mlx.minimap.img)
		mlx_destroy_image(vars->mlx.mlx, vars->mlx.minimap.img);
	if (vars->map.north.img)
		mlx_destroy_image(vars->mlx.mlx, vars->map.north.img);
	if (vars->map.south.img)
		mlx_destroy_image(vars->mlx.mlx, vars->map.south.img);
	if (vars->map.west.img)
		mlx_destroy_image(vars->mlx.mlx, vars->map.west.img);
	if (vars->map.east.img)
		mlx_destroy_image(vars->mlx.mlx, vars->map.east.img);
	ft_free_2d(vars->map.map);
	exit(exit_status);
}
