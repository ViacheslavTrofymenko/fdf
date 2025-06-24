/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:30:51 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/24 17:55:35 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_integer(const char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	is_valid_hex(const char *s)
{
	if (ft_strncmp(s, "0x", 2) != 0 && ft_strncmp(s, "0X", 2) != 0)
		return (0);
	s += 2;
	if (!*s)
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s) && !(*s >= 'A' && *s <= 'F')
			&& !(*s >= 'a' && *s <= 'f'))
			return (0);
		s++;
	}
	return (1);
}

int	parse_point(char *str, int *z, int *color)
{
	char	**parts;
	int		i;
	char	*base;

	base = "0123456789ABCDEF";
	parts = ft_split(str, ',');
	if (!parts || !is_valid_integer(parts[0]))
		return (0);
	*z = ft_atoi(parts[0]);
	if (parts[1])
	{
		if (!is_valid_hex(parts[1]))
			return (free(parts[0]), free(parts[1]), free(parts), 0);
		*color = ft_atoi_base(parts[1], base);
	}
	else
		*color = 0xFFFFFF;
	i = 0;
	while (parts[i])
		free(parts[i++]);
	free(parts);
	return (1);
}
