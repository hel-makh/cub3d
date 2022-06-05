/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:21:16 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/02 10:49:58 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (i < len)
	{
		if (i <= src_len)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i ++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		buffer_len;
	char	*buffer;

	if (!s)
		return (0);
	buffer_len = ft_strlen(s) - start;
	if (buffer_len > (int)len)
		buffer_len = len;
	if (buffer_len < 0)
		buffer_len = 0;
	buffer = (char *) malloc (buffer_len + 1);
	if (buffer == NULL)
		return (0);
	if (buffer_len > 0)
		ft_strncpy(buffer, s + start, buffer_len);
	buffer[buffer_len] = '\0';
	return (buffer);
}
