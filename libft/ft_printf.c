/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:07:39 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/23 20:04:43 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		chars_count;
	int		i;

	i = 0;
	va_start(ap, str);
	chars_count = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			chars_count += ft_parse_string(str[i + 1], &ap);
			i++;
		}
		else
			chars_count += ft_putchar_int(str[i]);
		i++;
	}
	va_end(ap);
	return (chars_count);
}
