/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:37:54 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 01:31:43 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strlen() function computes the length of the string str.
*/

#include "../libft.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
