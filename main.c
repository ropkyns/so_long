/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:58:33 by paulmart          #+#    #+#             */
/*   Updated: 2024/03/25 15:58:50 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_window;

	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, 600, 600, "TEST");
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}