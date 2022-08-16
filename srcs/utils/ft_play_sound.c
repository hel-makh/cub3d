/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_sound.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 09:44:02 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/15 09:44:15 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_play_sound(char *path)
{
	pid_t	pid;
	char	*argv[3];

	pid = fork();
	if (pid == -1)
		return ;
	else if (pid == 0)
	{
		argv[0] = ft_strdup("/usr/bin/afplay");
		argv[1] = ft_strdup(path);
		argv[2] = NULL;
		execve(argv[0], argv, NULL);
	}
}
