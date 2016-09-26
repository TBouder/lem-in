/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:06:53 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 15:03:46 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strstr() function locates the first occurrence of the
** null-terminated string little in the null-terminated string big.
*/

#include "../libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	if (s2[0] == '\0')
		return (char*)(s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			j++;
			if (s2[j] == '\0')
				return ((char*)s1 + i);
		}
		i++;
	}
	return (NULL);
}
