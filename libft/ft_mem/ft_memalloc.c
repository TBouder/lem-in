/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:29:44 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 15:22:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memalloc() function malloc a buffer and use the ft_bzero() function
** to initialize it.
*/

#include "../libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*buffer;

	if ((buffer = (void *)malloc(size)) == NULL)
		return (NULL);
	ft_bzero(buffer, size);
	return (buffer);
}
