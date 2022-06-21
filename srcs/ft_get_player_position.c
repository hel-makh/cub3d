/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:41:39 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/21 21:31:14 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_get_player_direction(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player.pos.x;
	y = vars->player.pos.y;
	vars->player.dir.x = x;
	vars->player.dir.y = y;
	if (vars->map.map[y][x] == 'N')
		vars->player.dir.y = 0;
	else if (vars->map.map[y][x] == 'S')
		vars->player.dir.y = ft_arrlen(vars->map.map);
	else if (vars->map.map[y][x] == 'E')
		vars->player.dir.x = ft_strlen(vars->map.map[y]);
	else if (vars->map.map[y][x] == 'W')
		vars->player.dir.x = 0;
}

void	ft_get_player_position(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map.map[i])
	{
		j = 0;
		while (vars->map.map[i][j])
		{
			if (ft_strchr("NSEW", vars->map.map[i][j]))
			{
				vars->player.pos.x = (double)j + 0.5;
				vars->player.pos.y = (double)i + 0.5;
				ft_get_player_direction(vars);
			}
			j ++;
		}
		i ++;
	}
}
