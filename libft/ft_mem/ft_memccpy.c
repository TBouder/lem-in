/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:30:00 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:11:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memccpy() function copies bytes from string src to string dst.
** If the character c (as converted to an unsigned char) occurs in the string
** src, the copy stops and a pointer to the byte after the copy of c in the
** string dst is returned.  Otherwise, n bytes are copied, and a NULL pointer
** is returned.
*/

#include "../libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = NULL;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		if (((char *)dst)[i] == c)
		{
			i++;
			return (dst + i);
		}
		i++;
	}
	return (ptr);
}
