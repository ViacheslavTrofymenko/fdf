/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:21 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/07/02 11:00:36 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	read_lines_from_file(char *filename, char ***lines, int *height)
{
	int		fd;
	char	**buffer;

	*height = count_lines(filename);
	if (*height <= 0)
		return (1);
	buffer = malloc(sizeof(char *) * (*height + 1));
	if (!buffer)
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(buffer), 1);
	if (read_lines(fd, buffer, *height))
	{
		close(fd);
		return (1);
	}
	close(fd);
	*lines = buffer;
	return (0);
}

static int allocate_and_prepare_map(char **lines, t_map *map, int height)
{
	char **words;
	int width = 0;

	words = split_by_spaces(lines[0]);
	if (!words)
		return (1);

	while (words[width])
		width++;

	free_str_array(words);

	map->width = width;
	map->height = height;
	map->z_matrix = allocate_matrix(width, height);
	map->color_matrix = allocate_matrix(width, height);

	if (!map->z_matrix || !map->color_matrix)
		return (1);

	return (0);
}

int parse_lines_into_map(char **lines, t_map *map, int height)
{
	int i;

	if (allocate_and_prepare_map(lines, map, height))
		return (1);

	i = 0;
	while (i < height)
	{
		if (parse_line(lines[i], i, map))
		{
			while (i < height)
				free(lines[i++]);
			free(lines);
			return (1);
		}
		free(lines[i]);
		i++;
	}
	free(lines);
	return (0);
}

int	parse_map(char *filename, t_map *map)
{
	char	**lines;
	int		height;

	if (read_lines_from_file(filename, &lines, &height))
		return (1);
	if (parse_lines_into_map(lines, map, height))
	{
		free_matrix(&map->z_matrix, height);
		free_matrix(&map->color_matrix, height);
		return (1);
	}
	return (0);
}
