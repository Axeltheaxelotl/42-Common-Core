/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envpset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:47:48 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 17:47:56 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**_get_envp(char *envp[], bool reset)
{
	static char	**static_envp = NULL;

	if (envp == NULL && !reset)
		return (static_envp);
	if (reset)
	{
		static_envp = NULL;
		return (NULL);
	}
	static_envp = envp;
	return (static_envp);
}

void	set_envp(char *envp[])
{
	_get_envp(envp, false);
}

char	**get_envp(void)
{
	return (_get_envp(NULL, false));
}

void	reset_envp(void)
{
	_get_envp(NULL, true);
}
