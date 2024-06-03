/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:24:34 by paulmart          #+#    #+#             */
/*   Updated: 2024/06/03 14:59:53 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_position(t_mlx *data)
{
	int		i;
	int		j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'E')
			{
				data->end_x = j;
				data->end_y = i;
			}
			else if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
			}
			else if (data->map[i][j] == 'C')
				data->coin++;
		}
	}
}

void	player_actualisation(t_mlx *data)
{
	if (data->map[data->next_y][data->next_x] == 'C')
		data->coin--;
	data->map[data->next_y][data->next_x] = 'P';
	data->map[data->player_y][data->player_x] = '0';
	mlx_put_image_to_window(data->ptr, data->window,
		data->sprite[0], data->player_x * 64, data->player_y * 64);
	mlx_put_image_to_window(data->ptr, data->window,
		data->sprite[3], data->next_x * 64, data->next_y * 64);
	data->player_x = data->next_x;
	data->player_y = data->next_y;
}

void	next_move(t_mlx *data, char c)
{
	data->next_x = data->player_x;
	data->next_y = data->player_y;
	if (c == 'U')
		data->next_y = data->player_y - 1;
	else if (c == 'D')
		data->next_y = data->player_y + 1;
	else if (c == 'L')
		data->next_x = data->player_x - 1;
	else if (c == 'R')
		data->next_x = data->player_x + 1;
}	

void	move(t_mlx *data, char move)
{
	next_move(data, move);
	if (!(data->next_x > (data->x - 1) / 64 || data->next_x < 0
			|| data->next_y > (data->y - 1) / 64 || data->next_y < 0)
		&& (data->map[data->next_y][data->next_x] != '1'
		|| (data->map[data->next_y][data->next_x] == 'E' && data->coin == 0)))
	{
		if (data->map[data->next_y][data->next_x] == 'E' && data->coin == 0)
			free_all(data);
		else if (data->map[data->next_y][data->next_x] != 'E')
		{
			data->nb_move++;
			player_actualisation(data);
		}
	}
}
