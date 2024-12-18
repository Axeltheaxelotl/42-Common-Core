/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifier_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:15:41 by alanty            #+#    #+#             */
/*   Updated: 2024/05/10 11:50:02 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	contient(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	est_nombre(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	verifier_arguments(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!est_nombre(args[i]))
			erreur("Erreur");
		if (contient(tmp, args, i))
			erreur("Erreur");
		if (tmp < -2147483648 || tmp > 2147483647)
			erreur("Erreur");
		i++;
	}
	if (argc == 2)
		liberer(args);
}
