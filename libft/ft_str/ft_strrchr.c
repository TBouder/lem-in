/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:06:07 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:36:08 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strrchr() function is identical to ft_strchr(), except it locates
** the last occurrence of c.
*/

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return (((char *)s + i));
		i--;
	}
	return (NULL);
}
