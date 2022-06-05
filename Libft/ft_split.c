/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:55:32 by hel-makh          #+#    #+#             */
/*   Updated: 2021/12/29 11:53:58 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**ft_free_arr(int i, char **arr)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (0);
}

static size_t	ft_split_strlen(char const *s, char c)
{
	size_t	str_len;

	str_len = 0;
	while (s[str_len] && s[str_len] != c)
		str_len++;
	return (str_len);
}

static size_t	ft_count_strs(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i ++;
	if (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	str_len;
	char	**arr;

	if (!s)
		return (0);
	arr = (char **) malloc (sizeof(char *) * (ft_count_strs(s, c) + 1));
	if (arr == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_count_strs(s, c))
	{
		while (s[j] == c)
			j++;
		str_len = ft_split_strlen(&s[j], c);
		arr[i] = ft_substr(s, j, str_len);
		if (arr[i] == NULL)
			return (ft_free_arr(i, arr));
		j += str_len;
		i ++;
	}
	arr[i] = 0;
	return (arr);
}
