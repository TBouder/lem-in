/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:37:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/02 16:49:39 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isprime() function tests is a number c is prime.
*/

#include "../libft.h"

int		ft_isprime(int c)
{
	int		i;

	if (c <= 0 || c == 1)
		return (0);
	i = 2;
	while (i < c)
	{
		if (c % i == 0)
			return (0);
		i++;
	}
	return (1);
}
