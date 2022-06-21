/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:04:43 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/21 13:14:56 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_is_parsed(t_map *map)
{
	if (map->north && map->south && map->west && map->east
		&& map->floor_color != -1 && map->ceilling_color != -1)
		return (1);
	return (0);
}

static int	ft_is_duplicated(t_map *map, char **info)
{
	if ((!ft_strcmp(info[0], "NO") && map->north)
		|| (!ft_strcmp(info[0], "SO") && map->south)
		|| (!ft_strcmp(info[0], "WE") && map->west)
		|| (!ft_strcmp(info[0], "EA") && map->east)
		|| (!ft_strcmp(info[0], "F")
			&& map->floor_color != -1)
		|| (!ft_strcmp(info[0], "C")
			&& map->ceilling_color != -1))
		return (1);
	return (0);
}

static int	ft_get_rgb_colors(int *color, char **info)
{
	char	**arr;
	int		rgb[3];

	arr = ft_split(info[1], ',');
	if (ft_arrlen(arr) != 3)
		return (printf("Error\nInvalid RGB format.\n"), ft_free(arr), 0);
	if (!ft_isnumber(arr[0]) || !ft_isnumber(arr[1]) || !ft_isnumber(arr[2]))
		return (printf("Error\nInvalid RGB values.\n"), ft_free(arr), 0);
	rgb[0] = ft_atoi(arr[0]);
	rgb[1] = ft_atoi(arr[1]);
	rgb[2] = ft_atoi(arr[2]);
	arr = ft_free(arr);
	if (rgb[0] < 0 || rgb[0] > 255
		|| rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
		return (printf("Error\nInvalid RGB combination.\n"), 0);
	*color = ft_create_trgb(0, rgb[0], rgb[1], rgb[2]);
	return (1);
}

static int	ft_get_textures(t_map *map, char **info)
{
	if (!ft_strcmp(info[0], "NO"))
		map->north = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "SO"))
		map->south = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "WE"))
		map->west = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "EA"))
		map->east = ft_strdup(info[1]);
	else if (!ft_strcmp(info[0], "F"))
	{
		if (!ft_get_rgb_colors(&map->floor_color, info))
			return (0);
	}
	else if (!ft_strcmp(info[0], "C"))
	{
		if (!ft_get_rgb_colors(&map->ceilling_color, info))
			return (0);
	}
	else
	{
		printf("Error\nInvalid texture information [%s].\n", info[0]);
		return (0);
	}
	return (1);
}

int	ft_parse_textures(t_map *map, int fd)
{
	char	*line;
	char	**info;

	while (!ft_is_parsed(map))
	{
		line = get_next_line(fd);
		if (!line)
			return (printf("Error\nMissing textures.\n"), 0);
		if (*line)
		{
			info = ft_split(line, ' ');
			if (ft_arrlen(info) != 2)
				return (printf("Error\nInvalid texture format.\n"), 0);
			if (ft_is_duplicated(map, info))
				return (printf("Error\nDuplicated textures [%s].\n", info[0]), 0);
			if (!ft_get_textures(map, info))
				return (0);
			info = ft_free_2d(info);
		}
		line = ft_free(line);
	}
	return (1);
}
