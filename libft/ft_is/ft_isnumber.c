/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:50:51 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/20 16:31:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isnumber() function behaves similarly to ft_isdigit().
*/

#include "../libft.h"

int		ft_isnumber(int c)
{
	if (ft_isdigit(c))
		return (1);
	return (0);
}
