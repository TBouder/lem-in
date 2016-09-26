/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:24:37 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/04 11:36:14 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_bzero() function writes n zeroed bytes to the string s.
** If n is zero, bzero() does nothing.
*/

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
