/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:48:07 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 17:48:25 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "expander_utils.h"

static t_exp_tok	**_get_exec_toks(t_exp_tok *exp_toks[], bool reset)
{
	static t_exp_tok	**static_exp_toks = NULL;

	if (exp_toks == NULL && !reset)
		return (static_exp_toks);
	if (reset)
	{
		static_exp_toks = NULL;
		return (NULL);
	}
	static_exp_toks = exp_toks;
	return (static_exp_toks);
}

t_exp_tok	**get_exp_toks(void)
{
	return (_get_exec_toks(NULL, false));
}

void	set_exp_toks(t_exp_tok *exp_toks[])
{
	_get_exec_toks(exp_toks, false);
}

void	reset_exp_toks(void)
{
	_get_exec_toks(NULL, true);
}
