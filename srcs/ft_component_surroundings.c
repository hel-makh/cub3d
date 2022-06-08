/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_component_surroundings.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:06:14 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/08 17:02:39 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_space_surroundings(char **map, int i, int j)
{
	if (map[i][j + 1]
		&& ft_strchr("0NSEW", map[i][j + 1]))
		return (0);
	if (j - 1 >= 0
		&& ft_strchr("0NSEW", map[i][j - 1]))
		return (0);
	if (map[i + 1]
		&& j < (int)ft_strlen(map[i + 1])
		&& ft_strchr("0NSEW", map[i + 1][j]))
		return (0);
	if (i - 1 >= 0
		&& j < (int)ft_strlen(map[i - 1])
		&& ft_strchr("0NSEW", map[i - 1][j]))
		return (0);
	return (1);
}

static int	ft_empty_space_surroundings(char **map, int i, int j)
{
	if (!map[i][j + 1]
		|| (map[i][j + 1]
			&& map[i][j + 1] == ' '))
		return (0);
	if (j - 1 < 0
		|| (j - 1 >= 0
			&& map[i][j - 1] == ' '))
		return (0);
	if (!map[i + 1]
		|| (map[i + 1]
			&& j < (int)ft_strlen(map[i + 1])
			&& map[i + 1][j] == ' '))
		return (0);
	if (i - 1 < 0
		|| (i - 1 >= 0
			&& j < (int)ft_strlen(map[i - 1])
			&& map[i - 1][j] == ' '))
		return (0);
	return (1);
}

static int	ft_player_surroundings(char **map, int i, int j)
{
	if (!map[i][j + 1]
		|| (map[i][j + 1]
			&& map[i][j + 1] == ' '))
		return (0);
	if (j - 1 < 0
		|| (j - 1 >= 0
			&& map[i][j - 1] == ' '))
		return (0);
	if (!map[i + 1]
		|| (map[i + 1]
			&& j < (int)ft_strlen(map[i + 1])
			&& map[i + 1][j] == ' '))
		return (0);
	if (i - 1 < 0
		|| (i - 1 >= 0
			&& j < (int)ft_strlen(map[i - 1])
			&& map[i - 1][j] == ' '))
		return (0);
	return (1);
}

int	ft_component_surroundings(char **map, int i, int j)
{
	if (map[i][j] == ' ')
	{
		if (!ft_space_surroundings(map, i, j))
			return (printf("Error\nInvalid map: misplaced [%c] space(s)."
					"\nLine: %d, Column: %d\n", map[i][j], i + 1, j + 1), 0);
	}
	else if (map[i][j] == '0')
	{
		if (!ft_empty_space_surroundings(map, i, j))
			return (printf("Error\nInvalid map: misplaced [%c] empty space(s)."
					"\nLine: %d, Column: %d\n", map[i][j], i + 1, j + 1), 0);
	}
	else if (ft_strchr("NSEW", map[i][j]))
	{
		if (!ft_player_surroundings(map, i, j))
			return (printf("Error\nInvalid map: misplaced [%c] player position."
					"\nLine: %d, Column: %d\n", map[i][j], i + 1, j + 1), 0);
	}
	return (1);
}
