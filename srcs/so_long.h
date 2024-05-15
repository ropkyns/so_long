/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:23:59 by paulmart          #+#    #+#             */
/*   Updated: 2024/05/15 15:26:01 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../lib/mlx/mlx.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/gnl/get_next_line.h"

typedef struct s_data_mlx
{
	void	*ptr;
	void	*window;
	void	*sprite[0];
	int		img_size;

}			t_mlx;

int		handle_input(int keysym, t_mlx *data);
void	init_image(t_mlx *data);

#endif