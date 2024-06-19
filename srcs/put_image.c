/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:05:48 by paulmart          #+#    #+#             */
/*   Updated: 2024/06/19 10:54:51 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_ptr(t_mlx *data)
{
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	exit (1);
}

void	error_xpm(t_mlx *data, int i)
{
	int		j;

	j = -1;
	while (++j < i)
		mlx_destroy_image(data->ptr, data->sprite[j]);
	mlx_destroy_window(data->ptr, data->window);
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	free_tab(data->map);
	perror("Error\nTexture failed");
	exit(0);
}

void	*open_xpm(t_mlx *data, char *path, int index)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->ptr, path, &data->img_size,
			&data->img_size);
	if (!img)
		error_xpm(data, index);
	return (img);
}

void	init_image(t_mlx *data)
{
	data->sprite[0] = open_xpm(data, "./textures/grass.xpm", 0);
	data->sprite[1] = open_xpm(data, "./textures/wall.xpm", 1);
	data->sprite[2] = open_xpm(data, "./textures/catu.xpm", 2);
	data->sprite[3] = open_xpm(data, "./textures/catd.xpm", 3);
	data->sprite[4] = open_xpm(data, "./textures/catl.xpm", 4);
	data->sprite[5] = open_xpm(data, "./textures/catr.xpm", 5);
	data->sprite[6] = open_xpm(data, "./textures/portal.xpm", 6);
	data->sprite[7] = open_xpm(data, "./textures/peanut.xpm", 7);
}
