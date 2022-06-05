/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:07:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/03/30 11:07:50 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnadd(char const *s1, char const *s2, size_t n)
{
	char	*buffer;
	size_t	buffer_len;
	size_t	i;

	if (!s1)
		return (0);
	buffer_len = ft_strlen(s2);
	if (n < buffer_len)
		buffer_len = n;
	buffer = (char *) malloc (ft_strlen(s1) + buffer_len + 1);
	if (buffer == NULL)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		buffer[i] = s1[i];
	buffer_len = i;
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		buffer[i + buffer_len] = s2[i];
		i ++;
	}
	buffer[i + buffer_len] = '\0';
	free((void *)s1);
	return (buffer);
}
