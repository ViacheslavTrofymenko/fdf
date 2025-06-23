/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:24 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/23 19:51:06 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**allocate_matrix(int width, int height)
{
	int	**matrix;
	int	i;

	matrix = malloc(sizeof(int *) * height);
	i = 0;
	if (!matrix)
		return (NULL);
	while (i < height)
	{
		matrix[i] = malloc(sizeof(int) * width);
		if (!matrix[i])
		{
			free_matrix(matrix, i);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

void	free_matrix(int **matrix, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	parse_point(char *str, int *z, int *color)
{
	char **parts;
	int		i;
	char	*base;

	base = "0123456789ABSDEF";
	parts = ft_split(str, ',');
	*z = ft_atoi(parts[0]);
	if (parts[1])
		*color = ft_atoi_base(parts[1], base);
	else
		*color = 0xFFFFFF;
	i = 0;
	while (parts[i])
	{
		free(parts[i]);
		i++;
	}
	free(parts);
}

int	count_words(const char *s, char c)
{
	int	count = 0;
	int	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}
