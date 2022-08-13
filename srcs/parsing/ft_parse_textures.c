/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <ybensell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:04:43 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/12 17:08:32 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_is_parsed(t_map *map)
{
	if (map->north.img && map->south.img && map->west.img && map->east.img
		&& map->door.img && map->sprite.img
		&& map->fl_color != -1 && map->ce_color != -1)
		return (1);
	return (0);
}

static int	ft_is_duplicated(t_map *map, char **info)
{
	if ((!ft_strcmp(info[0], "NO") && map->north.img)
		|| (!ft_strcmp(info[0], "SO") && map->south.img)
		|| (!ft_strcmp(info[0], "WE") && map->west.img)
		|| (!ft_strcmp(info[0], "EA") && map->east.img)
		|| (!ft_strcmp(info[0], "SP") && map->sprite.img)
		|| (!ft_strcmp(info[0], "DO") && map->door.img)
		|| (!ft_strcmp(info[0], "F") && map->fl_color != -1)
		|| (!ft_strcmp(info[0], "C") && map->ce_color != -1))
		return (printf("Error\nDuplicated textures [%s].\n", info[0]), 1);
	return (0);
}

static int	ft_is_valid_format(char **info)
{
	if ((!ft_strcmp(info[0], "NO") && ft_arrlen(info) != 2)
		|| (!ft_strcmp(info[0], "SO") && ft_arrlen(info) != 2)
		|| (!ft_strcmp(info[0], "WE") && ft_arrlen(info) != 2)
		|| (!ft_strcmp(info[0], "EA") && ft_arrlen(info) != 2)
		|| (!ft_strcmp(info[0], "SP") && ft_arrlen(info) < 2)
		|| (!ft_strcmp(info[0], "DO") && ft_arrlen(info) < 2)
		|| (!ft_strcmp(info[0], "F") && ft_arrlen(info) != 2)
		|| (!ft_strcmp(info[0], "C") && ft_arrlen(info) != 2))
		return (printf("Error\nInvalid texture format [%s].\n", info[0]), 0);
	return (1);
}

int	ft_parse_textures(t_vars *vars, int fd)
{
	char	*line;
	char	**info;

	while (!ft_is_parsed(&vars->map))
	{
		line = get_next_line(fd);
		if (!line)
			return (printf("Error\nMissing textures.\n"), 0);
		if (*line)
		{
			info = ft_split(line, ' ');
			if (!ft_is_valid_format(info)
				|| ft_is_duplicated(&vars->map, info)
				|| !ft_get_textures(vars, info))
				return (0);
			info = ft_free_2d(info);
		}
		line = ft_free(line);
	}
	return (1);
}
