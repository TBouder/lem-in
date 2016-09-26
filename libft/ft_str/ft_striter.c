/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:37:01 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:48:13 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_striter() function applies the function f() to each part of s
*/

#include "../libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	if (s != NULL && f != NULL)
		while (s && *s)
			f(s++);
}
