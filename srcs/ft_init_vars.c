/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:00:29 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/05 18:09:39 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_init_map(t_map *map)
{
	map->map = NULL;
	map->ceilling[0] = -1;
	map->ceilling[1] = -1;
	map->ceilling[2] = -1;
	map->floor[0] = -1;
	map->floor[1] = -1;
	map->floor[2] = -1;
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
}

void	ft_init_vars(t_vars *vars)
{
	ft_init_map(&vars->map);
}
