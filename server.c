/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:39:18 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/06/05 12:39:21 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr(int num)
{
	if (num > 9)
		ft_putnbr(num / 10);
	num = num % 10 + '0';
	write(1, &num, 1);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static int	bit;

	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write (1, &i, 1);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	saction;

	(void)argv;
	if (argc != 1)
		return (0);
	write(1, "PID:", 5);
	ft_putnbr(getpid());
	write (1, "\n---Esperando el mensaje del client---\n", 41);
	saction.sa_sigaction = handler;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &saction, NULL);
		sigaction(SIGUSR2, &saction, NULL);
		pause();
		if (sigaction(SIGUSR1, &saction, NULL) == -1)
			exit(1);
		else if (sigaction(SIGUSR2, &saction, NULL) == -1)
			exit(1);
	}
	while (1)
		pause();
	return (0);
}
