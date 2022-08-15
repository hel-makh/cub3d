/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:27:23 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/15 11:15:48 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mouse_rotation(int x, int y, t_vars *vars)
{
	double	diff;

	(void)y;
	diff = x - (WIDTH / 2);
	vars->player.angle = ft_radian_operations(vars->player.angle,
			diff * vars->mlx.fspeed * (MOUSE_ROT_SPEED / 200.0));
	# if defined(__linux__)
		mlx_mouse_move(vars->mlx.mlx, vars->mlx.win, WIDTH / 2, HEIGHT / 2);
	# elif defined(__APPLE__) && defined(__MACH__)
		mlx_mouse_move(vars->mlx.win, WIDTH / 2, HEIGHT / 2);
	# endif
	return (0);
}

static void	ft_get_player_direction(t_vars *vars)
{
	double	direction_angle;

	if (vars->player.rotate)
		vars->player.angle = ft_radian_operations(vars->player.angle,
				vars->player.rotate * vars->mlx.fspeed * ROT_SPEED);
	direction_angle = vars->player.angle;
	if (vars->player.move.y == -1)
		direction_angle = ft_radian_operations(direction_angle, M_PI);
	else if (vars->player.move.x)
		direction_angle = ft_radian_operations(direction_angle,
				-vars->player.move.x * M_PI_2);
	if (vars->player.move.x && vars->player.move.y)
		direction_angle = ft_radian_operations(direction_angle,
				vars->player.move.x * M_PI_4);
	vars->player.dir.x = cos(direction_angle);
	vars->player.dir.y = sin(direction_angle);
}

void	ft_move_player(t_vars *vars)
{
	t_coor	new_pos;

	ft_get_player_direction(vars);
	if (!vars->player.move.x && !vars->player.move.y)
		return ;
	new_pos.x = vars->player.pos.x
		+ (vars->player.dir.x * vars->mlx.fspeed * SPEED);
	if (!ft_strchr(WALLS, vars->map.map[(int)vars->player.pos.y][(int)new_pos.x]))
		vars->player.pos.x = new_pos.x;
	new_pos.y = vars->player.pos.y
		+ (vars->player.dir.y * vars->mlx.fspeed * SPEED);
	if (!ft_strchr(WALLS, vars->map.map[(int)new_pos.y][(int)vars->player.pos.x]))
		vars->player.pos.y = new_pos.y;
	if (vars->map.map[(int)vars->player.pos.y][(int)vars->player.pos.x]
		== COLLECTIBLE)
	{
		vars->map.map[(int)vars->player.pos.y][(int)vars->player.pos.x]
			= EMPTY_SPACE;
		ft_play_sound(COIN_COLLECT);
		ft_collectible_lstdel(&vars->map.collectibles,
			vars->player.pos.x, vars->player.pos.y);
	}
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_A)
		vars->player.move.x = -1;
	else if (keycode == KEY_W || keycode == KEY_UP)
		vars->player.move.y = -1;
	else if (keycode == KEY_D)
		vars->player.move.x = 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		vars->player.move.y = 1;
	else if (keycode == KEY_LEFT)
		vars->player.rotate = -1;
	else if (keycode == KEY_RIGHT)
		vars->player.rotate = 1;
	else if (keycode == KEY_E)
		ft_open_close_door(vars);
	else if (keycode == KEY_ESC)
		ft_exit_game(vars, EXIT_SUCCESS);
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == KEY_A)
		vars->player.move.x = 0;
	else if (keycode == KEY_W || keycode == KEY_UP)
		vars->player.move.y = 0;
	else if (keycode == KEY_D)
		vars->player.move.x = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		vars->player.move.y = 0;
	else if (keycode == KEY_LEFT)
		vars->player.rotate = 0;
	else if (keycode == KEY_RIGHT)
		vars->player.rotate = 0;
	return (0);
}
