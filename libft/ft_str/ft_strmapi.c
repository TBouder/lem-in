/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:38 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/26 15:19:15 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strmapi() applies to each character the f function and creates a
** "fresh" new list with malloc resulting from successive applications, by
** specifying the index.
*/

#include "../libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*temp;
	char			*buffer;
	unsigned int	i;
	unsigned int	index;

	if (s == NULL || f == NULL)
		return (NULL);
	temp = (char *)s;
	i = 0;
	index = 0;
	if ((buffer = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	while (temp[i])
	{
		buffer[i] = f(index, temp[i]);
		i++;
		index++;
	}
	buffer[i] = '\0';
	return (buffer);
}
