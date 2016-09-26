/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:54:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/23 23:46:06 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strnew() function malloc a char buffer and use the ft_bzero()
** function to initialize it.
*/

#include "../libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*buffer;

	if (!(buffer = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(buffer, size + 1);
	return (buffer);
}
