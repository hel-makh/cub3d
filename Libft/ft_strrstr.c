/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:47:08 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/20 18:39:15 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = ft_strlen(haystack) - 1;
	while (i >= 0)
	{
		j = ft_strlen(needle) - 1;
		while (i - ((int)ft_strlen(needle) - 1 - j) >= 0
			&& haystack[i - ((int)ft_strlen(needle) - 1 - j)] == needle[j])
		{
			if (j == 0)
				return ((char *)&haystack
					[i - ((int)ft_strlen(needle) - 1 - j)]);
			j --;
		}
		i --;
	}
	return (0);
}
