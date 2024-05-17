/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:30:11 by paulmart          #+#    #+#             */
/*   Updated: 2024/05/17 15:46:57 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_mlx data)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < 640)
	{
		while (x < 640)
		{
			mlx_put_image_to_window(data.ptr, data.window,
				data.sprite[0], x, y);
			x += 64;
		}
		x = 0;
		y += 64;
	}
}
