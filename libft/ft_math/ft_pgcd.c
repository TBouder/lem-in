/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:30:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/10 17:34:09 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_power() function returns the PGCD of the two numbers nb1 and nb2.
*/

#include "../libft.h"

int		ft_pgcd(int nb1, int nb2)
{
	int value;
	int save;

	value = 1;
	save = 1;
	while (value <= nb1 && value <= nb2)
	{
		if (nb1 % value == 0 && nb2 % value == 0)
			save = value;
		value++;
	}
	return (save);
}
