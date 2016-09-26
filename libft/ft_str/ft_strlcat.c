/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:37:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 15:23:42 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strlcat() function will first count the difference between the %p of
** the original dst (dst[0]) and the "final" dst (dst[size]).
** When space == 0 || *dst == '\0', the fonction will make this difference
** and will give us len, wich is the size of dst that will be concat'
** the, the ft_swap_cat function wille just do the contatenation
*/

#include "../libft.h"

static void	ft_swap_cat(int space, const char *src, char *dest)
{
	while (*src != '\0')
	{
		if (space != 1)
		{
			*dest = *src;
			dest++;
			space--;
		}
		src++;
	}
	*dest = '\0';
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*temp;
	int		len;
	int		space;

	temp = dst;
	space = size;
	while (space && *temp)
	{
		space--;
		temp++;
	}
	len = temp - dst;
	space = size - len;
	if (space == 0)
		return (len + ft_strlen(src));
	ft_swap_cat(space, src, temp);
	return (len + ft_strlen(src));
}
