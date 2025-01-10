/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:41:10 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 17:41:38 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error_utils.h"

static int	_get_err_code(int err_code, bool set_err_code)
{
	static int	static_err_code = 0;

	if (set_err_code)
		static_err_code = err_code;
	return (static_err_code);
}

void	set_err_code(int err_code)
{
	static bool	last_cmd_ctrlc = false;

	if (last_cmd_ctrlc)
	{
		last_cmd_ctrlc = false;
		return ;
	}
	if (err_code == 130)
		last_cmd_ctrlc = true;
	_get_err_code(err_code, true);
}

int	get_err_code(void)
{
	return (_get_err_code(0, false));
}
