/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radian_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:05:36 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/17 09:59:31 by hel-makh         ###   ########.fr       */
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
