/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportspecial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:42:56 by alanty            #+#    #+#             */
/*   Updated: 2024/07/08 19:36:27 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "minishell.h"
#include "env_var_utils.h"
#include "inbuilt_utils.h"

int	export_wd(t_env *envv, t_export *exp, char **argv)
{
	if (ft_strlen(argv[exp->j]) > ft_strlen("PWD=")
		&& ft_strncmp(argv[exp->j], "PWD=", 4) == 0)
	{
		ft_free_str(&envv->pwd);
		envv->pwd = ft_strdup(ft_strchr(argv[exp->j], '='));
		if (envv->pwd == NULL)
			return (EXIT_FAILURE);
	}
	else if (ft_strlen(argv[exp->j]) > ft_strlen("OLDPWD=")
		&& ft_strncmp(argv[exp->j], "OLDPWD=", 7) == 0)
	{
		ft_free_str(&envv->oldpwd);
		envv->oldpwd = ft_strdup(ft_strchr(argv[exp->j], '='));
		if (envv->oldpwd == NULL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	export_special(t_env *envv, t_export *exp)
{
	if (envv->env_var == NULL)
		return (EXIT_FAILURE);
	if (ft_strcmp(envv->env_var[exp->i], "PWD") == 0)
		envv->env_var[exp->i] = ft_strstrjoin(envv->env_var[exp->i],
				envv->pwd, "=");
	else if (ft_strcmp(envv->env_var[exp->i], "PWD=") == 0)
		envv->env_var[exp->i] = ft_strstrjoin(envv->env_var[exp->i],
				envv->pwd, NULL);
	else if (ft_strcmp(envv->env_var[exp->i], "OLDPWD") == 0)
		envv->env_var[exp->i] = ft_strstrjoin(envv->env_var[exp->i],
				envv->oldpwd, "=");
	else if (ft_strcmp(envv->env_var[exp->i], "OLDPWD=") == 0)
		envv->env_var[exp->i] = ft_strstrjoin(envv->env_var[exp->i],
				envv->oldpwd, NULL);
	if (envv->env_var[exp->i] == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
*/
#include "minishell.h"
#include "env_var_utils.h"
#include "inbuilt_utils.h"

static int	update_pwd(t_env *envv, char *arg)
{
	ft_free_str(&envv->pwd);
	envv->pwd = ft_strdup(ft_strchr(arg, '='));
	if (envv->pwd == NULL)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	update_oldpwd(t_env *envv, char *arg)
{
	ft_free_str(&envv->oldpwd);
	envv->oldpwd = ft_strdup(ft_strchr(arg, '='));
	if (envv->oldpwd == NULL)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	export_wd(t_env *envv, t_export *exp, char **argv)
{
	if (ft_strlen(argv[exp->j]) > ft_strlen("PWD=")
		&& ft_strncmp(argv[exp->j], "PWD=", 4) == 0)
	{
		return (update_pwd(envv, argv[exp->j]));
	}
	else if (ft_strlen(argv[exp->j]) > ft_strlen("OLDPWD=")
		&& ft_strncmp(argv[exp->j], "OLDPWD=", 7) == 0)
	{
		return (update_oldpwd(envv, argv[exp->j]));
	}
	return (EXIT_SUCCESS);
}

static int	handle_env_var_update(t_env *envv, int i, char *value, char *suffix)
{
	envv->env_var[i] = ft_strstrjoin(envv->env_var[i], value, suffix);
	if (envv->env_var[i] == NULL)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	export_special(t_env *envv, t_export *exp)
{
	if (envv->env_var == NULL)
	{
		return (EXIT_FAILURE);
	}
	if (ft_strcmp(envv->env_var[exp->i], "PWD") == 0)
	{
		return (handle_env_var_update(envv, exp->i, envv->pwd, "="));
	}
	else if (ft_strcmp(envv->env_var[exp->i], "PWD=") == 0)
	{
		return (handle_env_var_update(envv, exp->i, envv->pwd, NULL));
	}
	else if (ft_strcmp(envv->env_var[exp->i], "OLDPWD") == 0)
	{
		return (handle_env_var_update(envv, exp->i, envv->oldpwd, "="));
	}
	else if (ft_strcmp(envv->env_var[exp->i], "OLDPWD=") == 0)
	{
		return (handle_env_var_update(envv, exp->i, envv->oldpwd, NULL));
	}
	return (EXIT_SUCCESS);
}
