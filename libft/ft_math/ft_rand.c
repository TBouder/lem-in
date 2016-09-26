/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:54:04 by tbouder           #+#    #+#             */
/*   Updated: 2016/09/13 09:36:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_rand() fonction gives you a random number between 0 and (max - 1).
*/

#include <stdlib.h>
#include "../libft.h"

static int		ft_rev_nb(int nb)
{
	int		nb_l;
	int		i;
	int		*new_nb;

	nb_l = ft_nbrlen(nb);
	i = 0;
	if (!(new_nb = (int *)malloc(sizeof(int) * nb_l)))
		return (0);
	while (i < nb_l)
	{
		new_nb[i] = nb % 10;
		nb /= 10;
		i++;
	}
	i = 0;
	nb = 0;
	while (i < nb_l - 1)
	{
		nb += new_nb[i];
		nb *= 10;
		i++;
	}
	return (nb);
}

static int		ft_rand_max_peer(int max)
{
	static int	prime = 0;
	int			nb;
	void		*r;

	if (!(r = (void *)malloc(2)))
		return (0);
	nb = (int)r + prime;
	nb < 0 ? nb = -nb : 0;
	prime = ft_next_prime(prime);
	ft_rev_nb(nb);
	while (nb >= max)
		nb %= max;
	if (nb == max - 1)
		nb = ft_rand_max_peer(max);
	return (nb);
}

static int		ft_rand_max_odd(int max)
{
	static int	prime = 0;
	int			nb;
	void		*r;

	if (!(r = (void *)malloc(2)))
		return (0);
	nb = (int)r + prime;
	nb < 0 ? nb = -nb : 0;
	prime = ft_next_prime(prime);
	ft_rev_nb(nb);
	while (nb >= max)
		nb %= max;
	return (nb);
}

int				ft_rand(int nb)
{
	unsigned int	result;

	if (nb % 2 == 0)
	{
		nb++;
		result = ft_rand_max_peer(nb);
	}
	else
		result = ft_rand_max_odd(nb);
	return (result);
}
