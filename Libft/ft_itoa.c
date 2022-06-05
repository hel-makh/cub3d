/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:28:48 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/04 12:28:49 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_intlen(int n, int count_zero)
{
	int		intlen;

	intlen = 0;
	if (count_zero && n == 0)
		return (1);
	while (n != 0)
	{
		intlen ++;
		n /= 10;
	}
	return (intlen);
}

char	*ft_itoa(int n)
{
	char	*integer;
	long	nb;
	int		isnegative;

	nb = n;
	isnegative = 0;
	if (nb < 0)
	{
		isnegative = 1;
		nb = -nb;
	}
	integer = (char *) malloc (ft_intlen(nb, 1) + isnegative + 1);
	if (integer == NULL)
		return (0);
	integer[ft_intlen(nb, 1) + isnegative] = '\0';
	if (nb == 0)
		integer[0] = '0';
	while (ft_intlen(nb, 0) > 0)
	{
		integer[ft_intlen(nb, 0) - 1 + isnegative] = (nb % 10) + '0';
		nb /= 10;
	}
	if (isnegative)
		integer[0] = '-';
	return (integer);
}
