/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:54:29 by hel-makh          #+#    #+#             */
/*   Updated: 2022/03/26 11:36:13 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;

	if (!s1)
		return (0);
	buffer = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (buffer == NULL)
		return (0);
	ft_strcpy(buffer, s1);
	ft_strcat(buffer, s2);
	return (buffer);
}
