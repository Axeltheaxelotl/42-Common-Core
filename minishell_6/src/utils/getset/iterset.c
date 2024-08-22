/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:48:35 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 17:48:43 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.h"
#include "parser_utils.h"

static t_iter	*_get_iter(t_iter *iter, bool reset)
{
	static t_iter	*static_iter = NULL;

	if (iter == NULL && !reset)
		return (static_iter);
	if (reset)
	{
		static_iter = NULL;
		return (NULL);
	}
	static_iter = iter;
	return (static_iter);
}

t_iter	*get_iter(void)
{
	return (_get_iter(NULL, false));
}

void	set_iter(t_iter *iter)
{
	_get_iter(iter, false);
}

void	reset_iter(void)
{
	_get_iter(NULL, true);
}
