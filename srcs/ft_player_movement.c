/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:27:23 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/22 18:47:43 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	increment_radian(double *radian, double amout)
{
	*radian += amout;
	while (*radian > 2 * PI)
		*radian -= 2 * PI;
	while (*radian < 0)
		*radian += 2 * PI;
}

static void	ft_get_player_direction(t_vars *vars)
{
	double	direction_angle;

	if (vars->player.rotate)
		increment_radian(&vars->player.angle, vars->player.rotate / 50);
	direction_angle = vars->player.angle;
	if (vars->player.move.y == -1)
		increment_radian(&direction_angle, PI);
	else if (vars->player.move.x)
		increment_radian(&direction_angle, vars->player.move.x * (PI / 2));
	if (vars->player.move.x && vars->player.move.y)
		increment_radian(&direction_angle, -vars->player.move.x * (PI / 4));
	vars->player.dir.x = cos(direction_angle);
	vars->player.dir.y = sin(direction_angle);
}

void	ft_move_player(t_vars *vars)
{
	t_coor	new_pos;

	if (!vars->player.move.x && !vars->player.move.y)
		return ;
	ft_get_player_direction(vars);
	new_pos.x = vars->player.pos.x + (vars->player.dir.x / 175);
	if (vars->map.map[(int)floor(vars->player.pos.y)]
		[(int)floor(new_pos.x)] != '1')
		vars->player.pos.x = new_pos.x;
	new_pos.y = vars->player.pos.y + (vars->player.dir.y / 175);
	if (vars->map.map[(int)floor(new_pos.y)]
		[(int)floor(vars->player.pos.x)] != '1')
		vars->player.pos.y = new_pos.y;
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_A)
		vars->player.move.x = 1;
	else if (keycode == KEY_W || keycode == KEY_UP)
		vars->player.move.y = -1;
	else if (keycode == KEY_D)
		vars->player.move.x = -1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		vars->player.move.y = 1;
	else if (keycode == KEY_LEFT)
		vars->player.rotate = -1;
	else if (keycode == KEY_RIGHT)
		vars->player.rotate = 1;
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
