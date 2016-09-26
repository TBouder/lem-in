/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 01:23:19 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/20 16:38:46 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_linelen() function computes the length of the line str, until \n.
*/

#include "../libft.h"

int		ft_linelen(const char *str, int i)
{
	int		len;

	len = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}
