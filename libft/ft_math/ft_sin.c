/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:49:27 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/09 15:21:49 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_sin() function computes the sine of x (measured in degree)
*/

#include "../libft.h"

double		ft_sin(double nb)
{
	double		taylor;
	double		square_nb;
	int			i;

	i = 3;
	nb *= PI / 180;
	taylor = nb;
	square_nb = (nb * nb);
	while (i <= 21)
	{
		nb = -nb * (square_nb);
		taylor += nb / ft_factorial(i);
		i += 2;
	}
	return (taylor);
}
