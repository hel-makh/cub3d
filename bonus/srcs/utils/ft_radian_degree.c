/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radian_degree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:13:11 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/04 16:20:44 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_rtod(double radian)
{
	return (radian * (180.0 / M_PI));
}

double	ft_dtor(double degree)
{
	return (degree * (M_PI / 180.0));
}
