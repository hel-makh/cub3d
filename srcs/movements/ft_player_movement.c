/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <ybensell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:27:23 by hel-makh          #+#    #+#             */
/*   Updated: 2022/07/02 15:16:45 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
int mouse_rotation(int x, int y, t_vars *vars)
{
	double	direction_angle;
	double rotation_speed;
	(void)y;

	rotation_speed = fabs(vars->player.rot.x - x);
	if (x < vars->player.rot.x)
	{
		vars->player.rotate = -1;
		vars->player.rot.x = x;
	}
	else if (x > vars->player.rot.x)
	{
		vars->player.rotate = 1;
		vars->player.rot.x = x;
	}
	vars->player.angle = ft_radian_operations(vars->player.angle,
				(vars->player.rotate * rotation_speed) / vars->mlx.fps);
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
	vars->player.rotate = 0;
	return 0;
}


static void	ft_get_player_direction(t_vars *vars)
{
	double	direction_angle;

	if (vars->player.rotate)
		vars->player.angle = ft_radian_operations(vars->player.angle,
				(vars->player.rotate * ROT_SPEED) / vars->mlx.fps);
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
		+ (vars->player.dir.x * SPEED) / vars->mlx.fps;
	if (vars->map.map[(int)vars->player.pos.y][(int)new_pos.x] != '1')
		vars->player.pos.x = new_pos.x;
	new_pos.y = vars->player.pos.y
		+ (vars->player.dir.y * SPEED) / vars->mlx.fps;
	if (vars->map.map[(int)new_pos.y][(int)vars->player.pos.x] != '1')
		vars->player.pos.y = new_pos.y;
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
