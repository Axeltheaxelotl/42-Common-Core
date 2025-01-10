/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:51:19 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:44:21 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Allocates (with malloc(3)) and returns a new element. The variable ’content’
 * is initialized with the value of the parameter ’content’. The variable
 * ’next’ is initialized to NULL.
 * 
 * @param content The content to create the new element with.
 * @return The new element.
 */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int	main()
{
	t_list	*new_node;
	int data = 42;
	new_node = ft_lstnew(&data);
	if (!new_node)
	{
        	printf("Memory allocation failed.\n");
        	return (1);
    	}
	printf("Content: %d\n", *(int *)new_node->content);
	printf("Next: %p\n", new_node->next);
	free(new_node);
	return (0);
}
*/
