/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:23:59 by paulmart          #+#    #+#             */
/*   Updated: 2024/05/30 15:32:31 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include "../lib/mlx/mlx.h"
# include "../lib/ft_printf/ft_printf.h"
# include "get_next_line.h"

typedef struct s_data_mlx
{
	void	*ptr;
	void	*window;
	void	*sprite[8];
	int		img_size;
	char	**map;
	int		x;
	int		y;
	int		nb_move;
}			t_mlx;

int		handle_input(int keysym, t_mlx *data);
void	init_image(t_mlx *data);
void	map_init_window(t_mlx data);
void	map_read(t_mlx *data, char *map);
char	**maploc(int count_line, char *map);
void	initialised(t_mlx *data);
void	put_image_on_map(t_mlx data, int i, int j);

#endif