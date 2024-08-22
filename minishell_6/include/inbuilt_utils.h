/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inbuilt_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:56:22 by alanty            #+#    #+#             */
/*   Updated: 2024/07/05 19:48:01 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INBUILT_UTILS_H
# define INBUILT_UTILS_H

# include "env_var_utils.h"
typedef struct s_export
{
	int		i;
	int		j;
	char	*var;
}			t_export;
int		export_only(t_env *envv);
int		export_input_error(char **argv);
int		export_special(t_env *envv, t_export *exp);
int		export_wd(t_env *envv, t_export *exp, char **argv);

#endif
