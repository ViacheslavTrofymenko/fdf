/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:38:31 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/23 20:05:20 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_int(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
