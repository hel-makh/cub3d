/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_lstfuncs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:37:49 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/04 17:10:58 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_render	*ft_render_lstnew(void)
{
	t_render	*element;

	element = malloc (1 * sizeof(t_render));
	if (element == NULL)
		return (NULL);
	element->next = NULL;
	return (element);
}

void	ft_render_lstadd_front(t_render **lst, t_render *new)
{
	t_render	*holder;

	holder = *lst;
	*lst = new;
	(*lst)->next = holder;
}

void	ft_render_lstclear(t_render **lst)
{
	t_render	*holder;

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
