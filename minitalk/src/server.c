/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:48:14 by alanty            #+#    #+#             */
/*   Updated: 2024/04/15 11:48:16 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h> 

void	reception_signal(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[91mErreur: format incorrect.\033[0m\n");
		ft_printf("\033[33mEssayer: ./server\033[0m\n");
		return (0);
	}
	pid = getpid();
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
	ft_printf("\033[90mEn attente d'un message...\033[0m\n");
	while (argc == 1)
	{
		signal(SIGUSR1, reception_signal);
		signal(SIGUSR2, reception_signal);
		pause ();
	}
	return (0);
}
