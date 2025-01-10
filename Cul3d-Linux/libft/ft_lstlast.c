/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:33:25 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:44:27 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Returns the last element of the list.
 * 
 * @param lst The beginning of the list.
 * @return The last element of the list.
 */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}
