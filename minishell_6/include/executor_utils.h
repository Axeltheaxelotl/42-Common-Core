/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:55:30 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 17:55:35 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_UTILS_H
# define EXECUTOR_UTILS_H

int		clean_exp_tok_cmds(t_exp_tok *exp_tok);
int		handle_inbuilt_redir(t_exp_tok *exp_tok);
int		execute_inbuilt(t_exp_tok *exp_tok);
bool	is_inbuilt(char *cmd);
int		execute_child(t_exp_tok *exp_tok, char *abs_cmd_path, int status);
int		execute_inbuilt_child(t_exp_tok *exp_tok);
int		execute_inbuilt_reset_fds(t_exp_tok *exp_tok, int saved_fds[2]);

#endif
