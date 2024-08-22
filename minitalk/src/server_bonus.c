/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:48:32 by alanty            #+#    #+#             */
/*   Updated: 2024/04/15 11:48:34 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	reception_signal(int signal, siginfo_t *info, void *s)
{
	static int		bit = 0;
	static unsigned char	c = 0;

	(void)s;
	if (signal == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_putstr_fd("Impossible d'envoyer SIGUSR1\n", 2);
	}
	else
	{
		if (kill(info->si_pid, SIGUSR2) == -1)
			ft_putstr_fd("Impossible d'envoyer SIGUSR2\n", 2);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[91mErreur: format incorrect.\033[0m\n");
		ft_printf("\033[33mRessayez: ./server\033[0m\n");
		return (1);
	}
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", getpid());
	ft_printf("\033[90mEn attente d'un message...\033[0m\n");
	sig.sa_sigaction = reception_signal;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
