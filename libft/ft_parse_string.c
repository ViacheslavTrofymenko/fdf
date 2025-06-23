/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:53:53 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/23 20:04:31 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parse_string(char c, va_list *arg)
{
	if (c == 'c')
		return (ft_putchar_int(va_arg(*arg, int)));
	else if (c == 's')
		return (ft_putstr_int(va_arg(*arg, char *)));
	else if (c == 'p')
		return (ft_putpointer_int(va_arg(*arg, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_int(va_arg(*arg, int)));
	else if (c == 'u')
		return (ft_put_unsigned_int(va_arg(*arg, unsigned int)));
	else if (c == 'x')
		return (ft_put_hex(va_arg(*arg, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_put_hex(va_arg(*arg, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}
