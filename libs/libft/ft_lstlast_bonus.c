/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:28:50 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/04/14 12:28:52 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int main()
{
	t_list *head = ft_lstnew(1);
	head->next = ft_lstnew(2);
	head->next->next = ft_lstnew(3);

	t_list *last = ft_lstlast(head);
	if (last != NULL)
		printf("Last node: %d\n", last->content);
	return (0);
}
*/
