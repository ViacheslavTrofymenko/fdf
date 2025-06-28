/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:24 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/28 18:45:19 by vtrofyme         ###   ########.fr       */
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
			free_matrix(&matrix, i);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

void	free_matrix(int ***matrix, int height)
{
	int	i;

	if (!matrix || !*matrix)
		return ;
	i = 0;
	while (i < height)
	{
		free((*matrix)[i]);
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}

void	free_str_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static int	count_words(const char *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!ft_isspace(*s) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (ft_isspace(*s))
			in_word = 0;
		s++;
	}
	return (count);
}

char	**split_by_spaces(char *s)
{
	char	**result;
	int		count;
	int		i;
	char	*start;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	count = count_words(s);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s && ft_isspace(*s))
			s++;
		if (*s)
		{
			start = s;
			len = 0;
			while (s[len] && !ft_isspace(s[len]))
				len++;
			result[i++] = ft_substr(start, 0, len);
			s += len;
		}
	}
	result[i] = NULL;
	return (result);
}
