/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:48:07 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/01 18:48:10 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		source = src;
		dest = dst;
		while (len--)
			*dest++ = *source++;
	}
	else
	{
		source = src + len - 1;
		dest = dst + len - 1;
		while (len--)
			*dest-- = *source--;
	}
	return (dst);
}
