/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <ybensell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:03:39 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/12 17:08:40 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_init_map_vars(t_map *map)
{
	map->map = NULL;
	map->ce_color = -1;
	map->fl_color = -1;
	map->north.img = NULL;
	map->south.img = NULL;
	map->west.img = NULL;
	map->east.img = NULL;
	map->sprite.img = NULL;
	map->door.img = NULL;
	map->door.frames = 0;
	map->doors = NULL;
}

int	ft_import_map(t_vars *vars, char *file)
{
	char	*extension;
	int		fd;

	ft_init_map_vars(&vars->map);
	extension = ft_strrstr(file, ".cub");
	if (!extension || (extension && ft_strcmp(extension, ".cub")))
		return (printf("Error\nInvalid file extension.\n%s\n", USAGE), 0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nCouldn't open <%s> file.\n", file), 0);
	if (!ft_parse_textures(vars, fd) || !ft_parse_map(&vars->map, fd))
		return (0);
	close(fd);
	ft_get_player_position(vars);
	return (1);
}
