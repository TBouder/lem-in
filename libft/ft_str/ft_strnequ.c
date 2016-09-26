/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:54:06 by tbouder           #+#    #+#             */
/*   Updated: 2016/09/13 09:30:12 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strnequ() function is identical to ft_strncmp(), except it returns 1
** if both are equal of 0 if they are not.
*/

#include "../libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2 && ft_strncmp(s1, s2, n) == 0)
		return (1);
	return (0);
}
