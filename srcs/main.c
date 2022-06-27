/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:49:49 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/27 01:16:05 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx.mlx, vars->mlx.win);
	if (vars->mlx.img.img)
		mlx_destroy_image(vars->mlx.mlx, vars->mlx.img.img);
	ft_free_2d(vars->map.map);
	ft_free(vars->map.north);
	ft_free(vars->map.south);
	ft_free(vars->map.west);
	ft_free(vars->map.east);
	exit (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 2)
		return (printf("Error\nMissing map file.\n%s\n", USAGE), EXIT_FAILURE);
	else if (argc > 2)
		return (printf("Error\nInvalid arguments.\n%s\n", USAGE), EXIT_FAILURE);
	if (!ft_import_map(&vars.map, argv[1]))
		return (EXIT_FAILURE);
	ft_get_player_position(&vars);
	vars.mlx.fps = 1000;
	vars.mlx.img.img = NULL;
	vars.mlx.mlx = mlx_init();
	vars.mlx.win = mlx_new_window(vars.mlx.mlx, WIDTH, HEIGHT, "cub3d");
	mlx_hook(vars.mlx.win, 02, (1L << 0), key_press, &vars);
	mlx_hook(vars.mlx.win, 03, (1L << 1), key_release, &vars);
	mlx_hook(vars.mlx.win, 17, 0L, exit_game, &vars);
	mlx_loop_hook(vars.mlx.mlx, frame_rendering, &vars);
	mlx_loop(vars.mlx.mlx);
	return (EXIT_SUCCESS);
}
