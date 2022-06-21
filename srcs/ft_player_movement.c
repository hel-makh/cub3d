/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:27:23 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/21 23:23:01 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_player(t_vars *vars)
{
	double	new_pos;

	if (vars->player.move.x)
	{
		new_pos = vars->player.pos.x + (vars->player.move.x / 150);
		if (vars->map.map[(int)floor(vars->player.pos.y)]
			[(int)floor(new_pos)] != '1')
			vars->player.pos.x = new_pos;
	}
	if (vars->player.move.y)
	{
		new_pos = vars->player.pos.y + (vars->player.move.y / 150);
		if (vars->map.map[(int)floor(new_pos)]
			[(int)floor(vars->player.pos.x)] != '1')
			vars->player.pos.y = new_pos;
	}
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_A)
		vars->player.move.x += -1;
	else if (keycode == KEY_W)
		vars->player.move.y += -1;
	else if (keycode == KEY_S)
		vars->player.move.y += 1;
	else if (keycode == KEY_D)
		vars->player.move.x += 1;
	return (1);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == KEY_A)
		vars->player.move.x = 0;
	else if (keycode == KEY_W)
		vars->player.move.y = 0;
	else if (keycode == KEY_S)
		vars->player.move.y = 0;
	else if (keycode == KEY_D)
		vars->player.move.x = 0;
	return (1);
}
