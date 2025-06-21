/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:21 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/20 15:58:33 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_map_height(char *filename)
{
	int	fd;
	int	height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

static int	get_map_width(char *filename)
{
	int	fd;
	int	width;
	char	*line;

	width = -1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (line)
		width = ft_how_many_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int	parse_map(char *filename, t_map *map)
{
	map->height = get_map_height(filename);
	map->width = get_map_width(filename);
	if (map->height <= 0 || map->width <= 0)
		return (1);
	map->z_matrix = allocate_matrix(map->width, map->height);
	map->color_matrix = allocate_matrix(map->width, map->height);
	if (!map->z_matrix || !map->color_matrix)
		return (1);
	return fill_data(filename, map);
}
