/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_component_surroundings.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <ybensell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:06:14 by hel-makh          #+#    #+#             */
/*   Updated: 2022/08/11 14:33:45 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_is_component_surrounded(char **map, int i, int j)
{
	if (map[i][j + 1]
		&& ft_strchr("0NSEW", map[i][j + 1]))
		return (1);
	else if (j - 1 >= 0
		&& ft_strchr("0NSEW", map[i][j - 1]))
		return (1);
	else if (map[i + 1]
		&& j < (int)ft_strlen(map[i + 1])
		&& ft_strchr("0NSEW", map[i + 1][j]))
		return (1);
	else if (i - 1 >= 0
		&& j < (int)ft_strlen(map[i - 1])
		&& ft_strchr("0NSEW", map[i - 1][j]))
		return (1);
	return (0);
}

static int	ft_is_space_surrounded(char **map, int i, int j)
{
	if (!map[i][j + 1]
		|| (map[i][j + 1]
			&& map[i][j + 1] == SPACE))
		return (1);
	else if (j - 1 < 0
		|| (j - 1 >= 0
			&& map[i][j - 1] == SPACE))
		return (1);
	else if (!map[i + 1]
		|| (map[i + 1]
			&& j >= (int)ft_strlen(map[i + 1]))
		|| (map[i + 1]
			&& j < (int)ft_strlen(map[i + 1])
			&& map[i + 1][j] == SPACE))
		return (1);
	else if (i - 1 < 0
		|| (i - 1 >= 0
			&& j >= (int)ft_strlen(map[i - 1]))
		|| (i - 1 >= 0
			&& j < (int)ft_strlen(map[i - 1])
			&& map[i - 1][j] == SPACE))
		return (1);
	return (0);
}

int	ft_component_surroundings(char **map, int i, int j)
{
	if (map[i][j] == SPACE && ft_is_component_surrounded(map, i, j))
		return (printf("Error\nInvalid map: misplaced [%c] space(s)."
				"\nLine: %d, Column: %d\n", map[i][j], i + 1, j + 1), 0);
	else if (ft_strchr("0NSEW", map[i][j]))
	{
		if (ft_is_space_surrounded(map, i, j))
		{
			if (map[i][j] == EMPTY_SPACE)
				printf("Error\nInvalid map: misplaced [%c] empty space(s)."
					"\nLine: %d, Column: %d\n", map[i][j], i + 1, j + 1);
			else
				printf("Error\nInvalid map: misplaced [%c] player position."
					"\nLine: %d, Column: %d\n", map[i][j], i + 1, j + 1);
			return (0);
		}
	}
	return (1);
}
