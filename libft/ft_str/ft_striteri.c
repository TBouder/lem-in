/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:37:13 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:49:17 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_striteri() function applies the function f() to each part of s with
** an index to secure the f().
*/

#include "../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	index = 0;
	if (s != NULL && f != NULL)
		while (s && *s)
			f(index++, s++);
}
