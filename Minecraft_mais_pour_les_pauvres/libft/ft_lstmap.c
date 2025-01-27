/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:37:03 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:44:26 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Iterates the list ’lst’ and applies the function ’f’ to the content of each
 * element. Creates a new list resulting of the successive applications of the
 * function ’f’. The ’del’ function is used to delete the content of an element
 * if needed.
 * 
 * @param lst The address of a pointer to the first link of a list.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content.
 * @return The new list. NULL if the allocation fails.
 */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
