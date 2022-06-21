/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:03:39 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/21 13:22:24 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_init_map(t_map *map)
{
	map->map = NULL;
	map->ce_color = -1;
	map->fl_color = -1;
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
}

static int	ft_open_map(char *file)
{
	char	*extension;
	int		fd;

	extension = ft_strrstr(file, ".cub");
	if (!extension || (extension && ft_strcmp(extension, ".cub")))
		return (printf("Error\nInvalid file extension.\n%s\n", USAGE), -1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		printf("Error\nCouldn't open <%s> file.\n", file);
	return (fd);
}

int	ft_import_map(t_map *map, char *file)
{
	int		fd;

	ft_init_map(map);
	fd = ft_open_map(file);
	if (fd == -1)
		return (0);
	if (!ft_parse_textures(map, fd) || !ft_parse_map(map, fd))
		return (0);
	close(fd);
	return (1);
}
