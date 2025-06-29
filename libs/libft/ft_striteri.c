/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:40:20 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/04/14 10:40:28 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
/*
void to_upper(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int main()
{
	char str[] = "Hello Madrid!";

	printf("Before: \n%s\n", str);
	ft_striteri(str, to_upper);
	printf("After:\n%s\n", str);
	return (0);
}
*/
