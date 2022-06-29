/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:48:05 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/29 12:59:54 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

typedef struct s_content {
	int	space;
	int	wall;
	int	player;
}	t_content;

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

static int	ft_check_component(t_map *map, int i, int j, t_content *content)
{
	if (!ft_strchr(" 01NSEW", map->map[i][j]))
	{
		printf("Error\nInvalid map: Invalid component [%c]."
			"\nLine: %d, Column: %d\n", map->map[i][j], i + 1, j + 1);
		return (0);
	}
	if (map->map[i][j] == '0')
		content->space ++;
	else if (map->map[i][j] == '1')
		content->wall ++;
	else if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
			|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
		content->player ++;
	return (1);
}

static int	ft_check_map_content(t_map *map)
{
	t_content	content;
	int			i;
	int			j;

	content.space = 0;
	content.wall = 0;
	content.player = 0;
	i = 0;
	while (map->map[i])
	{
		j = -1;
		while (map->map[i][++j])
			if (!ft_check_component(map, i, j, &content))
				return (0);
		i ++;
	}
	if (!content.space)
		return (printf("Error\nInvalid map: No valid path.\n"), 0);
	else if (!content.wall)
		return (printf("Error\nInvalid map: Map not closed.\n"), 0);
	else if (content.player != 1)
		return (printf("Error\nInvalid map: Missing player.\n"), 0);
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
	return (1);
}
