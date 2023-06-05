/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:04:06 by lnarvaez          #+#    #+#             */
/*   Updated: 2022/03/22 13:04:08 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Convierte la porcion inicial de un str en un int, devuleve el valor convertido
o 0 en caso de error.
*/
#include "libft.h"

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
	while (ft_isdigit(str[i]))
	{
		if ((a / 10 < res) || (a + (str[i] - '0') < res * 10))
			return (a * signo);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * signo);
}

int	main(void)
{
	char str[]= " --5+4";
	printf("\natoi: %d",atoi(str));
	printf("\nmia : %d",ft_atoi(str));
}
