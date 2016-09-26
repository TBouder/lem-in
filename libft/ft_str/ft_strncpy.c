/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:53:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 14:57:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strncpy() function copy at most len characters from src into dst.
** If src is less than len characters long, the remainder of dst is filled
** with `\0' characters.  Otherwise, dst is not terminated.
*/

#include "../libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		while (src[i] && i < n)
		{
			dst[i] = src[i];
			i++;
		}
		while (i < n)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}
