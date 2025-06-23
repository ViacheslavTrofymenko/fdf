/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:21 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/23 19:25:29 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_map_height(char *filename)
{
	int	fd;
	int	height;
	char	*line;

	height = 0;
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
		width = count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

static int	parse_line(char *line, int y, t_map *map)
{
	char	**words;
	int		x;

	words = ft_split(line, ' ');
	if (!words)
		return (1);
	x = 0;
	while (x < map->width)
	{
		parse_point(words[x], &map->z_matrix[y][x],
			&map->color_matrix[y][x]);
		free(words[x]);
		x++;
	}
	free(words);
	return (0);
}

int	fill_data(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	y = 0;
	while (y < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (parse_line(line, y, map))
			return (free(line), close(fd), 1);
		free(line);
		y++;
	}
	return (close(fd), 0);
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
	return (fill_data(filename, map));
}
