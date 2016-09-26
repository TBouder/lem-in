/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:48:38 by Tbouder           #+#    #+#             */
/*   Updated: 2016/05/31 12:57:52 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_sqrt() function returns the square of nb.
*/

#include "../libft.h"

int		ft_sqrt(int nb)
{
	int	i;
	int	sqr;

	sqr = 0;
	i = 1 << 30;
	while (i > nb)
		i >>= 2;
	while (i != 0)
	{
		if (nb >= sqr + i)
		{
			nb -= sqr + i;
			sqr = (sqr >> 1) + i;
		}
		else
			sqr >>= 1;
		i >>= 2;
	}
	return (sqr);
}
