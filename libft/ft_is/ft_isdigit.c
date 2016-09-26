/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:27:44 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 15:24:29 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isdigit() function tests for a decimal digit character :
** 0 - 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9.
*/

#include "../libft.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
