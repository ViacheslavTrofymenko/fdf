/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:17:37 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/04/14 12:17:39 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int main(void)
{
	t_list *node1 = ft_lstnew("Madrid");
	t_list *node2 = ft_lstnew("Hello");

	ft_lstadd_front(&node1, node2);

	t_list *tmp = node2;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	free(node1);
	return (0);
}
*/
