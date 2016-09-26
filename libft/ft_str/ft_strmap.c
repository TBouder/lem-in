/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/26 15:19:08 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strmap() applies to each character the f function and creates a
** "fresh" new list with malloc resulting from successive applications.
*/

#include "../libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*temp;
	char			*buffer;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	temp = (char *)s;
	i = 0;
	if ((buffer = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	while (temp[i])
	{
		buffer[i] = f(temp[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
