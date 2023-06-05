/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:13:18 by lnarvaez          #+#    #+#             */
/*   Updated: 2022/03/21 14:23:25 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1 si es digito, 0 si no
*/
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%d", ft_isdigit(-57));
}*/

