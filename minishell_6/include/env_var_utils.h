/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:54:44 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 19:47:43 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_UTILS_H
# define ENV_VAR_UTILS_H

typedef struct s_env
{
	char	**envp;
	char	**env_var;
	char	*pwd;
	char	*oldpwd;
}			t_env;

t_env	*init_envv(char **envp);
void	free_envv(t_env *envv);
int		reinit_env_var(t_env *envv, char **argv);
char	*get_env_var_value(t_env *envv, char *var);
void	set_envv(t_env *envv);
t_env	*get_envv(void);
char	**get_env_var(void);

#endif
