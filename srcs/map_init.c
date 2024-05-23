/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:30:11 by paulmart          #+#    #+#             */
/*   Updated: 2024/05/23 19:08:18 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**maploc(int count_line, int fd)
{
	char	**tab;
	int		i;

	tab = malloc(sizeof(char *) * count_line + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (count_line >= i)
	{
		tab[i] = get_next_line(fd);
		if (tab[i] == NULL)
		{
			i = -1;
			while (tab[++i])
				free(tab[i]);
			free(tab);
			perror("Error\nMemory allocation failed\n");
			return (NULL);
		}
		i++;
	}
	return (tab);
}

void	map_read(t_mlx data, char *map)
{
	int		fd;
	char	*line;
	size_t	len;
	int		count_line;

	fd = open(map, 0);
	if (fd == -1)
	{
		perror("Error\nCan't open the file\n");
		return ;
	}
	count_line = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		len = strlen(line);
		count_line++;
		free(line);
	}
	data.x = (int)len;
	data.y = count_line;
	data.map = maploc(count_line, fd);
	close(fd);
}

void	map_init_window(t_mlx data)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < 640)
	{
		while (x < 640)
		{
			mlx_put_image_to_window(data.ptr, data.window,
				data.sprite[0], x, y);
			x += 64;
		}
		x = 0;
		y += 64;
	}
}
