/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:25:34 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/04 14:25:37 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*buffer;
	unsigned int	i;

	if (!s)
		return (0);
	buffer = (char *) malloc (ft_strlen(s) + 1);
	if (buffer == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		buffer[i] = f(i, s[i]);
		i ++;
	}
	buffer[i] = '\0';
	return (buffer);
}
