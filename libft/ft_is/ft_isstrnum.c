/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:19:38 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/23 13:20:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isstrnum() function tests if a string contains only numbers.
*/

#include "../libft.h"

int		ft_isstrnum(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isnumber(str[i]))
			return (0);
		i++;
	}
	return (1);
}
