/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:35:29 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:30:40 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strchr() function locates the first occurrence of c (converted to
** a char) in the string pointed to by s. The terminating null character is
** considered to be part of the string; therefore if c is `\0', the functions
** locate the terminating `\0'.
*/

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (((char *)s + i));
		i++;
	}
	if (s[i] == c)
		return (((char *)s + i));
	return (NULL);
}
