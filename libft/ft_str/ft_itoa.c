/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:28:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/05 10:55:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_itoa() function converts the initial int representation by a string
** pointed to by nb.
*/

#include "../libft.h"
#include <stdlib.h>

static char	*except(int n, char *nb)
{
	if (n < -2147483647)
	{
		ft_memset(nb, '\0', ft_strlen("-2147483648") + 1);
		ft_memmove(nb, "-2147483648", 11);
	}
	else
	{
		ft_memset(nb, '\0', ft_strlen("0") + 1);
		ft_memmove(nb, "0", 2);
	}
	return (nb);
}

char		*ft_itoa(int n)
{
	char	*nb;
	int		i;
	int		j;
	int		len;
	int		sign;

	i = 0;
	len = ft_nbrlen(n);
	sign = n < 0 ? -1 : 1;
	n < 0 ? n = -n : 0;
	n < 0 ? len++ : 0;
	j = (sign < 0) ? len + 1 : len;
	nb = ft_strnew(len + 2);
	if (n < -2147483647 || n == 0)
		return (except(n, nb));
	nb[j--] = '\0';
	while (i < len)
	{
		nb[j--] = n % 10 + '0';
		n /= 10;
		i++;
	}
	(sign == -1) ? nb[j] = '-' : 0;
	return (nb);
}
