/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:33:45 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/08 14:16:46 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_get_longest_length(char **map)
{
	int	i;
	int	j;

	if (!*map)
		return (-1);
	i = 0;
	j = i;
	while (map[i])
	{
		if (ft_strlen(map[i]) > ft_strlen(map[j]))
			j = i;
		i ++;
	}
	return (ft_strlen(map[j]));
}

static int	ft_check_top_walls(char **map)
{
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	k;

	len = ft_get_longest_length(map);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (map[j] && ft_strlen(map[j]) <= i)
			j ++;
		k = j;
		while (map[k] && map[k][i] == ' ')
			k ++;
		if (map[k] && map[k][i] != '1')
			return (0);
		i ++;
	}
	return (1);
}

static int	ft_check_bottom_walls(char **map)
{
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	k;

	len = ft_get_longest_length(map);
	i = 0;
	while (i < len)
	{
		j = ft_arrlen(map) - 1;
		while (j >= 0 && ft_strlen(map[j]) <= i)
			j --;
		k = j;
		while (k >= 0 && map[k][i] == ' ')
			k --;
		if (k >= 0 && map[k][i] != '1')
			return (0);
		i ++;
	}
	return (1);
}

int	ft_is_map_closed(t_map *map)
{
	if (!ft_check_top_walls(map->map)
		|| !ft_check_bottom_walls(map->map)
		/*|| !ft_check_left_walls(map->map)
		|| !ft_check_right_walls(map->map)*/)
		return (printf("Error\nMap is not closed\n"), 0);
	return (1);
}
