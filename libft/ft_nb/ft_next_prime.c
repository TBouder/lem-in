/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_prime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:37:30 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:17:04 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_next_prime() function return the next prime number after nb or nb
** if nb is prime.
*/

#include "../libft.h"

int		ft_next_prime(int nb)
{
	nb++;
	if (ft_isprime(nb) == 0)
	{
		while (!(ft_isprime(nb)))
			nb++;
	}
	return (nb);
}
