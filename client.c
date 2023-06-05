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

#include "minitalk.h"

/* Atoi: para validar si el PID es un numero */
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

/* Transformar de Caracter a Binario */
void	char_to_bin(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (0x01 << i))
            kill(pid, SIGUSR1);
        else
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
}


int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if(argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while(argv[2][i] != '\0')
		{
			char_to_bin(pid, argv[2][i]);
			i++;
		}
	}
	return(0);
}
