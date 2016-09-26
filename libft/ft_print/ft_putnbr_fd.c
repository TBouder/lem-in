/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:34:25 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/09 16:40:49 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putnbr_fd() function prints the number nb to the output stream
** pointed to by fd.
*/

#include "../libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < -2147483647)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb = -nb;
		}
		if (nb <= 9)
			ft_putchar_fd(nb + '0', fd);
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
	}
}
