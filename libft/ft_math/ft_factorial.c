/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:47:06 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/20 23:56:27 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_factorial() function gives us the factorial result of nb.
*/

#include "../libft.h"

double		ft_factorial(double nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (nb);
	return (nb * ft_factorial(nb - 1));
}
