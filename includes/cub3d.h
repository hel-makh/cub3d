/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:43:14 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/08 15:08:17 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
// # include <mlx.h>
# include "../Libft/libft.h"

# define USAGE "Usage: ./cub3d <file.cub>"

typedef struct s_map {
	char	**map;
	int		ceilling[3];
	int		floor[3];
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_map;

typedef struct s_vars {
	t_map	map;
}	t_vars;

void	ft_init_vars(t_vars *vars);
int		ft_import_map(t_map *map, char *file);
int		ft_parse_textures(t_map *map, int fd);
int		ft_parse_map(t_map *map, int fd);
int		ft_component_surroundings(char **map, int i, int j);

#endif