/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:50:16 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:29:51 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strncat() function append a copy of the null-terminated string s2
** to the end of the null-terminated string s1, while n is not 0,
** then add a terminating `\0'. The string s1 must have sufficient space to
** hold the result.
*/

#include "../libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		y;

	i = 0;
	y = 0;
	while (s1[y])
		y++;
	while (i < n)
	{
		s1[y] = s2[i];
		y++;
		i++;
	}
	s1[y] = '\0';
	return (s1);
}
