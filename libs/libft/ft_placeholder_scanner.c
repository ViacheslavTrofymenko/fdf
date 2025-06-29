/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeholder_scanner.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:53:53 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/24 17:33:34 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_placeholder_scanner(char c, va_list *arg)
{
	if (c == 'c')
		return (ft_putchar_int(va_arg(*arg, int)));
	else if (c == 's')
		return (ft_putstr_int(va_arg(*arg, char *)));
	else if (c == 'p')
		return (ft_putpointer_int(va_arg(*arg, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_int(va_arg(*arg, int)));
	return (0);
}
