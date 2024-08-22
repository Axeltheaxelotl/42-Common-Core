/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:48:08 by alanty            #+#    #+#             */
/*   Updated: 2024/04/15 13:50:23 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	envoyer_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			envoyer_bits(pid, argv[2][i]);
			i++;
		}
		envoyer_bits(pid, '\n');
	}
	else
	{
		ft_printf("\033[91mErreur: format incorrect.\033[0m\n");
		ft_printf("\033[33mEssayez: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
	return (0);
}
