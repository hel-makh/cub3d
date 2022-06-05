/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:20:15 by hel-makh          #+#    #+#             */
/*   Updated: 2022/03/24 15:06:36 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace_str(
	char *s1, const char *s2, unsigned int start, unsigned int len
	)
{
	char	*str;
	size_t	str_len;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !s2)
		return (NULL);
	str_len = ft_strlen(s1) - len + ft_strlen(s2);
	str = ft_calloc(str_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (i < str_len)
	{
		if (i == start)
			j += len;
		if (i >= start && i < start + ft_strlen(s2))
			str[i++] = s2[k++];
		else
			str[i++] = s1[j++];
	}
	return (free(s1), str);
}
