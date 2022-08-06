/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:24:09 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/06 13:09:39 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_destroy_image(t_vars *vars, t_img *img)
{
	if (img->img)
		mlx_destroy_image(vars->mlx.mlx, img->img);
	img->data = ft_free(img->data);
}

static void	ft_destroy_sprite(t_vars *vars, t_spr *spr)
{
	int	i;

	i = 0;
	while (i < spr->frames)
	{
		ft_destroy_image(vars, &spr->img[i]);
		i ++;
	}
}

int	ft_exit_game(t_vars *vars, int exit_status)
{
	if (vars->mlx.win)
		mlx_destroy_window(vars->mlx.mlx, vars->mlx.win);
	ft_destroy_image(vars->mlx.mlx, &vars->mlx.img);
	ft_destroy_image(vars->mlx.mlx, &vars->mlx.minimap);
	ft_destroy_image(vars->mlx.mlx, &vars->map.north);
	ft_destroy_image(vars->mlx.mlx, &vars->map.south);
	ft_destroy_image(vars->mlx.mlx, &vars->map.west);
	ft_destroy_image(vars->mlx.mlx, &vars->map.east);
	ft_destroy_sprite(vars->mlx.mlx, &vars->map.door);
	ft_door_lstclear(&vars->map.doors);
	vars->map.map = ft_free_2d(vars->map.map);
	exit(exit_status);
}
