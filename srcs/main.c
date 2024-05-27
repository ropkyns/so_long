/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:58:33 by paulmart          #+#    #+#             */
/*   Updated: 2024/05/27 17:29:37 by paulmart         ###   ########.fr       */
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

void	initialised(t_mlx *data)
{
	data->ptr = NULL;
	data->window = NULL;
	data->sprite[0] = NULL;
	data->img_size = 0;
	data->map = NULL;
	data->x = 0;
	data->y = 0;
}

int	main(int argc, char **argv)
{
	t_mlx	data;

	if (argc > 2)
		exit(1);
	initialised(&data);
	data.ptr = mlx_init();
	if (data.ptr == NULL)
		return (1);
	map_read(&data, argv[1]);
	ft_printf("%s\n", data.map[1]);
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
	ft_printf("apres cas d'erreur!\n");
	mlx_key_hook(data.window, handle_input, &data);
	init_image(&data);
	map_init_window(data);
	mlx_loop(data.ptr);
	ft_printf("fin!\n");
	return (0);
}
