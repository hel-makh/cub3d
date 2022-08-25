/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_floor_ceilling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:50:59 by hel-makh          #+#    #+#             */
/*   Updated: 2022/07/01 20:51:07 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_floor_ceilling(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				vars->mlx.img.data[y * WIDTH + x] = vars->map.ce_color;
			else
				vars->mlx.img.data[y * WIDTH + x] = vars->map.fl_color;
			x ++;
		}
		y ++;
	}
}
