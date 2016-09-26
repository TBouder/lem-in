/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:36:49 by tbouder           #+#    #+#             */
/*   Updated: 2016/09/13 09:26:29 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strequ() function is identical to ft_strcmp(), except it returns 1
** if both are equal of 0 if they are not.
*/

#include "../libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2 && ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}
