/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:24 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/20 15:59:23 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	**allocate_matrix(int width, int height)
{
	int	**matrix = malloc(sizeof(int *) * height);
	if (!matrix) return (NULL);
	for (int i = 0; i < height; i++)
	{
		matrix[i] = malloc(sizeof(int) * width);
		if (!matrix[i])
		{
			free_matrix(matrix, i);
			return (NULL);
		}
	}
	return (matrix);
}

void	free_matrix(int **matrix, int height)
{
	for (int i = 0; i < height; i++)
		free(matrix[i]);
	free(matrix);
}

void	parse_point(char *str, int *z, int *color)
{
	char **parts = ft_split(str, ',');
	*z = ft_atoi(parts[0]);
	*color = (parts[1]) ? ft_atoi_base(parts[1], 16) : 0xFFFFFF;
	for (int i = 0; parts[i]; i++)
		free(parts[i]);
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
