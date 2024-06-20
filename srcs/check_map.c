/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:10:53 by paulmart          #+#    #+#             */
/*   Updated: 2024/06/20 13:43:07 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_check(t_mlx *data, char **map, int i, int len)
{
	int	j;

	j = -1;
	if (ft_strlen(map[i]) != len - 1 && map[i][len - 2] != '1')
		return (1);
	while (++j < data->x / 64)
	{
		if (map[i][j] != '1')
			return (1);
	}
	return (0);
}

int	size_check(t_mlx *data, char **map)
{
	int		len;
	int		i;

	len = ft_strlen(map[0]);
	i = -1;
	while (++i < data->x / 64)
	{
		if (map[0][i] != '1')
			return (1);
	}
	i = -1;
	while (++i < ((data->y / 64) - 1))
	{
		if (ft_strlen(map[i]) != len || map[i][0] != '1'
			|| map[i][len - 2] != '1')
			return (1);
	}
	if (line_check(data, map, i, len) == 1)
		return (1);
	return (0);
}

int	player_end_check(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	player;

	player = 0;
	exit = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				player++;
			if (map[i][j] == 'E')
				exit++;
		}
	}
	if (player != 1 || exit != 1)
		return (1);
	return (0);
}

int	map_check(t_mlx *data)
{
	if (size_check(data, data->map) == 1)
	{
		perror("Error\nInvalid map");
		return (1);
	}
	if (player_end_check(data->map) == 1 || data->coin == 0)
	{
		perror("Error\nYou need only 1 (P), 1 (E) and at least 1 (C)");
		return (1);
	}
	if (flood_fill(data) == 1)
	{
		perror("Error\nCan't reach exit or all collectibles");
		return (1);
	}
	else
		return (0);
}
