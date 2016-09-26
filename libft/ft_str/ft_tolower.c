/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:07:30 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 15:12:27 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The tolower() function converts an upper-case letter to the corresponding
** lower-case letter.
*/

#include "../libft.h"

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
