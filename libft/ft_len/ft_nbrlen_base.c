/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 22:06:30 by Tbouder           #+#    #+#             */
/*   Updated: 2016/06/02 13:04:25 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_nbrlen_base() function computes the length of nbr, according to the
** base. TO DO : add bases after 10.
*/

#include "../libft.h"

int		ft_nbrlen_base(long long n, int base)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}
