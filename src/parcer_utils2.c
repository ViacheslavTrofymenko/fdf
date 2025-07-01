/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 12:14:25 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/07/01 10:14:39 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	validate_line_width(char **words, int expected_width, int y)
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

int	parse_line(char *line, int y, t_map *map)
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

int	read_lines(int fd, char **buffer, int height)
{
	char	*line;
	int		i;

	i = 0;
	while (i < height)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free_str_array(buffer);
			return (1);
		}
		buffer[i++] = line;
	}
	buffer[i] = NULL;
	return (0);
}
