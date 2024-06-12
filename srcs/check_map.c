/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:10:53 by paulmart          #+#    #+#             */
/*   Updated: 2024/06/12 12:32:22 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_check(t_mlx *data, char **map)
{
	int		len;
	int		i;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[++i] && i < data->y / 64)
	{
		if (ft_strlen(map[i] != len))
			return (1);
		if (map[i][0] != '1' || map[i][len - 2] != '1')
			return (1);
	}

}

int	map_check(t_mlx *data)
{
	if ()
	{
		
	}
}
