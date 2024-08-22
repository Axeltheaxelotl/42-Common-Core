/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:50:15 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 19:45:21 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "parser_utils.h"

int	get_tok_cmd(char *lex_tok, t_par_tok *par_tok, t_iter *iter)
{
	if (lex_tok == NULL)
		return (EXIT_SUCCESS);
	if (!is_quote_token(lex_tok) && (is_special_token(lex_tok) \
	|| is_redir_token(lex_tok) || (ft_strchr(lex_tok, '(') \
	|| ft_strchr(lex_tok, ')'))))
		return (EXIT_SUCCESS);
	if (init_curr_par_tok() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	par_tok->cmd_size++;
	par_tok->cmd = ft_str_arr_realloc(par_tok->cmd, par_tok->cmd_size);
	if (par_tok->cmd == NULL)
		return (EXIT_FAILURE);
	par_tok->cmd[iter[cmd]] = ft_strdup(lex_tok);
	if (par_tok->cmd[iter[cmd]] == NULL)
		return (EXIT_FAILURE);
	iter[lex]++;
	iter[cmd]++;
	return (EXIT_SUCCESS);
}

int	get_tok_redir(char *lex_toks[], t_iter *iter)
{
	int		i;
	t_iter	*buf_iter;
	char	***buf;
	size_t	*buf_size;

	if (lex_toks[iter[lex]] == NULL)
		return (EXIT_SUCCESS);
	if (!try_get_tok_redir_buf(&buf, &buf_size, &buf_iter))
		return (EXIT_SUCCESS);
	if (init_curr_par_tok() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	get_curr_par_tok()->redir_type \
	[get_tok_redir_type(lex_toks[iter[lex]])] = true;
	(*buf_size) += 2;
	*buf = ft_str_arr_realloc(*buf, *buf_size);
	if (*buf == NULL)
		return (EXIT_FAILURE);
	i = 2;
	while (i--)
	{
		(*buf)[*buf_iter] = ft_strdup(lex_toks[iter[lex]++]);
		if ((*buf)[(*buf_iter)++] == NULL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	get_special_tok(char *lex_tok, t_par_tok *par_toks[], t_iter *iter)
{
	if (lex_tok == NULL)
		return (EXIT_SUCCESS);
	if (ft_strchr(lex_tok, '\'') || ft_strchr(lex_tok, '\"'))
		return (EXIT_SUCCESS);
	if ((ft_strstr(lex_tok, "&&") || ft_strstr(lex_tok, "||")) \
	&& ft_strlen(lex_tok) == 2)
	{
		iter[par]++;
		if (init_curr_par_tok() == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (ft_strstr(lex_tok, "&&"))
			par_toks[iter[par]++]->type = and;
		else if (ft_strstr(lex_tok, "||"))
			par_toks[iter[par]++]->type = or;
		iter[lex]++;
		return (EXIT_BREAK);
	}
	if (ft_strchr(lex_tok, '('))
		return (get_subshell_tok(iter));
	return (EXIT_SUCCESS);
}

int	get_tok_type(char *lex_tok, t_iter *iter)
{
	t_par_tok	*par_tok;

	if (lex_tok == NULL)
		return (EXIT_SUCCESS);
	if (init_curr_par_tok() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	par_tok = get_curr_par_tok();
	if (ft_strlen(lex_tok) == 1)
	{
		if (ft_strchr(lex_tok, '|'))
			return (set_tok_type_pipe(par_tok, iter));
		if (ft_strchr(lex_tok, '<'))
			par_tok->redir_type[is_in] = true;
		if (ft_strchr(lex_tok, '>'))
			par_tok->redir_type[is_out] = true;
	}
	if (ft_strlen(lex_tok) == 2 && ft_strstr(lex_tok, "<<"))
		par_tok->redir_type[is_in_heredoc] = true;
	if (ft_strlen(lex_tok) == 2 && ft_strstr(lex_tok, ">>"))
		par_tok->redir_type[is_out_append] = true;
	if ((lex_tok[0] != '\'' && lex_tok[0] != '\"') \
	&& (ft_strchr(lex_tok, '(') && ft_strchr(lex_tok, ')')))
		par_tok->type = subshell;
	return (EXIT_SUCCESS);
}
