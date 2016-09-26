/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:47:17 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/20 23:56:04 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_power() function returns the number according to the power.
*/

#include "../libft.h"

double		ft_power(double nb, double power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}
