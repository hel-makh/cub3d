/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:49:49 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/06 16:10:54 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	print_info(t_vars vars)
{
	printf("north: '%s'\n", vars.map.north);
	printf("south: '%s'\n", vars.map.south);
	printf("west: '%s'\n", vars.map.west);
	printf("east: '%s'\n", vars.map.east);
	printf("floor: %d,%d,%d\n",	vars.map.floor[0],
								vars.map.floor[1],
								vars.map.floor[2]);
	printf("ceilling: %d,%d,%d\n",	vars.map.ceilling[0],
									vars.map.ceilling[1],
									vars.map.ceilling[2]);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 2)
		return (printf("Error\nMissing map file.\n%s\n", USAGE), EXIT_FAILURE);
	else if (argc > 2)
		return (printf("Error\nInvalid arguments.\n%s\n", USAGE), EXIT_FAILURE);
	ft_init_vars(&vars);
	if (!ft_import_map(&vars.map, argv[1]))
		return (EXIT_FAILURE);
	print_info(vars);
	return (EXIT_SUCCESS);
}
