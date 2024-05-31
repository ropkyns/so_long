/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:05:48 by paulmart          #+#    #+#             */
/*   Updated: 2024/05/31 14:23:28 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*open_xpm(t_mlx *data, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->ptr, path, &data->img_size,
			&data->img_size);
	if (!img)
		free_all(data);
	return (img);
}

void	init_image(t_mlx *data)
{
	data->sprite[0] = open_xpm(data, "./textures/grass.xpm");
	data->sprite[1] = open_xpm(data, "./textures/wall.xpm");
	data->sprite[2] = open_xpm(data, "./textures/catu.xpm");
	data->sprite[3] = open_xpm(data, "./textures/catd.xpm");
	data->sprite[4] = open_xpm(data, "./textures/catl.xpm");
	data->sprite[5] = open_xpm(data, "./textures/catr.xpm");
	data->sprite[6] = open_xpm(data, "./textures/portal.xpm");
	data->sprite[7] = open_xpm(data, "./textures/peanut.xpm");
}
