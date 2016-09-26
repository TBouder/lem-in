/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:21:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 15:22:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_realloc() function tries to change the size of the allocation
** pointed to by ptr to size, and returns ptr. If ptr is NULL, ft_realloc()
** is identical to a call to malloc() for size bytes.
*/

#include <stdlib.h>
#include "../libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void		*new_mem;
	size_t		len;
	t_block		*block;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(size));
	block = ptr - 8;
	if (size > block->size / 2 && size < block->size - 8)
		return (ptr);
	new_mem = ft_memalloc(size);
	len = block->size - 8;
	if (len > size)
		len = size;
	ft_memcpy(new_mem, ptr, len);
	free(ptr);
	return (new_mem);
}
