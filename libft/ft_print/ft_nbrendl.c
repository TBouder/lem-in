/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:53:17 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/24 12:47:02 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_nbrendl() function prints the number nb followed by a \n.
*/

#include "../libft.h"

void		ft_nbrendl(int nb)
{
	ft_putnbr(nb);
	ft_putchar('\n');
}
