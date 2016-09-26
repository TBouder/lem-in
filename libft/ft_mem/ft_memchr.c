/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:30:17 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:11:41 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memchr() function locates the first occurrence of c (converted to
** an unsigned char) in string s.
*/

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	void			*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
	{
		if (((unsigned char *)temp)[i] == (unsigned char)c)
			return (temp + i);
		i++;
	}
	temp = NULL;
	return (temp);
}
