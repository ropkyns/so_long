/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:58:33 by paulmart          #+#    #+#             */
/*   Updated: 2024/05/15 14:58:49 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <stdlib.h>
#include "so_long.h"

int	handle_input(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->ptr, data->window);
		mlx_destroy_display(data->ptr);
		free(data->ptr);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	main(void)
{
	t_mlx	data;

	data.ptr = mlx_init();
	if (data.ptr == NULL)
		return (1);
	data.window = mlx_new_window(data.ptr, 500, 500, "so_long");
	if (data.window == NULL)
	{
		mlx_destroy_display(data.ptr);
		free(data.ptr);
		return (1);
	}
	mlx_key_hook(data.window, handle_input, &data);
	init_image(&data);
	mlx_put_image_to_window(data.ptr, data.window, data.sprite[0], 250, 250);
	mlx_loop(data.ptr);
	return (0);
}
