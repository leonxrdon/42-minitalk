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

void	ft_putnbr(int num)
{
	if (num > 9)
		ft_putnbr(num / 10);
	num = num % 10 + '0';
	write(1, &num, 1);
}

void	bin_to_char(int sig)
{
	static int	i;
	static int	bit;

	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write (1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	write(1, "PID:", 5);
	ft_putnbr(getpid());
	write (1, "\n---Esperando el mensaje del client---\n", 41);
	signal(SIGUSR1, bin_to_char);
	signal(SIGUSR2, bin_to_char);
	while (1)
		pause();
	return (0);
}
