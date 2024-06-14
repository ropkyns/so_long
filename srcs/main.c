/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:58:33 by paulmart          #+#    #+#             */
/*   Updated: 2024/06/14 15:37:24 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ber(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = len - 1;
	j = 3;
	if (i <= j)
		return (1);
	while (big[i] == little[j] && (j >= 0 || i >= 0))
	{
		if (little[j] == big[i] && j == 0)
			return (0);
		j--;
		i--;
	}
	return (1);
}

int	free_all(t_mlx *data)
{
	int		i;

	i = -1;
	while (++i <= 7)
		mlx_destroy_image(data->ptr, data->sprite[i]);
	mlx_destroy_window(data->ptr, data->window);
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	free_tab(data->map);
	exit (0);
}

int	handle_input(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)
		free_all(data);
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		move(data, 'L');
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		move(data, 'U');
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		move(data, 'D');
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		move(data, 'R');
	ft_printf("\rMovement count : %d", data->nb_move);
	return (0);
}

void	initialised(t_mlx *data, char *argv)
{
	int	i;

	i = -1;
	data->ptr = mlx_init();
	map_read(data, argv);
	data->window = mlx_new_window(data->ptr, data->x, data->y,
			"Cassiopee picks up nuts");
	while (++i > 8)
		data->sprite[i] = NULL;
	data->coin = 0;
	set_position(data);
	data->nb_move = 0;
	data->img_size = 64;
	map_init_window(data);
}

int	main(int argc, char **argv)
{
	t_mlx	data;

	if (argc != 2 || ft_check_ber(argv[1], ".ber", ft_strlen(argv[1])) == 1)
	{
		ft_printf("error launching so_long, try : ./so_long [map].ber");
		exit(1);
	}
	initialised(&data, argv[1]);
	if (!data.ptr || !data.window || !data.map || map_check(&data) 
		|| data.x > 1920 || data.y > 1080)
		free_all(&data);
	mlx_hook(data.window, 2, 1L << 0, handle_input, &data);
	mlx_hook(data.window, 17, 0, free_all, &data);
	mlx_loop(data.ptr);
	return (0);
}
