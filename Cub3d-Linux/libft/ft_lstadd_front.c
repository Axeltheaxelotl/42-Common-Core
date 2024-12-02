/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:50:18 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:44:36 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Adds the element ’new’ at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
		new->next = *lst;
	*lst = new;
}
/*
int main()
{
	t_list	head = NULL;
	t_list	*node1;
	t_list	*node2;

	node1 = ft_lstnew("Node 1");
	node2 = ft_lstnew("Node 2");

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	t_list *current = head;
	while (current)
		printf("%s\n", (char *)current->);
		current = current->next;
	ft_lstclear(&head, free);
	return (0);

}
*/
