/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <ybensell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:49:49 by hel-makh          #+#    #+#             */
/*   Updated: 2022/07/02 14:30:52 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_game(t_vars *vars)
{
	ft_exit_game(vars, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static void	ft_init_mlx(t_vars *vars)
{
	vars->mlx.win = NULL;
	vars->mlx.img.img = NULL;
	vars->mlx.minimap.img = NULL;
	vars->mlx.fps = 1000;
	vars->mlx.mlx = mlx_init();
	vars->player.rot.x = WIDTH / 2;
	vars->player.rot.y = HEIGHT / 2;
	if (!vars->mlx.mlx)
	{
		printf("Error\nCouldn't initialize mlx.\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 2)
		return (printf("Error\nMissing map file.\n%s\n", USAGE), EXIT_FAILURE);
	else if (argc > 2)
		return (printf("Error\nInvalid arguments.\n%s\n", USAGE), EXIT_FAILURE);
	ft_init_mlx(&vars);
	if (!ft_import_map(&vars, argv[1]))
		ft_exit_game(&vars, EXIT_FAILURE);
	if (!ft_init_images(&vars))
		ft_exit_game(&vars, EXIT_FAILURE);
	vars.mlx.win = mlx_new_window(vars.mlx.mlx, WIDTH, HEIGHT, "cub3d");
	if (!vars.mlx.win)
	{
		printf("Error\nCouldn't open window.\n");
		ft_exit_game(&vars, EXIT_FAILURE);
	}
	
	mlx_hook(vars.mlx.win, 02, (1L << 0), key_press, &vars);
	mlx_hook(vars.mlx.win, 03, (1L << 1), key_release, &vars);
	mlx_hook(vars.mlx.win, 17, 0L, exit_game, &vars);
	mlx_hook(vars.mlx.win, 06, (1L<<7),  mouse_rotation, &vars);
	mlx_loop_hook(vars.mlx.mlx, frame_rendering, &vars);
	mlx_loop(vars.mlx.mlx);
	return (EXIT_SUCCESS);
}
