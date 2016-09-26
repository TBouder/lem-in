/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:30:30 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:07:11 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
*/

#include "../libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*c1;
	char	*c2;

	i = 0;
	c1 = (char *)s1;
	c2 = (char *)s2;
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (((unsigned char*)c1)[i] - ((unsigned char*)c2)[i]);
		i++;
	}
	return (0);
}
