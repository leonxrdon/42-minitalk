/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:39:31 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/06/05 12:39:33 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int				i;
	int				signo;
	unsigned long	res;
	unsigned long	a;

	i = 0;
	signo = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -1;
		i++;
	}
	a = LONG_MAX + (signo == -1);
	while (str[i] >= 48 && str[i] <= 57)
	{
		if ((a / 10 < res) || (a + (str[i] - '0') < res * 10))
			return (a * signo);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * signo);
}

void	confirm(int sig)
{
	if (sig == SIGUSR2)
		write(1, "[ok] ", 5);
}

void	send_signals(int pid, char c)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (c & (1 << j))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid;
	struct sigaction	saction;

	saction.sa_handler = confirm;
	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			signal(SIGUSR1, confirm);
			signal(SIGUSR2, confirm);
			send_signals(pid, argv[2][i]);
			i++;
		}
		send_signals(pid, '\n');
	}
	return (0);
}
