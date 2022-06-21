/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:49:49 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/21 23:18:34 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

// void	print_info(t_vars vars)
// {
// 	printf("\n> textures:\n");
// 	printf("north: '%s'\n", vars.map.north);
// 	printf("south: '%s'\n", vars.map.south);
// 	printf("west: '%s'\n", vars.map.west);
// 	printf("east: '%s'\n", vars.map.east);
// 	printf("floor: %d,%d,%d\n",	vars.map.floor[0],
// 								vars.map.floor[1],
// 								vars.map.floor[2]);
// 	printf("ceilling: %d,%d,%d\n",	vars.map.ceilling[0],
// 									vars.map.ceilling[1],
// 									vars.map.ceilling[2]);

// 	printf("\n> map:\n");
// 	for (size_t i = 0; i < ft_arrlen(vars.map.map); i++)
// 		printf("%s\n", vars.map.map[i]);
// }

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 2)
		return (printf("Error\nMissing map file.\n%s\n", USAGE), EXIT_FAILURE);
	else if (argc > 2)
		return (printf("Error\nInvalid arguments.\n%s\n", USAGE), EXIT_FAILURE);
	if (!ft_import_map(&vars.map, argv[1]))
		return (EXIT_FAILURE);
	// print_info(vars);
	ft_get_player_position(&vars);
	vars.window.img = NULL;
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "cub3d");
	// mlx_hook(vars.mlx_win, 17, 0L, destroy_window, &vars);
	mlx_hook(vars.mlx_win, 02, (1L<<0), key_press, &vars);
	mlx_hook(vars.mlx_win, 03, (1L<<1), key_release, &vars);
	mlx_loop_hook(vars.mlx, ft_loop_hook, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
