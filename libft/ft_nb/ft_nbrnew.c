/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 04:18:19 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/30 04:20:40 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_nbrnew() function malloc an int buffer and initialize it with 0.
*/

#include "../libft.h"
#include <stdlib.h>

int		*ft_nbrnew(size_t size)
{
	int			*buffer;
	size_t		i;

	i = 0;
	if (!(buffer = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}
