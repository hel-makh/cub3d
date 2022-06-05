/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:22:20 by hel-makh          #+#    #+#             */
/*   Updated: 2022/03/30 11:38:26 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

#define BUFFER_SIZE 1

typedef struct s_list
{
	int				fd;
	char			content[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

static char	*get_fd_content(int fd, t_list *fd_list)
{
	while (fd_list)
	{
		if (fd_list->fd == fd)
			return (fd_list->content);
		fd_list = fd_list->next;
	}
	return ("");
}

static void	set_fd_content(
	int fd, t_list **fd_list, char content[BUFFER_SIZE + 1]
	)
{
	t_list	*holder;
	t_list	*new_list;

	holder = *fd_list;
	while (holder)
	{
		if (holder->fd == fd)
		{
			ft_strcpy(holder->content, content);
			return ;
		}
		holder = holder->next;
	}
	new_list = malloc (1 * sizeof(t_list));
	if (new_list == NULL)
		return ;
	new_list->fd = fd;
	ft_strcpy(new_list->content, content);
	new_list->next = 0;
	holder = *fd_list;
	*fd_list = new_list;
	(*fd_list)->next = holder;
}

static int	del_fd_content(int fd, t_list **fd_list)
{
	t_list	*holder;
	t_list	*prev_holder;

	holder = *fd_list;
	if (holder && holder->fd == fd)
	{
		*fd_list = (*fd_list)->next;
		free(holder);
		return (0);
	}
	while (holder)
	{
		if (holder->fd == fd)
		{
			prev_holder->next = holder->next;
			free(holder);
			return (0);
		}
		prev_holder = holder;
		holder = holder->next;
	}
	return (0);
}

static int	add_next_line(int fd, char **next_line)
{
	static t_list	*fd_list;
	char			buffer[BUFFER_SIZE + 1];
	char			*has_newline;
	int				ret;
	size_t			len;

	ft_strcpy(buffer, get_fd_content(fd, fd_list));
	if (!*buffer)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		if (ret < 1)
			return (del_fd_content(fd, &fd_list));
	}
	has_newline = ft_strchr(buffer, '\n');
	len = ft_strlen(buffer);
	if (has_newline)
		len += 1 - ft_strlen(has_newline);
	*next_line = ft_strnadd(*next_line, buffer, len);
	set_fd_content(fd, &fd_list, buffer + len);
	if (has_newline)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	char	*next_line;

	next_line = (char *) malloc (1 * sizeof(char));
	if (next_line == NULL)
		return (0);
	*next_line = '\0';
	while (add_next_line(fd, &next_line))
		;
	if (!*next_line)
		next_line = ft_free(next_line);
	return (next_line);
}
