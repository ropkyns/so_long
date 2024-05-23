/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:58:33 by paulmart          #+#    #+#             */
/*   Updated: 2024/05/23 19:07:06 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("\rThe %d key (ESC) has been pressed", keysym);
		mlx_destroy_window(data->ptr, data->window);
		mlx_destroy_display(data->ptr);
		free(data->ptr);
		exit(1);
	}
	ft_printf("\rThe %d key has been pressed", keysym);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	data;

	if (argc > 2)
		exit(1);
	data.ptr = mlx_init();
	if (data.ptr == NULL)
		return (1);
	map_read(data, argv[1]);
	if (data.map == NULL)
	{
		free(data.ptr);
		exit(1);
	}
	data.window = mlx_new_window(data.ptr, data.x, data.y, "so_long");
	if (data.window == NULL)
	{
		mlx_destroy_display(data.ptr);
		free(data.ptr);
		return (1);
	}
	mlx_key_hook(data.window, handle_input, &data);
	init_image(&data);
	/* map_init_window(data); */
	mlx_loop(data.ptr);
	return (0);
}
