/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:31:42 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/04/14 11:31:44 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
int main(void)
{
	char *str = "Hello Madrid!";
	t_list *node = ft_lstnew(str);

	if (node)
	{
		printf("Content: %s\n", (char *)node->content);
		printf("Next: %p\n", (void *)node->next);
	}

	free(node);
	return (0);
}
*/
