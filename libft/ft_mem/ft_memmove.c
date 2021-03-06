/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:31:08 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/30 18:21:10 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memmove() function copies len bytes from string src to string dst.
** The two strings may overlap; the copy is always done in a
** non-destructive manner.
*/

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;

	temp = ft_strnew(len);
	ft_memcpy(temp, src, len);
	ft_memcpy(dst, temp, len);
	ft_strdel(&temp);
	return (dst);
}
