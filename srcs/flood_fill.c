/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:27:09 by paulmart          #+#    #+#             */
/*   Updated: 2024/06/14 10:29:35 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_map(t_mlx *data, char **map)
{
	char		**dup;
	int			i;

	dup = malloc(sizeof(char *) * ((data->y / 64) + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < (data->y / 64))
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i])
		{
			free_tab(dup);
			return (NULL);
		}
	}
	dup[i] = NULL;
	return (dup);
}

void	fill(t_mlx *data, char **map, int y, int x)
{
	if (map[y][x] == 'C')
		data->coin_fill++;
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'F')
	{
		map[y][x] = 'F';
		fill(data, map, y + 1, x);
	}
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'F')
	{
		map[y][x] = 'F';
		fill(data, map, y - 1, x);
	}
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'F')
	{
		map[y][x] = 'F';
		fill(data, map, y, x + 1);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'F')
	{
		map[y][x] = 'F';
		fill(data, map, y, x - 1);
	}
	map[y][x] = 'F';
}

int	flood_fill(t_mlx *data)
{
	char	**dup;

	dup = dup_map(data, data->map);
	if (!dup)
		return (1);
	data->coin_fill = 0;
	fill(data, dup, data->player_y, data->player_x);
	if (dup[data->end_y][data->end_x] == 'F' && data->coin_fill == data->coin)
	{
		free_tab(dup);
		return (0);
	}
	free_tab(dup);
	return (1);
}
