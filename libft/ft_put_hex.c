/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:11:17 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/23 20:04:48 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_hex(unsigned int n, char *hex)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_put_hex(n / 16, hex);
	count += ft_putchar_int(hex[n % 16]);
	return (count);
}
