/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:31:50 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:44:33 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Deletes and frees the given element and every successor of that element,
 * using the function ’del’ and free(3). Finally, the pointer to the list must
 * be set to NULL.
 *
 * @param lst The address of a pointer to an element.
 * @param del The address of the function used to delete the content of the
 * element.
 */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
