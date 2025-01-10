/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:48:56 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 17:49:02 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.h"
#include "parser_utils.h"

static char	**_get_lex_toks(char **lex_toks, bool reset)
{
	static char	**static_lex_toks = NULL;

	if (lex_toks == NULL && !reset)
		return (static_lex_toks);
	if (reset)
	{
		static_lex_toks = NULL;
		return (NULL);
	}
	static_lex_toks = lex_toks;
	return (static_lex_toks);
}

char	*get_curr_lex_tok(void)
{
	t_iter	*iter;

	iter = get_iter();
	if (iter == NULL)
		return (NULL);
	return (get_lex_toks()[iter[lex]]);
}

char	**get_lex_toks(void)
{
	return (_get_lex_toks(NULL, false));
}

void	set_lex_toks(char **lex_toks)
{
	_get_lex_toks(lex_toks, false);
}

void	reset_lex_toks(void)
{
	_get_lex_toks(NULL, true);
}
