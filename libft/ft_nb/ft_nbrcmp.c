/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 14:30:38 by tbouder           #+#    #+#             */
/*   Updated: 2016/09/13 09:24:33 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_nbrcmp() function returns 0 if nb1 and nb2 are equal, or the diff
** between nb1 and nb2.
*/

#include "../libft.h"

int		ft_nbrcmp(int nb1, int nb2)
{
	if (nb1 == nb2)
		return (0);
	return (nb1 - nb2);
}
