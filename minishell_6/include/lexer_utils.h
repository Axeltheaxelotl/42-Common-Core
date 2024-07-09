/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:56:48 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 17:56:55 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_UTILS_H
# define LEXER_UTILS_H

typedef struct s_quotes
{
	int		i;
	int		j;
	int		len;
	char	*start;
	char	*end;
	char	*quote;
}	t_quotes;

// LEXER UTILS
char	get_next_special(char *token);
size_t	get_next_token_size(char *token, char next_special);
bool	token_is_unadjusted(char *token);
bool	is_special_char(char curr, char next);
int		jump_to_end_of_subshell(char *tokens[], int i);
int		get_subshell_count(char *tokens[], int i);
bool	token_is_subshell(char *token);
int		join_quotes(char ***tokens);
char	*get_end_of_subshell(char *tokens[], int *i, char *sub_tok);
bool	is_valid_syntax(char *lex_toks[]);
bool	is_valid_line_syntax(char *line);
int		token_join_all_starts(char ***tokens, t_quotes *quo, int i);
int		combine_loop(char ***tokens, t_quotes *quo);
int		token_join_end_one(char ***tokens, t_quotes *quo);
int		exit_on_syntax_error(void);

#endif
