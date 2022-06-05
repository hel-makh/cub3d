/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:47:20 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/01 18:47:22 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*buffer;
	size_t		i;

	buffer = s;
	i = 0;
	while (i < n)
	{
		if ((i > 0 && !(unsigned char)buffer[i])
			|| (unsigned char)buffer[i] == (unsigned char)c)
			return ((void *)&buffer[i]);
		i ++;
	}
	return (0);
}
