/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:13:17 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/04/11 19:13:19 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	total_size;
	char	*ptr;

	if (nmemb != 0 && size != 0)
	{
		if (nmemb > SIZE_MAX / size)
			return (NULL);
		total_size = nmemb * size;
	}
	else
		total_size = 0;
	ptr = malloc(total_size);
	if (ptr)
	{
		i = 0;
		while (i < total_size)
		{
			ptr[i] = '\0';
			i++;
		}
	}
	return ((void *)ptr);
}
/*
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		size_t n = atoi(argv[1]);
		int *arr = (int *)ft_calloc(n, sizeof(int));

		if (!arr)
		{
			printf("Memory allocation failed!\n");
			return 1;
		}

		int success = 1;
		for (size_t i = 0; i < n; i++)
		{
			if (arr[i] != 0)
			{
				success = 0;
				printf("Memory not zero at index %zu: %d\n", i, arr[i]);
			}
		}

		if (success)
		{
			printf("Test passed: All elements are zero.\n");
		}
		else
		{
			printf("Test failed.\n");
		}

		free(arr);
	}
	return 0;
}
*/
