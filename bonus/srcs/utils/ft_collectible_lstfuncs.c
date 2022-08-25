/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectible_lstfuncs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:59:51 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/14 21:01:48 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_col	*ft_collectible_lstnew(int x, int y)
{
	t_col	*element;

	element = malloc (1 * sizeof(t_col));
	if (element == NULL)
		return (NULL);
	element->x = x;
	element->y = y;
	element->frame = 1;
	element->next = NULL;
	return (element);
}

void	ft_collectible_lstadd_front(t_col **lst, t_col *new)
{
	t_col	*holder;

	holder = *lst;
	*lst = new;
	(*lst)->next = holder;
}

void	ft_collectible_lstdel(t_col **lst, int x, int y)
{
	t_col	*holder;
	t_col	*prev_holder;

	holder = *lst;
	prev_holder = *lst;
	if (holder && holder->x == x && holder->y == y)
	{
		*lst = (*lst)->next;
		holder = ft_free(holder);
		return ;
	}
	while (holder)
	{
		if (holder->x == x && holder->y == y)
		{
			prev_holder->next = holder->next;
			holder = ft_free(holder);
			return ;
		}
		prev_holder = holder;
		holder = holder->next;
	}
}

void	ft_collectible_lstclear(t_col **lst)
{
	t_col	*holder;

	if (!lst)
		return ;
	while (*lst)
	{
		holder = *lst;
		*lst = (*lst)->next;
		holder = ft_free(holder);
	}
	*lst = NULL;
}
