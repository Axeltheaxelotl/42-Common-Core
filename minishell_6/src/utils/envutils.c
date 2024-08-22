/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:40:34 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 19:44:29 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var_utils.h"
#include "minishell.h"

static void	handle_special_pwd(t_env *envv, char **value)
{
	if (ft_strlen(envv->pwd) == 0)
	{
		*value = ft_calloc(1, sizeof(char));
	}
	else
	{
		*value = ft_strdup(envv->pwd);
	}
}

static void	handle_special_oldpwd(t_env *envv, char **value)
{
	if (ft_strlen(envv->oldpwd) == 0)
	{
		*value = ft_calloc(1, sizeof(char));
	}
	else
	{
		*value = ft_strdup(envv->oldpwd);
	}
}

static void	handle_special_vars(t_env *envv, char *var, char **value)
{
	if (ft_strlen(*value) == 0)
	{
		if (ft_strcmp(var, "PWD") == 0)
		{
			handle_special_pwd(envv, value);
		}
		else if (ft_strcmp(var, "OLDPWD") == 0)
		{
			handle_special_oldpwd(envv, value);
		}
	}
	if (*value == NULL)
	{
		*value = ft_calloc(1, sizeof(char));
	}
}

char	*get_env_var_value(t_env *envv, char *var)
{
	int		i;
	char	*value;
	char	*found;

	i = 0;
	value = NULL;
	while (envv && envv->env_var && envv->env_var[i] != NULL)
	{
		if (ft_strncmp(var, envv->env_var[i], ft_strlen(var)) == 0
			&& envv->env_var[i][ft_strlen(var)] == '=')
		{
			found = ft_strchr(envv->env_var[i], '=');
			if (found != NULL)
			{
				value = ft_strdup(found + 1);
				break ;
			}
		}
		i++;
	}
	handle_special_vars(envv, var, &value);
	return (value);
}

t_env	*init_envv(char **envp)
{
	t_env	*envv;

	envv = ft_calloc(1, sizeof(t_env));
	if (envv == NULL || envp == NULL || *envp == NULL)
	{
		return (NULL);
	}
	envv->envp = envp;
	envv->env_var = ft_str_arr_dup(envp);
	envv->pwd = get_env_var_value(envv, "PWD");
	envv->oldpwd = get_env_var_value(envv, "OLDPWD");
	if (envv->env_var == NULL || envv->pwd == NULL || envv->oldpwd == NULL)
	{
		free_envv(envv);
		return (NULL);
	}
	return (envv);
}

void	free_envv(t_env *envv)
{
	if (envv == NULL)
	{
		return ;
	}
	envv->envp = NULL;
	ft_free_str_array(&envv->env_var);
	ft_free_str(&envv->pwd);
	ft_free_str(&envv->oldpwd);
	free(envv);
}

int	reinit_env_var(t_env *envv, char **argv)
{
	if (*envv->env_var == NULL)
	{
		envv->env_var = ft_realloc_str_arr(envv->env_var, 2);
		if (envv->env_var == NULL)
		{
			return (EXIT_FAILURE);
		}
		envv->env_var[0] = ft_strdup(argv[1]);
		if (envv->env_var[0] == NULL)
		{
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
