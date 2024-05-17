/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:58:33 by paulmart          #+#    #+#             */
/*   Updated: 2024/05/17 15:47:01 by paulmart         ###   ########.fr       */
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

int	main(void)
{
	t_mlx	data;

	data.ptr = mlx_init();
	if (data.ptr == NULL)
		return (1);
	data.window = mlx_new_window(data.ptr, 640, 640, "so_long");
	if (data.window == NULL)
	{
		mlx_destroy_display(data.ptr);
		free(data.ptr);
		return (1);
	}
	mlx_key_hook(data.window, handle_input, &data);
	init_image(&data);
	map_init(data);
	mlx_loop(data.ptr);
	return (0);
}
