/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:24 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/30 11:12:39 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

static int	get_word_len(char *s)
{
	int	len;

	len = 0;
	while (s[len] && !ft_isspace(s[len]))
		len++;
	return (len);
}

static char	*copy_word(char *s, int len)
{
	return (ft_substr(s, 0, len));
}

char	**split_by_spaces(char *s)
{
	char	**result;
	int		count;
	int		i;
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
			len = get_word_len(s);
			result[i++] = copy_word(s, len);
			s += len;
		}
	}
	result[i] = NULL;
	return (result);
}
