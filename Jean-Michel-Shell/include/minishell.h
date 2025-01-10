/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:57:03 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 19:48:16 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/include/libft.h"
# include <errno.h>
# include <dirent.h>
# include <stdbool.h>
# include <fcntl.h>
# include "error_utils.h"

# define EXIT_SYNTAX_ERROR 258
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_CTRL_D 130

int		echo(char **args);
int		export(char **argv);
int		unset(char **argv);
int		env(char **argv);
int		pwd(void);
int		cd(char **argv);
int		exit_inbuilt(char *args[]);
void	handle_cmd_signals(void);
void	handle_global_signals(void);

#endif
