/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 15:20:42 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/29 15:21:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strcountchar() function will count the number of occurence of c inside
** of str
*/

#include "../libft.h"

int		ft_strcountchar(char *str, char c)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	while (str[i])
	{
		if (str[i] == c)
			space++;
		i++;
	}
	return (space + 1);
}
