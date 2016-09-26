/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:49:27 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/09 15:21:38 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_cos() function computes the cosine of x (measured in degree)
*/

#include "../libft.h"

double		ft_cos(double nb)
{
	double		taylor;
	double		square_nb;
	int			i;

	i = 2;
	square_nb = ((nb * PI / 180) * (nb * PI / 180));
	nb = 1;
	taylor = 1;
	while (i <= 20)
	{
		nb = -nb * (square_nb);
		taylor += nb / ft_factorial(i);
		i += 2;
	}
	return (taylor);
}
