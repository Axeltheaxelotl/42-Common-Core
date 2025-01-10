/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:12:50 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:44:44 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Counts the number of elements in a list.
 * 
 * @param lst The beginning of the list.
 * @return The number of elements in the list.
 */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		list_len;
	t_list	*current;

	list_len = 0;
	current = lst;
	while (current)
	{
		list_len++;
		current = current->next;
	}
	return (list_len);
}

/*
#include <stdio.h>
int main()
{
	t_list head = NULL;
	ft_lstadd_front(&head, ft_lstnew("node 1"));
	ft_lstadd_front(&head, ft_lstnew("node 2"));
	ft_lstadd_front(&head, ft_lstnew("node 3"));
	ft_lstadd_front(&head, ft_lstnew("node 4"));
	ft_lstadd_front(&head, ft_lstnew("node 5"));
	printf("%d\n", ft_lstsize(&head));
        return (0);
}
*/
