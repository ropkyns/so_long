/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:05:48 by paulmart          #+#    #+#             */
/*   Updated: 2024/03/26 18:26:19 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_error(t_mlx *data, int index)
{
	int		i;

	i = -1;
	while (++i < index)
		mlx_destroy_image(data->ptr, data->sprite[i]);
	mlx_destroy_window(data->ptr, data->window);
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	exit (0);
}

void	*open_xpm(t_mlx *data, char *path, int index)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->ptr, path, &data->img_size,
			&data->img_size);
	if (!img)
		xpm_error(data, index);
	return (img);
}

void	init_image(t_mlx *data)
{
	data->sprite[0] = open_xpm(data, "grass_sprite.xpm", 0);
}
