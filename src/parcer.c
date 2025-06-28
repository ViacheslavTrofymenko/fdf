/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:21 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/28 11:22:11 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	validate_line_width(char **words, int expected_width, int y)
{
	int	count;

	count = 0;
	while (words[count])
		count++;
	if (count != expected_width)
	{
		ft_printf("%sError:\nInconsistent width at row %d "
			"(expected %d, got %d)%s\n",
			RED, y, expected_width, count, RESET);
		return (0);
	}
	return (1);
}

static int	parse_line(char *line, int y, t_map *map)
{
	char	**words;
	int		x;

	words = split_by_spaces(line);
	if (!words)
		return (1);
	if (!validate_line_width(words, map->width, y))
		return (free_str_array(words), 1);
	x = 0;
	while (x < map->width)
	{
		if (!parse_point(words[x], &map->z_matrix[y][x],
			&map->color_matrix[y][x]))
		{
			ft_printf("%sError: invalid value at row %d, column %d ('%s')%s\n",
				RED, y, x, words[x], RESET);
			free_str_array(words);
			return (1);
		}
		x++;
	}
	free_str_array(words);
	return (0);
}

int	count_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	read_lines_from_file(char *filename, char ***lines, int *height)
{
	int		fd;
	char	**buffer;
	char	*line;
	int		i;

	*height = count_lines(filename);
	if (*height <= 0)
		return (1);
	buffer = malloc(sizeof(char *) * (*height + 1));
	if (!buffer)
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(buffer), 1);
	i = 0;
	while (i < *height)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free_str_array(buffer);
			close(fd);
			return (1);
		}
		buffer[i++] = line;
	}
	buffer[i] = NULL;
	close(fd);
	*lines = buffer;
	return (0);
}

int	parse_lines_into_map(char **lines, t_map *map, int height)
{
	char	**words;
	int		i;

	words = split_by_spaces(lines[0]);
	if (!words)
		return (1);
	i = 0;
	while (words[i])
		i++;
	free_str_array(words);
	map->width = i;
	map->height = height;
	map->z_matrix = allocate_matrix(i, height);
	map->color_matrix = allocate_matrix(i, height);
	if (!map->z_matrix || !map->color_matrix)
		return (1);
	i = 0;
	while (i < height)
	{
		if (parse_line(lines[i], i, map))
			return (1);
		free(lines[i]);
		i++;
	}
	return (free(lines), 0);
}

int	parse_map(char *filename, t_map *map)
{
	char	**lines;
	int		height;

	if (read_lines_from_file(filename, &lines, &height))
		return (1);
	if (parse_lines_into_map(lines, map, height))
	{
		free_matrix(map->z_matrix, height);
		free_matrix(map->color_matrix, height);
		return (1);
	}
	return (0);
}
