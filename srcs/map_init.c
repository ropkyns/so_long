/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:30:11 by paulmart          #+#    #+#             */
/*   Updated: 2024/06/12 11:43:18 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

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
			free_tab(tab);
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
		free_all(data);
	}
	count_line = 0;
	line = get_next_line(fd);
	len = ft_strlen(line) - 1;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count_line++;
	}
	free(line);
	data->x = (int)len * 64;
	data->y = count_line * 64;
	close(fd);
	data->map = maploc(count_line, map);
}

void	put_image_on_map(t_mlx *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->ptr, data->window,
			data->sprite[1], j * 64, i * 64);
	else if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->ptr, data->window,
			data->sprite[3], j * 64, i * 64);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->ptr, data->window,
			data->sprite[6], j * 64, i * 64);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->ptr, data->window,
			data->sprite[7], j * 64, i * 64);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->ptr, data->window,
			data->sprite[0], j * 64, i * 64);
	else
	{
		perror("Error\nMap invalid\n");
		free_all(data);
	}
}

void	map_init_window(t_mlx *data)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	init_image(data);
	while (++i < (data->y / 64))
	{
		while (++j < (data->x / 64))
			put_image_on_map(data, i, j);
		j = -1;
	}
}
