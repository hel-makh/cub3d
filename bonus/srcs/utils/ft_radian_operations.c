/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radian_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <ybensell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:05:36 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/25 11:12:14 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_radian_operations(double radian, double amout)
{
	radian += amout;
	while (radian > 2 * M_PI)
		radian -= 2 * M_PI;
	while (radian < 0)
		radian += 2 * M_PI;
	return (radian);
}
