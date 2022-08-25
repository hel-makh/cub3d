/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <ybensell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:24:09 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/11 17:40:39 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_destroy_image(t_vars *vars, t_img *img)
{
	if (img->img)
		mlx_destroy_image(vars->mlx.mlx, img->img);
}

int	ft_exit_game(t_vars *vars, int exit_status)
{
	if (vars->mlx.win)
		mlx_destroy_window(vars->mlx.mlx, vars->mlx.win);
	ft_destroy_image(vars, &vars->mlx.img);
	ft_destroy_image(vars, &vars->map.north);
	ft_destroy_image(vars, &vars->map.south);
	ft_destroy_image(vars, &vars->map.west);
	ft_destroy_image(vars, &vars->map.east);
	vars->map.map = ft_free_2d(vars->map.map);
	exit(exit_status);
}
