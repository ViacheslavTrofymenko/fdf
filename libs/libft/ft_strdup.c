/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:10:41 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/07/01 11:29:09 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int	main()
{
	char	*dest;
	int		len = 0;
	int		i = 0;
	char	*src = "Hello Madrid";

	dest = ft_strdup(src);
	printf("Result1 = %p\n", dest);
	while (i < 12)
	{
		printf("Result = %c\n", dest[i]);
		i++;
	}
	free(dest);
	return (0);
}
*/
