/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:48:28 by Tbouder           #+#    #+#             */
/*   Updated: 2016/01/30 19:55:15 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_fibonacci() function returns a number according to fibonacci
** sequence.
*/

#include "../libft.h"

int		ft_fibonacci(int nb)
{
	if (nb < 0)
		return (-1);
	else if (nb == 0)
		return (0);
	if (nb == 1)
		return (1);
	return (ft_fibonacci(nb - 1) + ft_fibonacci(nb - 2));
}
