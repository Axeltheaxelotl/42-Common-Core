/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:57:23 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 19:48:37 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# define EXIT_BREAK 3
# include <stdbool.h>
# include "brain.h"

typedef struct s_func_args
{
	char		**lex_toks;
	t_par_tok	**par_toks;
	t_iter		*iter;
}	t_func_args;
int			get_tok_type(char *lex_tok, t_iter *iter);
int			get_tok_cmd(char *lex_tok, t_par_tok *par_tok, t_iter *iter);
int			get_tok_redir(char *lex_toks[], t_iter *iter);
int			get_special_tok( \
	char *lex_tok, t_par_tok *par_toks[], t_iter *iter \
	);
int			set_tok_type_pipe(t_par_tok *par_tok, t_iter *iter);
int			get_subshell_tok(t_iter *iter);
bool		is_quote_token(char *lex_tok);
bool		is_redir_token(char *lex_tok);
bool		is_special_token(char *lex_tok);
int			init_curr_par_tok(void);
int			free_parser(t_par_tok *par_tok[], t_iter *iter, int exit_status);
size_t		get_tokens_size(char *lex_toks[]);
char		*get_dir_items(void);
int			get_tok_redir_type(char *lex_tok);
bool		try_get_tok_redir_buf( \
	char ****buf, size_t **buf_size, t_iter **buf_iter \
	);
char		*interprete_env_var(char *lex_tok);
int			free_par_toks(t_par_tok *par_toks[], int exit_code);

#endif
