/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:48:05 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/08 16:59:23 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_read_map(t_map *map, int fd)
{
	char	*line;
	int		empty_line;

	map->map = ft_calloc(1, sizeof(char *));
	if (map->map == NULL)
		return (0);
	empty_line = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line)
		{
			if (ft_arrlen(map->map) && empty_line)
				return (printf("Error\nInvalid map.\n"), ft_free(line), 0);
			map->map = ft_add_str2arr(map->map, line);
			if (map->map == NULL)
				return (ft_free(line), 0);
		}
		else if (ft_arrlen(map->map))
			empty_line = 1;
		line = ft_free(line);
	}
	return (1);
}

static int	ft_check_map_content(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!ft_strchr(" 01NSEW", map->map[i][j]))
			{
				printf("Error\nInvalid map: Invalid component [%c]."
					"\nLine: %d, Column: %d\n", map->map[i][j], i + 1, j + 1);
				return (0);
			}
			j ++;
		}
		i ++;
	}
	return (1);
}

static int	ft_is_map_closed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (ft_strchr(" 0NSEW", map->map[i][j]))
			{
				if (!ft_component_surroundings(map->map, i, j))
					return (0);
			}
			j ++;
		}
		i ++;
	}
	return (1);
}

int	ft_parse_map(t_map *map, int fd)
{
	if (!ft_read_map(map, fd))
		return (0);
	if (!ft_arrlen(map->map))
		return (printf("Error\nInvalid map.\n"), 0);
	if (!ft_check_map_content(map))
		return (0);
	if (!ft_is_map_closed(map))
		return (0);
	printf("hh\n");
	return (1);
}
