/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:15:54 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/23 20:05:11 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_pointer(unsigned long n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_print_pointer(n / 16);
	count += ft_putchar_int(hex[n % 16]);
	return (count);
}

int	ft_putpointer_int(void *p)
{
	int	count;

	if (!p)
		return (ft_putstr_int("(nil)"));
	count = 0;
	count += ft_putstr_int("0x");
	count += ft_print_pointer((unsigned long)p);
	return (count);
}
