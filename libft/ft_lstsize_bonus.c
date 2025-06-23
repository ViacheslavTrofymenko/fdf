/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:25:01 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/04/14 12:25:05 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
int main(void)
{
	t_list *n1 = ft_lstnew("One");
	t_list *n2 = ft_lstnew("TWo");
	t_list *n3 = ft_lstnew("Three");

	ft_lstadd_front(&n2, n3);
	ft_lstadd_front(&n1, n2);

	printf("Result: %d\n", ft_lstsize(n3));
	return (0);
}
*/
