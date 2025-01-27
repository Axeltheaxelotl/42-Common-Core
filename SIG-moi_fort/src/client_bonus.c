/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:48:25 by alanty            #+#    #+#             */
/*   Updated: 2024/04/15 11:48:27 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	confirme_reception(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("\033[0;32mReception confirmee pour SIGUSR1\033[0m\n");
	else if (signal == SIGUSR2)
		ft_printf("\033[0;31mReception confirmee pour SIGUSR2\033[0m\n");
}

void	envoyer_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
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
			signal(SIGUSR1, confirme_reception);
			signal(SIGUSR2, confirme_reception);
			envoyer_bits(pid, argv[2][i]);
			i++;
		}
		envoyer_bits(pid, '\n');
	}
	else
	{
		ft_printf("\033[91mErreur: format incorrect.\033[0m\n");
		ft_printf("\033[33mEssayez: ./client_bonus [PID] [MESSAGE]\033[0m\n");
		return (1);
	}
	return (0);
}
