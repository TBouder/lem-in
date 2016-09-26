/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:34:12 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/14 21:57:54 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putnbr() function prints the number nb to STDIN.
*/

#include "../libft.h"

void	ft_putnbr(int nb)
{
	if (nb < -2147483647)
		ft_putstr("-2147483648");
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
	}
}
