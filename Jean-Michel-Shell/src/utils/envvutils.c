/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:40:54 by alanty            #+#    #+#             */
/*   Updated: 2024/07/08 19:22:25 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "minishell.h"
#include "env_var_utils.h"

static t_env	*_get_envv(t_env *envv)
{
	static t_env	*static_envv = NULL;

	if (envv == NULL)
		return (static_envv);
	static_envv = envv;
	return (static_envv);
}

void	set_envv(t_env *envv)
{
	_get_envv(envv);
}

t_env	*get_envv(void)
{
	return (_get_envv(NULL));
}

char	**get_env_var(void)
{
	t_env	*envv;

	envv = get_envv();
	if (envv == NULL)
		return (NULL);
	return (envv->env_var);
}
*/
#include "minishell.h"
#include "env_var_utils.h"

static t_env	*retrieve_envv(t_env *envv)
{
	static t_env	*static_envv = NULL;

	if (envv != NULL)
	{
		static_envv = envv;
	}
	return (static_envv);
}

void	set_envv(t_env *envv)
{
	retrieve_envv(envv);
}

t_env	*get_envv(void)
{
	return (retrieve_envv(NULL));
}

char	**get_env_var(void)
{
	t_env	*envv;

	envv = get_envv();
	if (envv == NULL)
	{
		return (NULL);
	}
	return (envv->env_var);
}
