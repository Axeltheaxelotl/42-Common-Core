/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:31:37 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:44:31 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Takes as a parameter an element and frees the memory of the element’s
 * content using the function ’del’ given as a parameter and free the element.
 * The memory of ’next’ must not be freed.
 * 
 * @param lst The element to free.
 * @param del The address of the function used to delete the content.
 */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
