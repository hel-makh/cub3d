/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_opening.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:30:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/07 19:05:40 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_door_frame(t_door *lst, int x, int y)
{
	while (lst)
	{
		if (lst->x == x && lst->y == y)
			return ((int)lst->frame);
		lst = lst->next;
	}
	return (0);
}

void	ft_door_animation(t_vars *vars)
{
	t_door	*holder;
	t_door	*next_holder;
	double	new_frame;

	holder = vars->map.doors;
	while (holder)
	{
		if (vars->map.map[holder->y][holder->x] == O_DOOR)
			new_frame = holder->frame + (vars->mlx.fspeed * 50);
		else
			new_frame = holder->frame - (vars->mlx.fspeed * 50);
		if ((int)new_frame < vars->map.door.frames)
			holder->frame = new_frame;
		if (holder->frame <= 0)
		{
			next_holder = holder->next;
			ft_door_lstdel(&vars->map.doors, holder->x, holder->y);
			holder = next_holder;
			continue ;
		}
		holder = holder->next;
	}
}

void	ft_open_close_door(t_vars *vars)
{
	t_coor	door;
	double	dist;

	door = ft_get_hit_wall(vars, vars->player.pos, vars->player.angle, NULL);
	if (!ft_strchr(DOORS, vars->map.map[(int)door.y][(int)door.x]))
		return ;
	door.x = (double)((int)door.x) + 0.5;
	door.y = (double)((int)door.y) + 0.5;
	dist = ft_get_distance(vars->player.pos, door);
	if (dist > 2.0)
		return ;
	if (vars->map.map[(int)door.y][(int)door.x] == C_DOOR)
	{
		ft_door_lstadd_front(&vars->map.doors, ft_door_lstnew(door.x, door.y));
		vars->map.map[(int)door.y][(int)door.x] = O_DOOR;
	}
	else if (vars->map.map[(int)door.y][(int)door.x] == O_DOOR)
		vars->map.map[(int)door.y][(int)door.x] = C_DOOR;
}
