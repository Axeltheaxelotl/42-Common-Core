/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:31:06 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:44:29 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Iterates the list ’lst’ and applies the function ’f’ to the content of each
 * element.
 * 
 * @param lst The address of a pointer to the first link of a list.
 * @param f The address of the function used to iterate on the list.
 */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
