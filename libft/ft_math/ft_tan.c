/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 00:16:48 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/21 00:21:02 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_tan() function computes the tangent of x (measured in degree).
*/

#include "../libft.h"

double		ft_tan(double nb)
{
	return (ft_sin(nb) / ft_cos(nb));
}
