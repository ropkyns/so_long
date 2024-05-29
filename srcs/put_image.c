/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:05:48 by paulmart          #+#    #+#             */
/*   Updated: 2024/05/29 18:27:44 by palu             ###   ########.fr       */
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
	data->sprite[0] = open_xpm(data, "./sprites/grass.xpm", 0);
	data->sprite[1] = open_xpm(data, "./sprites/wall.xpm", 0);
	data->sprite[2] = open_xpm(data, "./sprites/catu.xpm", 0);
	data->sprite[3] = open_xpm(data, "./sprites/catd.xpm", 0);
	data->sprite[4] = open_xpm(data, "./sprites/catl.xpm", 0);
	data->sprite[5] = open_xpm(data, "./sprites/catr.xpm", 0);
	data->sprite[6] = open_xpm(data, "./sprites/portal.xpm", 0);
}
