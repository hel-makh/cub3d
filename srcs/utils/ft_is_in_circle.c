/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_circle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:15:56 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/23 15:24:00 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_is_in_circle(double x, double y, t_circle circle)
{
	double	distance_to_center;

	distance_to_center = sqrtf(powf(x - circle.x, 2) + powf(y - circle.y, 2));
	if (distance_to_center <= circle.radius)
	{
		if (distance_to_center <= circle.radius - 2)
			return (1);
		return (2);
	}
	return (0);
}
