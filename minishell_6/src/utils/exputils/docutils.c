/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   docutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:46:55 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 19:46:03 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "expander_utils.h"
#include <readline/history.h>
#include <readline/readline.h>

static char	*get_heredoc(t_par_tok *par_tok)
{
	int	i;

	i = 0;
	while (par_tok->in[i])
	{
		if (ft_strcmp(par_tok->in[i], "<<") == 0)
			return (par_tok->in[i + 1]);
		i++;
	}
	return (NULL);
}

static int	exit_close_fds(int fd1, int fd2, int exit_status)
{
	if (fd1 != -1)
		close(fd1);
	if (fd1 != -1)
		close(fd2);
	return (exit_status);
}

static void	wait_for_heredoc_help(t_exp_tok *exp_tok)
{
	if (exp_tok->cmd == NULL && exp_tok->out != STDOUT_FILENO)
	{
		close(exp_tok->out);
		exp_tok->out = STDOUT_FILENO;
	}
}

int	wait_for_heredoc(
	t_par_tok *par_tok, t_exp_tok *exp_tok, char *buf, char *heredoc
	)
{
	int		end[2];

	if (pipe(end) == -1)
		return (ft_perror(EXIT_FAILURE, "pipe error"));
	exp_tok->in = end[0];
	heredoc = get_heredoc(par_tok);
	if (heredoc == NULL)
		return (exit_close_fds(end[0], end[1], EXIT_FAILURE));
	while (true)
	{
		buf = readline("> ");
		if (buf == NULL)
			return (exit_close_fds(end[1], -1, EXIT_SUCCESS));
		if (ft_strcmp(buf, heredoc) == 0)
			break ;
		ft_fprintf(end[1], "%s\n", buf);
		free(buf);
	}
	free(buf);
	close(end[1]);
	wait_for_heredoc_help(exp_tok);
	return (EXIT_SUCCESS);
}
