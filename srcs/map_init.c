/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:30:11 by paulmart          #+#    #+#             */
/*   Updated: 2024/05/27 17:25:31 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**maploc(int count_line, char *map)
{
	char	**tab;
	int		i;
	int		fd;

	fd = open(map, 0);
	tab = malloc(sizeof(char *) * (count_line + 1));
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (count_line > ++i)
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
	}
	tab[i] = NULL;
	close(fd);
	return (tab);
}

void	map_read(t_mlx *data, char *map)
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
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		count_line++;
		free(line);
	}
	data->x = (int)len * 64;
	data->y = count_line * 64;
	close(fd);
	data->map = maploc(count_line, map);
	int		i = -1;
	while (++i <= 4)
		ft_printf("%s\n", data->map[i]);
}

void	map_init_window(t_mlx data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < data.y)
	{
		while (j < data.x)
		{
			mlx_put_image_to_window(data.ptr, data.window,
				data.sprite[0], j, i);
			j += 64;
		}
		j = 0;
		i += 64;
	}
}
