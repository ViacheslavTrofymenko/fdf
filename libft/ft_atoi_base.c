/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:37:34 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/28 10:20:20 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_base(char c, const char *base);
int			ft_atoi_base_aux(const char *nptr, const char *base, int sign);

int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

// Convert a string to an integer according to the base passed as argument
int	ft_atoi_base(const char *nptr, const char *base)
{
	int	sign;

	sign = 1;
	if (!nptr || !base || ft_strlen(base) < 2 || ft_strlen(base) > 16)
		return (0);
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-' && ft_strlen(base) == 10)
			sign = -1;
		nptr++;
	}
	if (*nptr == '0' && (*(nptr + 1) == 'x' || *(nptr + 1) == 'X'))
		nptr += 2;
	return (ft_atoi_base_aux(nptr, base, sign));
}

static int	is_in_base(char c, const char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

int	ft_atoi_base_aux(const char *nptr, const char *base, int sign)
{
	int	result;
	int	base_len;
	int	digit_value;

	result = 0;
	base_len = ft_strlen(base);
	while ((digit_value = is_in_base(ft_tolower(*nptr), base)) != -1)
	{
		result = result * base_len + digit_value;
		if (result < 0)
			return (0);
		nptr++;
	}
	return (result * sign);;
}
