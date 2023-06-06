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


#include "minitalk.h"
#include <stdlib.h>

void	bin_to_char(int bin)
{
	static int	i;
	static int	bit;

	if(bin == SIGUSR1)
		i |= (1 << bit);
	bit++;

	if(bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("\n\tPID: %d\n", pid);
	printf("---Esperando el mensaje del client---\n");
	signal(SIGUSR1, bin_to_char);
	signal(SIGUSR2, bin_to_char);
	printf("\n");
	while(1)
		pause();
	return (0);
}
