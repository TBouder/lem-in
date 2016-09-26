/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:25:30 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/20 16:31:11 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isascii() function tests for an ASCII character, which is any
** character between 0 and octal 0177 inclusive.
*/

#include "../libft.h"

int		ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
