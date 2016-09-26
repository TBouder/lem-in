/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlargest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 11:54:15 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/30 03:47:48 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_nbrlargest() function looks for the largest number in an INT table.
*/

#include "../libft.h"

int		ft_nbrlargest(int *nbr, int len)
{
	int		i;
	int		gr;

	i = 0;
	gr = 0;
	while (i < len)
	{
		if (nbr[i] > gr)
			gr = nbr[i];
		i++;
	}
	return (gr);
}
