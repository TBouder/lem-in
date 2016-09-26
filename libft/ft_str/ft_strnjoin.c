/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:37:27 by tbouder           #+#    #+#             */
/*   Updated: 2016/07/28 17:24:03 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strnjoin() function appends the string s2 to the end of s1 in a new
** string str with the n value, the same way than for strncat.
*/

#include "../libft.h"
#include <stdlib.h>

char	*ft_strnjoin(char const *s1, char const *s2, int n1, int n2)
{
	char	*str;

	if (s1 != NULL && s2 != NULL)
	{
		str = ft_strnew((n1 + n2 + 1));
		ft_strncpy(str, (char *)s1, n1);
		return (ft_strncat(str, s2, n2));
	}
	return (NULL);
}
